#include <stdio.h>
#include "intlist.h"

void test_int_range();
void test_int_range2();
void test_itol();

int main() {
  test_int_range();
  test_int_range2();
  test_itol();

  return 0;
}

void test_int_range() {
  IntList *list = NULL;

  printf("Testing int_range()\n");
  list = int_range(0);
  print_int_list(list);
  list = int_range(1);
  print_int_list(list);
  list = int_range(10);
  print_int_list(list);		   
  printf("\n");
}

void test_int_range2() {
  IntList *list = NULL;

  printf("Testing in_range2()\n");
  list = int_range2(0, 0);
  print_int_list(list);
  list = int_range2(0, 1);
  print_int_list(list);		   
  list = int_range2(-5, 5);
  print_int_list(list);		   
  list = int_range2(5, 0);
  print_int_list(list);		   
  printf("\n");
}

void test_itol() {
  IntList *list = NULL;

  printf("Testing itol()\n");
  list = itol(0);
  print_int_list(list);		   
  list = itol(12);
  print_int_list(list);		   
  list = itol(123);
  print_int_list(list);		   
  list = itol(-5);
  print_int_list(list);		   
  printf("\n");
}
