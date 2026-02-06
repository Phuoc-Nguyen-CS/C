#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void visit(TreeNode* node) {
    if (node) std::cout << node->val << " ";
}

// In-Order Traversal
// Visit the left branch, then current, and then right
void inOrderTraversal(TreeNode* node)
{
    if (node != nullptr)
    {
        inOrderTraversal(node->left);
        visit(node);
        inOrderTraversal(node->right);
    }
}

// Pre-Order Traversal
// Visits current node before child node
void preOrderTraversal(TreeNode* node)
{
    if (node != nullptr)
    {
        visit(node);
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}

// Post-Order Traversal
// Visits the current node after its child nodes
void postOrderTraversal(TreeNode* node)
{
    if (node != nullptr)
    {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        visit(node);
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    std::cout << "In-Order Traversal ";
    inOrderTraversal(root);
    std::cout << "Pre-Order Traversal ";
    preOrderTraversal(root);
    std::cout << "Post-Order Traversal ";
    postOrderTraversal(root);

    return 0;
}