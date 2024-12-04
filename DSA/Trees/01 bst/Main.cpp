#include <iostream>

#include "BST.h"

int main() {
    BST tree;

    tree.Add(10);
    tree.Add(5);
    tree.Add(15);
    tree.Add(10);
    tree.Add(3);
    tree.Add(7);

    std::cout << "Inorder traversal: ";
    tree.InorderTraversal();  // Output: 3 5 7 10 15

    std::cout << "Smallest: " << tree.FindSmallest() << std::endl;  // Output: 3
    std::cout << "Largest: " << tree.FindLargest() << std::endl;    // Output: 15

    std::cout << "Search for 7: " << (tree.Search(7) ? "Found" : "Not Found") << std::endl;  // Output: Found
    tree.Delete(7);

    std::cout << "Inorder traversal after deletion: ";
    tree.InorderTraversal();  // Output: 3 5 10 15

    return 0;
}