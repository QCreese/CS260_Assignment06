#include <iostream>
#include <queue>
using namespace std;

// TreeNode struct representing a node in the binary search tree
struct TreeNode {
    int val;            // Value stored in the node
    TreeNode* left;     // Pointer to the left child node
    TreeNode* right;    // Pointer to the right child node

    // Constructor to initialize a TreeNode with a given value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// BinarySearchTree class representing a binary search tree
class BinarySearchTree {
public:
    // Constructor to initialize an empty binary search tree
    BinarySearchTree() : root(nullptr) {}

    // Function to add a value to the binary search tree
    void add(int val) {
        root = addNode(root, val);
    }

    // Function to remove a value from the binary search tree
    void remove(int val) {
        root = removeNode(root, val);
    }

    // Function to perform pre-order traversal of the binary search tree
    void preOrderTraversal() {
        preOrder(root);
    }

    // Function to perform in-order traversal of the binary search tree
    void inOrderTraversal() {
        inOrder(root);
    }

    // Function to perform post-order traversal of the binary search tree
    void postOrderTraversal() {
        postOrder(root);
    }

    // Function to perform breadth-first traversal of the binary search tree
    void breadthFirstTraversal() {
        if (root == nullptr) return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            cout << current->val << " ";

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
    }

private:
    TreeNode* root; // Pointer to the root node of the binary search tree

    // Helper function to recursively add a value to the binary search tree
    TreeNode* addNode(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }

        if (val <= node->val) {
            node->left = addNode(node->left, val);
        } else {
            node->right = addNode(node->right, val);
        }

        return node;
    }

    // Helper function to find the minimum node in the binary search tree
    TreeNode* findMinNode(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Helper function to recursively remove a value from the binary search tree
    TreeNode* removeNode(TreeNode* node, int val) {
        if (node == nullptr) {
            return nullptr;
        }

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

    // Helper function to perform pre-order traversal recursively
    void preOrder(TreeNode* node) {
        if (node == nullptr) return;
        cout << node->val << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    // Helper function to perform in-order traversal recursively
    void inOrder(TreeNode* node) {
        if (node == nullptr) return;
        inOrder(node->left);
        cout << node->val << " ";
        inOrder(node->right);
    }

    // Helper function to perform post-order traversal recursively
    void postOrder(TreeNode* node) {
        if (node == nullptr) return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->val << " ";
    }
};

// Main function to test the BinarySearchTree class
int main() {
    BinarySearchTree bst;
    bst.add(50);
    bst.add(30);
    bst.add(20);
    bst.add(40);
    bst.add(70);
    bst.add(60);
    bst.add(80);

    cout << "In-order traversal: ";
    bst.inOrderTraversal();
    cout << endl;

    cout << "Pre-order traversal: ";
    bst.preOrderTraversal();
    cout << endl;

    cout << "Post-order traversal: ";
    bst.postOrderTraversal();
    cout << endl;

    cout << "Breadth-first traversal: ";
    bst.breadthFirstTraversal();
    cout << endl;

    bst.remove(20);
    bst.remove(30);

    cout << "In-order traversal after removal: ";
    bst.inOrderTraversal();
    cout << endl;

    return 0;
}
