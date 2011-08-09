#include <stdio.h>
#include "quicksort.h"

void test(int *, int);
void print_list(int *, int);

int main() {
  int single[1] = {0};
  int two_s[2] = {4, 5};
  int two_u[2] = {5, 4};
  int three_s[3] = {1, 2, 3};
  int three_u[3] = {3, 1, 2};
  int four_u[4] = {8, 5, 9, 1};
  int five_u[5] = {1, 6, 3, 8, 2};
  int blah[8] = {6, 4, 9, 1, 3, 0, 2, 5};

  test(single, 1);
  test(two_s, 2);
  test(two_u, 2);
  test(three_s, 3);
  test(three_u, 3);
  test(four_u, 4);
  test(five_u, 5);
  test(blah, 8);

  printf("Done testing.\n");

  return 0;
}

void test(int *list, int size) {
  printf("Testing: ");
  print_list(list, size);
  list = quick_sort(list, 0, size-1);
  printf("Sorted:  ");
  print_list(list, size);
  printf("\n");
}

void print_list(int *list, int size) {
  int count;
  
  printf("[");
  for(count = 0; count < size; count++) {
    printf("%d", list[count]);
    if(count < size - 1)
      printf(", ");
  }
  printf("]\n");
}


