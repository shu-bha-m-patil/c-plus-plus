#include <iostream>
#include <unordered_set>

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

bool IsSumPresent(BST* iRoot, int sum, std::unordered_set<int>& set)
{
    if(iRoot == nullptr) return false;

    if(IsSumPresent(iRoot->_left, sum, set))
        return true;

    if(set.find(sum - iRoot->_data) != set.end()) 
        return true;
    else
        set.insert(iRoot->_data);

    return IsSumPresent(iRoot->_right, sum, set); 
}

int main()
{
    const size_t size = 8;
    int arr[size] = {10,8,4,9,20,11,30,25};
    BST* root = nullptr;
    BuildBST(root, arr, size);
    int sum = 31;
    std::unordered_set<int> set;
    if(IsSumPresent(root, sum, set))
        std::cout << "THe sum is present" << std::endl;
    else
        std::cout << "THe sum is not present" << std::endl;
}