#include <iostream>
#include <climits> // For INT_MIN and INT_MAX

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Helper function to check BST property with range constraints
bool isBSTHelper(TreeNode* node, int minValue, int maxValue) {
    if (!node) 
        return true; // An empty tree is a BST.

    // Check if the current node's value violates the BST property.
    if (node->data <= minValue || node->data >= maxValue) 
        return false;

    // Recursively check left and right subtrees with updated ranges.
    return isBSTHelper(node->left, minValue, node->data) &&
           isBSTHelper(node->right, node->data, maxValue);
}

// Main function to check if the tree is a BST
bool isBST(TreeNode* root) {
    return isBSTHelper(root, INT_MIN, INT_MAX);
}

// Example usage
int main() {
    // Example of a BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(17);

    if (isBST(root)) 
        std::cout << "The tree is a BST.\n";
    else 
        std::cout << "The tree is not a BST.\n";

    return 0;
}
