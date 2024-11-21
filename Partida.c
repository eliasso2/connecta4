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
    printf("\nIntrodueix la columna on vols fer la tirada\n");
    scanf("%i", &col);
    return col;
}

int canviaTorn(int torn) {
    return (torn == JUGADOR1) ? JUGADOR2 : JUGADOR1;
}

int ferTirada(int tauler[N][N], int torn) {
    int col = demanaTirada();

    while (col < 0 || col >= N || esColumnaPlena(col, tauler)) {
        printf("ERROR: Columna invàlida o plena\n");
        col = demanaTirada();
    }

    int fila = trobaFila(col, tauler);
    tauler[fila][col] = torn;
    dibuixaTauler(tauler);
    if(esVictoria(tauler, fila, col, torn)) {
        printf("\nVictoria del jugador %i!\n", torn);
        return TRUE;
    }
    return FALSE;
}

int esConnectaVertical(int tauler[N][N], int fila, int col, int jugador) {
    for (int i = 1; i < 4; i++) {
        if (fila + i >= N || tauler[fila + i][col] != jugador) {
            return FALSE;
        }
    }
    return TRUE;
}

int trobaLimitHoritzontal(int tauler[N][N], int fila, int col, int torn) {
    int i = 0;
    while (col - i >= 0) {
        i++;
        if (tauler[fila][col - i] != torn) break;
    } return col - i + 1;
}

int esConnectaHoritzontal(int tauler[N][N], int fila, int col, int jugador) {
    col = trobaLimitHoritzontal(tauler, fila, col, jugador);
    for(int i = 1; i < 4; i++) {
        if(col + i >= N || tauler[fila][col + i] != jugador) {
            return FALSE;
        }
    }
    return TRUE;
}

int esConnectaHoritzontalEsquerra(int tauler[N][N], int fila, int col, int jugador) {
    for(int i = 1; i < 4; i++) {
        if(col - i < 0 || tauler[fila][col - i] != jugador) {
            return FALSE;
        }
    }
    return TRUE;
}

int trobaLimitDiagonalAscendent(int tauler[N][N], int fila, int col, int torn) {
    int i = 0;
    while (col - i >= 0 && fila + i < N) {
        if (tauler[fila + i][col - i] != torn) break;
        i++;
    } return col - i + 1;
}

int esConnectaDiagonalAsc(int tauler[N][N], int fila, int col, int jugador) {
    col = trobaLimitDiagonalAscendent(tauler, fila, col, jugador);
    fila = trobaFila(col, tauler) + 1;
    for(int i = 1; i < 4; i++) {
        if(col + i >= N || fila - i < 0 || tauler[fila - i][col + i] != jugador) {
            return FALSE;
        }
    }
    return TRUE;
}

int trobaLimitDiagonalDescendent(int tauler[N][N], int fila, int col, int torn) {
    int i = 1;
    while (col + i < N && fila + i < N) {
        if (tauler[fila + i][col + i] != torn) break;
        i++;
    } return col + i - 1;
}

int esConnectaDiagonalDesc(int tauler[N][N], int fila, int col, int jugador) {
    col = trobaLimitDiagonalDescendent(tauler, fila, col, jugador);
    fila = trobaFila(col, tauler) + 1;
    for(int i = 1; i < 4; i++) {
        if(col - i < 0 || fila - i < 0 || tauler[fila - i][col - i] != jugador) {
            return FALSE;
        }
    }
    return TRUE;
}

int esConnectaDiagonalInfDreta(int tauler[N][N], int fila, int col, int jugador) {
    for(int i = 1; i < 4; i++) {
        if(col + i >= N || fila + i >= N || tauler[fila + i][col + i] != jugador) {
            return FALSE;
        }
    }
    return TRUE;
}

int esConnectaDiagonalInfEsquerra(int tauler[N][N], int fila, int col, int jugador) {
    for(int i = 1; i < 4; i++) {
        if(col - i < 0 || fila + i >= N || tauler[fila + i][col - i] != jugador) {
            return FALSE;
        }
    }
    return TRUE;
}

int esVictoria(int tauler[N][N], int fila, int col, int jugador) {
    if (esConnectaVertical(tauler, fila, col, jugador) ||
        esConnectaHoritzontal(tauler, fila, col, jugador) ||
        esConnectaDiagonalAsc(tauler, fila, col, jugador) ||
        esConnectaDiagonalDesc(tauler, fila, col, jugador)) {
        return TRUE;
    }
    return FALSE;
}

void inicialitzaTauler(Node *n) {
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
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %i ", tauler[i][j]);
        }
        printf("\n");
    }
}
