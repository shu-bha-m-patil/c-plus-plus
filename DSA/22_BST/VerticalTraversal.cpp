#include <iostream>
#include <map>
#include <vector>

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

void VerticalTraversal(BST* iRoot, int iHD, std::map<int, std::vector<int>> &map)
{
    if(iRoot == nullptr) return;

    std::map<int, std::vector<int>>::iterator it = map.find(iHD);
    if(it == map.end())
    {
        std::vector<int> vertNodes;
        vertNodes.push_back(iRoot->_data);
        map[iHD] = vertNodes;
    }
    else
        it->second.push_back(iRoot->_data);

    VerticalTraversal(iRoot->_left, iHD - 1, map);
    VerticalTraversal(iRoot->_right, iHD + 1, map);
}

int main()
{
    const size_t size = 8;
    int arr[size] = {10,8,4,9,20,11,30,25};
    BST* root = nullptr;
    BuildBST(root, arr, size);

    std::map<int, std::vector<int>> map;
    int hd = 0;
    VerticalTraversal(root, hd, map);

    for (auto hd : map)
    {
        for (size_t i = 0; i < hd.second.size(); i++)
            std::cout << hd.second[i] << " ";
        std::cout << std::endl;
    }
}