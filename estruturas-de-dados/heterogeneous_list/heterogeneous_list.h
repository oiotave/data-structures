#ifndef HETEROGENEOUS_LIST_H_INCLUDED
#define HETEROGENEOUS_LIST_H_INCLUDED

struct tNode {
    char type; // stores element type (int or float)
    void *info; // Supports basic numerical inputs (int or float)
    struct tNode *next;
};

typedef struct tNode Node;

// List constructor
Node* new_list();

// Checks if list is empty
int is_empty(Node*);

// Checks if list is unitary
int is_unitary(Node*);

// Shows all elements in list
void show_list(Node*);

// Adds new element
void insert(Node**, int, float, char);

// Removes the last element
void remove(Node**);

// Clears the list
void clear(Node**);

#endif // HETEROGENEOUS_LIST_H_INCLUDED
