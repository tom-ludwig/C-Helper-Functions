/*
 * Copyright © 2024
 * Created by Tom M. Ludwig, Louis Kauer, Julian Kuecken, and Pepe Hanisch
 *
 * This project is licensed under the MIT License.
 * You may use, modify, and distribute this software under the terms of the license.
*/

#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdbool.h>

// Define colors for Red-Black Tree
#define RED 0
#define BLACK 1

// Define structure for a tree node
typedef struct RBTreeNode {
  int value;                 // Value of the node
  int color;                 // Color of the node (RED or BLACK)
  struct RBTreeNode *parent; // Parent node
  struct RBTreeNode *left;   // Left child
  struct RBTreeNode *right;  // Right child
} RBTreeNode;

// Define structure for the Red-Black Tree
typedef struct RBTree {
  RBTreeNode *root; // Root node of the tree
} RBTree;

// Function prototypes
RBTree *create_rb_tree();
void free_rb_tree(RBTree *tree);
void insert_rb_tree(RBTree *tree, int value);
void inorder_traversal(RBTreeNode *root);
void preorder_traversal(RBTreeNode *root);
void postorder_traversal(RBTreeNode *root);
RBTreeNode *find_rb_tree(RBTree *tree, int value);

// Utility functions
RBTreeNode *create_rb_tree_node(int value, int color);
void left_rotate(RBTree *tree, RBTreeNode *x);
void right_rotate(RBTree *tree, RBTreeNode *x);
void fix_rb_tree(RBTree *tree, RBTreeNode *z);
void transplant(RBTree *tree, RBTreeNode *u, RBTreeNode *v);

#endif // RED_BLACK_TREE_H
