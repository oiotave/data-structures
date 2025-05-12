#ifndef ORDERED_LIST_H_INCLUDED
#define ORDERED_LIST_H_INCLUDED

struct tList {
    struct tList *prev;
    int info;
    struct tList *next;
};

// Pointers to list extremes
struct pointer {
    struct tList *str;
    struct tList *end;
};

typedef struct tList List;
typedef struct pointer pList;

// List constructor
void new_list(pList*);

// Checks if list is empty
int is_empty(pList);

// Checks if list has a single element
int is_unitary(pList);

// Returns the number of elements in the list
int length(pList);

// Displays all elements in the list
void show_list(pList);

// Manages the addition of new element in the list
void insert(pList*, int);

// Removes an element from the list
void remove(pList*, int);

// Clears the list
void clear(pList*);

#endif // ORDERED_LIST_H_INCLUDED
