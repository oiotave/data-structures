#ifndef ARVORE_BINARIA_H_INCLUDED
#define ARVORE_BINARIA_H_INCLUDED

// Definicao do tipo arvore binaria
struct tTree {
    int info;
    struct tTree *left;
    struct tTree *right;
};

typedef struct tTree Tree;

// Construtor de �rvore
Tree* new_tree();

// Insere novo n� de forma ordenada (chave de ordena��o: valor do inteiro)
Tree* insert_node(Tree*, int);

// Limpa �rvore
Tree* clean(Tree*);

// Mostra todos os elementos da �rvore
void show_tree(Tree*, int);

// Conta o n�mero total de n�s da �rvore
int nodes_number(Tree*);

// Calcula a profundidade da �rvore
int height(Tree*);

// Balanceia a �rvore (�rvore bin�ria AVL)
Tree* balance(Tree*);

Tree* left_rotation(Tree*); // Rota��o � direita

Tree* right_rotation(Tree*); // Rota��o � esquerda

// Calcula o fato de balanceamento do n�
int factor(Tree*);

#endif // ARVORE_BINARIA_H_INCLUDED
