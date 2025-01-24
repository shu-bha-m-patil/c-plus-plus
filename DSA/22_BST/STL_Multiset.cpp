#include <iostream>
#include <functional>
#include <queue>

// Enum to represent node colors
enum Color { RED, BLACK };

// Node structure for Red-Black Tree
template <typename T>
struct Node {
    T data;          // The value stored in the node
    Node* parent;    // Pointer to the parent node
    Node* left;      // Pointer to the left child
    Node* right;     // Pointer to the right child
    Color color;     // RED or BLACK

    Node(T value) : data(value), parent(nullptr), left(nullptr), right(nullptr), color(RED) {}
};

// Simplified Red-Black Tree for multiset
template <typename T, typename Compare = std::less<T>>
class Multiset {
private:
    Node<T>* root;
    Compare comp;

    // Helper function to fix violations after insertion
    void fixInsertion(Node<T>*& node) {
        while (node->parent && node->parent->color == RED) {
            Node<T>* grandparent = node->parent->parent;
            if (node->parent == grandparent->left) {
                Node<T>* uncle = grandparent->right;
                if (uncle && uncle->color == RED) {
                    // Case 1: Uncle is red
                    grandparent->color = RED;
                    node->parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandparent;
                } else {
                    // Case 2 and 3: Uncle is black
                    if (node == node->parent->right) {
                        node = node->parent;
                        rotateLeft(node);
                    }
                    node->parent->color = BLACK;
                    grandparent->color = RED;
                    rotateRight(grandparent);
                }
            } else {
                Node<T>* uncle = grandparent->left;
                if (uncle && uncle->color == RED) {
                    // Case 1: Uncle is red
                    grandparent->color = RED;
                    node->parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandparent;
                } else {
                    // Case 2 and 3: Uncle is black
                    if (node == node->parent->left) {
                        node = node->parent;
                        rotateRight(node);
                    }
                    node->parent->color = BLACK;
                    grandparent->color = RED;
                    rotateLeft(grandparent);
                }
            }
        }
        root->color = BLACK;
    }

    // Helper function to rotate a subtree to the left
    void rotateLeft(Node<T>*& node) {
        Node<T>* rightChild = node->right;
        node->right = rightChild->left;
        if (rightChild->left) {
            rightChild->left->parent = node;
        }
        rightChild->parent = node->parent;
        if (!node->parent) {
            root = rightChild;
        } else if (node == node->parent->left) {
            node->parent->left = rightChild;
        } else {
            node->parent->right = rightChild;
        }
        rightChild->left = node;
        node->parent = rightChild;
    }

    // Helper function to rotate a subtree to the right
    void rotateRight(Node<T>*& node) {
        Node<T>* leftChild = node->left;
        node->left = leftChild->right;
        if (leftChild->right) {
            leftChild->right->parent = node;
        }
        leftChild->parent = node->parent;
        if (!node->parent) {
            root = leftChild;
        } else if (node == node->parent->right) {
            node->parent->right = leftChild;
        } else {
            node->parent->left = leftChild;
        }
        leftChild->right = node;
        node->parent = leftChild;
    }

    // Helper function to perform an in-order traversal
    void inOrder(Node<T>* node) const {
        if (node) {
            inOrder(node->left);
            std::cout << node->data << " ";
            inOrder(node->right);
        }
    }

public:
    Multiset() : root(nullptr) {}

    // Insert a value into the multiset
    void insert(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!root) {
            root = newNode;
            root->color = BLACK;
            return;
        }

        Node<T>* current = root;
        Node<T>* parent = nullptr;

        while (current) {
            parent = current;
            if (comp(value, current->data)) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        newNode->parent = parent;
        if (comp(value, parent->data)) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }

        fixInsertion(newNode);
    }

    // Print the multiset in sorted order
    void print() const {
        inOrder(root);
        std::cout << std::endl;
    }
};

int main() {
    Multiset<int> ms;
    ms.insert(10);
    ms.insert(20);
    ms.insert(10);
    ms.insert(15);
    ms.insert(10);
    ms.insert(10);

    std::cout << "Multiset elements in sorted order: ";
    ms.print(); // Output: 10 10 15 20

    return 0;
}
