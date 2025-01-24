#include <iostream>
#include <climits>

struct BST {
    int data;
    BST* left;
    BST* right;
    BST(int val) : data(val), left(nullptr), right(nullptr) {}
};

void FixedBST(BST* iRoot, int min, int max, BST*& first, BST*& second)
{
    if(iRoot == nullptr) return;

    if(min >= iRoot->data || iRoot->data >= max)
    {
        if(first == nullptr)
            first = iRoot;
        second = iRoot;

        FixedBST(iRoot->left, min, max, first, second);
        FixedBST(iRoot->right, min, max, first, second);
    }
    else
    {
        FixedBST(iRoot->left, min, iRoot->data, first, second);
        FixedBST(iRoot->right, iRoot->data, max, first, second);
    }
}

int main() {
    
    BST* root = new BST(10);
    root->left = new BST(5);
    root->right = new BST(15);
    root->left->left = new BST(17);
    root->left->right = new BST(7);
    root->right->left = new BST(12);
    root->right->right = new BST(2);

    BST* firstNode = nullptr;
    BST* secondNode = nullptr;
    FixedBST(root, INT_MIN, INT_MAX, firstNode, secondNode);

    std::cout << "The mismatch nodes are " << firstNode->data << " " << secondNode->data << std::endl;
    return 0;
}
