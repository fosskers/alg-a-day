#include "intlist.h"

#ifndef BSTREE_H
#define BSTREE_H

typedef struct LEAF {
  int data;
  struct LEAF *left;
  struct LEAF *right;
} Leaf;

typedef struct TREE {
  Leaf *root;
} Tree;

// Tree Functions
Tree * new_tree();
Tree * new_tree_from_list(IntList *);
int contains(Tree *, int);
int _contains(Leaf *, int);
void insert(Tree *, int);
Leaf * _insert(Leaf *, int);
void print_tree(Tree *);
void _print_tree(Leaf *, int);
void print_indent(int);

// Leaf Functions
Leaf * new_leaf(int);

#endif
