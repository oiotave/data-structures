#include <stdio.h>
#include <stdlib.h>
#include "lista_heterogenea.h"

Node* new_list() {
    return NULL;
}

int is_empty(Node *mlist) {
    if(!mlist) return 1;
    else return 0;
}

int is_unitary(Node *mlist) {
    if(!mlist->next) return 1;
    else return 0;
}

void show_list(Node *mlist) {
    int *num; // Caso o elemento atual seja inteiro
    float *num2; // Caso o elemento atual seja float

    Node *aux;

    if(is_empty(mlist)) printf("\nLista vazia\n");

    else {
        printf("\nLista: ");

        for(aux = mlist; aux; aux = aux->next) {
            // Mostra quando for inteiro
            if(aux->type == 'i') {
                num = aux->info;
                printf("%d ", *num);
            }
            // Mostra quando for float
            else {
                num2 = aux->info;
                printf("%.2f ", *num2);
            }
        }
    }
}

void insert(Node **plist) {
    int opt; // Armazena a opcao de escolha

    int *num;
    float *num2;

    Node *aux;
    aux = (Node*) malloc(sizeof(Node));
    aux->next = NULL;

    printf("\nDigite o tipo ('1' para int | '2' para float): ");
    scanf("%d", &opt);

    switch(opt) {
        case 1:
            num = (int*) malloc(sizeof(int));
            printf("\nDigite o numero: ");
            scanf("%d", num);

            aux->info = num;
            aux->type = 'i';
            break;

        case 2:
            num2 = (float*) malloc(sizeof(float));
            printf("\nDigite o numero: ");
            scanf("%f", num2);

            aux->info = num2;
            aux->type = 'f';
            break;

        default:
            printf("\nOpcao indisponivel\n");
            break;
    }

    if(is_empty(*plist)) *plist = aux;

    else if(is_unitary(*plist)) (*plist)->next = aux;

    else {
        Node *temp;

        // Adiciona sempre ao final da lista
        for(temp = *plist; temp->next; temp = temp->next);
        temp->next = aux;
    }
}

void remover(Node **plist) {
    Node *aux, *temp;

    if(is_empty(*plist)) {
        printf("\nLista vazia\n");
        return;
    }

    if(is_unitary(*plist)) {
        aux = *plist;
        *plist = NULL;

        free(aux);
        return;
    }
    // Remove sempre ao final da lista
    for(temp = *plist; temp->next->next; temp = temp->next);

    aux = temp->next;
    temp->next = NULL;
    free(aux);
}

void clean(Node **plist) {
    Node *aux, // Armazena os elementos da lista
         *aux2; // Guarda o elemento a ser removido

    if(is_empty(*plist)) {
        printf("\nLista vazia\n");
        return;
    }

    if(is_unitary(*plist)) {
        aux = *plist;

        free(aux->info);
        free(aux);

        *plist = NULL;
    }

    aux = *plist;
    while(aux) {
        aux2 = aux;
        aux = aux->next;

        free(aux2->info);
        free(aux2);

        *plist = NULL;
    }
}
