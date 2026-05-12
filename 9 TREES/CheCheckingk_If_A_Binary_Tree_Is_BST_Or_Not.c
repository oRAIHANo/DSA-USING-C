#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

/// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Helper function to check if a tree is BST within a given range
bool isBSTUtil(struct Node* node, int min, int max) {
    if (node == NULL) return true;

    // If the current node's data 
    // is not in the valid range, return false
    if (node->data < min || node->data > max) return false;

    // Recursively check the left and 
    // right subtrees with updated ranges
    return isBSTUtil(node->left, min, node->data - 1) &&
           isBSTUtil(node->right, node->data + 1, max);
}

// Function to check if the entire binary tree is a BST
bool isBST(struct Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

struct Node* createNode(int value) {
    struct Node* newNode = 
      (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
  
    // Create a sample binary tree
    //     10
    //    /  \
    //   5    20
    //        / \
    //       9   25

    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->right->left = createNode(9);
    root->right->right = createNode(25);

    if (isBST(root)) 
        printf("true");
    else 
         printf("false");
    
    return 0;
}



Note: We can avoid the use of an Auxiliary Array. While doing In-Order traversal, we can keep track of previously visited value. If the value of the currently visited node is less than the previous value, then the tree is not BST.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definition for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Recursive Function for inorder traversal
int isValidBST(struct Node* root, int* prev) {
    if (root == NULL) return 1;

    // Recursively check the left subtree
    if (!isValidBST(root->left, prev)) return 0;

    // Check the current node value
    // against the previous value
    if (*prev >= root->data) return 0;

    *prev = root->data;

    // Recursively check the right subtree
    return isValidBST(root->right, prev);
}

// Function to check if the entire binary tree is a BST
int isBST(struct Node* root) {
    int prev = INT_MIN;
    return isValidBST(root, &prev);
}

struct Node* createNode(int value) {
    struct Node* node = 
      (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
  
    // Create a sample binary tree
    //     10
    //    /  \
    //   5    20
    //        / \
    //       9   25

    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->right->left = createNode(9);
    root->right->right = createNode(25);

    if (isBST(root)) 
        printf("true");
    else 
         printf("false");
    
    return 0;
}
