#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

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

// 'opt' armazena o tipo de inser��o: In�cio (1) | Final (2) | Meio (3)
void insert(List **plist, int num, char opt) {
    int opt2; // Caso seja inser��o intermedi�ria, guarda a posi��o de inser��o desejada
    List* aux;

    // Aloca��o de mem�ria para novo elemento da lista
    aux = (List*) malloc(sizeof(List));
    if(!aux) {
        printf("\nErro na alocacao\n");
        return;
    }
    aux->info = num;

    if(opt == 3) {
        printf("\nDigite a posicao de posicao: ");
        scanf("%d", &opt2);

        if(opt2 > length(*plist) || opt2 <= 0) {
            printf("\nPosicao inexistente\n");
            return;
        }
    }
    // Redireciona para a inser��o adequada
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

void remover(List **plist) {
    int opt, // Guarda a posi��o do elemento que ser� removido
        opt_ctr = 1; // Conta o n�mero de elementos percorridos at� o momento

    List *aux;

    if(is_empty(*plist))
        printf("\nLista vazia\n");

    else if(is_unitary(*plist)) {
        aux = *plist;

        *plist = NULL;
        free(aux);
    }

    else {
        List *temp = *plist;

        printf("\nDigite a posicao para deletar: ");
        scanf("%d", &opt);

        if(opt > length(*plist) || opt <= 0) {
            printf("\nPosicao inexistente\n");
            return;
        }

        // Caso para quando se deseja remover o primeiro elemento
        if(opt == 1) {
            aux = *plist;
            *plist = aux->next;
            free(aux);

            return;
        }
        // Percorre todos os elementos at� a posi��o de remo��o
        while(1) {
            if(opt_ctr == opt - 1) // Para na posi��o imediante anterior � de remo��o
                break;

            opt_ctr = opt_ctr + 1;
            temp = temp->next;
        }
        aux = temp->next;
        temp->next = temp->next->next;
        free(aux);
    }
}

void clean(List **plist) {
    List *aux, // Guarda o elemento seguinte para ser removido
         *aux2; // Guarda o elemento atual � ser removido

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
