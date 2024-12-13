/*
 * Copyright © 2024
 * Created by Tom M. Ludwig, Louis Kauer, Julian Kuecken, and Pepe Hanisch
 *
 * This project is licensed under the MIT License.
 * You may use, modify, and distribute this software under the terms of the license.
*/

#include "binary-tree.h"
#include <stdio.h>

int main() {
  BinaryTree *tree = create_tree();

  // Insert nodes
  insert(tree, 50);
  insert(tree, 30);
  insert(tree, 70);
  insert(tree, 20);
  insert(tree, 40);
  insert(tree, 60);
  insert(tree, 80);

  printf("In-order traversal: ");
  inorder_traversal(
      tree->root); // Output should be sorted: 20 30 40 50 60 70 80
  printf("\n");

  printf("Pre-order traversal: ");
  preorder_traversal(tree->root);
  printf("\n");

  printf("Post-order traversal: ");
  postorder_traversal(tree->root);
  printf("\n");

  printf("Level-order traversal: ");
  levelorder_traversal(tree);
  printf("\n");

  // Find a node
  TreeNode *found = find(tree, 40);
  if (found) {
    printf("Node with value 40 found!\n");
  } else {
    printf("Node with value 40 not found.\n");
  }

  // Invert the tree
  invert_tree(tree->root);
  printf("Inverted tree (In-order traversal): ");
  inorder_traversal(tree->root);
  printf("\n");

  // Delete a node
  delete_node(tree, 30);
  printf("After deleting node 30 (In-order traversal): ");
  inorder_traversal(tree->root);
  printf("\n");

  // Clean up
  free_tree(tree);

  return 0;
}
