#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

Tree* new_tree() {
    return NULL;
}

Tree* insert_node(Tree *ptree, int num) {
    Tree* aux;

    // Verifies if current node is leaf
    if(!ptree) {
        aux = (Tree*) malloc(sizeof(Tree*));

        if(!aux) {
            printf("\nAllocation error\n");
            return 0;
        }
        aux->info = num;
        aux->left = 0;
        aux->right = 0;

        return aux;
    }
    // If it's not leaf, goes to subtree according to the value of num
    else {
        if(num <= ptree->info) {
            // Goes to left subnode if num's smaller than current node
            ptree->left = insert_node(ptree->left, num);

            // Balances tree after insertion, if needed
            if(factor(ptree) > 1 || factor(ptree) < -1) ptree = balance(ptree);
        }
        else {
            // Goes to right subnode if num's greater than current node
            ptree->right = insert_node(ptree->right, num);

            // Balances tree after insertion, if needed
            if(factor(ptree) > 1 || factor(ptree) < -1) ptree = balance(ptree);
        }
        return ptree;
    }
}

Tree* clear(Tree *ptree) {
    if(!ptree) return 0;

    else {
        ptree->left = clean(ptree->left);
        ptree->right = clean(ptree->right);

        free(ptree);
        return 0;
    }
}

// 'opt' represents exhibition mode ('1' - Prefix | '2' - Infix | '3' - Postfix)
void show_tree(Tree *ptree, int opt) {
    if(!ptree) return;

    switch(opt) {
        case 1:
            printf("%d ", ptree->info);
            show_tree(ptree->left, 1);
            show_tree(ptree->right, 1);
            break;
    
        case 2:
            show_tree(ptree->left, 2);
            printf("%d ", ptree->info);
            show_tree(ptree->right, 2);
            break;

        case 3:
            show_tree(ptree->left, 3);
            show_tree(ptree->right, 3);
            printf("%d ", ptree->info);
            break;

        default: break;
    }
}

int nodes_number(Tree *ptree) {
    int sum = 0,  // Stores number of nodes from the left side
        sum2 = 0; // Stores number of nodes from the right side

    if(!ptree) return 0;

    else {
        sum = 1 + nodes_number(ptree->left);
        sum2 = 1 + nodes_number(ptree->right);
        return sum + sum2 - 1;
    }
}

int height(Tree *ptree) {
    int a, // Height from the left side
        b; // Height from the right side

    if(!ptree) return 0;

    else {
        a = height(ptree->left);
        b = height(ptree->right);

        if(a >= b) return a + 1;
        else return b + 1;
    }
}

int factor(Tree *ptree) {
    int fact;

    fact = height(ptree->left) - height(ptree->right);
    return fact;
}

Tree* balance(Tree *ptree) {
    Tree *aux;

    // Left side is unbalanced
    if(factor(ptree) == 2) {
        // If true, does a double rotation
        if(factor(ptree->left) < 0) ptree->left = right_rotation(ptree->left);

        ptree = left_rotation(ptree);
        return ptree;
    }
    // Right side is unbalanced
    else if(factor(ptree) == -2) {
        // If true, does a double rotation
        if(factor(ptree->right) > 0) ptree->right = left_rotation(ptree->right);

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
