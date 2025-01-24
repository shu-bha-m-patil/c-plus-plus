#include <iostream>
#include <vector>

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

void Serialize(BST* root , std::vector<int>& iArray)
{
    if(root == nullptr)
    {
        iArray.push_back(-1);
        return;
    }
    iArray.push_back(root->_data);
    Serialize(root->_left, iArray);
    Serialize(root->_right, iArray);
}



BST* DeSerialize(std::vector<int>& iArray)
{
    if(iArray.size() == 0) return nullptr;

    int val = iArray[0];
    if (val == -1) 
    {
        iArray.erase(iArray.begin());
        return nullptr;
    }

    BST* iRoot = new BST(val);
    iArray.erase(iArray.begin());

    iRoot->_left = DeSerialize(iArray);
    iRoot->_right = DeSerialize(iArray);
    return iRoot;
}

void PrintInorderTraversal(BST* iRoot)
{
    if(iRoot == nullptr) return;

    std::cout << iRoot->_data << " ";
    PrintInorderTraversal(iRoot->_left);
    PrintInorderTraversal(iRoot->_right);
}

void PrintVect(std::vector<int>arrVect)
{
    for (size_t i = 0; i < arrVect.size(); i++)
        std::cout << arrVect[i] << " ";    
}

int main()
{
    const size_t size = 15;
    int arr[size] = {50,40,60,35,45,55,65,32,37,42,47,52,57,62,67};

    BST* root = nullptr;
    BuildBST(root, arr, size);

    PrintInorderTraversal(root);
    std::cout << std::endl;

    std::vector<int>arrVect;
    Serialize(root, arrVect);

    PrintVect(arrVect);
    std::cout << std::endl;

    BST* root1 =  DeSerialize(arrVect);

    PrintInorderTraversal(root);
}