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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}  TreeNode(int x) : val(x), left(nullptr), right(nullptr){}  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
                                                                                                                                                                                                   
};


#endif