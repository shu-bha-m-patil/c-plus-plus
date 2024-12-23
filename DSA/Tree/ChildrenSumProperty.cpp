#include <iostream>
#include <queue>

struct BST
{
    int _data;
    BST *_left;
    BST *_right;

    BST(int iData)
    {
        _data = iData;
        _left = nullptr;
        _right = nullptr;
    }
};

void LevelOrderTraversalNewLine(BST *iRoot)
{
    if (iRoot == nullptr)
        return;

    std::queue<BST *> queue;
    queue.push(iRoot);
    while (!queue.empty())
    {
        int size = queue.size();
        for (size_t i = 0; i < size; i++)
        {
            BST *curr = queue.front();
            queue.pop();
            std::cout << curr->_data << " ";

            if (curr->_left)
                queue.push(curr->_left);
            if (curr->_right)
                queue.push(curr->_right);
        }
        std::cout << std::endl;
    }
}

void BuildBST(BST *&iRoot, int *iArray, size_t iSize)
{
    int count = 0;
    std::queue<BST *> queue;
    if (iRoot == nullptr)
    {
        BST *newNode = new BST(iArray[count]);
        queue.push(newNode); count++;
        iRoot = newNode;
    }
    while (!queue.empty())
    {
        BST *root = queue.front();
        queue.pop();

        if (count < iSize)
        {
            BST *leftNode = new BST(iArray[count]);
            count++;
            root->_left = leftNode;
            queue.push(leftNode);
        }
        if (count < iSize)
        {
            BST *rightNode = new BST(iArray[count]);
            count++;
            root->_right = rightNode;
            queue.push(rightNode);
        }
    }
}

bool ChildrenSumProperty(BST *iRoot)
{
    if (iRoot == nullptr)
        return true;

    if (iRoot->_left == nullptr && iRoot->_right == nullptr)
        return true;

    return ChildrenSumProperty(iRoot->_left) 
    && ChildrenSumProperty(iRoot->_right)
    && iRoot->_data == (iRoot->_left->_data + iRoot->_right->_data);
}

int main()
{
    const size_t size = 7;
    int arr[size] = {16, 4, 12, 1, 3, 5, 7};
    BST *root = nullptr;
    BuildBST(root, arr, size);
    LevelOrderTraversalNewLine(root);
    std::cout << "The ChildrenSumProperty of BST is " << ChildrenSumProperty(root) << std::endl;
}