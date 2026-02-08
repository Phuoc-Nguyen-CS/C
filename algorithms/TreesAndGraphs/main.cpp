#include <iostream>
#include <unordered_set> 
#include "node.h"
#include "existPath.h"

int main()
{
    std::unordered_set<Node *> visited;

    Node *a = new Node(1, "Alice");
    Node *b = new Node(2, "Bob");
    Node *c = new Node(3, "Charlie");
    Node *d = new Node(4, "David");
    Node *e = new Node(5, "Eve");

    a->addNeighbor(b);
    b->addNeighbor(c);
    d->addNeighbor(e);
    c->addNeighbor(a); // Cycle: Charlie -> Alice -> Bob -> Charlie

    // -- TEST CASE 1: Path exists (A -> B -> C)
    std::cout << "Test 1 (Alice -> Charlie): ";
    if (existPath(a, c, visited))
        std::cout << "PASSED" << std::endl;
    else
        std::cout << "FAILED" << std::endl;

    visited.clear();

    // -- TEST CASE 2: Path does NOT exist (A to separate island E)
    std::cout << "Test 2 (Alice -> Eve):     ";
    if (!existPath(a, e, visited))
        std::cout << "PASSED (No path found)" << std::endl; 
    else
        std::cout << "FAILED (Path incorrectly found)" << std::endl;

    visited.clear();

    // -- TEST CASE 3: Start is End
    std::cout << "Test 3 (Alice -> Alice):   ";
    if (existPath(a, a, visited))
        std::cout << "PASSED" << std::endl;
    else
        std::cout << "FAILED" << std::endl;

    visited.clear();

    // -- TEST CASE 4: Path via Cycle (C -> A -> B)
    std::cout << "Test 4 (Charlie -> Bob):   ";
    if (existPath(c, b, visited))
        std::cout << "PASSED" << std::endl;
    else
        std::cout << "FAILED" << std::endl;

    delete a;
    delete b;
    delete c;
    delete d;
    delete e;

    return 0;
}