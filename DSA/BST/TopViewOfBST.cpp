#include <iostream>
#include <queue>
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

void PrintTopView(BST* iRoot, int iHD, std::map<int , int>& map)
{
    std::queue<std::pair<int,BST*>> queue;
    queue.push({iHD,iRoot});
    while (!queue.empty())
    {
        std::pair<int, BST*> pair = queue.front(); queue.pop();
        if(map.find(pair.first) == map.end())
            map[pair.first] = pair.second->_data;

        if(pair.second->_left) queue.push({pair.first - 1, pair.second->_left});
        if(pair.second->_right) queue.push({pair.first + 1, pair.second->_right});
    }
}

int main()
{
    const size_t size = 15;
    int arr[size] = {50,40,60,35,45,55,65,32,37,42,47,52,57,62,67};

    BST* root = nullptr;
    BuildBST(root, arr, size);

    int hd = 0;
    std::map<int , int> map;
    PrintTopView(root, hd, map);

    for (auto mapElem : map)
        std::cout << mapElem.second << " ";

    std::cout << std::endl;
}