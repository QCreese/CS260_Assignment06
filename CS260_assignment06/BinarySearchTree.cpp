#include "BinarySearchTree.hpp"
#include <iostream>
#include <queue>
#include <functional>

BinarySearchTree::BinarySearchTree() : root(NULL) {} // Constructor initializes root to NULL

void BinarySearchTree::add(int val) {
    root = addNode(root, val); // Add a value to the binary search tree
}

void BinarySearchTree::remove(int val) {
    root = removeNode(root, val); // Remove a value from the binary search tree
}

void BinarySearchTree::preOrder(std::function<void(TreeNode*)> callback) {
    preOrder(root, callback); // Perform pre-order traversal starting from the root
}

void BinarySearchTree::inOrder(std::function<void(TreeNode*)> callback) {
    inOrder(root, callback); // Perform in-order traversal starting from the root
}

void BinarySearchTree::postOrder(std::function<void(TreeNode*)> callback) {
    postOrder(root, callback); // Perform post-order traversal starting from the root
}

void BinarySearchTree::breadthFirst(std::function<void(TreeNode*)> callback) {
    if (root == NULL) return; // If the tree is empty, return immediately

    std::queue<TreeNode*> q;
    q.push(root);

    // Perform breadth-first traversal using a queue
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        callback(current); // Call the callback function for the current node

        // Enqueue left and right child nodes if they exist
        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
    }
}

// Private helper functions for the binary search tree operations
TreeNode* BinarySearchTree::addNode(TreeNode* node, int val) {
    if (node == nullptr) {
        return new TreeNode(val);
    }

    // Recursively insert the value based on the binary search tree property
    if (val <= node->val) {
        node->left = addNode(node->left, val);
    } else {
        node->right = addNode(node->right, val);
    }

    return node;
}

TreeNode* BinarySearchTree::findMinNode(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

TreeNode* BinarySearchTree::removeNode(TreeNode* node, int val) {
    if (node == nullptr) {
        return nullptr;
    }

    // Recursively remove the value from the binary search tree
    if (val < node->val) {
        node->left = removeNode(node->left, val);
    } else if (val > node->val) {
        node->right = removeNode(node->right, val);
    } else {
        if (node->left == nullptr) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }

        TreeNode* temp = findMinNode(node->right);
        node->val = temp->val;
        node->right = removeNode(node->right, temp->val);
    }
    return node;
}

// Traversal functions using recursion
void BinarySearchTree::preOrder(TreeNode* node, std::function<void(TreeNode*)> callback) {
    if (node == nullptr) return;
    callback(node); // Process the current node
    preOrder(node->left, callback); // Traverse left subtree
    preOrder(node->right, callback); // Traverse right subtree
}

void BinarySearchTree::inOrder(TreeNode* node, std::function<void(TreeNode*)> callback) {
    if (node == nullptr) return;
    inOrder(node->left, callback); // Traverse left subtree
    callback(node); // Process the current node
    inOrder(node->right, callback); // Traverse right subtree
}

void BinarySearchTree::postOrder(TreeNode* node, std::function<void(TreeNode*)> callback) {
    if (node == nullptr) return;
    postOrder(node->left, callback); // Traverse left subtree
    postOrder(node->right, callback); // Traverse right subtree
    callback(node); // Process the current node
}