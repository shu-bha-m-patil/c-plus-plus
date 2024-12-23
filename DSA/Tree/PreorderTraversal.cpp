#include <iostream>

struct BST
{
    int _data;
    BST* _left;
    BST* _right;

    BST(int iData)
    {
        _data = iData;
        _left = nullptr;
        _right = nullptr;
    }
};


void PreorderTraversal(BST* iNode)
{
    if(iNode == nullptr)
        return;
    std::cout << iNode->_data << " ";
    PreorderTraversal(iNode->_left);
    PreorderTraversal(iNode->_right);
}

void AddChild(BST*& iRoot, int iData)
{
    if(iRoot == nullptr)
    {
        iRoot = new BST(iData);
        return;
    }

    if(iData < iRoot->_data)
        AddChild(iRoot->_left, iData);
    else if(iRoot->_data < iData)
        AddChild(iRoot->_right, iData);
}

void BuildBST(BST*& iRoot, int* iArray, size_t iSize)
{
    for (size_t i = 0; i < iSize; i++)
        AddChild(iRoot, iArray[i]);
}

int main()
{
    const size_t size = 7;
    int arr[size] = {4,2,6,1,3,5,7};
    BST* root = nullptr;
    BuildBST(root, arr, size);

    std::cout << "Pre-order Traversal: ";
    PreorderTraversal(root); // To copy the tree
}