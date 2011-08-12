#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"
#include "intlist.h"

void test_contains(Tree *, int);

int main() {
  Tree *tree = NULL;
  IntList *list = NULL;
  int nums[12] = {10, 15, 5, 3, 14, 7, 2, 11, 9, 0, 16, 15};

  // NULL Tree.
  printf("Attempting to make and print a NULL Tree...\n");
  tree = new_tree_from_list(list);
  print_tree(tree);

  // Few elements at a time.
  printf("Adding a few elements at a time...\n");
  tree = new_tree();
  insert(tree, 5);
  printf("One leaf...\n");
  print_tree(tree);
  insert(tree, 3);
  printf("Two leaves...\n");
  print_tree(tree);
  insert(tree, 7);
  printf("Three leaves...\n");
  print_tree(tree);

  // From a list.
  printf("Making a Tree from an IntList...\n");
  list = wrap_array(nums, 12);
  tree = new_tree_from_list(list);
  print_tree(tree);

  // Testing contains.
  test_contains(tree, 1);
  test_contains(tree, 16);
  test_contains(tree, 15);
  test_contains(tree, 5);
  test_contains(tree, 7);
  test_contains(tree, 0);
  test_contains(tree, 6);
  
  return 0;
}

void test_contains(Tree *tree, int item) {
  printf("Is %d in the tree?\n", item);
  if(contains(tree, item))
    printf("Yes.\n");
  else
    printf("No.\n");
}
