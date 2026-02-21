#include "includes.h"
class Solution
{
public:
    int findMin(std::vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int left = 0;
        int right = nums.size() - 1;
        int ans = INT_MAX;

        while (left <= right)
        {
            if (nums[left] <= nums[right])
            {
                ans = std::min(ans, nums[left]);
                break;
            }

            int mid = left + (right - left) / 2;
            ans = std::min(nums[mid], ans);

            if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ans;
    }
};
