#ifndef LISTA_ORDENADA_H_INCLUDED
#define LISTA_ORDENADA_H_INCLUDED

// Defini��o do tipo lista
struct tList {
    struct tList *prev;
    int info;
    struct tList *next;
};

// Definicao de ponteiro para as extremidades da lista
struct pointer {
    struct tList *str;
    struct tList *end;
};

typedef struct tList List;
typedef struct pointer pList;

// Construtor da lista
void new_list(pList*);

// Checa se a lista est� vazia
int is_empty(pList);

// Checa se a lista � unit�ria
int is_unitary(pList);

// Calcula o n�mero de elementos da lista
int length(pList);

// Mostra todos os elementos da lista
void show_list(pList);

// Gerencia a inser��o ordenada
void insert(pList*, int);

// Remove um elemento da lista
void remover(pList*);

// Limpa a lista
void clean(pList*);

#endif // LISTA_ORDENADA_H_INCLUDED
