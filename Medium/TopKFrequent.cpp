#include "includes.h"

// Time Complexity: O (NlogN)
// Space Complexity: O(N) 
class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k)
    {
        // Map storing the number, times we've seen
        std::unordered_map<int, int> mp;

        for (const auto &num : nums) {
            mp[num]++;
        }

        // Convert the mp to a vector to sort
        std::vector<std::pair<int, int>> numOfTimes;
        for (auto &it : mp) {
            numOfTimes.push_back(it);
        }

        std::sort(numOfTimes.begin(), numOfTimes.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) { 
            return a.second > b.second; 
        });

        std::vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(numOfTimes[i].first);
        }

        return result;
    }
};

// Time Complexity O(N)
// Space Complexity O(N)
class Solution
{
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k){

        // Get the frequencies
        std::unordered_map<int, int> counts;
        for (int num : nums) counts[num]++;

        // Create the buckets
        std::vector<std::vector<int>> buckets(nums.size() + 1);
        for (auto const &[num, freq] : counts) {
            buckets[freq].push_back(num);
        }

        // Grab the k amount
        std::vector<int> result;
        for (int i = buckets.size() - 1; i >= 0; --i) {
            for (int num : buckets[i])
            {
                result.push_back(num);
                if (result.size() == k)
                    return result;
            }
        }

        return result;
    }
};
