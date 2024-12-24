#include <iostream>


struct BST
{
    int _data;
    BST *_left;
    BST *_right;

    BST(int iData)
    {
        _data = iData;
        _left = _right = nullptr;
    }
};

BST *_prev = nullptr;

void AddChild(BST *&iRoot, int iData)
{
    if (iRoot == nullptr)
    {
        iRoot = new BST(iData);
        return;
    }

    if (iData < iRoot->_data)
        AddChild(iRoot->_left, iData);
    else if (iRoot->_data < iData)
        AddChild(iRoot->_right, iData);
}

void BuildBST(BST *&iRoot, int *iArray, size_t iSize)
{
    for (size_t i = 0; i < iSize; i++)
        AddChild(iRoot, iArray[i]);
}

BST *ConvertBSTToDoublyLinkedList(BST *&iRoot)
{
    if (iRoot == nullptr)
        iRoot;
    if (iRoot->_left == nullptr && iRoot->_right == nullptr)
        iRoot;

    BST *head = ConvertBSTToDoublyLinkedList(iRoot->_left);
    if (head == nullptr)
        head = iRoot;
    _prev = iRoot;
    ConvertBSTToDoublyLinkedList(iRoot->_right);
    _prev->_right = iRoot;
    _prev = iRoot;
    return head;
}

int main()
{
    const size_t size = 7;
    int arr[size] = {4, 2, 6, 1, 3, 5, 7};
    BST *root = nullptr;
    BuildBST(root, arr, size);
}