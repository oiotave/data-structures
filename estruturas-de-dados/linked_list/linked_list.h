#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

struct tList {
    int info;
    struct tList *next;
};

typedef struct tList List;

// List constructor
List* new_list();

// Checks if list is empty
int is_empty(List*);

// Checks if list contains a single element
int is_unitary(List*);

// Shows the number os elements in the list
int length(List*);

// Shows all elements in the list
void show_list(List*);

// Manages different insertions in list
void insert(List**, int, int);

void insert_start(List**, List*); // Insertion in the beggining

void insert_end(List**, List*); // Insertion in the end

void insert_gnr(List**, List*, int); // Insertion in generic position

// Removes an element from list
void remove(List**);

// Clears the list
void clear(List**);

#endif // LINKED_LIST_H_INCLUDED
