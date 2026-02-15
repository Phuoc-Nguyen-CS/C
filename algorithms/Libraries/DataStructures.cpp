#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <stack>

void ds_review() {
    
    // 1. Priority Queue (Default is the Max-Heap)
    std::priority_queue<int> maxHeap;

    // 2. Min-Heap (Common for "K-closest" problems)
    // std::priority_queue<Type, Container, Comparator)
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    minHeap.push(10);             // Adding elements - O(log n)
    minHeap.push(5);
    minHeap.push(20);
    int smallest = minHeap.top(); // Accessing the smallest element - O(1)
    minHeap.pop();                // Removing the smallest element- O(log n). 5 is now at the top

    // Checks if empty
    if (!minHeap.empty()) {
        std::cout << minHeap.size();
    }

    // 3. Unordered Map (Hash Table)
    std::unordered_map<std::string, int> fruitBasket;
    fruitBasket["apple"] = 5;
    
    // Checks for the existence without creating an entry
    if (fruitBasket.find("apple") != fruitBasket.end()) { /*The item exists */}

    // 4. Sets (Ordered vs Unordered)
    std::set<int> orderedSet;        // O(log n) - keeps element sorted
    std::unordered_set<int> fastSet; // O(1) avg - unique elements only

}