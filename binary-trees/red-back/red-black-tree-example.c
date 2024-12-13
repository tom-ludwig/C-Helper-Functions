/*
 * Copyright © 2024
 * Created by Tom M. Ludwig, Louis Kauer, Julian Kuecken, and Pepe Hanisch
 *
 * This project is licensed under the MIT License.
 * You may use, modify, and distribute this software under the terms of the license.
*/

#include "red-black-tree.h"
#include <stdio.h>
int main() {
  RBTree *tree = create_rb_tree();

  // Insert nodes into the Red-Black Tree
  insert_rb_tree(tree, 10);
  insert_rb_tree(tree, 20);
  insert_rb_tree(tree, 30);
  insert_rb_tree(tree, 15);
  insert_rb_tree(tree, 25);
  insert_rb_tree(tree, 5);

  // Perform various traversals
  printf("In-order traversal: ");
  inorder_traversal(tree->root);
  printf("\n");

  printf("Pre-order traversal: ");
  preorder_traversal(tree->root);
  printf("\n");

  printf("Post-order traversal: ");
  postorder_traversal(tree->root);
  printf("\n");

  // Find a node
  RBTreeNode *found = find_rb_tree(tree, 15);
  if (found) {
    printf("Node with value 15 found!\n");
  } else {
    printf("Node with value 15 not found.\n");
  }

  // Clean up the tree
  free_rb_tree(tree);

  return 0;
}
