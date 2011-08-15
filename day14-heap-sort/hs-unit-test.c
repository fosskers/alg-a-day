#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "heapsort.h"
#include "intlist.h"

int main()
{
	Heap *heap;
	IntList *list;

	list = fuse_intlists(int_range(20), int_range2(-5, 10));
	printf("To Heapify: ");
	print_intlist(list);
	printf("List size: %d\n", list->size);
	heap = new_heap_from_array(list->list, list->size);
	printf("The heap!\n");
	print_heap(heap);
	printf("Heap size: %d\n", heap->ins_pos);
	
	/* Sort and print */
	list = heap_sort(heap);
	printf("Sorted:\n");
	print_intlist(list);
	printf("New list size: %d\n", list->size);
    
	return 0;
}
