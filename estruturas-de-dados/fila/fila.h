#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

// Definição do tipo fila
struct tQueue {
    int info;
    struct tQueue *next;
};

typedef struct tQueue Queue;

// Construtor da fila
Queue* new_queue();

// Checa se a fila está vazia
int is_empty(Queue*);

// Checa se a fila é unitária
int is_unitary(Queue*);

// Mostra o primeiro elemento da fila
void show_queue(Queue*);

// Insere novo elemento na fila
void insert(Queue**, int);

// Remove um elemento da fila
int remover(Queue**);

// Limpa a fila
void clean(Queue**);

#endif // FILA_H_INCLUDED
