#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
// Function to get the maximum of two integers
int getMax(int a, int b) {
    return (a > b) ? a : b;
}

// Function to get the height of a binary tree
int getHeight(Node* root) {
    // If the tree is empty, height is 0
    if (root == nullptr) {
        return 0;
    }
    
    // Recursively calculate the height of the left and right subtrees
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    // Return 1 plus the maximum of the left and right subtree heights
    return 1 + getMax(leftHeight, rightHeight); // Use getMax to get the maximum value
}

bool equalPaths(Node* root) {
    // If the tree is empty, all paths are equal (trivially true)
    if (root == nullptr) {
        return true;
    }

    // Check if both left and right children exist
    if (root->left && root->right) {
        // Check if the heights of the left and right subtrees are equal
        if (getHeight(root->left) != getHeight(root->right)) {
            return false;
        }
    }

    // Recursively check equality of paths in left and right subtrees
    return equalPaths(root->left) && equalPaths(root->right);
}
