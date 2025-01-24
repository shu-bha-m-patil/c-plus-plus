#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}

    Node *sibling()
    {
        // If the node or its parent is null, no sibling exists
        if (this == nullptr || this->parent == nullptr)
        {
            return nullptr;
        }

        // Determine sibling based on the node's position (left or right)
        if (this == this->parent->left)
        {
            return this->parent->right;
        }
        else
        {
            return this->parent->left;
        }
    }
};

void rotateLeft(Node*& root, Node*& node) {
    Node* nodeRight = node->right;

    node->right = nodeRight->left;
    if (node->right != nullptr)
        node->right->parent = node;

    nodeRight->parent = node->parent;
    if (node->parent == nullptr)
        root = nodeRight;
    else if (node == node->parent->left)
        node->parent->left = nodeRight;
    else
        node->parent->right = nodeRight;

    nodeRight->left = node;
    node->parent = nodeRight;
}

void rotateRight(Node*& root, Node*& node) {
    Node* nodeLeft = node->left;

    node->left = nodeLeft->right;
    if (node->left != nullptr)
        node->left->parent = node;

    nodeLeft->parent = node->parent;
    if (node->parent == nullptr)
        root = nodeLeft;
    else if (node == node->parent->left)
        node->parent->left = nodeLeft;
    else
        node->parent->right = nodeLeft;

    nodeLeft->right = node;
    node->parent = nodeLeft;
}

void fixDoubleBlack(Node*& root, Node* node) {
    if (node == root) return;

    Node* sibling = (node == node->parent->left) ? node->parent->right : node->parent->left;
    Node* parent = node->parent;

    if (sibling == nullptr) {
        // No sibling case
        fixDoubleBlack(root, parent);
    } else if (sibling->color == RED) {
        // Sibling is red
        parent->color = RED;
        sibling->color = BLACK;
        if (sibling == parent->left)
            rotateRight(root, parent);
        else
            rotateLeft(root, parent);
        fixDoubleBlack(root, node);
    } else {
        // Sibling is black
        if ((sibling->left && sibling->left->color == RED) || 
            (sibling->right && sibling->right->color == RED)) {
            // At least one red child
            if (sibling->left && sibling->left->color == RED) {
                if (sibling == parent->left) {
                    sibling->left->color = sibling->color;
                    sibling->color = parent->color;
                    rotateRight(root, parent);
                } else {
                    sibling->left->color = parent->color;
                    rotateRight(root, sibling);
                    rotateLeft(root, parent);
                }
            } else {
                if (sibling == parent->left) {
                    sibling->right->color = parent->color;
                    rotateLeft(root, sibling);
                    rotateRight(root, parent);
                } else {
                    sibling->right->color = sibling->color;
                    sibling->color = parent->color;
                    rotateLeft(root, parent);
                }
            }
            parent->color = BLACK;
        } else {
            // Both children black
            sibling->color = RED;
            if (parent->color == BLACK)
                fixDoubleBlack(root, parent);
            else
                parent->color = BLACK;
        }
    }
}

Node* replaceNode(Node* node) {
    if (node->left && node->right) {
        Node* temp = node->right;
        while (temp->left)
            temp = temp->left;
        return temp;
    }
    return (node->left) ? node->left : node->right;
}

void deleteNode(Node*& root, Node* node) {
    Node* replacement = replaceNode(node);

    bool doubleBlack = ((replacement == nullptr || replacement->color == BLACK) && node->color == BLACK);
    Node* parent = node->parent;

    if (replacement == nullptr) {
        // No replacement
        if (node == root) {
            root = nullptr;
        } else {
            if (doubleBlack)
                fixDoubleBlack(root, node);
            else if (node->sibling())
                node->sibling()->color = RED;

            if (node == parent->left)
                parent->left = nullptr;
            else
                parent->right = nullptr;
        }
        delete node;
        return;
    }

    if (node->left == nullptr || node->right == nullptr) {
        // Single child
        if (node == root) {
            node->data = replacement->data;
            node->left = node->right = nullptr;
            delete replacement;
        } else {
            if (node == parent->left)
                parent->left = replacement;
            else
                parent->right = replacement;

            delete node;
            replacement->parent = parent;
            if (doubleBlack)
                fixDoubleBlack(root, replacement);
            else
                replacement->color = BLACK;
        }
        return;
    }

    // Node with two children
    swap(node->data, replacement->data);
    deleteNode(root, replacement);
}

Node* findNode(Node* root, int value) {
    Node* current = root;

    while (current != nullptr) {
        if (value < current->data) {
            current = current->left;
        } else if (value > current->data) {
            current = current->right;
        } else {
            return current; // Node found
        }
    }

    return nullptr; // Node not found
}


int main() {
    Node* root = nullptr;
    

    // Insert nodes here (implementation not included)
    // Delete a node
    int valueToDelete = 40; // Example value
    Node* nodeToDelete = findNode(root, valueToDelete); // Implementation of findNode not included
    if (nodeToDelete) {
        deleteNode(root, nodeToDelete);
    }

    return 0;
}
