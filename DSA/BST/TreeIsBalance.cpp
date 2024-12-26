#include <iostream>

struct AVLTree
{
    int _data;
    AVLTree* _left;
    AVLTree* _right;
    int _height;

    AVLTree(int iData) : _data(iData), _left(nullptr), _right(nullptr), _height(1) {}
};

int GetHeight(AVLTree* iRoot){
    return iRoot ? iRoot->_height : 0;
}

int GetBalanceFactor(AVLTree* iRoot){
    return iRoot ? GetHeight(iRoot->_left) - GetHeight(iRoot->_right) : 0;
}

AVLTree* AddChild(AVLTree*& iRoot, int iData)
{
    if(iRoot == nullptr)
    {
        iRoot = new AVLTree(iData);
        return iRoot;
    }

    if(iData < iRoot->_data)
        iRoot->_left = AddChild(iRoot->_left, iData);
    else if(iRoot->_data < iData)
        iRoot->_right = AddChild(iRoot->_right, iData);

    int lh = 0; if(iRoot->_left) lh = iRoot->_left->_height;
    int rh = 0; if(iRoot->_right) rh = iRoot->_right->_height;

    iRoot->_height = std::max(lh, rh) + 1;
    return iRoot;
}

void BuildAVLTree(AVLTree*& iRoot, int* iArray, size_t iSize)
{
    for (size_t i = 0; i < iSize; i++)
    {
        AddChild(iRoot, iArray[i]);
    }
}

int main()
{
    const size_t size = 15;
    int arr[size] = {50,40,60,35,45,55,65,32,37,42,47,52,57,62,67};
    AVLTree* root = nullptr;
    BuildAVLTree(root, arr, size);
    if(-1 <= GetBalanceFactor(root) <= 1 )
        std::cout << "The tree is balance." << std::endl;
    else
        std::cout << "The tree is not balance." << std::endl;
}