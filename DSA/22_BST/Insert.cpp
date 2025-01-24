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

BST* Insert(BST* iRoot, int insertVal)
{
    if(iRoot == nullptr)
        return new BST(insertVal);

    if(insertVal < iRoot->_data)
        iRoot->_left = Insert(iRoot->_left, insertVal);
    else if(iRoot->_data < insertVal)
        iRoot->_right = Insert(iRoot->_right, insertVal);

    return iRoot;
}

void PrintBST(BST* iRoot)
{
    std::queue<BST*>queue;
    queue.push(iRoot);
    while (!queue.empty())
    {
        size_t size = queue.size();
        for (size_t i = 0; i < size; i++)
        {
            BST* root = queue.front(); queue.pop();
            std::cout << root->_data << " ";
            if(root->_left) queue.push(root->_left);
            if(root->_right) queue.push(root->_right);
        }
        std::cout << std::endl;
    }
}

int main()
{
    const size_t size = 15;
    int arr[size] = {50,40,60,35,45,55,65,32,37,42,47,52,57,62};

    BST* root = nullptr;
    BuildBST(root, arr, size);

    PrintBST(root);

    int insertVal = 67;
    Insert(root, insertVal);

    PrintBST(root);
}