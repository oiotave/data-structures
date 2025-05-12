#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

struct tStack {
    int info;
    struct tStack *next; // Pointer to the next element
};

typedef struct tStack Stack;

// Stack constructor
Stack* new_stack();

// Checks if stack is empty
int is_empty(Stack*);

// Checks if stack contains a single element
int is_unitary(Stack*);

// Adds new element to stack
void push(Stack**, int);

// Removes element at the top of the stack
int pop(Stack**);

// Clears the stack
void clear(Stack**);

#endif // STACK_H_INCLUDED
