#include <stdio.h>
#include <stdlib.h>
#include "intlist.h"


IntList * int_list(int size) {
  // Creates an int array of length 'size'.
  IntList *list = NULL;

  if(size > 0) {
    list = malloc(sizeof(IntList));

    if(list != NULL) {
      list->list = malloc(sizeof(int) * size);
      
      if(list->list != NULL)
	list->size = size;
    }
  }

  return list;
}

IntList * int_range(int upper) {
  // Returns a list of ints from 0 to upper.
  int size = upper + 1;
  IntList *list = int_list(size);
  int count;

  if(list != NULL) {
    for(count = 0; count < size; count++)
      list->list[count] = count;
  }

  return list;
}

IntList * int_range2(int lower, int upper) {
  // Returns a list of ints from lower to upper.
  int size = upper - lower + 1;
  IntList *list = NULL;
  int count;

  if(size > 0) {
    list = int_list(size);

    if(list != NULL) {
      for(count = 0; count < size; count++) {
	list->list[count] = lower;
	lower++;
      }	
    }
  }

  return list;
}

IntList * list_wrap(int num) {
  // Wraps an int in an IntList.
  IntList *list = int_list(1);

  if(list != NULL)
    list->list[0] = num;

  return list;
}

IntList * itol(int num) {
  // Converts an int to an IntList containing an array of each digit.
  int count;   // For iteration.
  int digits;  //Number of digits in the number given.
  IntList *list  = NULL;

  if(num == 0)
    list = int_range(0);
  else {
    digits = count_digits(num);
    list = int_list(digits);
    if(list != NULL) {
      for(count = digits - 1; count >= 0; count--) {
	list->list[count] = num % 10;
	num /= 10;
      }
    }
  }

  return list;
}

int count_digits(int num) {
  // Determines how many digits a number has.
  int result = 0;

  while(num > 0) {
    result++;
    num /= 10;
  }

  return result;
}

int list_length(IntList *list) {
  // Determines the length of a given IntList.
  int length = 0;

  if(list != NULL)
    length = list->size;

  return length;
}

void print_int_list(IntList *list) {
  // Prints an int array prettily.
  int length, count;

  if(list != NULL) {
    length = list_length(list);
    printf("[");
    
    for(count = 0; count < length; count++) {
      printf("%d", list->list[count]);
      if(count < length - 1)
	printf(", ");
    }

    printf("]\n");
  }
  else
    printf("Attempted to print a NULL IntList.\n");
}
