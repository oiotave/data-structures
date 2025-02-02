#include <stdio.h>
#include <stdlib.h>
#include "lista_ordenada.h"

void new_list(pList *plist) {
    plist->str = NULL;
    plist->end = NULL;
}

int is_empty(pList l) {
    if(l.str == NULL && l.end == NULL)
        return 1;
    else
        return 0;
}

int is_unitary(pList l) {
    if(l.str != NULL && l.str == l.end)
        return 1;
    else
        return 0;
}

int length(pList l) {
    int num = 0;
    List *aux;

    if(is_empty(l))
        return 0;

    if(is_unitary(l))
        return 1;

    for(aux = l.str; aux != l.end; aux = aux->next)
        num = num + 1;

    num = num + 1;

    return num;
}

void show_list(pList l) {
    List *aux;

    if(is_empty(l)) {
        printf("\nLista vazia\n");
        return;
    }

    if(is_unitary(l)) {
        printf("\nLista: %d", (l.str)->info);
        return;
    }

    else {
        printf("\nLista:");
        for(aux = l.end; aux != l.str; aux = aux->prev)
            printf(" %d", aux->info);

        printf(" %d", aux->info);
    }
}

void insert(pList *plist, int num) {
    List *aux, *temp;

    // Alocacao de novo elemento da lista
    aux = (List*) malloc(sizeof(List));
    if(!aux) {
        printf("\nErro na alocacao\n");
        return;
    }

    aux->info = num;

    // Inser��o para lista vazia
    if(is_empty(*plist)) {
        aux->prev = NULL;
        aux->next = NULL;

        plist->str = aux;
        plist->end = aux;
    }

    // Inser��o para lista unit�ria
    else if(is_unitary(*plist)) {
        // Se o novo elemento for maior, insere ao final
        if(aux->info >= plist->str->info) {
            aux->next = NULL;
            aux->prev = plist->end;
            aux->prev->next = aux;
            plist->end = aux;
        }

        // Se for menor, insere ao come�o
        else {
            aux->prev = NULL;
            aux->next = plist->str;
            aux->next->prev = aux;
            plist->str = aux;
        }
    }

    // Inser��o ao final da lista, quando novo elemento for o maior
    else if(aux->info > plist->end->info) {
        aux->next = NULL;
        aux->prev = plist->end;
        aux->prev->next = aux;
        plist->end = aux;
    }

    // Inser��o ao come�o da lista, quando novo elemento for o menor
    else if(aux->info < plist->str->info) {
        aux->prev = NULL;
        aux->next = plist->str;
        aux->next->prev = aux;
        plist->str = aux;
    }

    else {
        // Percorre a lista at� achar a posi��o de inser��o
        for(temp = plist->str; temp->info < aux->info; temp = temp->next);

        aux->next = temp;
        aux->prev = temp->prev;

        aux->prev->next = aux;
        aux->next->prev = aux;
    }
}

void remover(pList *plist) {
    List *aux, // Guarda o elemento a ser exclu�do
         *temp;

    int opt, // Guarda a posicao de remocao
        opt_ctr = 1; // Armazena todos os elementos visitados

    if(is_empty(*plist))
        printf("\nLista vazia\n");

    else if(is_unitary(*plist)) {
        aux = plist->str;

        plist->str = NULL;
        plist->end = NULL;

        free(aux);
    }

    else {
        printf("\nDigite a posicao de remocao: ");
        scanf("%d", &opt);

        if(opt > length(*plist) || opt <= 0) {
            printf("\nPosicao indisponivel\n");
            return;
        }

        // Caso para remo��o do primeiro elemento
        if(opt == 1) {
            aux = plist->str;

            aux->next->prev = NULL;
            plist->str = aux->next;

            free(aux);
            return;
        }

        // Caso para remo��o do �ltimo elemento
        if(opt == length(*plist)) {
            aux = plist->end;

            aux->prev->next = NULL;
            plist->end = aux->prev;

            free(aux);
            return;
        }

        temp = plist->str;
        while(1) {

            if(opt_ctr == opt) // Para exatamento na posi��o de remo��o
                break;

            temp = temp->next;
            opt_ctr = opt_ctr + 1;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        free(temp);
    }
}

void clean(pList *plist) {
    List *aux, *aux2;

    if(is_empty(*plist)) {
        printf("\nLista vazia\n");
        return;
    }

    if(is_unitary(*plist)) {
        aux = plist->str;

        plist->str = NULL;
        plist->end = NULL;

        free(aux);
        return;
    }

    aux = plist->str;
    while(aux) {
        aux2 = aux;
        aux = aux->next;

        free(aux2);
    }
    plist->str = NULL;
    plist->end = NULL;
}
