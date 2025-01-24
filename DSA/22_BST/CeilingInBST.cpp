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

void GetCeilingInBST(BST* iRoot, int iVal, BST*& oCellingNode)
{
    if(iRoot == nullptr) return;

    if(iVal < iRoot->_data)
    {
        oCellingNode = iRoot;
        GetCeilingInBST(iRoot->_left, iVal, oCellingNode);
    }
    else if(iRoot->_data < iVal)
        GetCeilingInBST(iRoot->_right, iVal, oCellingNode);
    else
        oCellingNode = iRoot;
}

int main()
{
    const size_t size = 15;
    int arr[size] = {50,40,60,35,45,55,65,32,37,42,47,52,57,62,67};
    BST* root = nullptr;
    BuildBST(root, arr, size);
    BST* CellingNode = nullptr;
    GetCeilingInBST(root, 36, CellingNode);
    if (CellingNode)
        std::cout << "The floor of the BST is " << CellingNode->_data << std::endl;
    else
        std::cout << "The given value is out of range" << std::endl;
}