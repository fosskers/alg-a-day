#include <stdlib.h>
#include "quicksort.h"

int * quick_sort(int *list, int lower, int upper) {
  // Sorts a list of ints.
  int size = upper - lower + 1;
  int pivot_pos;

  if(list != NULL) {
    if(size > 1) {
      pivot_pos = qsort_partition(list, lower, upper);
      quick_sort(list, lower, pivot_pos - 1);
      quick_sort(list, pivot_pos + 1, upper);
    }
  }

  return list;
}

int qsort_partition(int *list, int lower, int upper) {
  // Divide the list by the pivot.
  int pivot_pos = get_pivot_pos(list, lower, upper);
  int swap_index = lower;  
  int count;
  
  // Move pivot to the end.
  swap(list, upper, pivot_pos);
  
  // Move along array and perform swaps.
  for(count = lower; count < upper; count++) {
    if(list[count] < list[upper]) {
      swap(list, count, swap_index);
      swap_index++;
    }
  }

  // Move pivot back into its proper spot.
  swap(list, upper, swap_index);

  return swap_index;
}

int get_pivot_pos(int *list, int lower, int upper) {
  // Find the pivot. This can be changed easily to fit the mood you're in.
  return (lower + upper + 1) / 2;  // Watch out for overflows.
}

int * swap(int *list, int pos1, int pos2) {
  // Swaps two elements of a given list.
  int temp;

  temp = list[pos1];
  list[pos1] = list[pos2];
  list[pos2] = temp;
  
  return list;
}
