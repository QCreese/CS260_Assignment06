#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

#include <cstddef> // Include necessary header for NULL definition

// TreeNode struct representing a node in a binary tree
struct TreeNode {
    int val;        // Value stored in the node
    TreeNode* left; // Pointer to the left child node
    TreeNode* right; // Pointer to the right child node

    // Constructor to initialize a TreeNode with a given value
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif // TREE_NODE_HPP
