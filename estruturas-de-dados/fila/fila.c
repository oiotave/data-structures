#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Queue* new_queue() {
    return NULL;
}

int is_empty(Queue* nqueue) {
    if(!nqueue)
        return 1;
    else
        return 0;
}

int is_unitary(Queue* nqueue) {
    if(nqueue->next == NULL)
        return 1;
    else
        return 0;
}

void show_queue(Queue* nqueue) {
    if(is_empty(nqueue)) {
        printf("\nFila vazia\n");
        return;
    }

    printf("\nPrimeiro elemento da fila: %d", nqueue->info);
}

void insert(Queue **pqueue, int num) {
    Queue *aux, *aux2;

    // Alocação de novo elemento
    aux = (Queue*) malloc(sizeof(Queue));

    if(!aux) {
        printf("\nErro de alocacao\n");
        return;
    }
    aux->next = NULL;
    aux->info = num;

    if(is_empty(*pqueue))
        *pqueue = aux;

    else if(is_unitary(*pqueue))
        (*pqueue)->next = aux;

    // Inserção sempre no final
    else {
        for(aux2 = *pqueue; aux2->next; aux2 = aux2->next);
        aux2->next = aux;
    }
}

int remover(Queue **pqueue) {
    Queue *aux;
    int num;

    if(is_empty(*pqueue))
        printf("\nFila vazia\n");

    else if(is_unitary(*pqueue)) {
        num = (*pqueue)->info;
        aux = *pqueue;

        *pqueue = NULL;
        free(aux);

        return num;
    }

    // Remoção sempre no início
    else {
        num = (*pqueue)->info;
        aux = *pqueue;

        *pqueue = aux->next;
        free(aux);

        return num;
    }
}

void clean(Queue **pqueue) {
    Queue *aux, *aux2;

    if(is_empty(*pqueue))
        printf("\nFila vazia\n");

    else if(is_unitary(*pqueue)) {
        aux = *pqueue;

        *pqueue = NULL;
        free(aux);
    }

    else {
        aux = *pqueue;

        while(aux) {
            aux2 = aux;
            aux = aux->next;

            free(aux2);
        }
        *pqueue = NULL;
    }
}
