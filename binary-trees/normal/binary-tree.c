#include "binary-tree.h"
#include <stdio.h>
#include <stdlib.h>

// Create a new binary tree
BinaryTree *create_tree() {
  BinaryTree *tree = (BinaryTree *)malloc(sizeof(BinaryTree));
  tree->root = NULL;
  tree->size = 0;
  return tree;
}

// Free the entire tree
void free_tree(BinaryTree *tree) {
  if (!tree)
    return;
  clear_tree(tree->root);
  free(tree);
}

// Clear the tree (delete all nodes)
void clear_tree(TreeNode *root) {
  if (root == NULL)
    return;
  clear_tree(root->left);
  clear_tree(root->right);
  free(root);
}

// Insert a new value into the binary tree
TreeNode *insert(BinaryTree *tree, int value) {
  TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));
  new_node->value = value;
  new_node->left = NULL;
  new_node->right = NULL;

  if (tree->root == NULL) {
    tree->root = new_node;
    tree->size++;
    return new_node;
  }

  TreeNode *current = tree->root;
  TreeNode *parent = NULL;
  while (current != NULL) {
    parent = current;
    if (value < current->value)
      current = current->left;
    else
      current = current->right;
  }

  if (value < parent->value)
    parent->left = new_node;
  else
    parent->right = new_node;

  tree->size++;
  return new_node;
}

// Find a node with a specific value in the tree
TreeNode *find(BinaryTree *tree, int value) {
  TreeNode *current = tree->root;
  while (current != NULL) {
    if (value == current->value)
      return current;
    if (value < current->value)
      current = current->left;
    else
      current = current->right;
  }
  return NULL; // Return NULL if not found
}

// In-order traversal: Left -> Root -> Right
void inorder_traversal(TreeNode *root) {
  if (root == NULL)
    return;
  inorder_traversal(root->left);
  printf("%d ", root->value);
  inorder_traversal(root->right);
}

// Pre-order traversal: Root -> Left -> Right
void preorder_traversal(TreeNode *root) {
  if (root == NULL)
    return;
  printf("%d ", root->value);
  preorder_traversal(root->left);
  preorder_traversal(root->right);
}

// Post-order traversal: Left -> Right -> Root
void postorder_traversal(TreeNode *root) {
  if (root == NULL)
    return;
  postorder_traversal(root->left);
  postorder_traversal(root->right);
  printf("%d ", root->value);
}

// Level-order traversal (Breadth-First Search)
void levelorder_traversal(BinaryTree *tree) {
  if (tree->root == NULL)
    return;

  TreeNode *queue[100]; // Simple queue (fixed size for simplicity)
  int front = 0, rear = 0;

  queue[rear++] = tree->root;

  while (front != rear) {
    TreeNode *node = queue[front++];
    printf("%d ", node->value);

    if (node->left != NULL)
      queue[rear++] = node->left;
    if (node->right != NULL)
      queue[rear++] = node->right;
  }
}

// Invert the binary tree (mirror the tree)
void invert_tree(TreeNode *root) {
  if (root == NULL)
    return;

  // Swap the left and right children
  TreeNode *temp = root->left;
  root->left = root->right;
  root->right = temp;

  // Recursively invert the left and right subtrees
  invert_tree(root->left);
  invert_tree(root->right);
}

// Get the height of the tree (maximum depth)
size_t tree_height(TreeNode *root) {
  if (root == NULL)
    return 0;

  size_t left_height = tree_height(root->left);
  size_t right_height = tree_height(root->right);

  return (left_height > right_height ? left_height : right_height) + 1;
}

// Delete a node from the tree (simple delete logic)
void delete_node(BinaryTree *tree, int value) {
  TreeNode *parent = NULL;
  TreeNode *current = tree->root;

  // Find the node and its parent
  while (current != NULL && current->value != value) {
    parent = current;
    if (value < current->value)
      current = current->left;
    else
      current = current->right;
  }

  if (current == NULL) {
    printf("Node not found.\n");
    return;
  }

  // Node with one or no children
  if (current->left == NULL) {
    if (parent == NULL) {
      tree->root = current->right;
    } else if (parent->left == current) {
      parent->left = current->right;
    } else {
      parent->right = current->right;
    }
  } else if (current->right == NULL) {
    if (parent == NULL) {
      tree->root = current->left;
    } else if (parent->left == current) {
      parent->left = current->left;
    } else {
      parent->right = current->left;
    }
  }
  free(current);
  tree->size--;
}
