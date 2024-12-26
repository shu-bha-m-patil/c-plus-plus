#include <iostream>

struct BST
{
    int _data;
    BST* _left;
    BST* _right;

    BST(int iData) : _data(iData), _left(nullptr), _right(nullptr) {}
};

BST* AddChild(BST*& iRoot, int iData)
{
    if(iRoot == nullptr)
    {
        iRoot = new BST(iData);
        return iRoot;
    }

    if(iData < iRoot->_data)
        iRoot->_left = AddChild(iRoot->_left, iData);
    else if(iRoot->_data < iData)
        iRoot->_right = AddChild(iRoot->_right, iData);
    return iRoot;
}

void BuildBST(BST*& iRoot, int* iArray, size_t iSize)
{
    for (size_t i = 0; i < iSize; i++)
        AddChild(iRoot, iArray[i]);
}

// bool CheckBST(BST* iRoot)
// {
//     bool isBST = true;
//     if(iRoot->_left)
//     {
//         if(iRoot->_left->_data < iRoot->_data)
//         {
//             isBST = CheckBST(iRoot->_left);
//             if(!isBST) 
//                 return false;
//         }
//         else
//             return false;
//     }

//     if(iRoot->_right)
//     {
//         if(iRoot->_data < iRoot->_right->_data)
//         {
//             isBST = CheckBST(iRoot->_right);
//             if(!isBST) 
//                 return false;
//         }
//         else
//             return false;
//     }

//     return isBST;
// }

bool CheckBST(BST* iRoot, int minVal, int maxVal)
{
    if(iRoot == nullptr) return true;

    if (minVal >= iRoot->_data || iRoot->_data >= maxVal)
        return false;

    return CheckBST(iRoot->_left, minVal, iRoot->_data) && CheckBST(iRoot->_right, iRoot->_data, maxVal);
}

int main()
{
    const size_t size = 15;
    int arr[size] = {50,40,60,35,45,55,65,32,37,42,47,52,57,62,67};
    BST* root = nullptr;
    BuildBST(root, arr, size);
    if(CheckBST(root, INT_MIN, INT_MAX))
        std::cout << "The given tree is BST" << std::endl;
    else
        std::cout << "The given tree is not BST" << std::endl;
}