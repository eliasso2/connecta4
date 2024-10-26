#include "Node.h"

#include <stdio.h>
#include <stdlib.h>

int calculaNumFills(char tauler[N][N]) {
    int colsPlenes = 0;
    for (int i = 0; i < N; i++) {
        if (tauler[i][0] != '*') {
            colsPlenes++;
        }
    }
    return N - colsPlenes;
}

int valor_node = 0;

Node *creaNode(Node *pare, int nivell, int numDeFill) {
    Node *p = malloc(sizeof(Node));
    //copiaTauler(p->tauler,pare->tauler);
    //int columna = transformaFillAColumna(p->tauler , numDeFill);
    //ferTirada( p->tauler , columna );
    valor_node++;
    p->valor = valor_node;
    if (nivell < 2) {
        p->n_fills = calculaNumFills(p->tauler);
        p->fills = malloc(p->n_fills * sizeof(Node *));
    } else {
        p->n_fills = 0;
        p->fills = NULL;
    }
    return p;
}

void creaNivell(Node *pare, int nivell) {
    for (int i = 0; i < pare->n_fills; i++) {
        pare->fills[i] = creaNode(pare, nivell, i);
    }
}

void recorreNivell(Node *pare, int nivell) {
    for (int i = 0; i < pare->n_fills; i++) {
        for (int j = 0; j < nivell; j++)
            printf("  ");
        printf("%i\n", (int) pare->fills[i]->valor); //valor del fill i-�ssim*/
    }
}


void crearArbre(Node *arrel) {
    creaNivell(arrel, 1);
    for (int i = 0; i < arrel->n_fills; i++) {
        creaNivell(arrel->fills[i], 2);
    }
}

void recorreArbre(Node *arrel) {
    recorreNivell(arrel, 1);
    for (int i = 0; i < arrel->n_fills; i++) {
        recorreNivell(arrel->fills[i], 2);
    }
}

void recorreArbreRecursiu(Node *p, int nivell) {
    for (int j = 0; j < nivell; j++)
        printf("  ");
    printf("%i\n", (int) p->valor);
    for (int i = 0; i < p->n_fills; i++) {
        recorreArbreRecursiu(p->fills[i], nivell + 1);
    }
}