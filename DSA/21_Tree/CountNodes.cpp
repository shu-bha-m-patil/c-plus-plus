#include <iostream>
#include <cmath>

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

int LeftHeight(BST *iRoot)
{
    if (iRoot == nullptr)
        return 0;

    return LeftHeight(iRoot->_left) + 1;
}

int RightHeight(BST *iRoot)
{
    if (iRoot == nullptr)
        return 0;

    return LeftHeight(iRoot->_right) + 1;
}

bool IsBalance(BST* iRoot, int& height)
{
    if(iRoot == nullptr) return true;

    int lh = LeftHeight(iRoot->_left);
    int rh = RightHeight(iRoot->_right);

    height = std::max(lh, rh) + 1;
    return lh == rh ? true : false;
}

int GetCount(BST* iRoot)
{
    if(iRoot == nullptr) return 0;

    int leftHeight = 0;
    int leftNodeCount = 0;
    if(IsBalance(iRoot->_left, leftHeight))
    {
         leftNodeCount = std::pow(2, leftHeight) - 1;
    }
    else
    {
        leftNodeCount = GetCount(iRoot->_left);
    }
    
    int rightHeight = 0;
    int rightNodeCount = 0;
    if(IsBalance(iRoot->_right, rightHeight))
    {
        rightNodeCount = std::pow(2, rightHeight) - 1;
    }
    else
    {
        rightNodeCount = GetCount(iRoot->_right);
    }

    return leftNodeCount + rightNodeCount + 1;
}

int main()
{
    const size_t size = 15;
    int arr[size] = {50,40,60,35,45,55,65,32,37,42,47,52,57,62,67};
    BST* root = nullptr;
    BuildBST(root, arr, size);
    std::cout << "The count of tree is " << GetCount(root) << std::endl;
}