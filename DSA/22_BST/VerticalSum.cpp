#include <iostream>
#include <map>

struct BST
{
    int _data;
    BST* _left;
    BST* _right;

    BST(int iData) : _data(iData), _left(nullptr), _right(nullptr) {}
};

BST* AddChild(BST*& iRoot, int iData)
{
    if(iRoot == nullptr)
    {
        iRoot = new BST(iData);
        return iRoot;
    }

    if(iData < iRoot->_data)
        iRoot->_left = AddChild(iRoot->_left, iData);
    else if(iRoot->_data < iData)
        iRoot->_right = AddChild(iRoot->_right, iData);
    return iRoot;
}

void BuildBST(BST*& iRoot, int* iArray, size_t iSize)
{
    for (size_t i = 0; i < iSize; i++)
        AddChild(iRoot, iArray[i]);
}

void VerticalDist(BST* iRoot, int iHD, std::map<int, int> &map)
{
    if(iRoot == nullptr) return;

    VerticalDist(iRoot->_left, iHD - 1, map);
    map[iHD] += iRoot->_data;
    VerticalDist(iRoot->_right, iHD + 1, map);
}

int main()
{
    const size_t size = 8;
    int arr[size] = {10,8,4,9,20,11,30,25};
    BST* root = nullptr;
    BuildBST(root, arr, size);

    std::map<int, int> map;
    int hd = 0;
    VerticalDist(root, hd, map);

    for (auto hd : map)
        std::cout << hd.second << " ";
    
    std::cout << std::endl;
}