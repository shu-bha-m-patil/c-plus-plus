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


void PostorderTraversal(BST* iNode)
{
    if(iNode == nullptr)
        return;
    PostorderTraversal(iNode->_left);
    PostorderTraversal(iNode->_right);
    std::cout << iNode->_data << " ";
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
    PostorderTraversal(root); // To delete the tree
}