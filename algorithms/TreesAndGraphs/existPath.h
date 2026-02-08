//existPath.cpp
#ifndef EXISTPATH_H
#define EXISTPATH_H

#include "node.h"
#include <unordered_set>

bool existPath(Node *start, Node *end, std::unordered_set<Node*>& visited) {
    if (start == nullptr)
        return false;
    if (start == end)
        return true;

    visited.insert(start);

    for (Node *neighbor : start->adj)
    {
        if (visited.find(neighbor) == visited.end()) { 
            if (existPath(neighbor, end, visited)) return true;
        }
    }
    
    return false;
    
}
#endif