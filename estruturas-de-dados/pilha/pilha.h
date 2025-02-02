#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

// Definição da estrutura de pilha
struct tStack {
    int info;
    struct tStack *next;
};

typedef struct tStack Stack;

// Construtor da pilha
Stack* new_stack();

// Checa se a pilha está vazia
int is_empty(Stack*);

// Checa se a pilha é unitária
int is_unitary(Stack*);

// Adiciona novo elemento no topo da pilha
void push(Stack**, int);

// Retira elemento no topo da pilha
int pop(Stack**);

// Limpa a pilha
void clear(Stack**);

#endif // STACK_H_INCLUDED
