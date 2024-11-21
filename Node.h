#pragma once

#define N 8

typedef struct node {
    struct node **fills;
    int n_fills; //tamany de l'array dinàmic
    int tauler[N][N];
    int valor;
} Node;

int calculaNumFills(int tauler[N][N]);

Node *creaNode(Node *pare, int nivell, int numDeFill);

void creaNivell(Node *pare, int nivell);

void creaDiversosNivells(Node *pare, int nivells);

void recorreNivell(Node *pare, int nivell);

void creaArbre(Node *arrel, int nivell);

void recorreArbre(Node *arrel);

void recorreArbreRecursiu(Node *p, int nivell, int *A, int *B, int *C, int *D);

int colRand(int tauler[N][N]);

int ferTiradaCPURand(int tauler[N][N], int torn);

int ferTiradaCPU(Node *arrel, int torn, int debug);

void copiaTauler(int plantilla[N][N], int pacient[N][N]);

void destrueixNodesDescartats(Node *pare);

int SAVertical(int tauler[N][N], int fila, int col, int torn);

int SAHoritzontalDreta(int tauler[N][N], int fila, int col, int torn);

int SAHoritzontalEsquerra(int tauler[N][N], int fila, int col, int torn);

int SADiagonalSupDreta(int tauler[N][N], int fila, int col, int torn);

int SADiagonalSupEsquerra(int tauler[N][N], int fila, int col, int torn);

int SADiagonalInfDreta(int tauler[N][N], int fila, int col, int torn);

int SADiagonalInfEsquerra(int tauler[N][N], int fila, int col, int torn);

int SAs(Node *arrel, int fila, int col, int torn);

int min(Node arrel);

int max(Node arrel);

void miniMax(Node *arrel, int nivell);

int calculSAs(Node *arrel, int nivell, int SAs);