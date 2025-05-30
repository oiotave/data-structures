#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

List* new_list() {
    return NULL;
}

int is_empty(List* nlist) {
    if(!nlist) return 1;
    else return 0;
}

int is_unitary(List* nlist) {
    if(nlist->next == NULL) return 1;
    else return 0;
}

int length(List* nlist) {
    int len = 0;

    while(nlist) {
        len = len + 1;
        nlist = nlist->next;
    }
    return len;
}

void show_list(List* nlist) {
    if(is_empty(nlist)) {
        printf("\nLista vazia\n");
        return;
    }

    while(nlist) {
        printf("%d ", nlist->info);
        nlist = nlist->next;
    }
    printf("\n");
}

// 'opt' stores place of insertion: Beggining (1) | End (2) | Middle (3)
void insert(List **plist, int num, int opt) {
    int opt2; // If insertion is done in the middle, stores the position of insertion
    List* aux;

    aux = (List*) malloc(sizeof(List));
    if(!aux) {
        printf("\nAllocation error\n");
        return;
    }
    aux->info = num;

    if(opt == 3) {
        printf("\nType the position: ");
        scanf("%d", &opt2);

        if(opt2 > length(*plist) || opt2 <= 0) {
            printf("\nInvalid position\n");
            return;
        }
    }
    // Redirects to proper functions
    switch(opt) {
        case 1:
            insert_start(plist, aux);
            break;

        case 2:
            insert_end(plist, aux);
            break;

        case 3:
            insert_gnr(plist, aux, opt2);
            break;

        default:
            printf("\nOpcao indisponivel\n");
            break;
    }
}

void insert_start(List** plist, List* aux) {
    aux->next = *plist;
    *plist = aux;
}

void insert_end(List **plist, List *aux) {
    aux->next = NULL;

    if(is_empty(*plist)) *plist = aux;

    else if(is_unitary(*plist)) (*plist)->next = aux;

    else {
        List *temp;
        for(temp = *plist; temp->next; temp = temp->next);
        temp->next = aux;
    }
}

void insert_gnr(List **plist, List *aux, int pst) {
    int pst_ctr = 1; // Guarda n�mero de posi��es percorridas na lista at� o momento

    if(is_unitary(*plist)) insert_start(plist, aux);

    else {
        List *temp = *plist;

        // Percorre todos os elementos at� a posi��o de inser��o desejada
        while(1) {
            if(pst_ctr == pst - 1) // Para na posi��o imediatamente anterior � desejada
                break;

            pst_ctr = pst_ctr + 1;
            temp = temp->next;
        }
        aux->next = temp->next;
        temp->next = aux;
    }
}

void remove(List **plist) {
    int opt, // Stores the position of the element to be removed
        opt_ctr = 1; // Stores the number of nodes visited

    List *aux;

    if(is_empty(*plist)) return;

    else if(is_unitary(*plist)) {
        aux = *plist;

        *plist = NULL;
        free(aux);
    }

    else {
        List *temp = *plist;

        printf("\nType the position to be deleted: ");
        scanf("%d", &opt);

        if(opt > length(*plist) || opt <= 0) {
            printf("\Invalid position\n");
            return;
        }

        // First element removal
        if(opt == 1) {
            aux = *plist;
            *plist = aux->next;
            free(aux);

            return;
        }
        // Visits all elements until removal position
        while(1) {
            if(opt_ctr == opt - 1) break; // Stops exactly one position before removal position

            opt_ctr = opt_ctr + 1;
            temp = temp->next;
        }
        aux = temp->next;
        temp->next = temp->next->next;
        free(aux);
    }
}

void clear(List **plist) {
    List *aux, // Stores next element to be removed
         *aux2; // Stores current element to be removed

    if(is_empty(*plist)) printf("\nEmpty list\n");

    else if(is_unitary(*plist)) {
        aux = *plist;
        *plist = NULL;
        free(aux);
    }
    else {
        aux = *plist;

        while(aux) {
            aux2 = aux;
            aux = aux->next;
            free(aux2);
        }
        *plist = NULL;
    }
}
