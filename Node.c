#include "Node.h"
#include "Partida.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GENS 6

int calculaNumFills(int tauler[N][N]) {
    int colsPlenes = 0;
    for (int i = 0; i < N; i++) {
        if (tauler[0][i] != 0) {
            colsPlenes++;
        }
    }
    return N - colsPlenes;
}

int colsPlenesSuperades(int tauler[N][N], int numDeFill) {
    int colsPlenesSuperades = 0;
    for (int i = 0; i <= numDeFill; i++) {
        if(esColumnaPlena(i, tauler)) {
            colsPlenesSuperades++;
        }
    }
    return colsPlenesSuperades;
}

Node *creaNode(Node *pare, int nivell, int numDeFill) {
    Node *p = (Node *)malloc(sizeof(Node));
    copiaTauler(pare->tauler, p->tauler);
    int col = numDeFill + colsPlenesSuperades(pare->tauler, numDeFill);
    int fila = trobaFila(col, p->tauler);
    p->tauler[fila][col] = nivell % 2 + 1;
    p->valor = 0;
    for (int i = 0; i < N; i++) {
        if (nivell < GENS) {
            p->n_fills = calculaNumFills(p->tauler);
            p->fills = (Node**)malloc(p->n_fills * sizeof(Node *));
        } else {
            p->n_fills = 0;
            p->fills = NULL;
        }
    }
    return p;
}

void creaNivell(Node *pare, int nivell) {
    pare->n_fills = calculaNumFills(pare->tauler);
    if(nivell == 1) pare->fills = (Node **)malloc(pare->n_fills * sizeof(Node *));
    for (int i = 0; i < pare->n_fills; i++) {
        pare->fills[i] = creaNode(pare, nivell, i);
    }
}

void destrueixNodesDescartats(Node *pare) {
    for (int i = 0; i < pare->n_fills; i++) {
        destrueixNodesDescartats(pare->fills[i]);
    }
    for (int i = 0; i < pare->n_fills; i++) {
        if(pare->fills[i] != NULL) free(pare->fills[i]);
    }
}

void recorreNivell(Node *pare, int nivell) {
    for (int i = 0; i < pare->n_fills; i++) {
        for (int j = 0; j < nivell; j++)
            printf("  ");
        printf("%i\n", (int) pare->fills[i]->valor); //valor del fill i-èssim
    }
}

void creaArbre(Node *arrel, int nivell) {
    if (nivell < GENS) {
        nivell++;
        creaNivell(arrel, nivell);
        for (int i = 0; i < arrel->n_fills; i++) {
            creaArbre(arrel->fills[i], nivell);
        }
    }
}

void recorreArbre(Node *arrel) {
    recorreNivell(arrel, 1);
    for (int i = 0; i < arrel->n_fills; i++) {
        recorreNivell(arrel->fills[i], 2);
    }
}

void recorreArbreRecursiu(Node *p, int nivell, int *A, int *B, int *C, int *D) {
    /*static int A, B, C;
    A = 0; B = 0; C = 0;*/
    if(nivell == 0) {
        *A = -1;
        *B = -1;
        *C = -1;
        *D = -1;
    }
    if(nivell == 1) {
        *A = (*A + 1) % N;
        *B = -1;
        *C = -1;
        *D = -1;
    }
    if(nivell == 2) {
        *B = (*B + 1) % N;
        *C = -1;
        *D = -1;
    }
    if(nivell == 3) {
        *C = (*C + 1) % N;
        *D = -1;
    }
    if(nivell == 4) {
        *D = (*D + 1) % N;
    }
    for (int j = 0; j < nivell; j++)
        printf("  ");
    printf("ID: %i.%i.%i.%i nivell: %i AdM: %x valor: %i n_fills: %i\n", *A, *B, *C, *D, nivell, p, (int) p->valor, p->n_fills);
    for (int i = 0; i < p->n_fills; i++) {
        recorreArbreRecursiu(p->fills[i], nivell + 1, A, B, C, D);
    }
}

int colRand(int tauler[N][N]) {
    int col = 0;
    do {
        col = rand() % N;
    } while (esColumnaPlena(col, tauler));
    return col;
}

int ferTiradaCPURand(int tauler[N][N], int torn) {
    printf("\nTorn de la CPU:\n");
    int col = colRand(tauler);
    int fila = trobaFila(col, tauler);
    tauler[fila][col] = torn;
    return esVictoria(tauler, fila, col, torn);
}

int recuperaColumna(int taulerPare[N][N], int taulerFill[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (taulerPare[i][j] != taulerFill[i][j]) {
                return j;
            }
        }
    } printf("\nNo s'ha trobat cap diferència entre els dos taulers\n");
    return -1;
}

Node recuperaFill(Node pare) {
    for (int i = 0; i < pare.n_fills; i++) {
        if (pare.fills[i]->valor == max(pare)) {
            return *pare.fills[i];
        }
    }
}

int ferTiradaCPU(Node *arrel, int torn, int debug) {
    printf("\nTorn de la CPU:\n");
    int col = -1;
    calculSAs(arrel, 0, 0);
    miniMax(arrel, 0);
    if(debug == 1) {
        int A = -1, B = -1, C = -1, D = -1;
        recorreArbreRecursiu(arrel, 0, &A, &B, &C, &D);
    }
    col = recuperaColumna(arrel->tauler, recuperaFill(*arrel).tauler);
    int fila = trobaFila(col, arrel->tauler);
    arrel->tauler[fila][col] = torn;
    dibuixaTauler(arrel->tauler);
    printf("L'ordinador ha jugat a la columna %i\n", col);
    destrueixNodesDescartats(arrel);
    if(esVictoria(arrel->tauler, fila, col, torn)) {
        printf("\nVictoria del jugador %i!\n", torn);
        return TRUE;
    }
    return FALSE;
}

void copiaTauler(int plantilla[N][N], int pacient[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            pacient[i][j] = plantilla[i][j];
        }
    }
}

int SAVertical(int tauler[N][N], int fila, int col, int torn) {
    int comptador = 0;
    for (int i = 1; i < 3; i++) {
        if (tauler[fila + i][col] == torn) comptador++; else {
            comptador = 0;
        }
    } return comptador * (int)pow(-1, torn % 2);
}

int SAHoritzontalDreta(int tauler[N][N], int fila, int col, int torn) {
    fila = trobaFila(col, tauler);
    int comptador = 0;
    for (int j = 1; j < 5; j++) {
        if(tauler[fila][col + j] == canviaTorn(torn)) return comptador;
    }
    if (col + 3 < N) {
        int i=0;
        while(i < N) {
            if (tauler[fila][col + i] == torn) {
                comptador++;
            } i++;
        }
    } return comptador * (int)pow(-1, torn % 2);
}

int SAHoritzontalEsquerra(int tauler[N][N], int fila, int col, int torn) {
    fila = trobaFila(col, tauler);
    int comptador = 0;
    for (int j = 1; j < 5; j++) {
        if(tauler[fila][col - j] == canviaTorn(torn)) return comptador;
    }
    if (col - 3 >= 0) {
        int i =0;
        while(i < N) {
            if (tauler[fila][col - i] == torn) {
                comptador++;
            } i++;
        }
    } return comptador * (int)pow(-1, torn % 2);
}

int SADiagonalSupDreta(int tauler[N][N], int fila, int col, int torn) {
    fila = trobaFila(col, tauler);
    int comptador = 0;
    for (int j = 1; j < 5; j++) {
        if(tauler[fila - j][col + j] == canviaTorn(torn)) return comptador;
    }
    if (col + 3 < N && fila - 3 >= 0) {
        int i = 0;
        while(i < N) {
            if (tauler[fila - i][col + i] == torn) {
                comptador++;
            } i++;
        }
    } return comptador * (int)pow(-1, torn % 2);
}

int SADiagonalSupEsquerra(int tauler[N][N], int fila, int col, int torn) {
    fila = trobaFila(col, tauler);
    int comptador = 0;
    for (int j = 1; j < 5; j++) {
        if(tauler[fila - j][col - j] == canviaTorn(torn)) return comptador;
    }
    if (col - 3 >= 0 && fila - 3 >= 0) {
        int i =0;
        while(i < N) {
            if (tauler[fila - i][col - i] == torn) {
                comptador++;
            } i++;
        }
    } return comptador * (int)pow(-1, torn % 2);
}

int SADiagonalInfDreta(int tauler[N][N], int fila, int col, int torn) {
    fila = trobaFila(col, tauler);
    int comptador = 0;
    for (int j = 1; j < 5; j++) {
        if(tauler[fila + j][col + j] == canviaTorn(torn)) return comptador;
    }
    if (col + 3 < N && fila + 3 < N) {
        int i = 0;
        while(i < N) {
            if (tauler[fila + i][col + i] == torn) {
                comptador++;
            } i++;
        }
    } return comptador * (int)pow(-1, torn % 2);
}

int SADiagonalInfEsquerra(int tauler[N][N], int fila, int col, int torn) {
    fila = trobaFila(col, tauler);
    int comptador = 0;
    for (int j = 1; j < 5; j++) {
        if(tauler[fila + j][col - j] == canviaTorn(torn)) return comptador;
    }
    if (col - 3 >= 0 && fila + 3 < N) {
        int i = 0;
        while(i < N) {
            if (tauler[fila + i][col - i] == torn) {
                comptador++;
            } i++;
        }
    } return comptador * (int)pow(-1, torn % 2);
}

int min(Node arrel) {
    int vmin = arrel.fills[0]->valor;
    for (int i = 1; i < arrel.n_fills; i++) {
        if (arrel.fills[i]->valor < vmin) {
            vmin = arrel.fills[i]->valor;
        }
    } return vmin;
}

int max(Node arrel) {
    int vmax = arrel.fills[0]->valor;
    for (int i = 1; i < arrel.n_fills; i++) {
        if (arrel.fills[i]->valor > vmax) {
            vmax = arrel.fills[i]->valor;
        }
    } return vmax;
}

int sumaSAs(Node pare, Node fill, int nivell) {
    int col = recuperaColumna(pare.tauler, fill.tauler);
    int fila = trobaFila(col, pare.tauler);
    return SAVertical(pare.tauler, fila, col, (nivell + 1) % 2 + 1) +
    SAHoritzontalDreta(pare.tauler, fila, col, (nivell + 1) % 2 + 1) +
    SAHoritzontalEsquerra(pare.tauler, fila, col, (nivell + 1) % 2 + 1) +
    SADiagonalSupDreta(pare.tauler, fila, col, (nivell + 1) % 2 + 1) +
    SADiagonalSupEsquerra(pare.tauler, fila, col, (nivell + 1) % 2 + 1) +
    SADiagonalInfDreta(pare.tauler, fila, col, (nivell + 1) % 2 + 1) +
    SADiagonalInfEsquerra(pare.tauler, fila, col, (nivell + 1) % 2 + 1);
}

int calculSAs(Node *arrel, int nivell, int SAs) {
    int SAsFills[arrel->n_fills];
    for (int i = 0; i < arrel->n_fills; i++) {
        SAsFills[i] = SAs;
    }
    if (nivell < GENS - 1) {
        for (int i = 0; i < arrel->n_fills; i++){
            int col = recuperaColumna(arrel->tauler, arrel->fills[i]->tauler);
            if (esVictoria(arrel->fills[i]->tauler, trobaFila(col, arrel->tauler), col, (nivell + 1) % 2 + 1)) {
                SAsFills[i] += (GENS - nivell) * 10000 * (int)pow(-1, nivell % 2);
            } else {
                SAsFills[i] += sumaSAs(*arrel, *(arrel->fills[i]), nivell);
            }
            calculSAs(arrel->fills[i], nivell + 1, SAsFills[i]);
        }
    }
    if (nivell == GENS - 1) {
        for (int i = 0; i < arrel->n_fills; i++) {
            int col = recuperaColumna(arrel->tauler, arrel->fills[i]->tauler);
            if (esVictoria(arrel->fills[i]->tauler, trobaFila(col, arrel->tauler), col, (nivell + 1) % 2 + 1)) {
                SAsFills[i] += (GENS - nivell) * 10000 * (int)pow(-1, nivell % 2);
            } else {
                SAsFills[i] += sumaSAs(*arrel, *(arrel->fills[i]), nivell);
            }
            arrel->fills[i]->valor = SAsFills[i];
        }
    } return SAs;
}

void miniMax(Node *arrel, int nivell) {
    if (nivell != GENS) {
        for (int i = 0; i < arrel->n_fills; i++) {
            miniMax(arrel->fills[i], nivell + 1);
            arrel->valor = (nivell % 2 == 0) ? max(*arrel) : min(*arrel);
        }
    }
}