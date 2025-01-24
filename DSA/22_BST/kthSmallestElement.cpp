#include <iostream>

struct BST
{
    int _data;
    BST* _left;
    BST* _right;
    int _lCount;

    BST(int iData) : _data(iData), _left(nullptr), _right(nullptr), _lCount(0) {}
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

int count = 0;
BST* FindKthSmallestElement(BST* iRoot, int kthSmallElement)
{
    if(iRoot == nullptr) return nullptr;
    BST* kthNode = nullptr;

    kthNode = FindKthSmallestElement(iRoot->_left, kthSmallElement);
    if(kthNode) return kthNode;

    count++;
    if(count == kthSmallElement) return iRoot;

    kthNode = FindKthSmallestElement(iRoot->_right, kthSmallElement);
    if(kthNode) return kthNode;

    return kthNode;
}

int main()
{
    const size_t size = 15;
    int arr[size] = {50,40,60,35,45,55,65,32,37,42,47,52,57,62,67};
    BST* root = nullptr;
    BuildBST(root, arr, size);
    int kthSmallElement = 3;
    BST* kthSmallestNode = FindKthSmallestElement(root, kthSmallElement);
    std::cout << "The " << kthSmallElement << "smallest element is " << kthSmallestNode->_data << std::endl;
}