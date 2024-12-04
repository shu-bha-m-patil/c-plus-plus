#pragma once

// Node structure to represent each element in the tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST();
    ~BST();
public:
    void Add(int value);
    void Delete(int value);
public:
    bool Search(int value);
    int FindSmallest();
    int FindLargest();
public:
    void PreorderTraversal();
    void InorderTraversal();
    void PostorderTraversal();
private:
    Node* DeleteNode(Node* root, int value);
    Node* FindMin(Node* root);
    Node* FindMax(Node* root);
    void Preorder(Node* root);
    void Inorder(Node* root);
    void Postorder(Node* root);
    void Clear(Node* root);
private:
    Node* m_root;
};