#ifndef INTLIST_H
#define INTLIST_H

typedef struct INTLIST {
  int *list;  
  int size;  // Size of the int array.
} IntList;

IntList * new_intlist(int);  // Creates an IntList of size 'int'.
IntList * int_range(int);
IntList * int_range2(int, int);
IntList * wrap_int(int);  // Wraps an int in an IntList.
IntList * wrap_array(int *, int);  // Wraps an array in an IntList.
IntList * itol(int);
IntList * copy_intlist(IntList *);
int count_digits(int);
int list_length(IntList *);
void print_intlist(IntList *);

#endif
