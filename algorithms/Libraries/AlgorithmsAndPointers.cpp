#include <algorithm>
#include <vector>

void algo_review() {
    
    std::vector<int> nums = {3, 1, 4, 1, 5};

    // Sorting
    // std::sort(first, last, comparison(function or lambda))
    std::sort(nums.begin(), nums.end());                      // Ascending sort
    std::sort(nums.begin(), nums.end(), std::greater<int>()); // Descending

    std::sort(nums.begin(), nums.end(), [](int a, int b) {
        return abs(a) < abs(b);
    });

    std::sort(nums.begin(), nums.end(), [](int& a, int& b) {
        return a < b ; // Returns if a before b
    });

    // Binary Search (Returns boolean, requires sorted range)
    bool exists = std::binary_search(nums.begin(), nums.end(), 4);

    // Lower Bound (First Element >= value)
    auto it = std::lower_bound(nums.begin(), nums.end(), 2);
    int index = std::distance(nums.begin(), it);
}