#include <iostream>
#include <stack>
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

void PrintTreeInSpiralForm(BST* iRoot)
{
    std::queue<BST*> queue;
    std::stack<BST*> stack;
    queue.push(iRoot);
    bool reverse = true;
    while (!queue.empty())
    {
        size_t size = queue.size();
        for (size_t i = 0; i < size; i++)
        {
            BST *root = queue.front(); queue.pop();
            if (reverse)
            {
                std::cout << root->_data << " ";
                if (root->_left) stack.push(root->_left);
                if (root->_right) stack.push(root->_right);
            }
            if (root->_left) queue.push(root->_left);
            if (root->_right) queue.push(root->_right);
        }
        std::cout << std::endl;
        size_t sizep = stack.size();
        for (size_t i = 0; i < sizep; i++)
        {
            BST *root = stack.top();
            stack.pop();
            std::cout << root->_data << " ";
        }
        reverse = !reverse;
    }
}

int main()
{
    const size_t size = 7;
    int arr[size] = {4,2,6,1,3,5,7};
    BST* root = nullptr;
    BuildBST(root, arr, size);
    PrintTreeInSpiralForm(root);
}