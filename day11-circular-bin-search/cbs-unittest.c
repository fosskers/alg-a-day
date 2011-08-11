#include <stdio.h>
#include <stdlib.h>
#include "circbs.h"
#include "intlist.h"

void find_all_values(IntList *);

int main() {
  IntList *list = NULL;

  // NULL list
  printf("Trying a NULL list...\n");
  find_all_values(NULL);

  // Large, normal.
  printf("Trying a normal list...\n");
  list = int_range(1000);
  find_all_values(list);

  // Large, split.
  printf("Trying a split (circular) list...\n");
  list = fuse_intlists(int_range2(2000, 2500), list);
  find_all_values(list);

  return 0;
}

void find_all_values(IntList *list) {
  int count;
  int pos;

  if(list != NULL) {
    printf("Finding all values in a length %d list..,\n", list->size);

    for(count = 0; count < list->size; count++) {
      pos = circ_bs(list->list, list->list[count], list->size);

      if(pos == -1) {
	printf("Couldn't find %d!\n", list->list[count]);
	break;
      }  
    }
  }
  printf("Done.\n");
}


