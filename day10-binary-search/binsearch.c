#include <stdlib.h>
#include "binsearch.h"

int binary_search(int *list, int size, int item) {
  // Returns the position of the item in the array,
  // or -1 if the item isn't present.
  int result = -1;
  int mid;
  int lower = 0;
  int upper = size - 1;

  if(list != NULL) {  // Don't be caught with your pants down.
    while(lower <= upper) {
      // Find new mid.
      mid = (lower + upper) / 2;  // This can overflow. Watch out.

      if(list[mid] < item)
	lower = mid + 1;
      else if(list[mid] > item)
	upper = mid - 1;
      else {  // list[mid] == item
	result = mid;
	break;
      }
    }
  }

  return result;
}
