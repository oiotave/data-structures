#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

struct tQueue {
    int info;
    struct tQueue *next;
};

typedef struct tQueue Queue;

// Queue constructor
Queue* new_queue();

// Checks if queue is empty
int is_empty(Queue*);

// Checks if queue contains only one element
int is_unitary(Queue*);

// Shows first element in the Queue
void show_queue(Queue*);

// Adds new elements in the queue
void insert(Queue**, int);

// Removes an element from the queue
int remove(Queue**);

// Clears the queue
void clear(Queue**);

#endif // QUEUE_H_INCLUDED