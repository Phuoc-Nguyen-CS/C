#ifndef INCLUDES_H
#define INCLUDES_H

// Core Input/Output
#include <iostream>
#include <sstream>

// Containers
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>

// Algorithms & Utilities
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>

// Linked List Declaration
//  * Definition for singly-linked list.
struct ListNode
{
    int val;        // The value stored in the node
    ListNode *next; // Pointer to the next node in the list

    // Default constructor (sets val to 0 and next to null)
    ListNode() : val(0), next(nullptr) {}

    // Constructor with value (sets next to null)
    ListNode(int x) : val(x), next(nullptr) {}

    // Constructor with value and a specific next node
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif