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

BST* GetSuccesor(BST* iRoot)
{
    BST* succesorNode = iRoot;
    while (succesorNode && succesorNode->_left)
    {
        succesorNode = succesorNode->_left;
    }
    return succesorNode;
}

BST* DeleteNode(BST* iRoot, int iVal)
{
    if(iVal < iRoot->_data)
        iRoot->_left = DeleteNode(iRoot->_left, iVal);
    else if(iRoot->_data < iVal)
        iRoot->_right = DeleteNode(iRoot->_right, iVal);
    else
    {
        if(iRoot->_left == nullptr)
        {
            BST* rightChild = iRoot->_right;
            delete iRoot;
            return rightChild;
        }
        if(iRoot->_right == nullptr)
        {
            BST* leftChild = iRoot->_left;
            delete iRoot;
            return leftChild;
        }
        else
        {
            BST* successorNode = GetSuccesor(iRoot->_right);
            iRoot->_data = successorNode->_data;
            DeleteNode(iRoot->_right, successorNode->_data);
        }
    }
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
    int arr[size] = {50,40,60,35,45,55,65,32,37,42,47,52,57,62,67};

    BST* root = nullptr;
    BuildBST(root, arr, size);

    DeleteNode(root, 60);
    PrintBST(root);
}