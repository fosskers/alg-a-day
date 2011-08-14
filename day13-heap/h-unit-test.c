#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "intlist.h"

int main()
{
	IntList *list = NULL;
	Heap *heap = NULL;
	Heap *heap2 = NULL;
	int result;

	list = int_range(15);
	heap = new_heap_from_array(list->list, list->size);
	print_intlist(list);
	result = print_heap(heap);
	printf("Max: %d\n", find_max(heap));

	/* Try a deletion. */
	printf("Deleting max!\n");
	delete_max(heap);
	print_heap(heap);
	printf("Max: %d\n", find_max(heap));

	/* Fuse two heaps */
	printf("Fusing two heaps!\n");
	list = int_range2(10, 20);
	printf("Adding this: ");
	print_intlist(list);
	heap2 = new_heap_from_array(list->list, list->size);
	heap = heap_merge(heap, heap2);
	printf("Heap size: %d\n", heap->ins_pos);
	print_heap(heap);
	printf("Max: %d\n", find_max(heap));

	return 0;
}
