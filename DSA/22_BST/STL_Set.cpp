#include <iostream>
#include <memory>
#include <set>


enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    std::shared_ptr<Node> left, right, parent;

    Node(int val)
        : data(val), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTreeSet {
private:
    std::shared_ptr<Node> root;

    // Left Rotate
    void leftRotate(std::shared_ptr<Node> x) {
        auto y = x->right;
        x->right = y->left;

        if (y->left != nullptr) {
            y->left->parent = x;
        }

        y->parent = x->parent;

        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }

        y->left = x;
        x->parent = y;
    }

    // Right Rotate
    void rightRotate(std::shared_ptr<Node> x) {
        auto y = x->left;
        x->left = y->right;

        if (y->right != nullptr) {
            y->right->parent = x;
        }

        y->parent = x->parent;

        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }

        y->right = x;
        x->parent = y;
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

public:
    RedBlackTreeSet() : root(nullptr) {}

    void insert(int data) {
        auto z = std::make_shared<Node>(data);
        auto y = std::shared_ptr<Node>(nullptr);
        auto x = root;

        // Perform BST insertion
        while (x != nullptr) {
            y = x;
            if (z->data < x->data) {
                x = x->left;
            } else if (z->data > x->data) {
                x = x->right;
            } else {
                // Duplicate values are ignored
                return;
            }
        }

        z->parent = y;
        if (y == nullptr) {
            root = z; // Tree was empty
        } else if (z->data < y->data) {
            y->left = z;
        } else {
            y->right = z;
        }

        // Fix Red-Black Tree violations
        fixInsertion(z);
    }

    void inorderTraversal(std::shared_ptr<Node> node) const {
        if (node == nullptr) return;

        inorderTraversal(node->left);
        std::cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void print() const {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    RedBlackTreeSet mySet;
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(15);
    mySet.insert(5);
    mySet.insert(1);

    std::cout << "Inorder Traversal of Red-Black Tree: ";
    mySet.print();

    std::set<int>set;
    set.begin();

    return 0;
}
