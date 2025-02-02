#ifndef ARVORE_BINARIA_H_INCLUDED
#define ARVORE_BINARIA_H_INCLUDED

// Definicao do tipo arvore binaria
struct tTree {
    int info;
    struct tTree *left;
    struct tTree *right;
};

typedef struct tTree Tree;

// Construtor de árvore
Tree* new_tree();

// Insere novo nó de forma ordenada (chave de ordenação: valor do inteiro)
Tree* insert_node(Tree*, int);

// Limpa àrvore
Tree* clean(Tree*);

// Mostra todos os elementos da árvore
void show_tree(Tree*, int);

// Conta o número total de nós da árvore
int nodes_number(Tree*);

// Calcula a profundidade da árvore
int height(Tree*);

// Balanceia a árvore (árvore binária AVL)
Tree* balance(Tree*);

Tree* left_rotation(Tree*); // Rotação à direita

Tree* right_rotation(Tree*); // Rotação à esquerda

// Calcula o fato de balanceamento do nó
int factor(Tree*);


#endif // ARVORE_BINARIA_H_INCLUDED
