#include "testsPartida.h"
#include <stdio.h>

#include "Node.h"
#include "Partida.h"

#define N_TEST 8

int testsPartida() {
    return test_comprovaColumnaPlena() && test_trobaFila();
}

int test_comprovaColumnaPlena() {
    printf("Starting test - comprovaColumna\n");
    int tauler[N_TEST][N_TEST] = {0};

    // Test case 1: Column is empty
    if (esColumnaPlena(0, tauler) == 0) {
        printf("Test case 1 passed\n");
    } else {
        printf("Test case 1 failed\n");
        return 1;
    }

    // Test case 2: Column is not empty
    tauler[0][0] = 1;
    if (esColumnaPlena(0, tauler) == 1) {
        printf("Test case 2 passed\n");
    } else {
        printf("Test case 2 failed\n");
        return 1;
    }

    printf("TEST - comprovaColumna PASSED\n");
}

int test_trobaFila() {
    printf("Starting test - trobaFila\n");
    int tauler[N_TEST][N_TEST] = {0};

    if (trobaFila(0, tauler) == 7) {
        printf("Test case 1 passed\n");
    } else {
        printf("Test case 1 failed\n");
        return 1;
    }

    tauler[7][0] = 1;
    if (trobaFila(0, tauler) == 6) {
        printf("Test case 2 passed\n");
    } else {
        printf("Test case 2 failed\n");
        return 1;
    }

    tauler[6][0] = 2;
    if (trobaFila(0, tauler) == 5) {
        printf("Test case 3 passed\n");
    } else {
        printf("Test case 3 failed\n");
        return 1;
    }

    tauler[5][0] = 2;
    if (trobaFila(0, tauler) == 4) {
        printf("Test case 4 passed\n");
    } else {
        printf("Test case 4 failed\n");
        return 1;
    }

    tauler[4][0] = 1;
    if (trobaFila(0, tauler) == 3) {
        printf("Test case 5 passed\n");
    } else {
        printf("Test case 5 failed\n");
        return 1;
    }

    tauler[3][0] = 1;
    if (trobaFila(0, tauler) == 2) {
        printf("Test case 6 passed\n");
    } else {
        printf("Test case 6 failed\n");
        return 1;
    }

    tauler[2][0] = 2;
    if (trobaFila(0, tauler) == 1) {
        printf("Test case 7 passed\n");
    } else {
        printf("Test case 7 failed\n");
        return 1;
    }

    tauler[1][0] = 1;
    if (trobaFila(0, tauler) == 0) {
        printf("Test case 8 passed\n");
    } else {
        printf("Test case 8 failed\n");
        return 1;
    }

    // Columna plena no pot passar (funció comprovaColumnaPlena)

    printf("TEST - trobaFila PASSED\n");
    return 0;
}
