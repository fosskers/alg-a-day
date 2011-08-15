#include <stdio.h>  // Take this out.
#include <stdlib.h>
#include "heap.h"
#include "intlist.h"

/* Done in place, then wrapped in an IntList.
 * The original heap is ruined, but memory is saved. 
 */
IntList * heap_sort(Heap *heap) 
{
	IntList *list = NULL;
	int heap_size;  /* Must keep track of original size of Heap. */
	
	if(heap != NULL) {
		heap_size = heap->ins_pos;

		while(heap->ins_pos > 1) {
			swap_elements(heap, 0, heap->ins_pos - 1);
			heap->ins_pos -= 1;
			cascade_down(heap, 0);
		}

		list = wrap_array(heap->list, heap_size);
	}
	
	return list;
}
