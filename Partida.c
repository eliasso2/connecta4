#include "Partida.h"

#include <stdio.h>

int esColumnaPlena(int col, int tauler[N][N]) {
    if (tauler[0][col] != 0) {
        return 1;
    }
    return 0;
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

void ferTirada(int tauler[N][N], int torn) {
    int col = demanaTirada();

    while (col < 0 || col >= N || esColumnaPlena(col, tauler)) {
        printf("ERROR: Columna invàlida o plena\n");
        col = demanaTirada();
    }

    int fila = trobaFila(col, tauler);
    tauler[fila][col] = torn;
}

int eskVictoria(Node *n) {
    //es podria passar la tirada cada torn i comprovar que la tirada no guanyés en comptes de comprovar tot el tauler cada torn
    //cal comprovar que les columnes i les files estiguin bé però la idea és aquesta
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (n->tauler[i][j] == !0) {
                int candidat = n->tauler[i][j];
                if (n->tauler[i + 1][j] == candidat) {
                    //comprovació horitzontal
                    if (n->tauler[i + 2][j] == candidat) {
                        if (n->tauler[i + 3][j] == candidat) {
                            if (n->tauler[i + 4][j] == candidat) {
                                return 1;
                            }
                        }
                    }
                } else if (n->tauler[i][j - 1] == candidat) {
                    //comprovació vertical
                    if (n->tauler[i][j - 2] == candidat) {
                        if (n->tauler[i][j - 3] == candidat) {
                            if (n->tauler[i][j - 4] == candidat) {
                                return 1;
                            }
                        }
                    }
                } else if (n->tauler[i - 1][j - 1] == candidat) {
                    if (n->tauler[i - 2][j - 2] == candidat) {
                        if (n->tauler[i - 3][j - 3] == candidat) {
                            if (n->tauler[i - 4][j - 4] == candidat) {
                                return 1;
                            }
                        }
                    }
                }
            } else return 0;
        }
    }
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
