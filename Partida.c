#include "Partida.h"

#include <stdio.h>

int esColumnaPlena(int col, int tauler[N][N]) {
    if (tauler[0][col] != 0) {
        return TRUE;
    }
    return FALSE;
}

int trobaFila(int col, int tauler[N][N]) {
    for (int i = 0; i < N; i++) {
        if (tauler[i][col] != 0) {
            return (i == 0) ? N - 1 : i - 1;
        }
    }
    return N - 1;
}

int demanaTirada() {
    int col;
    printf("Introdueix la columna on vols fer la tirada\n");
    scanf("%i", &col);
    return col;
}

int canviaTorn(int torn) {
    return (torn == JUGADOR1) ? JUGADOR2 : JUGADOR1;
}


/*void ferTirada(int tauler[N][N], int torn) {
    int col = demanaTirada();

    while (col < 0 || col >= N || esColumnaPlena(col, tauler)) {
        printf("ERROR: Columna invàlida o plena\n");
        col = demanaTirada();
    }

    int fila = trobaFila(col, tauler);
    tauler[fila][col] = torn;
    esVictoria(tauler, col, fila, torn);
}*/

int ferTirada(int tauler[N][N], int torn) {
    int col = demanaTirada();

    while (col < 0 || col >= N || esColumnaPlena(col, tauler)) {
        printf("ERROR: Columna invàlida o plena\n");
        col = demanaTirada();
    }

    int fila = trobaFila(col, tauler);
    tauler[fila][col] = torn;
    return esVictoria(tauler, col, fila, torn);
}

int esConnectaVertical(int tauler[N][N], int col, int fila, int jugador) {
    for (int i = 1; i < 4; i++) {
        if (fila + i >= N || tauler[fila + i][col] != jugador) {
            return FALSE;
        }
    }
    return TRUE;
}

int esConnectaHoritzontalDreta(int tauler[N][N], int col, int fila, int jugador) {
    for(int i = 1; i < 4; i++) {
        if(col + i >= N || tauler[fila][col + i] != jugador) {
            return FALSE;
        }
    }
    return TRUE;
}

int esConnectaHoritzontalEsquerra(int tauler[N][N], int col, int fila, int jugador) {
    for(int i = 1; i < 4; i++) {
        if(col - i < 0 || tauler[fila][col - i] != jugador) {
            return FALSE;
        }
    }
    return TRUE;
}

int esConnectaDiagonalSupDreta(int tauler[N][N], int col, int fila, int jugador) {
    for(int i = 1; i < 4; i++) {
        if(col + i >= N || fila - i < 0 || tauler[fila - i][col + i] != jugador) {
            return FALSE;
        }
    }
    return TRUE;
}

int esConnectaDiagonalSupEsquerra(int tauler[N][N], int col, int fila, int jugador) {
    for(int i = 1; i < 4; i++) {
        if(col - i < 0 || fila - i < 0 || tauler[fila - i][col - i] != jugador) {
            return FALSE;
        }
    }
    return TRUE;
}

int esConnectaDiagonalInfDreta(int tauler[N][N], int col, int fila, int jugador) {
    for(int i = 1; i < 4; i++) {
        if(col + i >= N || fila + i >= N || tauler[fila + i][col + i] != jugador) {
            return FALSE;
        }
    }
    return TRUE;
}

int esConnectaDiagonalInfEsquerra(int tauler[N][N], int col, int fila, int jugador) {
    for(int i = 1; i < 4; i++) {
        if(col - i < 0 || fila + i >= N || tauler[fila + i][col - i] != jugador) {
            return FALSE;
        }
    }
    return TRUE;
}

int esVictoria(int tauler[N][N], int col, int fila, int jugador) {
    if (esConnectaVertical(tauler, col, fila, jugador) ||
        esConnectaHoritzontalDreta(tauler, col, fila, jugador) ||
        esConnectaHoritzontalEsquerra(tauler, col, fila, jugador) ||
        esConnectaDiagonalSupDreta(tauler, col, fila, jugador) ||
        esConnectaDiagonalSupEsquerra(tauler, col, fila, jugador) ||
        esConnectaDiagonalInfDreta(tauler, col, fila, jugador) ||
        esConnectaDiagonalInfEsquerra(tauler, col, fila, jugador)) {
        dibuixaTauler(tauler);
        printf("Victoria del jugador %i!\n", jugador);
        return TRUE;
    }
    return FALSE;
}

char inicialitzaTauler(Node *n) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            n->tauler[i][j] = 0;
        }
    }
}


void imprimirTauler(Node *n) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %i ", n->tauler[i][j]);
        }
        printf("\n");
    }
}

void dibuixaTauler(int tauler[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %i ", tauler[i][j]);
        }
        printf("\n");
    }
}
