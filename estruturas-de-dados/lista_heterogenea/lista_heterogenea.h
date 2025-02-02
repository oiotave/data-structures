#ifndef LISTA_HETEROGENEA_H_INCLUDED
#define LISTA_HETEROGENEA_H_INCLUDED

// Definição da estrutura da lista
struct tNode {
    char type; // Armazena o tipo do elemento
    void *info; // Configurado para suportar tipo numéricos simples (int & float)
    struct tNode *next;
};

typedef struct tNode Node;

// Construtor da lista
Node* new_list();

// Checa se a lista está vazia
int is_empty(Node*);

// Checa se lista é unitária
int is_unitary(Node*);

// Mostra todos os elementos da lista
void show_list(Node*);

// Adiciona novo elemento int ou float
void insert(Node**);

// Remove o último elemento
void remover(Node**);

// Limpa a lista
void clean(Node**);

#endif // LISTA_HETEROGENEA_H_INCLUDED
