#include <iostream>
#include <stack>

#include "BST.h"

BST::BST() : m_root(nullptr) {}

BST::~BST() {
	Clear(m_root);
}

void BST::Add(int value) {
	// Prepare new node
	Node* newNode = new Node(value);

	// If tree is empty, treat new node as root node
	if (m_root == nullptr) {
		m_root = newNode;
		return;
	}

	// Locate the correct parent
	Node* current = m_root;
	Node* parent = nullptr;

	while (current != nullptr) {
		parent = current;
		if (value < current->data) {
			current = current->left;
		}
		else if (value > current->data) {
			current = current->right;
		}
		else {
			return; // Value already exists, no duplicates
		}
	}

	// Attach node to the located parent
	if (value < parent->data) {
		parent->left = newNode;
	}
	else {
		parent->right = newNode;
	}
}

void BST::Delete(int value) {
	m_root = DeleteNode(m_root, value);
}

Node* BST::DeleteNode(Node* root, int value) {
	Node* parent = nullptr;
	Node* current = root;

	// Locate the node that contains the value
	while (current != nullptr && current->data != value) {
		parent = current;
		if (value < current->data) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}

	// Value not found
	if (current == nullptr) {
		return root; // Value not found
	}

	// Case 1: Node has no children (leaf node)
	if (current->left == nullptr && current->right == nullptr) {
		if (current == root) {
			delete current;
			return nullptr;
		}
		if (parent->left == current) {
			parent->left = nullptr;
		}
		else {
			parent->right = nullptr;
		}
		delete current;
	}
	// Case 2: Node has one child
	else if (current->left == nullptr || current->right == nullptr) {
		Node* child = (current->left != nullptr) ? current->left : current->right;
		if (current == root) {
			delete current;
			return child;
		}
		if (parent->left == current) {
			parent->left = child;
		}
		else {
			parent->right = child;
		}
		delete current;
	}
	// Case 3: Node has two children
	else {
		Node* minNode = FindMin(current->right);
		current->data = minNode->data;
		current->right = DeleteNode(current->right, minNode->data);
	}

	return root;
}

bool BST::Search(int value) {
	Node* current = m_root;
	while (current != nullptr) {
		if (value == current->data) {
			return true;
		}
		else if (value < current->data) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}
	return false;
}

int BST::FindSmallest() {
	Node* minNode = FindMin(m_root);
	return minNode ? minNode->data : -1;
}

Node* BST::FindMin(Node* root) {
	while (root && root->left) {
		root = root->left;
	}
	return root;
}

int BST::FindLargest() {
	Node* maxNode = FindMax(m_root);
	return maxNode ? maxNode->data : -1;
}

Node* BST::FindMax(Node* root) {
	while (root && root->right) {
		root = root->right;
	}
	return root;
}

void BST::PreorderTraversal() {
	Preorder(m_root);
	std::cout << std::endl;
}

void BST::Preorder(Node* root) {
	if (root == nullptr) {
		return;
	}
	std::cout << root->data << " ";
	Preorder(root->left);
	Preorder(root->right);
}

void BST::InorderTraversal() {
	Inorder(m_root);
	std::cout << std::endl;
}

void BST::Inorder(Node* root) {
	if (root == nullptr) {
		return;
	}
	Inorder(root->left);
	std::cout << root->data << " ";
	Inorder(root->right);
}

void BST::PostorderTraversal() {
	Postorder(m_root);
	std::cout << std::endl;
}

void BST::Postorder(Node* root) {
	if (root == nullptr) {
		return;
	}
	Postorder(root->left);
	Postorder(root->right);
	std::cout << root->data << " ";
}

void BST::Clear(Node* root) {
	if (root == nullptr) {
		return;
	}

	// Recursively clear the left and right subtrees
	Clear(root->left);
	Clear(root->right);

	// Delete the current node after its children are cleared
	delete root;
}