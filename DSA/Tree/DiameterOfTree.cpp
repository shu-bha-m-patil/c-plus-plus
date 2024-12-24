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

int Height(BST* iRoot)
{
    if(iRoot == nullptr) return 0;
    if(iRoot->_left == nullptr && iRoot->_right == nullptr) return 1;

    return std::max(Height(iRoot->_left), Height(iRoot->_right)) + 1;
}

int DiameterOfTree(BST* iRoot)
{
    return Height(iRoot->_left) + Height(iRoot->_right) + 1; 
}

int maxDia(BST* iRoot)
{
    int leftNodeDia = 0; if(iRoot->_left) leftNodeDia = DiameterOfTree(iRoot->_left);
    int rightNodeDia = 0; if(iRoot->_right) rightNodeDia = DiameterOfTree(iRoot->_right);

    int leftNodeHeight = 0; if(iRoot->_left) leftNodeHeight = Height(iRoot->_left);
    int rightNodeHeight = 0; if(iRoot->_right) rightNodeHeight = Height(iRoot->_right);
    int rootNodeDia = leftNodeHeight + rightNodeHeight + 1;

    int childMaxDia = std::max(leftNodeDia, rightNodeDia);
    return std::max(rootNodeDia, childMaxDia);
}

int main()
{
    const size_t size = 15;
    int arr[size] = {50,40,60,35,45,55,65,32,37,42,47,52,57,62,67};

    // const size_t size = 12;
    // int arr[size] = {50,40,60,35,45,55,32,37,42,47,52,57};
    
    // const size_t size = 8;
    // int arr[size] = {50,40,35,45,32,37,42,47};
    BST* root = nullptr;
    BuildBST(root, arr, size);
    std::cout << "The max dia is " << maxDia(root) << std::endl;
}