#include <iostream>
#include <memory>

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    std::shared_ptr<Node> left, right, parent;

    // Constructor
    Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    std::shared_ptr<Node> root;

    // Left Rotate
    void leftRotate(std::shared_ptr<Node> x) {
        auto y = x->right;
        x->right = y->left;

        if (y->left != nullptr)
            y->left->parent = x;

        y->parent = x->parent;
        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    // Right Rotate
    void rightRotate(std::shared_ptr<Node> y) {
        auto x = y->left;
        y->left = x->right;

        if (x->right != nullptr)
            x->right->parent = y;

        x->parent = y->parent;
        if (y->parent == nullptr)
            root = x;
        else if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;

        x->right = y;
        y->parent = x;
    }

    // Fix violations after insertion
    void fixInsertion(std::shared_ptr<Node> z) {
        while (z->parent != nullptr && z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                auto y = z->parent->parent->right; // Uncle
                if (y != nullptr && y->color == RED) {
                    // Case 1: Uncle is red
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    // Case 2 or 3: Uncle is black
                    if (z == z->parent->right) {
                        z = z->parent;
                        leftRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            } else {
                auto y = z->parent->parent->left; // Uncle
                if (y != nullptr && y->color == RED) {
                    // Case 1: Uncle is red
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    // Case 2 or 3: Uncle is black
                    if (z == z->parent->left) {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    // In-order traversal
    void inorderTraversal(std::shared_ptr<Node> node) const {
        if (node == nullptr)
            return;

        inorderTraversal(node->left);
        std::cout << node->data << (node->color == RED ? "R " : "B ");
        inorderTraversal(node->right);
    }

public:
    RedBlackTree() : root(nullptr) {}

    // Insert a new node
    void insert(int data) {
        auto z = std::make_shared<Node>(data);
        auto y = std::shared_ptr<Node>(nullptr);
        auto x = root;

        // Perform standard BST insertion
        while (x != nullptr) {
            y = x;
            if (z->data < x->data)
                x = x->left;
            else if (z->data > x->data)
                x = x->right;
            else
                return; // No duplicates allowed
        }

        z->parent = y;
        if (y == nullptr)
            root = z; // Tree was empty
        else if (z->data < y->data)
            y->left = z;
        else
            y->right = z;

        // Fix Red-Black Tree violations
        fixInsertion(z);
    }

    // Find a node in the tree
    bool find(int data) const {
        auto current = root;
        while (current != nullptr) {
            if (data < current->data)
                current = current->left;
            else if (data > current->data)
                current = current->right;
            else
                return true; // Data found
        }
        return false; // Data not found
    }

    // Print the tree in in-order
    void print() const {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    RedBlackTree tree;

    // Insert elements
    tree.insert(10);
    tree.insert(20);
    tree.insert(15);
    tree.insert(5);
    tree.insert(1);

    // Print tree (in-order traversal)
    std::cout << "Tree elements (in-order with colors): ";
    tree.print();

    // Search for elements
    std::cout << "Is 15 in the tree? " << (tree.find(15) ? "Yes" : "No") << std::endl;
    std::cout << "Is 25 in the tree? " << (tree.find(25) ? "Yes" : "No") << std::endl;

    return 0;
}
