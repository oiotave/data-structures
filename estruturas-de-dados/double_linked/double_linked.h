#ifndef DOUBLE_LINKED_H_INCLUDED
#define DOUBLE_LINKED_H_INCLUDED

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
List* new_list(pList*);

// Checks if list is empty
int is_empty(pList);

// Checks if list contains a single element
int is_unitary(pList);

// Shows the number os elements in the list
int length(pList);

// Shows all elements in the list
void show_list(pList);

// Manages different insertions in list
void insert(pList*, int, int);

void insert_start(pList*, List*); // Insertion in the beggining

void insert_end(pList*, List*); // Insertion in the end

void insert_gnr(pList*, List*, int); // Insertion in generic position

// Removes an element from list
void remove(pList*);

// Clears the list
void clear(pList*);

#endif // DOUBLE_LINKED_H_INCLUDED
