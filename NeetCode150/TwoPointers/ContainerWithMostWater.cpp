#include "includes.h"
class Solution
{
public:
    int maxArea(std::vector<int> &heights)
    {

        int n = heights.size() - 1;
        int left = 0;
        int right = n;
        int maxVolume = 0;

        // Calculate the distance between left and right
        while (left < right)
        {
            // The min(left,right) * the length = volume
            int volume = std::min(heights[left], heights[right]) * (right - left);
            maxVolume = std::max(maxVolume, volume);

            if (heights[left] < heights[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return maxVolume;
    }
};
