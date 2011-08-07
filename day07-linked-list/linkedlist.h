// A List structure that can do everything anyone would ever want. Maybe.
// This C version does more than the Python and Haskell versions,
// simply because the list structures already present in those languages
// are much more powerful than a simple C array.

typedef struct LINKEDLIST LinkedList;
typedef struct NODE Node;

// A Linked List.
struct LINKEDLIST {
  Node *root;
  Node *end;
  int length;
};

// Node in a Linked List.
struct NODE {
  int data;
  Node *prev;
  Node *next;
};

// LinkedList specific
LinkedList * new_list(int);
LinkedList * push(LinkedList *, int);
LinkedList * insert(LinkedList *, int);
LinkedList * list_remove(LinkedList *, int);
int pop(LinkedList *);
int head(LinkedList *);
int contains(LinkedList *, int);
int length(LinkedList *);
void print_list(LinkedList *);
void destroy_list(LinkedList *);

// Node stuff.
Node * new_node(int);
void print_node(Node *);
void destroy_node(Node *);
void destroy_nodes(Node *);

