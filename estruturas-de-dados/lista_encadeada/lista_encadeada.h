#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

// Definição do tipo lista
struct tList {
    int info;
    struct tList *next;
};

typedef struct tList List;

// Construtor da lista
List* new_list();

// Checa se a lista está vazia
int is_empty(List*);

// Checa se a lista é unitária
int is_unitary(List*);

// Retorna o número de elementos da lista
int length(List*);

// Mostra todos os elementos da lista
void show_list(List*);

// Gerencia as inserções na lista
void insert(List**, int, char);

void insert_start(List**, List*); // Inserção no começo

void insert_end(List**, List*); // Inserção no final

void insert_gnr(List**, List*, int); // Inserção em qualquer posição intermediária

// Remove um elemento da lista
void remover(List**);

// Limpa a lista
void clean(List**);

#endif // LINKED_LIST_H_INCLUDED
