#include <stdio.h>
#include <stdlib.h>
#include "intlist.h"


IntList * new_intlist(int size) {
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
  IntList *list = new_intlist(size);
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
    list = new_intlist(size);

    if(list != NULL) {
      for(count = 0; count < size; count++) {
	list->list[count] = lower;
	lower++;
      }	
    }
  }

  return list;
}

IntList * wrap_int(int num) {
  // Wraps an int in an IntList.
  IntList *list = new_intlist(1);

  if(list != NULL)
    list->list[0] = num;

  return list;
}

IntList * wrap_array(int *array, int size) {
  // Wraps an int array in an IntList.
  // Note that this is NOT a copy, but a simple wrapping!
  IntList *list = NULL;

  if(array != NULL && size > 0) {
    list = new_intlist(size);
    
    if(list != NULL) {
      list->list = array;
      list->size = size;
    }
  }

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
    list = new_intlist(digits);
    if(list != NULL) {
      for(count = digits - 1; count >= 0; count--) {
	list->list[count] = num % 10;
	num /= 10;
      }
    }
  }

  return list;
}

IntList * copy_intlist(IntList *original) {
  // Creates a copy of an IntList.
  IntList *copy = NULL;
  int count;

  if(original != NULL) {
    copy = new_intlist(original->size);

    // Copy elements over if possible.
    if(copy != NULL)
      for(count = 0; count < copy->size; count++)
	copy->list[count] = original->list[count];
  }

  return copy;
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

void print_intlist(IntList *list) {
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
