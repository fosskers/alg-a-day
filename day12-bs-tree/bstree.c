// A Binary Search Tree in C.

#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"
#include "intlist.h"

Tree * new_tree() {
  // Creates a new, empty Tree.
  Tree *tree = NULL;

  tree = malloc(sizeof(Tree));

  if(tree != NULL) 
    tree->root = NULL;

  return tree;
}

Tree * new_tree_from_list(IntList *list) {
  // Given an IntList, creates a Tree from it.
  Tree *tree = NULL;
  int count;

  if(list != NULL) {
    tree = new_tree();

    if(tree != NULL) {
      // Insert every item in 'list' into the Tree.
      for(count = 0; count < list->size; count++)
	insert(tree, list->list[count]);
    }
  }

  return tree;
}

int contains(Tree *tree, int item) {
  // Determines if 'item' is in the given Tree.
  int result = 0;

  if(tree != NULL)
    result = _contains(tree->root, item);
  
  return result;    
}

int _contains(Leaf *leaf, int item) {
  // Uses recursion to test for containment.
  int result;

  if(leaf == NULL)
    return 0;

  if(item == leaf->data)
    result = 1;
  else if(item < leaf->data)
    result = _contains(leaf->left, item);
  else
    result = _contains(leaf->right, item);

  return result;
}

void insert(Tree *tree, int item) {
  // Inserts an item into the given Tree.
  if(tree != NULL) {
    tree->root = _insert(tree->root, item);
  }
}

Leaf * _insert(Leaf *leaf, int item) {
  // Inserts the new item via recursion.
  if(leaf == NULL)
    return new_leaf(item);

  if(item < leaf->data)
    leaf->left = _insert(leaf->left, item);
  else
    leaf->right = _insert(leaf->right, item);

  return leaf;
}

void print_tree(Tree *tree) {
  // Figured out a great way to print trees.
  if(tree != NULL)
    _print_tree(tree->root, 0);
}

void _print_tree(Leaf *leaf, int indent) {
  // Prints the tree opening to the right via recursion.
  if(leaf != NULL) {
    _print_tree(leaf->right, indent + 2);
    print_indent(indent);
    printf("%d\n", leaf->data);
    _print_tree(leaf->left, indent + 2);
  }
}

void print_indent(int indent) {
  // Prints a bunch of whitespace.
  int count;

  for(count = 0; count < indent; count++)
    printf(" ");
}

Leaf * new_leaf(int item) {
  Leaf *leaf = NULL;

  leaf = malloc(sizeof(Leaf));

  if(leaf != NULL) {
    leaf->data = item;
    leaf->left = NULL;
    leaf->right = NULL;
  }
  
  return leaf;
}
