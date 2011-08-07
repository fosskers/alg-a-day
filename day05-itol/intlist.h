typedef struct INTLIST {
  int *list;  
  int size;  // Size of the int array.
} IntList;

IntList * int_list(int);  // Creates an IntList of size 'int'.
IntList * int_range(int);
IntList * int_range2(int, int);
IntList * list_wrap(int);  // Wraps an int in an IntList.
IntList * itol(int);
int count_digits(int);
int list_length(IntList *);
void print_int_list(IntList *);
