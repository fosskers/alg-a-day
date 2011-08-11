#include <stdio.h>
#include "intlist.h"

void test_int_range();
void test_int_range2();
void test_wrap_int();
void test_wrap_array();
void test_itol();
void test_copy_intlist();
void test_copy_intlist_helper(IntList *);
void test_fuse_intlists();
void test_fuse_intlists_helper(IntList *, IntList *);

int main() {
  test_int_range();
  test_int_range2();
  test_wrap_int();
  test_wrap_array();
  test_itol();
  test_copy_intlist();
  test_fuse_intlists();

  printf("Tests complete.\n");

  return 0;
}

void test_int_range() {
  IntList *list = NULL;

  printf("Testing int_range()\n");
  list = int_range(0);
  print_intlist(list);
  list = int_range(1);
  print_intlist(list);
  list = int_range(10);
  print_intlist(list);		   
  printf("\n");
}

void test_int_range2() {
  IntList *list = NULL;

  printf("Testing in_range2()\n");
  list = int_range2(0, 0);
  print_intlist(list);
  list = int_range2(0, 1);
  print_intlist(list);		   
  list = int_range2(-5, 5);
  print_intlist(list);		   
  list = int_range2(5, 0);
  print_intlist(list);		   
  printf("\n");
}

void test_wrap_int() {
  IntList *list = NULL;

  printf("Testing wrap_int()\n");
  list = wrap_int(42);
  print_intlist(list);
  printf("\n");
}

void test_wrap_array() {
  IntList *list = NULL;
  int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

  printf("Testing wrap_array()\n");
  list = wrap_array(nums, 10);
  print_intlist(list);
  printf("\n");
}

void test_itol() {
  IntList *list = NULL;

  printf("Testing itol()\n");
  list = itol(0);
  print_intlist(list);		   
  list = itol(12);
  print_intlist(list);		   
  list = itol(123);
  print_intlist(list);		   
  list = itol(-5);
  print_intlist(list);		   
  printf("\n");
}

void test_copy_intlist() {
  IntList *list = NULL;

  printf("Testing copy_intlist()\n");

  printf("Single element...\n");
  list = wrap_int(5);
  test_copy_intlist_helper(list);

  printf("Two elements...\n");
  list = int_range(1);
  test_copy_intlist_helper(list);

  printf("Three elements...\n");
  list = int_range(2);
  test_copy_intlist_helper(list);

  printf("No elements...\n");
  list = int_range2(5, 0);  // This will return NULL.
  test_copy_intlist_helper(list);

  printf("\n");
}

void test_copy_intlist_helper(IntList *list) {
  IntList *copy = NULL;

  printf("Original: ");
  print_intlist(list);
  copy = copy_intlist(list);
  printf("Copy:     ");
  print_intlist(copy);
}

void test_fuse_intlists() {
  IntList *first = NULL;
  IntList *second = NULL;

  printf("Testing fuse_intlists()\n");

  // NULL lists.
  test_fuse_intlists_helper(NULL, NULL);

  // Fusing singletons.
  first = wrap_int(5);
  second = wrap_int(9);
  test_fuse_intlists_helper(first, second);

  // Twos.
  first = itol(12);
  second = itol(56);
  test_fuse_intlists_helper(first, second);

  // Different lenths.
  first = itol(154);
  second = itol(98354);
  test_fuse_intlists_helper(first, second);

  printf("\n");
}

void test_fuse_intlists_helper(IntList *first, IntList *second) {
  IntList *list = NULL;
  
  printf("Attempting to fuse:\n");
  print_intlist(first);
  print_intlist(second);
  list = fuse_intlists(first, second);
  printf("Fused into: ");
  print_intlist(list);
  printf("\n");
}
