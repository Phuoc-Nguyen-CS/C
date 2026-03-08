#include "includes.h"

class Solution {
public:
    bool hasDuplicate(std::vector<int> &nums)
    {
        std::unordered_set<int> seen;

        for (int num : nums)
        {
            if (!seen.insert(num).second)
                return true;
        }

        return false;
    }
};