// See the header for notes.

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// LINKED LIST FUNCTIONS

LinkedList * new_list(int data) {
  // Creates a new Linked List.
  LinkedList *list = NULL;

  list = malloc(sizeof(LinkedList));
  
  if(list != NULL) {
    list->root = new_node(data);
    list->end  = list->root;
    list->length = 1;
  }

  return list;
}

LinkedList * push(LinkedList *list, int data) {
  // Adds new data to the end of the list.
  Node *node = NULL;

  if(list != NULL) {
    node = new_node(data);

    if(node != NULL) {
      if(list->root == NULL)  // Pushing into an empty list.
	list->root = node;
      else {
	list->end->next = node;
	node->prev = list->end;
      }
      list->end = node;
      list->length += 1;
    }
  }

  return list;
}

LinkedList * insert(LinkedList *list, int data) {
  // Adds new data to the front of the list.
  Node *node = NULL;

  if(list != NULL) {
    node = new_node(data);

    if(node != NULL) {
      node->next = list->root;
      list->root->prev = node;
      list->root = node;
      list->length += 1;
    }
  }

  return list;
}

LinkedList * list_remove(LinkedList *list, int data) {
  // Removes a given piece of data from the list.
  Node *curr;

  if(list != NULL) {
    curr = list->root;

    while(curr != NULL) {
      if(curr->data == data) {
	list->length -= 1;

	if(curr == list->root) {  // Removing the root.
	  list->root = list->root->next;
	  
	  if(list->length == 0)
	    list->end = NULL;
	  else
	    list->root->prev = NULL;
	}
	else if(curr->next == NULL) {  // Removing last node.
	  curr->prev->next = NULL;
	  list->end = curr->prev;
	}
	else  // A normal node.
	  curr->prev->next = curr->next;

	destroy_node(curr);
	break;
      }
      curr = curr->next;
    }
  }

  return list;
}

int pop(LinkedList *list) {
  // Yields the last item in the list.
  int result = 0;
  Node *temp;

  if(list != NULL && list->length > 0) {
    temp = list->end;
    result = temp->data;
    list->length -= 1;
    
    if(list->length == 0) {  // We emptied the list.
      list->root = NULL;
      list->end = NULL;
    }
    else {  // Still other nodes left.
      temp->prev->next = NULL;
      list->end = temp->prev;
    }

    destroy_node(temp);
  }
  else {
    perror("ERROR: Empty List passed!");
  }

  return result;
}

int head(LinkedList *list) {
  // Yields the first item in the list.
  int result = 0;
  Node *temp;
  
  if(list != NULL && list->length > 0) {
    temp = list->root;
    result = temp->data;
    list->root = temp->next;
    list->length -= 1;

    if(list->length > 0)
      list->root->prev = NULL;
    else
      list->end = NULL;

    destroy_node(temp);
  }
  else {
    perror("ERROR: Empty List passed!");
  }

  return result;
}

int contains(LinkedList *list, int data) {
  // Checks if a list contains a given piece of data.
  Node *curr;
  int result = 0;  // Assume failure.

  if(list != NULL) {
    curr = list->root;

    while(curr != NULL) {
      if(curr->data == data) {
	result = 1;
	break;
      }
      curr = curr->next;
    }
  }

  return result;
}

int length(LinkedList *list) {
  // Yields the length of the list.
  int result = -1;

  if(list != NULL)
    result = list->length;

  return result;
}

void print_list(LinkedList *list) {
  // Prints a given Linked List.
  Node *curr;

  if(list != NULL) {
    curr = list->root;

    if(curr == NULL)
      printf("Empty\n");

    while(curr != NULL) {
      print_node(curr);
      curr = curr->next;
    }
  }
}

void destroy_list(LinkedList *list) {
  // Emancipates a Linked List from its memory-bound slavery.
  if(list != NULL) {
    destroy_nodes(list->root);
    free(list);
  }
}

// NODE FUNCTIONS

Node * new_node(int data) {
  // Creates a new Node.
  Node *node = NULL;

  node = malloc(sizeof(Node));
  
  if(node != NULL) {
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
  }

  return node;
}

void print_node(Node *node) {
  // Prints a Node all pretty-like.
  if(node != NULL) {
    printf("%d ~> ", node->data);
    if(node->next == NULL)
      printf("End\n");
  }
}

void destroy_node(Node *node) {
  // Destroys the given Node. With rage.
  free(node);
}

void destroy_nodes(Node *node) {
  // Recursively frees all the Nodes.
  if(node != NULL) {
    if(node->next == NULL)
      destroy_node(node);
    else {
      destroy_nodes(node->next);
      destroy_node(node);
    }
  }
}
