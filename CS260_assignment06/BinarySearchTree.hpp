#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include "TreeNode.hpp" // Include necessary header file for TreeNode definition
#include <functional>   // Include necessary header file for std::function

class BinarySearchTree {
private:
    TreeNode* root; // Pointer to the root of the binary search tree

    // Private helper functions for the binary search tree operations
    TreeNode* addNode(TreeNode* node, int val);
    TreeNode* findMinNode(TreeNode* node);
    TreeNode* removeNode(TreeNode* node, int val);
    void preOrder(TreeNode* node, std::function<void(TreeNode*)> callback);
    void inOrder(TreeNode* node, std::function<void(TreeNode*)> callback);
    void postOrder(TreeNode* node, std::function<void(TreeNode*)> callback);

public:
    // Public member functions of the BinarySearchTree class
    BinarySearchTree(); // Constructor
    void add(int val);  // Function to add a value to the binary search tree
    void remove(int val); // Function to remove a value from the binary search tree
    void preOrder(std::function<void(TreeNode*)> callback);  // Pre-order traversal
    void inOrder(std::function<void(TreeNode*)> callback);   // In-order traversal
    void postOrder(std::function<void(TreeNode*)> callback); // Post-order traversal
    void breadthFirst(std::function<void(TreeNode*)> callback); // Breadth-first traversal
};

#endif // BINARY_SEARCH_TREE_HPP

