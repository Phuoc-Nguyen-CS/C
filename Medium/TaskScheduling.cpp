#include "includes.h"
class Solution
{
public:
    int leastInterval(std::vector<char> &tasks, int n)
    {

        // Creates a mapping of frequency for how often the letter shows up
        std::vector<int> count(26, 0);
        for (char task : tasks)
        {
            count[task - 'A']++;
        }

        // Push the frequency into a heap
        // Pick most frequent task
        std::priority_queue<int> maxHeap;
        for (int i : count)
        {
            if (i > 0)
                maxHeap.push(i);
        }

    // Acts as a "cooldown room" for our tasks
    // Stores pairs of {remaining count, time when available}
    std::queue<std::pair<int, int>> q;
        int time = 0;

        // Run while there is something in the heap or the queue
        while (!maxHeap.empty() || !q.empty())
        {
            time++;

            if (maxHeap.empty())
            {
                // If no tasks are ready, we can jump to the moment when
                // the next task would be off cooldown
                time = q.front().second;
            }
            else
            {
                // Process the most frequent task
                int count1 = maxHeap.top() - 1;
                maxHeap.pop();
                // If more instances of the task remains, move it to the cooldown queue
                if (count1 > 0)
                    q.push({count1, time + n});
            }

            // Check cooldown. If the task at the front of the queue has gone off cooldown
            // We add it back to the maxHeap
            if (!q.empty() && q.front().second == time)
            {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
