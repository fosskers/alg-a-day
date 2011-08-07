#include <stdio.h>
#include <assert.h>
#include "linkedlist.h"

void test_new_list();
void test_push();
void test_insert();
void test_remove();
void test_contains();
void test_length();
void test_pop();
void test_pop_helper(LinkedList *);
void test_head();
void test_head_helper(LinkedList *);

int main() {
  printf("Starting tests!\n");

  test_new_list();
  test_push();
  test_insert();
  test_remove();
  test_contains();
  test_length();
  test_pop();
  test_head();

  printf("Tests complete.\n");

  return 0;
}

void test_new_list() {
  LinkedList *list = NULL;

  printf("Testing new_list()...\n");
  list = new_list(42);
  assert(list != NULL);
  print_list(list);
  printf("\n");
}

void test_push() {
  LinkedList *list = NULL;

  printf("Testing push()...\n");
  list = new_list(42);
  list = push(list, 49);
  assert(list != NULL);
  print_list(list);
  printf("\n");
}

void test_insert() {
  LinkedList *list = NULL;

  printf("Testing insert()...\n");
  list = new_list(42);
  list = insert(list, 11);
  assert(list != NULL);
  print_list(list);
  printf("\n");
}

void test_remove() {
  LinkedList *list = NULL;
  
  printf("Testing remove()...\n");
  
  // Remove the only element.
  list = new_list(42);
  printf("Before...\n");
  print_list(list);
  list = list_remove(list, 42);
  assert(list != NULL);
  printf("After...\n");
  print_list(list);

  // Remove the end.
  list = new_list(42);
  list = push(list, 1);
  list = push(list, 2);
  printf("Before...\n");
  print_list(list);
  list = list_remove(list, 2);
  printf("After...\n");
  print_list(list);

  // Remove a middle one.
  list = push(list, 5);
  list = push(list, 999);
  printf("Before...\n");
  print_list(list);
  list = list_remove(list, 1);
  printf("After...\n");
  print_list(list);

  printf("\n");
}

void test_contains() {
  LinkedList *list = NULL;
  int result;

  printf("Testing contains()...\n");

  list = new_list(42);
  assert(list != NULL);

  // Definitely in there.
  result = contains(list, 42);
  assert(result == 1);

  // Definitely not in there.
  result = contains(list, 999);
  assert(result == 0);

  printf("\n");
}

void test_length() {
  LinkedList *list = NULL;
  int result;

  printf("Testing length()...\n");

  list = new_list(42);
  assert(list != NULL);

  result = length(list);
  assert(result == 1);

  list = push(list, 1);
  result = length(list);
  assert(result == 2);

  list = insert(list, 55);
  result = length(list);
  assert(result == 3);

  list = list_remove(list, 1);
  result = length(list);
  assert(result == 2);

  printf("\n");
}

void test_pop() {
  LinkedList *list = NULL;

  printf("Testing test_pop()...\n");

  // Pop only element.
  list = new_list(42);
  test_pop_helper(list);

  // Pop off normal list.
  list = new_list(42);
  list = push(list, 5);
  list = push(list, 9);
  test_pop_helper(list);

  // Pop off empty list.
  list = new_list(42);
  list = list_remove(list, 42);
  test_pop_helper(list);

  printf("\n");
}

void test_pop_helper(LinkedList *list) {
  int result;

  printf("Unpopped: ");
  print_list(list);
  result = pop(list);
  printf("Got: %d\n", result);
  printf("Popped: ");
  print_list(list);
}

void test_head() {
  LinkedList *list = NULL;

  printf("Testing head()...\n");

  // Get only element.
  list = new_list(42);
  test_head_helper(list);

  // Get head from normal list.
  list = new_list(42);
  list = insert(list, 11);
  list = insert(list, 66);
  test_head_helper(list);

  // Get head from empty list.
  list = new_list(42);
  list = list_remove(list, 42);
  test_head_helper(list);

  printf("\n");
}

void test_head_helper(LinkedList *list) {
  int result;

  printf("Before: ");
  print_list(list);
  result = head(list);
  printf("Got: %d\n", result);
  printf("After: ");
  print_list(list);
}




