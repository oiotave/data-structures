#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada_dupla.h"

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
    int num = 0; // Guarda o n�mero de elementos
    List *aux;

    if(is_empty(l)) return 0;

    if(is_unitary(l)) return 1;

    // Percorre toda a lista
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

    printf("\nLista:");
    for(aux = l.str; aux != l.end; aux = aux->next)
        printf(" %d", aux->info);

    printf(" %d", aux->info);
}

// 'opt' armazena o tipo de inser��o: In�cio (1) | Final (2) | Meio (3)
void insert(pList *plist, int num, int opt) {
    int opt2; // Caso seja inser��o intermedi�ria, guarda a posi��o de inser��o desejada
    List *aux;

    // Aloca��o de mem�ria para novo elemento
    aux = (List*) malloc(sizeof(List));
    if(!aux) {
        printf("\nErro de alocacao\n");
        return;
    }
    aux->info = num;

    if(opt == 3) {
        printf("\nDigite a posicao de insercao: ");
        scanf("%d", &opt2);

        if(opt2 > length(*plist) || opt2 <= 0) {
            printf("\nPosicao indisponivel\n");
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
    int pst_ctr = 1; // Guarda a quantidade de elementos percorridos

    if(is_unitary(*plist)) insert_str(plist, aux);

    else {
        while(1) {
            if(pst_ctr == pst) // Para exatamente na posicao de inser��o
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

void remover(pList *plist) {
    List *aux, // Aponta para o bloco removido
         *temp; // Ponteiro tempor�rio usado para percorrer a lsita

    int opt, // Armazena a posi��o de remo��o
        opt_ctr = 1; // Guarda a quantidade de elementos percorridos

    if(is_empty(*plist)) printf("\nLista vazia\n");

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
        // Caso especial para remo��o do primeiro elemento
        if(opt == 1) {
            aux = plist->str;

            aux->next->prev = NULL;
            plist->str = aux->next;

            free(aux);
            return;
        }
        // Caso especial para remo��o do �ltimo elemento
        if(opt == length(*plist)) {
            aux = plist->end;

            aux->prev->next = NULL;
            plist->end = aux->prev;

            free(aux);
            return;
        }

        temp = plist->str;
        while(1) {

            if(opt_ctr == opt)
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
