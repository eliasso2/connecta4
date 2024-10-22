#include <stdio.h>
#include <stdlib.h>

// home/dev/elias/connecta4


#include <stdio.h>
#include <stdlib.h>

#define N 8

typedef struct node {
    struct node **fills;
    int n_fills; //tamany de l'array dinàmic
    char tauler[N][N];
    double valor;
} Node;

int valor_node = 0;

int calculaNumFills(char tauler[N][N]) {
    int colsPlenes = 0;
    for (int i = 0; i < N; i++) {
        if (tauler[i][0] != '*') {
            colsPlenes++;
        }
    } return N - colsPlenes;
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

Node *ferTirada(Node *n, int col, int comptadorTorn) {
    for (int i = 0; i < N; i++) {
        if (n->tauler[0][col] ==! 0) {
            printf("\nLa columna està plena!\n");
            break;
        }
        if (n->tauler[i][col] == 0 && n->tauler[i + 1][col] == !0) {//comprovar columnes i files
            n->tauler[i][col] = (comptadorTorn % 2) + 1;
            break;
        }
    }
    return creaNode(n, 2, calculaNumFills(&n->tauler));
}

//Quan creem un nivell, suposem que el node pare
//ja t� l'array de fills creat i el tauler actualitzat
void creaNivell(Node *pare, int nivell) {
    for (int i = 0; i < pare->n_fills; i++) {
        pare->fills[i] = creaNode(pare, nivell, i);
    }
}

/*void tornHuma(Node *n, int comptadorTorn) {
    int col;
    printf("TornHuma\n");
    scanf("%i", col);
    ferTirada(n->tauler, col, comptadorTorn);
}*/

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

int checkVictoria(Node *n) {//es podria passar la tirada cada torn i comprovar que la tirada no guanyés en comptes de comprovar tot el tauler cada torn
                            //cal comprovar que les columnes i les files estiguin bé però la idea és aquesta
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(n->tauler[i][j]==!0) {
                int  candidat=n->tauler[i][j];
                if(n->tauler[i+1][j]==candidat) {//comprovació horitzontal
                    if(n->tauler[i+2][j]==candidat) {
                        if(n->tauler[i+3][j]==candidat) {
                            if(n->tauler[i+4][j]==candidat) {
                                return 1;
                            }
                        }
                    }
                } else if(n->tauler[i][j-1]==candidat) {//comprovació vertical
                    if(n->tauler[i][j-2]==candidat) {
                        if(n->tauler[i][j-3]==candidat) {
                            if(n->tauler[i][j-4]==candidat) {
                                return 1;
                            }
                        }
                    }
                } else if(n->tauler[i-1][j-1]==candidat) {
                    if(n->tauler[i-2][j-2]==candidat) {
                        if(n->tauler[i-3][j-3]==candidat) {
                            if(n->tauler[i-4][j-4]==candidat) {
                                return 1;
                            }
                        }
                    }
                }
            }else return 0;
        }
    }
}

char inicialitzaTauler(Node *n) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            n->tauler[i][j] = 0;
        }
    }
}


void imprimirTauler(Node *n) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf(" %i ", n->tauler[i][j]);
        } printf("\n");
    }
}

void main(void) {
    //Node amb malloc
    int col = 0;
    int comptadorTorn = 0;
    Node *arrel = malloc(sizeof(Node));
    arrel->fills = malloc(N * sizeof(Node *));
    arrel->n_fills = N;
    arrel->valor = 0;

    inicialitzaTauler(&arrel);

    crearArbre(arrel);
    //recorreArbreRecursiu(arrel,0);
    imprimirTauler(&arrel);
    //tornHuma();
    //alternativa amb Node sense malloc
    /*Node arrel;
    arrel.fills = malloc(N * sizeof(Node *));
    arrel.n_fills=N;
    arrel.valor=0;

    crearArbre(&arrel);
    recorreArbreRecursiu(&arrel,0);*/
    do{
        //tornHuma(arrel, comptadorTorn);
        printf("És el torn del jugador %i\nIntroduïu columna per continuar\n",comptadorTorn % 2 + 1);
        scanf("%i", &col);
        arrel = ferTirada(arrel, col, comptadorTorn);
        imprimirTauler(ferTirada(arrel, col, comptadorTorn));
        comptadorTorn++;
    } while(checkVictoria(&arrel) ==! 1);
}
