// node.h
// Class needed for this section
#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>

class Node {
public:
    int id;
    std::string name;
    bool visited;

    Node* parent; // pathfinding

    std::vector<Node*> adj; // neighbors 

    Node (int id, std::string name) {
        this->id = id;
        this->name = name;
        this->visited = false;
        this->parent = nullptr;
    }

    void addNeighbor(Node* neighbor) {
        adj.push_back(neighbor);
    }
};

#endif