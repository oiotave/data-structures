#ifndef LISTA_ENCADEADA_DUPLA_H_INCLUDED
#define LISTA_ENCADEADA_DUPLA_H_INCLUDED

// Definição do tipo lista duplamente encadeada
struct tList {
    struct tList *prev;
    int info;
    struct tList *next;
};

// Definição do ponteiro para as extremidades da lista
struct pointer {
    struct tList *str;
    struct tList *end;
};

typedef struct tList List;
typedef struct pointer pList;

// Construtor da lista
void new_list(pList*);

// Checa se a lista está vazia
int is_empty(pList);

// Checa se a lista é unitária
int is_unitary(pList);

// Retorna o número de elementos da lista
int length(pList);

// Mostra todos os elementos da lista
void show_list(pList);

// Gerencia os diferentes tipos de inserção
void insert(pList*, int, int);

void insert_str(pList*, List*); // Inserção no começo

void insert_end(pList*, List*); // Inserção no final

void insert_gnr(pList*, List*, int); // Inserção em qualquer posição intermediária

// Remove um elemento da lista
void remover(pList*);

// Limpa a lista
void clean(pList*);

#endif // LISTA_ENCADEADA_DUPLA_H_INCLUDED
