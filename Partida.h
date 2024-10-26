#include "Node.h"

#define JUGADOR1 1
#define JUGADOR2 2

int esColumnaPlena(int col, int tauler[N][N]);

void ferTirada(int tauler[N][N], int torn);

int checkVictoria(Node *n);

char inicialitzaTauler(Node *n);

void imprimirTauler(Node *n);

void dibuixaTauler(int tauler[N][N]);

int trobaFila(int col, int tauler[N][N]);

int canviaTorn(int torn);
