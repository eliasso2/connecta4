#pragma once

#define N 8

typedef struct node {
    struct node **fills;
    int n_fills; //tamany de l'array dinàmic
    int tauler[N][N];
    double valor;
} Node;

int calculaNumFills(char tauler[N][N]);

Node *creaNode(Node *pare, int nivell, int numDeFill);

void creaNivell(Node *pare, int nivell);

void recorreNivell(Node *pare, int nivell);

void crearArbre(Node *arrel);

void recorreArbre(Node *arrel);

void recorreArbreRecursiu(Node *p, int nivell);