#include <iostream>

struct AVLTree
{
    int _data;
    AVLTree* _left;
    AVLTree* _right;
    int _height;

    AVLTree(int iData) : _data(iData), _left(nullptr), _right(nullptr), _height(1) {}
};

int Height(AVLTree* iRoot){
    return iRoot ? iRoot->_height : 0;
}

int GetBalance(AVLTree* iRoot){
    return iRoot ? Height(iRoot->_left) - Height(iRoot->_right) : 0;
}