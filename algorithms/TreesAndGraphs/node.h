// node.h
// Class needed for this section
#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>

class Node {
public:
    // String example
    int id;
    std::string name;
    bool visited;
    // Pathfinding
    Node *parent;

    // Neighbors
    std::vector<Node *> adj;

    // Minimal BST 
    int data;
    Node* left;
    Node* right;


    Node (int id, std::string name) {
        this->id = id;
        this->name = name;
        this->visited = false;
        this->parent = nullptr;
    }

    Node (int val) { 
        data = val;
        left = nullptr;
        right = nullptr; 
    }

    void addNeighbor(Node* neighbor) {
        adj.push_back(neighbor);
    }
};

#endif