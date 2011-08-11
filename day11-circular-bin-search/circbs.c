#include <stdlib.h>
#include "circbs.h"

int circ_bs(int *list, int target, int size) {
  // Performs a circular binary search on the given list.
  int lower = 0;
  int upper = size - 1;
  int result = -1;
  int mid;

  if(list != NULL) {
    while(lower <= upper) {
      // Calculate new mid.
      mid = (upper + lower) / 2;  // This can overflow.

      if(list[mid] == target) {
	result = mid;
	break;
      }
      else if(list[lower] <= target && target < list[mid])
	upper = mid - 1;
      else if(list[mid] < target && target <= list[upper])
	lower = mid + 1;
      else {  // Standard binary search logic has failed.
	if(list[lower] > list[mid])  // Link is on the left.
	  upper = mid - 1;
	else  // Link is on the right.
	  lower = mid + 1;
      }
    }
  }

  return result;
}
