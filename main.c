#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Partida.h"
#include "testsPartida.h"
#include "Node.h"

#define N 8

void iniciaJoc();

int menuPrincipal() {
    int mode = 0;
    printf("     4 EN RATLLA\n    ============\n\n  (1) Un jugador\n  (2) Dos jugadors\n  (q) Sortir\n\n");
    mode = getchar();
    return mode;
}

void iniciaPartida() {
    int tauler[N][N] = {0};
    int indicadorVictoria = FALSE;
    int torn = JUGADOR1;

    do {
        dibuixaTauler(tauler);
        indicadorVictoria = ferTirada(tauler, torn);
        torn = canviaTorn(torn);
    } while (indicadorVictoria == FALSE);
}

int menuDificultat() {
    return 2;
}

void iniciaPartidaCPU(int debug) {
    Node arrel;
    inicialitzaTauler(&arrel);
    int indicadorVictoria = FALSE;
    srand(time(NULL));
    int torn = rand() % 2 + 1;
    if(torn == JUGADOR2) {
        ferTiradaCPURand(arrel.tauler, torn);
        torn = canviaTorn(torn);
    }

    dibuixaTauler(arrel.tauler);
    do{
        if (torn == JUGADOR1) indicadorVictoria = ferTirada(arrel.tauler, torn);
        else {
            creaArbre(&arrel, 0);
            indicadorVictoria = ferTiradaCPU(&arrel, torn, debug);
        }
        arrel.n_fills = calculaNumFills(arrel.tauler);
        torn = canviaTorn(torn);
    } while (indicadorVictoria == FALSE);
}

void tests() {
    testsPartida();
}

void iniciaJoc() {
    int mode = 0;
    mode = getchar();
    switch(mode) {
        case '\n':
            iniciaJoc();
            break;
        case '1':
            iniciaPartidaCPU(0);
            break;
        case 'd':
            iniciaPartidaCPU(1);
            break;
        case 't':
            tests();
            break;
        case '2':
            iniciaPartida();
            break;
        case 'q': break;
        default:
            printf("Entrada invalida. Introdueix '1', '2' o 'q'.\n");
            iniciaJoc();
    }
}

void main() {
    printf("       4 EN RATLLA\n     ============\n\n  (1) Un jugador\n  (2) Dos jugadors\n  (q) Sortir\n\n");
    iniciaJoc(0);
}