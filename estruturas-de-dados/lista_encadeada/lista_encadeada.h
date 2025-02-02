#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

// Defini��o do tipo lista
struct tList {
    int info;
    struct tList *next;
};

typedef struct tList List;

// Construtor da lista
List* new_list();

// Checa se a lista est� vazia
int is_empty(List*);

// Checa se a lista � unit�ria
int is_unitary(List*);

// Retorna o n�mero de elementos da lista
int length(List*);

// Mostra todos os elementos da lista
void show_list(List*);

// Gerencia as inser��es na lista
void insert(List**, int, char);

void insert_start(List**, List*); // Inser��o no come�o

void insert_end(List**, List*); // Inser��o no final

void insert_gnr(List**, List*, int); // Inser��o em qualquer posi��o intermedi�ria

// Remove um elemento da lista
void remover(List**);

// Limpa a lista
void clean(List**);

#endif // LINKED_LIST_H_INCLUDED
