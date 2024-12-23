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

void LevelOrderTraversal(BST* iRoot)
{
    if(iRoot == nullptr) return;

    std::queue<BST *> queue;
    queue.push(iRoot);
    
    while (!queue.empty())
    {
        BST *curr = queue.front(); queue.pop();

        std::cout << curr->_data << " ";

        if(curr->_left) queue.push(curr->_left);
        if(curr->_right)  queue.push(curr->_right);
    }
}

int main()
{
    const size_t size = 7;
    int arr[size] = {4,2,6,1,3,5,7};
    BST* root = nullptr;
    BuildBST(root, arr, size);
    LevelOrderTraversal(root);
}