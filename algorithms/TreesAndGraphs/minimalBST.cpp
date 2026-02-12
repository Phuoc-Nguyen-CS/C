#ifndef MINIMAL_BST
#define MINIMAL_BST

#include "node.h";

Node* minimalBST(int arr[], int start, int end){
    if (end < start) return nullptr; // base

    int mid = start - (end - start) / 2;
    Node* n = new Node(arr[mid]);

    n->left = minimalBST(arr, start, mid - 1);
    n->right = minimalBST(arr, mid + 1, end);

    return n;
}
#endif