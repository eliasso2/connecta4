#include <stdio.h>
#include <stdlib.h>

// home/dev/elias/connecta4


#include <stdio.h>
#include <stdlib.h>

#define N 8

typedef struct node {
    struct node **fills;
    int n_fills; //tamany de l�array din�mic
    char tauler[N][N];
    double valor;
} Node;

int valor_node = 0;


void ferTirada(char tauler[N][N], int col, int comptadorJugador) {
    //1-Determinar la fila per gravetat
    for (int i = 0; i < N; i++) {
        if (i == 0 && i + 1 == !0) {
            tauler[i][col] = (comptadorJugador % 2) + 1;
        }
    }
    //2-posar la fitxa a la [fila][col] del tauler
}

void tornHuma() {
    int col;
    int comptadorJugador;
    char tauler[N][N];
    printf("TornHuma\n");
    scanf("%i", col);
    //ferTirada(col, comptadorJugador)
}

int calculaNumFills(char tauler[N][N]) {
    return N; //Modifiqueu per retornar el um. correcte
}

Node *creaNode(Node *pare, int nivell, int numDeFill) {
    Node *p = malloc(sizeof(Node));
    //copiaTauler(p->tauler,pare->tauler);
    //int columna = transformaFillAColumna(p->tauler , numDeFill);
    //ferTirada( p->tauler , columna );
    valor_node++;
    p->valor = valor_node;
    if (nivell < 2) {
        p->n_fills = calculaNumFills(p->tauler);
        p->fills = malloc(p->n_fills * sizeof(Node *));
    } else {
        p->n_fills = 0;
        p->fills = NULL;
    }
    return p;
}

//Quan creem un nivell, suposem que el node pare
//ja t� l'array de fills creat i el tauler actualitzat
void creaNivell(Node *pare, int nivell) {
    for (int i = 0; i < pare->n_fills; i++) {
        pare->fills[i] = creaNode(pare, nivell, i);
    }
}

void recorreNivell(Node *pare, int nivell) {
    for (int i = 0; i < pare->n_fills; i++) {
        for (int j = 0; j < nivell; j++)
            printf("  ");
        printf("%i\n", (int) pare->fills[i]->valor); //valor del fill i-�ssim*/
    }
}


void crearArbre(Node *arrel) {
    creaNivell(arrel, 1);
    for (int i = 0; i < arrel->n_fills; i++) {
        creaNivell(arrel->fills[i], 2);
    }
}

void recorreArbre(Node *arrel) {
    recorreNivell(arrel, 1);
    for (int i = 0; i < arrel->n_fills; i++) {
        recorreNivell(arrel->fills[i], 2);
    }
}

void recorreArbreRecursiu(Node *p, int nivell) {
    for (int j = 0; j < nivell; j++)
        printf("  ");
    printf("%i\n", (int) p->valor);
    for (int i = 0; i < p->n_fills; i++) {
        recorreArbreRecursiu(p->fills[i], nivell + 1);
    }
}

void main(void) {
    //Pas 1: Crear el node arrel
    //Pas 2: Crear l'arbre a partir de l'arrel

    //Node amb malloc
    int comptadorJugador = 1;
    Node *arrel = malloc(sizeof(Node));
    arrel->fills = malloc(N * sizeof(Node *));
    arrel->n_fills = N;
    arrel->valor = 0;

    crearArbre(arrel);
    //recorreArbreRecursiu(arrel,0);
    tornHuma();
    //alternativa amb Node sense malloc
    /*Node arrel;
    arrel.fills = malloc(N * sizeof(Node *));
    arrel.n_fills=N;
    arrel.valor=0;

    crearArbre(&arrel);
    recorreArbreRecursiu(&arrel,0);*/
}
