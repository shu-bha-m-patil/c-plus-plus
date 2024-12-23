#include <iostream>
#include <queue>

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

int MaximumWidth(BST* iRoot)
{
    if(iRoot == nullptr) return 0;

    std::queue<BST *> queue;
    queue.push(iRoot);
    int res = 0;
    while (!queue.empty())
    {
        int size = queue.size();
        res = std::max(res, size);
        for (size_t i = 0; i < size; i++)
        {
            BST* root = queue.front(); queue.pop();
            if(root->_left) queue.push(root->_left);
            if(root->_right) queue.push(root->_right);
        }
    }
    return res;
}

int main()
{
    const size_t size = 10;
    int arr[size] = {4,2,6,1,3,5,7,8,9,10};
    BST* root = nullptr;
    BuildBST(root, arr, size);
    std::cout << "The maximum width of tree is " << MaximumWidth(root) << std::endl;
}