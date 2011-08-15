/* Binary Max Heap implemention in Linux Kernel C style. */

#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#define DEFAULTMAX 10000  /* The default size of our Heap. */
#define ERROR      0xfeed
#define NULLPOINT  0xdead
#define OVERFLOW   0xb00b
#define INDEXERR   0xbeef

Heap * new_heap() 
{
	return new_heap_of_size(DEFAULTMAX);
}

Heap * new_heap_of_size(int size) 
{
	Heap *heap = NULL;

	heap = malloc(sizeof(Heap));

	if(heap != NULL && size > 0) {
		heap->list = malloc(sizeof(int) * size);

		if(heap->list != NULL) {
			heap->ins_pos = 0;
			heap->lim = size;
		} else {
			heap = NULL;
		}
	}

	return heap;
}

Heap * new_heap_from_array(int *array, int size) 
{
	Heap *heap = NULL;
	int count, result;
  
	if(array != NULL) {
		if(size > DEFAULTMAX)
			heap = new_heap_of_size(size + DEFAULTMAX);
		else
			heap = new_heap();

		if(heap != NULL) {
			for(count = 0; count < size; count++) {
				result = heap_insert(heap, array[count]);
			}
		}
	}

	return heap;
}

Heap * heap_merge(Heap *first, Heap *second) 
{
	/* Creates a new Heap with the contents of two given ones. */
	Heap *merged = NULL;
	int count, fst_size, snd_size, combined;

	if(first != NULL && second != NULL) {
		fst_size = heap_size(first);
		snd_size = heap_size(second);
		combined = fst_size + snd_size;
	
		if(combined > DEFAULTMAX)
			merged = new_heap_of_size(combined + DEFAULTMAX);
		else
			merged = new_heap();

		if(merged != NULL) {
			/* Insert all of 'first' */
			for(count = 0; count < fst_size; count++)
				heap_insert(merged, first->list[count]);

			/* Insert all of 'second' */
			for(count = 0; count < snd_size; count++)
				heap_insert(merged, second->list[count]);
		}
	}

	return merged;
}

int find_max(Heap *heap) 
{
	int result;

	if(heap != NULL && heap->ins_pos > 0)
		result = heap->list[0];
	else
		result = -ERROR;
	
	return result;
}

int in_heap(Heap *heap, int index) 
{
	int result = 0;  

	if(heap != NULL && index < heap->ins_pos && index >= 0)
		result = 1;

	return result;
}

int first_born_pos(int parent_pos) 
{
	return (2 * parent_pos) + 1;	
}

int second_born_pos(int parent_pos)
{
	return (2 * parent_pos) + 2;
}

int parent_pos(int child_pos)
{
	return (child_pos - 1) / 2;
}

int heap_insert(Heap *heap, int item)
{
	int result = 0;

	if(heap == NULL)
		return -NULLPOINT;
	else if(heap->ins_pos >= heap->lim)
		return -OVERFLOW;
			
	heap->list[heap->ins_pos] = item;
	heap->ins_pos += 1;
	result = cascade_up(heap, heap->ins_pos - 1);

	return result;
}

int cascade_up(Heap *heap, int kid_pos)
{
	/* Move new child up Heap until the Heap Property is restored. */
	int result = 0;
	int parent;

	if(heap == NULL)
		return -NULLPOINT;
	else if(!in_heap(heap, kid_pos))
		return -INDEXERR;

	if(kid_pos) {  /* 0 evaluates to False, at which point we're done */
		parent = parent_pos(kid_pos);
		
		if(heap->list[parent] < heap->list[kid_pos]) {
			swap_elements(heap, parent, kid_pos);
			result = cascade_up(heap, parent);
		}
	}

	return result;
}

int swap_elements(Heap *heap, int parent, int kid)
{
	int temp;

	if(heap == NULL)
		return -NULLPOINT;
	else if(!in_heap(heap, parent) || !in_heap(heap, kid))
		return -INDEXERR;

	temp = heap->list[parent];
	heap->list[parent] = heap->list[kid];
	heap->list[kid] = temp;

	return 0;
}

int delete_max(Heap *heap)
{
	int result;

	if(heap == NULL)
		return -NULLPOINT;

	swap_elements(heap, 0, heap->ins_pos - 1);
	heap->ins_pos -= 1;
	result = cascade_down(heap, 0);

	return result;
}

int cascade_down(Heap *heap, int index)
{
	int result = 0;
	int older_pos; 

	if(heap == NULL)
		return -NULLPOINT;
	else if(!in_heap(heap, index))
		return -INDEXERR;

	older_pos = find_older_pos(heap, index);

	if(older_pos) {
		if(heap->list[index] < heap->list[older_pos]) {
			swap_elements(heap, index, older_pos);
			result = cascade_down(heap, older_pos);
		}
	}

	return result;
}

int find_older_pos(Heap *heap, int index)
{	
	int fst_pos, snd_pos;
	int older_pos = 0;

	if(heap == NULL)
		return -NULLPOINT;

	fst_pos = first_born_pos(index);
	snd_pos = second_born_pos(index);
	
	if(in_heap(heap, fst_pos)) {
		if(in_heap(heap, snd_pos) && \
		   heap->list[snd_pos] > heap->list[fst_pos])
			older_pos = snd_pos;
		else
			older_pos = fst_pos;
	}
	
	return older_pos;
}

int destroy_heap(Heap *heap)
{
	if(heap == NULL)
		return -NULLPOINT;

	free(heap->list);
	free(heap);

	return 0;
}

int print_heap(Heap *heap)
{
	int result = 0;

	if(heap == NULL)
		return -NULLPOINT;
	
	if(heap->ins_pos == 0) {
		printf("\n");
	} else {
		result = _print_heap(heap, 0, 0);
	}
	
	return result;
}

int _print_heap(Heap *heap, int index, int indent)
{
	if(heap == NULL)
		return -NULLPOINT;

	if(in_heap(heap, index)) {
		_print_heap(heap, second_born_pos(index), indent + 2);
		print_whitespace(indent);
		printf("%d\n", heap->list[index]);
		_print_heap(heap, first_born_pos(index), indent + 2);
	} 

	return 0;
}

void print_whitespace(int spaces)
{
	int count;

	for(count = 0; count < spaces; count++)
		printf(" ");
}
