#include "Node.h"

#define TRUE 1
#define FALSE 0

#define JUGADOR1 1
#define JUGADOR2 2

int esColumnaPlena(int col, int tauler[N][N]);

int ferTirada(int tauler[N][N], int torn);

int esVictoria(int tauler[N][N], int col, int fila, int jugador);

char inicialitzaTauler(Node *n);

void imprimirTauler(Node *n);

void dibuixaTauler(int tauler[N][N]);

int trobaFila(int col, int tauler[N][N]);

int canviaTorn(int torn);

int esConnectaVertical(int tauler[N][N], int col, int fila, int jugador);

int esConnectaHoritzontalDreta(int tauler[N][N], int col, int fila, int jugador);

int esConnectaHoritzontalEsquerra(int tauler[N][N], int col, int fila, int jugador);

int esConnectaDiagonalSupDreta(int tauler[N][N], int col, int fila, int jugador);

int esConnectaDiagonalSupEsquerra(int tauler[N][N], int col, int fila, int jugador);

int esConnectaDiagonalInfDreta(int tauler[N][N], int col, int fila, int jugador);

int esConnectaDiagonalInfEsquerra(int tauler[N][N], int col, int fila, int jugador);