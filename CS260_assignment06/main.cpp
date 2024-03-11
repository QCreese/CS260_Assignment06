#include "BinarySearchTree.hpp"
#include <iostream>

// Test function to perform in-order traversal and print values
void testInOrderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    testInOrderTraversal(node->left);
    std::cout << node->val << " ";
    testInOrderTraversal(node->right);
}

// Test function to perform pre-order traversal and print values
void testPreOrderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    std::cout << node->val << " ";
    testPreOrderTraversal(node->left);
    testPreOrderTraversal(node->right);
}

// Test function to perform post-order traversal and print values
void testPostOrderTraversal(TreeNode* node) {
    if (node == nullptr) return;
    testPostOrderTraversal(node->left);
    testPostOrderTraversal(node->right);
    std::cout << node->val << " ";
}

int main() {
    BinarySearchTree bst;
    bst.add(50);
    bst.add(30);
    bst.add(20);
    bst.add(40);
    bst.add(70);
    bst.add(60);
    bst.add(80);

    std::cout << "In-order traversal: ";
    bst.inOrder(testInOrderTraversal);
    std::cout << std::endl;

    std::cout << "Pre-order traversal: ";
    bst.preOrder(testPreOrderTraversal);
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    bst.postOrder(testPostOrderTraversal);
    std::cout << std::endl;

    std::cout << "Breadth-first traversal: ";
    bst.breadthFirst([](TreeNode* node) { std::cout << node->val << " "; });
    std::cout << std::endl;

    bst.remove(20);
    bst.remove(30);

    std::cout << "In-order traversal after removal: ";
    bst.inOrder(testInOrderTraversal);
    std::cout << std::endl;

    return 0;
}