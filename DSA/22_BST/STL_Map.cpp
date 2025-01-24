#include <iostream>
#include <memory>

enum Color { RED, BLACK };

// Node structure for Red-Black Tree
template <typename K, typename V>
struct Node {
    K key;
    V value;
    Color color;
    std::shared_ptr<Node> left, right, parent;

    Node(K k, V v) : key(k), value(v), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

template <typename K, typename V>
class RedBlackTreeMap {
private:
    std::shared_ptr<Node<K, V>> root;

    // Left rotate
    void leftRotate(std::shared_ptr<Node<K, V>> x) {
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

    // Right rotate
    void rightRotate(std::shared_ptr<Node<K, V>> x) {
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
    void fixInsertion(std::shared_ptr<Node<K, V>> z) {
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

    // In-order traversal for printing
    void inorderTraversal(std::shared_ptr<Node<K, V>> node) const {
        if (node == nullptr) return;

        inorderTraversal(node->left);
        std::cout << node->key << ": " << node->value << " ";
        inorderTraversal(node->right);
    }

public:
    RedBlackTreeMap() : root(nullptr) {}

    // Insert key-value pair
    void insert(K key, V value) {
        auto z = std::make_shared<Node<K, V>>(key, value);
        auto y = std::shared_ptr<Node<K, V>>(nullptr);
        auto x = root;

        // Perform BST insertion
        while (x != nullptr) {
            y = x;
            if (z->key < x->key) {
                x = x->left;
            } else if (z->key > x->key) {
                x = x->right;
            } else {
                // Key already exists, update the value
                x->value = value;
                return;
            }
        }

        z->parent = y;
        if (y == nullptr) {
            root = z; // Tree was empty
        } else if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }

        // Fix Red-Black Tree violations
        fixInsertion(z);
    }

    // Find a value by key
    V find(K key) const {
        auto x = root;
        while (x != nullptr) {
            if (key < x->key) {
                x = x->left;
            } else if (key > x->key) {
                x = x->right;
            } else {
                return x->value;
            }
        }
        throw std::out_of_range("Key not found");
    }

    // Print the tree (in-order)
    void print() const {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    RedBlackTreeMap<int, std::string> myMap;

    myMap.insert(10, "Ten");
    myMap.insert(20, "Twenty");
    myMap.insert(15, "Fifteen");
    myMap.insert(5, "Five");

    std::cout << "Map contents (in-order traversal): ";
    myMap.print();

    std::cout << "Value for key 15: " << myMap.find(15) << std::endl;

    return 0;
}
