#include "includes.h"

class Twitter
{
public:
    int tweetNum;
    int screenSize = 10;
    std::unordered_map<int, std::vector<std::pair<int, int>>> tweetMap;
    std::unordered_map<int, std::unordered_set<int>> followMap;

    // Initializes Twitter with no tweets since we're just creating it
    Twitter()
    {
        tweetNum = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        // Add the tweet for the user
        tweetMap[userId].push_back({tweetNum, tweetId});
        // If the user has made more than 10 tweets
        // We erase the earliest tweet they made and keep the 10 most recent
        if (tweetMap[userId].size() > screenSize)
        {
            tweetMap[userId].erase(tweetMap[userId].begin());
        }
        tweetNum--;
    }

    std::vector<int> getNewsFeed(int userId)
    {
        std::vector<int> res;

        // 1. Ensure the user is following themselves to see their own tweets in the feed
        followMap[userId].insert(userId);
        // 2. The "VIP List" (minHeap): We use std::greater to make the SMALLEST timestamp
        // (which is actually our newest tweet because of tweetNum--) stay at the top.
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> minHeap;

        // 3. OPTIMIZATION: If we follow more than 10 people, we don't need to look at everyone's
        // entire history. We use a temporary maxHeap to find the 10 users with the most recent activity.
        if (followMap[userId].size() >= screenSize)
        {
            std::priority_queue<std::vector<int>> maxHeap;
            for (auto f : followMap[userId])
            {
                if (!tweetMap.count(f))
                    continue; // No tweets from the given user

                int index = tweetMap[f].size() - 1;
                auto &p = tweetMap[f][index];
                // Push {timestamp, tweetId, userId, tweetIndex}
                maxHeap.push({-p.first, p.second, f, index - 1});

                // Keep only the 10 users who tweeted most recently
                if (maxHeap.size() > screenSize)
                    maxHeap.pop();
            }

            // Transfer those top 10 candidates into our main minHeap
            while (!maxHeap.empty())
            {
                auto t = maxHeap.top();
                maxHeap.pop();
                minHeap.push({-t[0], t[1], t[2], t[3]});
            }
        }
        else
        {
            // 4. STANDARD CASE: If following < 10 people, just grab the latest tweet from everyone
            for (auto f : followMap[userId])
            {
                if (!tweetMap.count(f))
                    continue;
                int index = tweetMap[f].size() - 1;
                auto &p = tweetMap[f][index];
                minHeap.push({p.first, p.second, f, index - 1});
            }
        }

        // 5. THE MERGE: Pop the globally most recent tweet and "refill" the heap
        // from that same user's timeline until we have 10 tweets.
        while (!minHeap.empty() && res.size() < screenSize)
        {
            auto t = minHeap.top();
            minHeap.pop();

            res.push_back(t[1]); // Add tweetId to results

            // If the user who wrote this tweet has older tweets, push the next one into the heap
            int index = t[3];
            if (index >= 0)
            {
                auto &p = tweetMap[t[2]][index];
                minHeap.push({p.first, p.second, t[2], index - 1});
            }
        }
        return res;
    }

    // We would just add to the follow map of user -> follower id
    void follow(int followerId, int followeeId)
    {
        followMap[followerId].insert(followeeId);
    }

    // We check if its in the user's follower set and if so we can remove
    void unfollow(int followerId, int followeeId)
    {
        // Ensure that we can find it, if so we can remove
        // Apparently in C++ we can call erase even if the element isn't there as it won't crash
        if (followMap[followerId].find(followeeId) != followMap[followerId].end())
        {
            followMap[followerId].erase(followeeId);
        }
    }
};
