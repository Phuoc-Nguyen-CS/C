#ifndef LIST_OF_DEPTHS
#define LIST_OF_DEPTHS
// 4.3 List of Depths:
// Given a binary tree, design an algorithm which creates a linked list of
// all the nodes at each depth (e.g., if you have a tree with depth D,
// you'll have D linked lists)

// Thinking Process:
// BFS goes through each layer so this would probably be the easiest method
// We can go through each layer and create a list that would then just 
// connect at each depth

#include <list>
#include <queue>
#include <vector>
#include "node.h"

std::vector<std::list<Node*>> listOfDepths(Node* root) {
    std::vector<std::list<Node*>> result;
    if (root == nullptr) return result;

    std::queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        std::list<Node*> currentLevel;
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            Node* n = q.front();
            q.pop();

            currentLevel.push_back(n); // + to linked list for level
        
            if (n->left != nullptr) q.push(n->left);
            if (n->right !=nullptr) q.push(n->right);
        }
        result.push_back(currentLevel); // Saves each level
    }
    return result;
}
#endif