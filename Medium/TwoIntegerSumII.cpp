#include "includes.h" 
class Solution {
public:
std::vector<int> twoSum(std::vector<int> &numbers, int target) {

    int left = 0;
    int right = numbers.size() - 1;

    while (numbers[left] + numbers[right] != target)
    {
        if (numbers[left] + numbers[right] > target)
        {
            right--;
        }
        else
        {
            left++;
        }
    }

    return {left + 1, right + 1};
}};
