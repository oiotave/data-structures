#ifndef LISTA_ENCADEADA_DUPLA_H_INCLUDED
#define LISTA_ENCADEADA_DUPLA_H_INCLUDED

// Defini��o do tipo lista duplamente encadeada
struct tList {
    struct tList *prev;
    int info;
    struct tList *next;
};

// Defini��o do ponteiro para as extremidades da lista
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

// Retorna o n�mero de elementos da lista
int length(pList);

// Mostra todos os elementos da lista
void show_list(pList);

// Gerencia os diferentes tipos de inser��o
void insert(pList*, int, int);

void insert_str(pList*, List*); // Inser��o no come�o

void insert_end(pList*, List*); // Inser��o no final

void insert_gnr(pList*, List*, int); // Inser��o em qualquer posi��o intermedi�ria

// Remove um elemento da lista
void remover(pList*);

// Limpa a lista
void clean(pList*);

#endif // LISTA_ENCADEADA_DUPLA_H_INCLUDED
