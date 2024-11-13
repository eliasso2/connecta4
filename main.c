#include "Partida.h"
#include "testsPartida.h"

#define N 8

/*void iniciaPartida() {
    int tauler[N][N] = {0};
    int torn = JUGADOR1;

    do {
        dibuixaTauler(tauler);
        ferTirada(tauler, torn);
        torn = canviaTorn(torn);
    } while (1);
}*/

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

void tests() {
    testsPartida();
}

void main() {
    iniciaPartida();
    // tests();
}