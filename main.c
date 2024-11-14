#include "Partida.h"
#include "testsPartida.h"
#include "Node.h"

#define N 8

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

void iniciaPartidaCPU() {
    Node arrel;
    inicialitzaTauler(&arrel);
    int indicadorVictoria = FALSE;
    int torn = JUGADOR1; //JUGADOR1 serà el jugador humà i JUGADOR2 serà la CPU
                         //Potser implementar alguna funció per tal que el primer torn no sempre sigui el del jugador humà?
    do{
        dibuixaTauler(arrel.tauler);
        indicadorVictoria = (torn == JUGADOR1) ? ferTirada(arrel.tauler, torn) : ferTiradaCPU(arrel.tauler, torn);
        // copiaTauler(arrel.tauler, arrel.tauler);
        arrel.n_fills = calculaNumFills(arrel.tauler);
        torn = canviaTorn(torn);
    } while (indicadorVictoria == FALSE);
}

void tests() {
    testsPartida();
}

void main() {
    // iniciaPartida();
    iniciaPartidaCPU();
    // tests();
}