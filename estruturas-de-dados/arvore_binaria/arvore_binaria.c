#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

Tree* new_tree() {
    return NULL;
}

Tree* insert_node(Tree *ptree, int num) {
    Tree* aux;

    // Verifica se o n� atual � folha
    if(!ptree) {
        // Aloca��o de novo n� folha
        aux = (Tree*) malloc(sizeof(Tree*));

        if(!aux) {
            printf("\nErro de alocacao\n");
            return 0;
        }

        aux->info = num;
        aux->left = 0;
        aux->right = 0;

        return aux;
    }

    // Se n�o for, busca nos n�s filhos de acordo com a chave de ordena��o
    else {
        if(num <= ptree->info) {
            // Busca no filho � esquerda se o novo valor for menor que o n� atual
            ptree->left = insert_node(ptree->left, num);

            if(factor(ptree) > 1 || factor(ptree) < -1) // Balanceia a �rvore ap�s inser��o
                ptree = balance(ptree);
        }

        else {
            // Busca no filho � direita se o novo valor for maior que o n� atual
            ptree->right = insert_node(ptree->right, num);

            if(factor(ptree) > 1 || factor(ptree) < -1) // Balanceia a �rvore ap�s inser��o
                ptree = balance(ptree);
        }

        return ptree; // Retorna a �rvore com o novo elemento
    }
}

Tree* clean(Tree *ptree) {
    if(!ptree)
        return 0;

    else {
        ptree->left = clean(ptree->left);
        ptree->right = clean(ptree->right);

        free(ptree);

        return 0;
    }
}

// 'opt' representa o modelo de exibi��o ('1' - Prefixada | '2' - Infixada | '3' - Posfixa)
void show_tree(Tree *ptree, int opt) {
    if(!ptree)
        return;

    switch(opt) {
        // Prefixada
        case 1:
            printf("%d ", ptree->info);
            show_tree(ptree->left, 1);
            show_tree(ptree->right, 1);
            break;

        // Infixada
        case 2:
            show_tree(ptree->left, 2);
            printf("%d ", ptree->info);
            show_tree(ptree->right, 2);
            break;

        // Posfixada
        case 3:
            show_tree(ptree->left, 3);
            show_tree(ptree->right, 3);
            printf("%d ", ptree->info);
            break;

        default:
            break;
    }
}

int nodes_number(Tree *ptree) {
    int sum = 0, // Guarda o n�mero de n�s � esquerda da raiz
        sum2 = 0; // Guarda o n�mero de n�s � direita da raiz

    if(!ptree)
        return 0;

    else {
        sum = 1 + nodes_number(ptree->left);
        sum2 = 1 + nodes_number(ptree->right);

        return sum + sum2 - 1;
    }
}

int height(Tree *ptree) {
    int a, // Altura � esquerda da raiz
        b; // Altura � direita da raiz

    if(!ptree)
        return 0;

    else {
        a = height(ptree->left);
        b = height(ptree->right);

        if(a >= b)
            return a + 1;

        else
            return b + 1;
    }
}

int factor(Tree *ptree) {
    int fact;

    fact = height(ptree->left) - height(ptree->right);

    return fact;
}

Tree* balance(Tree *ptree) {
    Tree *aux;

    // Lado esquerdo desbalanceado
    if(factor(ptree) == 2) {
        if(factor(ptree->left) < 0) // Caso de rota��o dupla
            ptree->left = right_rotation(ptree->left);

        ptree = left_rotation(ptree);

        return ptree;
    }

    // Lado direito desbalanceado
    else if(factor(ptree) == -2) {
        if(factor(ptree->right) > 0) // Caso de rota��o dupla
            ptree->right = left_rotation(ptree->right);

        ptree = right_rotation(ptree);

        return ptree;

    }
}

Tree* left_rotation(Tree* ptree) {
    Tree *aux;

    aux = ptree->left;
    ptree->left = aux->right;
    aux->right = ptree;
    ptree = aux;

    return ptree;
}

Tree* right_rotation(Tree* ptree) {
    Tree *aux;

    aux = ptree->right;
    ptree->right = aux->left;
    aux->left = ptree;
    ptree = aux;

    return ptree;
}
