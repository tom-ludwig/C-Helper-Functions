#include "red-black-tree.h"
#include <stdio.h>
#include <stdlib.h>

// Create a new Red-Black Tree
RBTree *create_rb_tree() {
  RBTree *tree = (RBTree *)malloc(sizeof(RBTree));
  tree->root = NULL;
  return tree;
}

// Free the Red-Black Tree
void free_rb_tree(RBTree *tree) {
  if (tree == NULL)
    return;
  // Implement a function to free all nodes (postorder traversal)
  free(tree);
}

// Create a new Red-Black Tree node
RBTreeNode *create_rb_tree_node(int value, int color) {
  RBTreeNode *node = (RBTreeNode *)malloc(sizeof(RBTreeNode));
  node->value = value;
  node->color = color;
  node->parent = NULL;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Left rotation of a node
void left_rotate(RBTree *tree, RBTreeNode *x) {
  RBTreeNode *y = x->right;
  x->right = y->left;
  if (y->left != NULL) {
    y->left->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == NULL) {
    tree->root = y;
  } else if (x == x->parent->left) {
    x->parent->left = y;
  } else {
    x->parent->right = y;
  }
  y->left = x;
  x->parent = y;
}

// Right rotation of a node
void right_rotate(RBTree *tree, RBTreeNode *x) {
  RBTreeNode *y = x->left;
  x->left = y->right;
  if (y->right != NULL) {
    y->right->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == NULL) {
    tree->root = y;
  } else if (x == x->parent->right) {
    x->parent->right = y;
  } else {
    x->parent->left = y;
  }
  y->right = x;
  x->parent = y;
}

// Fix the Red-Black Tree properties after an insertion
void fix_rb_tree(RBTree *tree, RBTreeNode *z) {
  while (z->parent != NULL && z->parent->color == RED) {
    if (z->parent == z->parent->parent->left) {
      RBTreeNode *y = z->parent->parent->right;
      if (y != NULL && y->color == RED) {
        z->parent->color = BLACK;
        y->color = BLACK;
        z->parent->parent->color = RED;
        z = z->parent->parent;
      } else {
        if (z == z->parent->right) {
          z = z->parent;
          left_rotate(tree, z);
        }
        z->parent->color = BLACK;
        z->parent->parent->color = RED;
        right_rotate(tree, z->parent->parent);
      }
    } else {
      RBTreeNode *y = z->parent->parent->left;
      if (y != NULL && y->color == RED) {
        z->parent->color = BLACK;
        y->color = BLACK;
        z->parent->parent->color = RED;
        z = z->parent->parent;
      } else {
        if (z == z->parent->left) {
          z = z->parent;
          right_rotate(tree, z);
        }
        z->parent->color = BLACK;
        z->parent->parent->color = RED;
        left_rotate(tree, z->parent->parent);
      }
    }
  }
  tree->root->color = BLACK;
}

// Insert a new node into the Red-Black Tree
void insert_rb_tree(RBTree *tree, int value) {
  RBTreeNode *z = create_rb_tree_node(value, RED);
  RBTreeNode *y = NULL;
  RBTreeNode *x = tree->root;

  while (x != NULL) {
    y = x;
    if (z->value < x->value) {
      x = x->left;
    } else {
      x = x->right;
    }
  }

  z->parent = y;
  if (y == NULL) {
    tree->root = z;
  } else if (z->value < y->value) {
    y->left = z;
  } else {
    y->right = z;
  }

  fix_rb_tree(tree, z);
}

// Find a node with a specific value in the Red-Black Tree
RBTreeNode *find_rb_tree(RBTree *tree, int value) {
  RBTreeNode *current = tree->root;
  while (current != NULL && current->value != value) {
    if (value < current->value) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return current;
}

// In-order traversal: Left -> Root -> Right
void inorder_traversal(RBTreeNode *root) {
  if (root == NULL)
    return;
  inorder_traversal(root->left);
  printf("%d (%s) ", root->value, root->color == RED ? "RED" : "BLACK");
  inorder_traversal(root->right);
}

// Pre-order traversal: Root -> Left -> Right
void preorder_traversal(RBTreeNode *root) {
  if (root == NULL)
    return;
  printf("%d (%s) ", root->value, root->color == RED ? "RED" : "BLACK");
  preorder_traversal(root->left);
  preorder_traversal(root->right);
}

// Post-order traversal: Left -> Right -> Root
void postorder_traversal(RBTreeNode *root) {
  if (root == NULL)
    return;
  postorder_traversal(root->left);
  postorder_traversal(root->right);
  printf("%d (%s) ", root->value, root->color == RED ? "RED" : "BLACK");
}
