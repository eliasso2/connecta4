#include "Partida.h"
#include "testsPartida.h"

#define N 8

void iniciaPartida() {
    int tauler[N][N] = {0};

    int torn = JUGADOR1;

    do {
        dibuixaTauler(tauler);
        ferTirada(tauler, torn);
        torn = canviaTorn(torn);
    } while (1);
}

void tests() {
    testsPartida();
}

void main(void) {
    iniciaPartida();
    //tests();
}
