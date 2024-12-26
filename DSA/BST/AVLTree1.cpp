#include <iostream>

struct AVLTree
{
    int _data;
    AVLTree* _left;
    AVLTree* _right;
    int _height;

    AVLTree(int iData) : _data(iData), _left(nullptr),  _right(nullptr),  _height(1) {}
};

int GetHeight(AVLTree* iRoot)
{
    return iRoot ? iRoot->_height : 0;
}

int GetBalanceFactor(AVLTree* iRoot)
{
    return iRoot ? GetHeight(iRoot->_left) - GetHeight(iRoot->_right) : 0;
}

AVLTree* RotateRight(AVLTree* iRoot)
{
    AVLTree* leftChild = iRoot->_left;
    AVLTree* leftChildRight = leftChild->_right;

    leftChild->_right = iRoot;
    iRoot->_left = leftChildRight;

    iRoot->_height = std::max(GetHeight(iRoot->_left), GetHeight(iRoot->_right)) + 1;
    leftChild->_height = std::max(GetHeight(leftChild->_left), GetHeight(leftChild->_right)) + 1;

    return leftChild;
}

AVLTree* RotateLeft(AVLTree* iRoot)
{
    AVLTree* rightChild = iRoot->_right;
    AVLTree* rightChildLeft = rightChild->_left;

    rightChild->_left = iRoot;
    iRoot->_right = rightChildLeft;

    iRoot->_height = std::max(GetHeight(iRoot->_left), GetHeight(iRoot->_right)) + 1;
    rightChild->_height = std::max(GetHeight(rightChild->_left), GetHeight(rightChild->_right)) + 1;

    return rightChild;
}

AVLTree* Insert(AVLTree* iRoot, int iData)
{
    if(iRoot == nullptr) 
        return new AVLTree(iData);

    if(iData < iRoot->_data)
    {
        iRoot->_left = Insert(iRoot->_left, iData);
    }
    else if(iRoot->_data < iData)
    {
        iRoot->_right = Insert(iRoot->_right, iData);
    }
    else
    {
        return iRoot;
    }

    iRoot->_height = std::max(GetHeight(iRoot->_left), GetHeight(iRoot->_right)) + 1;

    int balanceFactor = GetBalanceFactor(iRoot);

    // Left left
    if(balanceFactor > 1 && iData < iRoot->_left->_data)
        return RotateRight(iRoot);

    // Right Right
    if(balanceFactor < -1 && iRoot->_right->_data < iData)
        return RotateLeft(iRoot);

    // Left Right
    if(balanceFactor > 1 && iRoot->_left->_data < iData)
    {
        iRoot->_left = RotateLeft(iRoot->_left);
        return RotateRight(iRoot);
    }
    
    // Right Left
    if(balanceFactor < -1 && iData < iRoot->_right->_data)
    {
        iRoot->_right = RotateRight(iRoot->_right);
        return RotateLeft(iRoot);
    }

    return iRoot;
}

void PrintTree(AVLTree* root) {
    if (root) {
        PrintTree(root->_left);
        std::cout << root->_data << " ";
        PrintTree(root->_right);
    }
}

int main()
{
    AVLTree* root = nullptr;

    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 30);
    root = Insert(root, 40);
    root = Insert(root, 50);
    root = Insert(root, 25);

    std::cout << GetHeight(root) << std::endl;
    std::cout << "Preorder traversal of AVL tree is: ";
    PrintTree(root);
    return 0;
}