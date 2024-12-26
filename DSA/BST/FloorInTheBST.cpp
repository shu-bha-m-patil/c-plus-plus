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

BST* GetFloorInBST(BST* iRoot, int iVal)
{
    if(iRoot == nullptr) return iRoot;

    if(iVal < iRoot->_data)
    {
        BST* floorNode = GetFloorInBST(iRoot->_left, iVal);
        if(floorNode == nullptr)
            return iRoot;
        else
            return floorNode;
    }
    else if(iRoot->_data < iVal)
    {
        BST* floorNode = GetFloorInBST(iRoot->_right, iVal);
        if(floorNode == nullptr)
            return iRoot;
        else
            return floorNode;
    }
    else
        return iRoot;
}

int main()
{
    const size_t size = 15;
    int arr[size] = {50,40,60,35,45,55,65,32,37,42,47,52,57,62,67};
    BST* root = nullptr;
    BuildBST(root, arr, size);
    BST* floorNode = GetFloorInBST(root, 90);
    std::cout << "The floor of the BST is " << floorNode->_data << std::endl;
}