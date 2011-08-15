#ifndef HEAP_H
#define HEAP_H
#define heap_size(x)  x->ins_pos

typedef struct HEAP {
	int *list;
	int ins_pos;  /* Next item to be entered goes here. */
	int lim;      /* Size limit of the Heap. */
} Heap;

Heap * new_heap();
Heap * new_heap_of_size(int);
Heap * new_heap_from_array(int *, int);
Heap * heap_merge(Heap *, Heap *);
int find_max(Heap *);
int in_heap(Heap *, int);
int first_born_pos(int);
int second_born_pos(int);
int parent_pos(int);
int heap_insert(Heap *, int);
int cascade_up(Heap *, int);
int swap_elements(Heap *, int, int);
int delete_max(Heap *);
int cascade_down(Heap *, int);
int destroy_heap(Heap *);
int print_heap(Heap *);
int _print_heap(Heap *, int, int);
void print_whitespace(int);

#endif
