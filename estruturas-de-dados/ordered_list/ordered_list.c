#include <stdio.h>
#include <stdlib.h>
#include "ordered_list.h"

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
    int num = 0;
    List *aux;

    if(is_empty(l))   return 0;
    if(is_unitary(l)) return 1;

    for(aux = l.str; aux != l.end; aux = aux->next)
        num = num + 1;

    num = num + 1;
    return num;
}

void show_list(pList l) {
    List *aux;

    if(is_empty(l)) return;
    
    else if(is_unitary(l)) printf("%d", (l.str)->info);
 
    else {
        for(aux = l.end; aux != l.str; aux = aux->prev)
            printf("%d ", aux->info);

        printf("%d", aux->info);
    }
}

void insert(pList *plist, int num) {
    List *aux, *temp;

    aux = (List*) malloc(sizeof(List));
    if(!aux) {
        printf("\nAllocation error\n");
        return;
    }
    aux->info = num;

    // Inserts if list is empty
    if(is_empty(*plist)) {
        aux->prev = NULL;
        aux->next = NULL;

        plist->str = aux;
        plist->end = aux;
    }
    // Inserts if list is unitary
    else if(is_unitary(*plist)) {
        // If new element is bigger, insert at the end
        if(aux->info >= plist->str->info) {
            aux->next = NULL;
            aux->prev = plist->end;
            aux->prev->next = aux;
            plist->end = aux;
        }
        // If it's smaller, insert at the beggining
        else {
            aux->prev = NULL;
            aux->next = plist->str;
            aux->next->prev = aux;
            plist->str = aux;
        }
    }
    // Inserts at the end, if new element is bigger than the last element in the list
    else if(aux->info > plist->end->info) {
        aux->next = NULL;
        aux->prev = plist->end;
        aux->prev->next = aux;
        plist->end = aux;
    }
    // Inserts at the beggining, if new element is smaller than the first element
    else if(aux->info < plist->str->info) {
        aux->prev = NULL;
        aux->next = plist->str;
        aux->next->prev = aux;
        plist->str = aux;
    }
    else {
        // Runs through the list until the insertion position
        for(temp = plist->str; temp->info < aux->info; temp = temp->next);

        aux->next = temp;
        aux->prev = temp->prev;

        aux->prev->next = aux;
        aux->next->prev = aux;
    }
}

void remove(pList *plist, int pos) {
    List *aux, // Stores the element to be removed
         *temp;

    int opt_ctr = 1; // Stores number of visited indexes

    if(is_empty(*plist)) return;

    else if(is_unitary(*plist)) {
        aux = plist->str;

        plist->str = NULL;
        plist->end = NULL;
        free(aux);
    }
    else {
        if(pos > length(*plist) || pos <= 0) {
            printf("\nInvalid position\n");
            return;
        }
        // First element removal
        if(pos == 1) {
            aux = plist->str;
            aux->next->prev = NULL;
            plist->str = aux->next;

            free(aux);
            return;
        }
        // Last element removal
        if(pos == length(*plist)) {
            aux = plist->end;
            aux->prev->next = NULL;
            plist->end = aux->prev;

            free(aux);
            return;
        }
        temp = plist->str;
        while(1) {
            // Stops exactly on the removal position
            if(opt_ctr == pos) break;
           
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
