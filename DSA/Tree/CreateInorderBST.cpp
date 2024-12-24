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

int preIndex = 0;
BST *BuildInorderBST(int *iInOrderArr, int *iPreOrderArr, size_t st, size_t end)
{
    if(st > end || end < st) return nullptr;

    BST *iRoot = new BST(iPreOrderArr[preIndex++]);

    if(st == end) return iRoot;

    int index = 0;
    for (size_t i = st; i <= end; i++)
    {
        if (iInOrderArr[i] == iRoot->_data)
        {
            index = i;
            break;
        }
    }

    iRoot->_left = BuildInorderBST(iInOrderArr, iPreOrderArr, st, index - 1);
    iRoot->_right = BuildInorderBST(iInOrderArr, iPreOrderArr, index + 1, end);
    return iRoot;
}

void PrintNewLine(BST *iRoot)
{
    std::queue<BST *> queue;
    queue.push(iRoot);
    while (!queue.empty())
    {
        size_t size = queue.size();
        for (size_t i = 0; i < size; i++)
        {
            BST *node = queue.front();
            queue.pop();
            std::cout << node->_data << " ";
            if (node->_left) queue.push(node->_left);
            if (node->_right) queue.push(node->_right);
        }
        std::cout << std::endl;
    }
}

int main()
{
    int inOrderArr[] = {40,20,50,10,30,80,70,90};
    int preOrderArr[] = {10,20,40,50,30,70,80,90};

    size_t iSize = sizeof(inOrderArr) / sizeof(int);
    size_t pSize = sizeof(preOrderArr) / sizeof(int);
    BST* InorderBST = BuildInorderBST(inOrderArr, preOrderArr,0, pSize);
    PrintNewLine(InorderBST);
}