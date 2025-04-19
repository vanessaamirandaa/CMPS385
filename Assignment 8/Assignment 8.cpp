//
//  main.cpp
//  Data Structures
//
//  Created by Vanessa Miranda on 4/7/25.
//

#include <iostream>
using namespace std;

// Definition of a tree node
struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

// Left Rotation
TreeNode* leftRotation(TreeNode* node) {
    if (!node || !node->right) return node;

    TreeNode* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;

    return newRoot;
}

// Right Rotation
TreeNode* rightRotation(TreeNode* node) {
    if (!node || !node->left) return node;

    TreeNode* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;

    return newRoot;
}

// Helper function to print tree (in-order traversal)
void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    cout << root->key << " ";
    printInOrder(root->right);
}

// Example usage
int main() {
    // Building a small tree manually
    TreeNode* root = new TreeNode(30);
    root->right = new TreeNode(40);
    root->right->right = new TreeNode(50);

    cout << "Before Left Rotation (in-order): ";
    printInOrder(root);
    cout << endl;

    // Perform left rotation
    root = leftRotation(root);

    cout << "After Left Rotation (in-order): ";
    printInOrder(root);
    cout << endl;

    // Perform right rotation (to reverse the left rotation)
    root = rightRotation(root);

    cout << "After Right Rotation (in-order): ";
    printInOrder(root);
    cout << endl;

    return 0;
}
