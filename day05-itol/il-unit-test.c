#include <stdio.h>
#include "intlist.h"

void test_int_range();
void test_int_range2();
void test_list_wrap();
void test_itol();
void test_copy_intlist();
void test_copy_intlist_helper(IntList *);

int main() {
  test_int_range();
  test_int_range2();
  test_list_wrap();
  test_itol();
  test_copy_intlist();

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

void test_list_wrap() {
  IntList *list = NULL;

  printf("Testing list_wrap()\n");
  list = list_wrap(42);
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
  list = list_wrap(5);
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
