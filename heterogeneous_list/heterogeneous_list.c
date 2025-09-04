#include <stdio.h>
#include <stdlib.h>
#include "heterogeneous_list.h"

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
    int *num; // Displays element if it's integer
    float *num2; // Displays element if it's float

    Node *aux;

    if(is_empty(mlist)) return;

    else {
        for(aux = mlist; aux; aux = aux->next) {
            // Displays when it's integer
            if(aux->type == 'i') {
                num = aux->info;
                printf("%d ", *num);
            }
            // Displays when it's float
            else if(aux->type == 'f') {
                num2 = aux->info;
                printf("%.2f ", *num2);
            }
        }
    }
}

void insert(Node **plist, int num1, float num2, char type) {
    int* info1;
    float* info2;
    
    Node *aux;
    aux = (Node*) malloc(sizeof(Node));
    aux->next = NULL;

    switch(type) {
        case 'i':
            info1 = (int*) malloc(sizeof(int));
            *info1 = num1;

            aux->info = info1;
            aux->type = 'i';
            break;

        case 'f':
            info2 = (float*) malloc(sizeof(float));
            *info2 = num2;

            aux->info = info2;
            aux->type = 'f';
            break;

        default:
            printf("\nInvalid option\n");
            break;
    }

    if(is_empty(*plist)) *plist = aux;

    else if(is_unitary(*plist)) (*plist)->next = aux;

    else {
        Node *temp;

        // Always adds at the end of the list
        for(temp = *plist; temp->next; temp = temp->next);
        temp->next = aux;
    }
}

void remove(Node **plist) {
    Node *aux, *temp;

    if(is_empty(*plist)) return;

    if(is_unitary(*plist)) {
        aux = *plist;
        *plist = NULL;

        free(aux);
        return;
    }
    // Always remove at the end of list
    for(temp = *plist; temp->next->next; temp = temp->next);

    aux = temp->next;
    temp->next = NULL;
    free(aux);
}

void clear(Node **plist) {
    Node *aux, // Stores elements of the list
         *aux2; // Stores element to be removed

    if(is_empty(*plist)) return;
    
    if(is_unitary(*plist)) {
        aux = *plist;

        free(aux->info);
        free(aux);

        *plist = NULL;
        return;
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
