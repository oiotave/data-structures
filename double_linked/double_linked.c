#include <stdio.h>
#include <stdlib.h>
#include "double_linked.h"

void new_list(pList *plist) {
    plist->str = NULL;
    plist->end = NULL;
}

int is_empty(pList l) {
    if(l.str == NULL && l.end == NULL) return 1;
    else return 0;
}

int is_unitary(pList l) {
    if(l.str != NULL && l.str == l.end) return 1;
    else return 0;
}

int length(pList l) {
    int num = 0; // Stores number of elements
    List *aux;

    if(is_empty(l)) return 0;

    if(is_unitary(l)) return 1;

    // Runs through the list
    for(aux = l.str; aux != l.end; aux = aux->next)
        num = num + 1;

    num = num + 1;
    return num;
}

void show_list(pList l) {
    List *aux;

    if(is_empty(l)) return;

    if(is_unitary(l)) {
        printf("%d", (l.str)->info);
        return;
    }
    for(aux = l.str; aux != l.end; aux = aux->next)
        printf("%d ", aux->info);

    printf("%d", aux->info);
}

// 'opt' stores place of insertion: Beggining (1) | End (2) | Middle (3)
void insert(pList *plist, int num, int opt) {
    int opt2; // If insertion is done in the middle, stores the position of insertion
    List *aux;

    aux = (List*) malloc(sizeof(List));
    if(!aux) {
        printf("\nAllocation error\n");
        return;
    }
    aux->info = num;

    if(opt == 3) {
        printf("\nType position of insertion: ");
        scanf("%d", &opt2);

        if(opt2 > length(*plist) || opt2 <= 0) {
            printf("\nInvalid postion\n");
            return;
        }
    }
    switch(opt) {
        case 1:
            insert_str(plist, aux);
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

void insert_str(pList *plist, List *aux) {
    aux->prev = NULL;

    if(is_empty(*plist)) {
        aux->next = NULL;
        plist->str = aux;
        plist->end = aux;
    }
    else {
        aux->next = plist->str;
        aux->next->prev = aux;
        plist->str = aux;
    }
}

void insert_end(pList *plist, List *aux) {
    aux->next = NULL;

    if(is_empty(*plist)) {
        aux->prev = NULL;
        plist->end = aux;
        plist->str = aux;
    }
    else {
        aux->prev = plist->end;
        aux->prev->next = aux;

        plist->end = aux;
    }
}

void insert_gnr(pList *plist, List *aux, int pst) {
    List* temp = plist->str;
    int pst_ctr = 1; // Stores number os elements visited

    if(is_unitary(*plist)) insert_str(plist, aux);

    else {
        while(1) {
            if(pst_ctr == pst) // Stop exactly on the insertion position
                break;

            temp = temp->next;
            pst_ctr = pst_ctr + 1;
        }
        aux->prev = temp->prev;
        aux->next = temp;

        aux->prev->next = aux;
        aux->next->prev = aux;
    }
}

void remove(pList *plist) {
    List *aux, // Points to the element to be removed
         *temp; // Used to runs through the list

    int opt, // Stores removal position
        opt_ctr = 1; // Stores number of elements visited

    if(is_empty(*plist)) return;

    else if(is_unitary(*plist)) {
        aux = plist->str;

        plist->str = NULL;
        plist->end = NULL;
        free(aux);
    }
    else {
        printf("\nType removal position: ");
        scanf("%d", &opt);

        if(opt > length(*plist) || opt <= 0) {
            printf("\nInvalid position\n");
            return;
        }
        // Removal of the first element
        if(opt == 1) {
            aux = plist->str;

            aux->next->prev = NULL;
            plist->str = aux->next;

            free(aux);
            return;
        }
        // Removal of the last element
        if(opt == length(*plist)) {
            aux = plist->end;

            aux->prev->next = NULL;
            plist->end = aux->prev;

            free(aux);
            return;
        }

        temp = plist->str;
        while(1) {
            if(opt_ctr == opt) break;

            temp = temp->next;
            opt_ctr = opt_ctr + 1;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

void clear(pList *plist) {
    List *aux, *aux2;

    if(is_empty(*plist)) return;

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
