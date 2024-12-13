/*
 * Copyright © 2024
 * Created by Tom M. Ludwig, Louis Kauer, Julian Kuecken, and Pepe Hanisch
 *
 * This project is licensed under the MIT License.
 * You may use, modify, and distribute this software under the terms of the license.
*/

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h>
#include <stddef.h>

// Define the structure for a tree node
typedef struct TreeNode {
  int value;              // Value of the node
  struct TreeNode *left;  // Pointer to the left child
  struct TreeNode *right; // Pointer to the right child
} TreeNode;

// Define the structure for the binary tree
typedef struct BinaryTree {
  TreeNode *root; // Root node of the tree
  size_t size;    // Number of nodes in the tree
} BinaryTree;

// Function prototypes

BinaryTree *create_tree();
void free_tree(BinaryTree *tree);

TreeNode *insert(BinaryTree *tree, int value);
TreeNode *find(BinaryTree *tree, int value);
void delete_node(BinaryTree *tree, int value);

void inorder_traversal(TreeNode *root);
void preorder_traversal(TreeNode *root);
void postorder_traversal(TreeNode *root);
void levelorder_traversal(BinaryTree *tree);

void invert_tree(TreeNode *root);
size_t tree_height(TreeNode *root);
void clear_tree(TreeNode *root);

#endif // BINARY_TREE_H
