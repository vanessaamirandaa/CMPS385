//
//  main.cpp
//  Data Structures
//
//  Created by Vanessa Miranda on 4/7/25.
//

#include <iostream>
using namespace std;

// Define the node structure
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

// Function to create a new node
TreeNode* CreateNode(int value) {
    TreeNode* newNode = new TreeNode();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Insert a value into the BST
TreeNode* InsertBST(int x, TreeNode* T) {
    if (T == nullptr) {
        return CreateNode(x);
    }

    if (x < T->data) {
        T->left = InsertBST(x, T->left);
    } else if (x > T->data) {
        T->right = InsertBST(x, T->right);
    }
    // Duplicate values are not inserted
    return T;
}

// Helper function to find the minimum value node in a subtree
TreeNode* FindMin(TreeNode* node) {
    while (node && node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Delete a value from the BST
TreeNode* DeleteBST(int x, TreeNode* T) {
    if (T == nullptr) return T;

    if (x < T->data) {
        T->left = DeleteBST(x, T->left);
    } else if (x > T->data) {
        T->right = DeleteBST(x, T->right);
    } else {
        // Node with one child or no child
        if (T->left == nullptr) {
            TreeNode* temp = T->right;
            delete T;
            return temp;
        } else if (T->right == nullptr) {
            TreeNode* temp = T->left;
            delete T;
            return temp;
        }

        // Node with two children: get the inorder successor (smallest in the right subtree)
        TreeNode* temp = FindMin(T->right);
        T->data = temp->data;
        T->right = DeleteBST(temp->data, T->right);
    }
    return T;
}

// In-order traversal for debugging
void InOrder(TreeNode* root) {
    if (root != nullptr) {
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }
}

// Main function to test the BST
int main() {
    TreeNode* T = nullptr;

    T = InsertBST(50, T);
    T = InsertBST(30, T);
    T = InsertBST(70, T);
    T = InsertBST(20, T);
    T = InsertBST(40, T);
    T = InsertBST(60, T);
    T = InsertBST(80, T);

    cout << "Inorder traversal before deletion:\n";
    InOrder(T);
    cout << endl;

    T = DeleteBST(50, T);

    cout << "Inorder traversal after deleting 50:\n";
    InOrder(T);
    cout << endl;

    return 0;
}
