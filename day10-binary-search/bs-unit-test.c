// unit test for a binary search.

#include <stdio.h>
#include "intlist.h"
#include "binsearch.h"

void test_list(IntList *, int);

int main() {
  IntList *list = NULL;

  // One element, should find it.
  list = wrap_int(9);
  test_list(list, 9);

  // One element, shouldn't find it.
  test_list(list, 99);

  // Two elements, should find it.
  list = int_range(1);
  test_list(list, 1);

  // Two elements, shouldn't find it.
  test_list(list, 9);
  
  // Three elements, should find it.
  list = int_range(2);
  test_list(list, 1);

  // Three elements, shouldn't find it.
  test_list(list, 9);

  // Four elements, should find it.
  list = int_range(3);
  test_list(list, 0);
  test_list(list, 3);

  // Four elements, shouldn't find it.
  test_list(list, 8);

  return 0;
}

void test_list(IntList *list, int item) {
  int pos;

  printf("Testing: ");
  print_intlist(list);
  printf("Looking for: %d\n", item);
  pos = binary_search(list->list, list->size, item);
  
  if(pos != -1)
    printf("Found at pos: %d\n", pos);
  else
    printf("Not found.\n");

  printf("\n");
}
