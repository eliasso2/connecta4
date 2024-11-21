#include "Node.h"

#define TRUE 1
#define FALSE 0

#define JUGADOR1 1
#define JUGADOR2 2

int esColumnaPlena(int col, int tauler[N][N]);

int ferTirada(int tauler[N][N], int torn);

int esVictoria(int tauler[N][N], int fila, int col, int jugador);

void inicialitzaTauler(Node *n);

void imprimirTauler(Node *n);

void dibuixaTauler(int tauler[N][N]);

int trobaFila(int col, int tauler[N][N]);

int canviaTorn(int torn);

int esConnectaVertical(int tauler[N][N], int fila, int col, int jugador);

int esConnectaHoritzontal(int tauler[N][N], int fila, int col, int jugador);

int esConnectaHoritzontalEsquerra(int tauler[N][N], int fila, int col, int jugador);

int esConnectaDiagonalAsc(int tauler[N][N], int fila, int col, int jugador);

int esConnectaDiagonalDesc(int tauler[N][N], int fila, int col, int jugador);

int esConnectaDiagonalInfDreta(int tauler[N][N], int fila, int col, int jugador);

int esConnectaDiagonalInfEsquerra(int tauler[N][N], int fila, int col, int jugador);