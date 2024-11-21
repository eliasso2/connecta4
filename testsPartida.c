#include "testsPartida.h"
#include <stdio.h>

#include "Node.h"
#include "Partida.h"

#define N_TEST 8
#define PASSED 0
#define FAILED 1

int testsPartida() {
    test_comprovaColumnaPlena();
    test_trobaFila();
    test_esConnectaVertical();
    test_esConnectaHoritzontalDreta();
    test_esConnectaHoritzontalEsquerra();
    return PASSED;
}

int test_comprovaColumnaPlena() {
    printf("Starting test - comprovaColumna\n");
    int tauler[N_TEST][N_TEST] = {0};

    // Test case 1: Column is empty
    if (esColumnaPlena(0, tauler) == 0) {
        printf("Test case 1 passed\n");
    } else {
        printf("Test case 1 failed\n");
        return FAILED;
    }

    // Test case 2: Column is not empty
    tauler[0][0] = 1;
    if (esColumnaPlena(0, tauler) == 1) {
        printf("Test case 2 passed\n");
    } else {
        printf("Test case 2 failed\n");
        return FAILED;
    }

    printf("TEST - comprovaColumna PASSED\n");
    return PASSED;
}

int test_trobaFila() {
    printf("Starting test - trobaFila\n");
    int tauler[N_TEST][N_TEST] = {0};

    if (trobaFila(0, tauler) == 7) {
        printf("Test case 1 passed\n");
    } else {
        printf("Test case 1 failed\n");
        return FAILED;
    }

    tauler[7][0] = 1;
    if (trobaFila(0, tauler) == 6) {
        printf("Test case 2 passed\n");
    } else {
        printf("Test case 2 failed\n");
        return FAILED;
    }

    tauler[6][0] = 2;
    if (trobaFila(0, tauler) == 5) {
        printf("Test case 3 passed\n");
    } else {
        printf("Test case 3 failed\n");
        return FAILED;
    }

    tauler[5][0] = 2;
    if (trobaFila(0, tauler) == 4) {
        printf("Test case 4 passed\n");
    } else {
        printf("Test case 4 failed\n");
        return FAILED;
    }

    tauler[4][0] = 1;
    if (trobaFila(0, tauler) == 3) {
        printf("Test case 5 passed\n");
    } else {
        printf("Test case 5 failed\n");
        return FAILED;
    }

    tauler[3][0] = 1;
    if (trobaFila(0, tauler) == 2) {
        printf("Test case 6 passed\n");
    } else {
        printf("Test case 6 failed\n");
        return FAILED;
    }

    tauler[2][0] = 2;
    if (trobaFila(0, tauler) == 1) {
        printf("Test case 7 passed\n");
    } else {
        printf("Test case 7 failed\n");
        return FAILED;
    }

    tauler[1][0] = 1;
    if (trobaFila(0, tauler) == 0) {
        printf("Test case 8 passed\n");
    } else {
        printf("Test case 8 failed\n");
        return FAILED;
    }

    // Columna plena no pot passar (funció comprovaColumnaPlena)

    printf("TEST - trobaFila PASSED\n");
    return PASSED;
}

int test_esConnectaVertical() {
    printf("Starting test - esConnectaVertical\n");
    int tauler[N_TEST][N_TEST] = {0};


    // Test case 1: Column does not win
    tauler[7][0] = 1;
    if (esConnectaVertical(tauler, 0, 7, 1) == 0) {
        printf("Test case 1 passed\n");
    } else {
        printf("Test case 1 failed\n");
        return FAILED;
    }

    // Test case 2: Column wins
    tauler[4][0] = 1;
    tauler[5][0] = 1;
    tauler[6][0] = 1;
    tauler[7][0] = 1;
    if (esConnectaVertical(tauler, 0, 4, 1) == 1) {
        printf("Test case 2 passed\n");
    } else {
        printf("Test case 2 failed\n");
        return FAILED;
    }

    //Test case 3: Out of bounds
    tauler[4][0] = 0;
    tauler[5][0] = 1;
    tauler[6][0] = 1;
    tauler[7][0] = 1;
    if (esConnectaVertical(tauler, 0, 5, 1) == 0) {
        printf("Test case 3 passed\n");
    } else {
        printf("Test case 3 failed\n");
        return FAILED;
    }

    //Test case 4: Different players
    tauler[4][0] = 1;
    tauler[5][0] = 2;
    tauler[6][0] = 2;
    tauler[7][0] = 2;
    if (esConnectaVertical(tauler, 0, 4, 1) == 0) {
        printf("Test case 4 passed\n");
    } else {
        printf("Test case 4 failed\n");
        return FAILED;
    }

    printf("TEST - esConnectaVertical PASSED\n");
    return PASSED;
}

int test_esConnectaHoritzontalDreta() {
    printf("Starting test - esConnectaHoritzontalDreta\n");
    int tauler[N_TEST][N_TEST] = {0};

    // Test case 1: Row does not win
    tauler[7][0] = 1;
    if (esConnectaHoritzontal(tauler, 0, 7, 1) == 0) {
        printf("Test case 1 passed\n");
    } else {
        printf("Test case 1 failed\n");
        return FAILED;
    }

    // Test case 2: Row wins
    tauler[7][0] = 1;
    tauler[7][1] = 1;
    tauler[7][2] = 1;
    tauler[7][3] = 1;
    if (esConnectaHoritzontal(tauler, 0, 7, 1) == 1) {
        printf("Test case 2 passed\n");
    } else {
        printf("Test case 2 failed\n");
        return FAILED;
    }

    //Test case 3: Out of bounds
    tauler[7][0] = 0;
    tauler[7][1] = 1;
    tauler[7][2] = 1;
    tauler[7][3] = 1;
    if (esConnectaHoritzontal(tauler, 1, 7, 1) == 0) {
        printf("Test case 3 passed\n");
    } else {
        printf("Test case 3 failed\n");
        return FAILED;
    }

    //Test case 4: Different players
    tauler[7][0] = 1;
    tauler[7][1] = 2;
    tauler[7][2] = 2;
    tauler[7][3] = 2;
    if (esConnectaHoritzontal(tauler, 0, 7, 1) == 0) {
        printf("Test case 4 passed\n");
    } else {
        printf("Test case 4 failed\n");
        return FAILED;
    }

    printf("TEST - esConnectaHoritzontalDreta PASSED\n");
    return PASSED;
}

int test_esConnectaHoritzontalEsquerra() {
    printf("Starting test - esConnectaHoritzontalEsquerra\n");
    int tauler[N_TEST][N_TEST] = {0};

    // Test case 1: Row does not win
    tauler[7][7] = 1;
    if (esConnectaHoritzontalEsquerra(tauler, 7, 7, 1) == 0) {
        printf("Test case 1 passed\n");
    } else {
        printf("Test case 1 failed\n");
        return FAILED;
    }

    // Test case 2: Row wins
    tauler[7][0] = 1;
    tauler[7][1] = 1;
    tauler[7][2] = 1;
    tauler[7][3] = 1;
    if (esConnectaHoritzontalEsquerra(tauler, 3, 7, 1) == 1) {
        printf("Test case 2 passed\n");
    } else {
        printf("Test case 2 failed\n");
        return FAILED;
    }

    //Test case 3: Out of bounds
    tauler[7][0] = 0;
    tauler[7][1] = 1;

    if (esConnectaHoritzontalEsquerra(tauler, 1, 7, 1) == 0) {
        printf("Test case 3 passed\n");
    } else {
        printf("Test case 3 failed\n");
        return FAILED;
    }

    //Test case 4: Different players
    tauler[7][0] = 1;
    tauler[7][1] = 2;
    tauler[7][2] = 2;
    tauler[7][3] = 2;
    if (esConnectaHoritzontalEsquerra(tauler, 3, 7, 2) == 0) {
        printf("Test case 4 passed\n");
    } else {
        printf("Test case 4 failed\n");
        return FAILED;
    }

    printf("TEST - esConnectaHoritzontalEsquerra PASSED\n");
    return PASSED;
}

int test_esConnectaDiagonalSupDreta() {
    printf("Starting test - esConnectaHoritzontalEsquerra\n");
    int tauler[N_TEST][N_TEST] = {0};

    // Test case 1: Diagonal does not win
    tauler[7][7] = 1;
    if (esConnectaDiagonalAsc(tauler, 7, 7, 1) == 0) {
        printf("Test case 1 passed\n");
    } else {
        printf("Test case 1 failed\n");
        return FAILED;
    }

    // Test case 2: Diagonal wins
    tauler[7][0] = 1;
    tauler[6][1] = 1;
    tauler[5][2] = 1;
    tauler[4][3] = 1;
    if (esConnectaDiagonalAsc(tauler, 3, 7, 1) == 1) {
        printf("Test case 2 passed\n");
    } else {
        printf("Test case 2 failed\n");
        return FAILED;
    }

    //Test case 3: Out of bounds - column
    tauler[7][7] = 0;
    tauler[6][7] = 1;

    if (esConnectaDiagonalAsc(tauler, 7, 6, 1) == 0) {
        printf("Test case 3 passed\n");
    } else {
        printf("Test case 3 failed\n");
        return FAILED;
    }

    //Test case 3: Out of bounds - row
    tauler[1][0] = 0;
    tauler[0][0] = 1;

    if (esConnectaDiagonalAsc(tauler, 0, 0, 1) == 0) {
        printf("Test case 4 passed\n");
    } else {
        printf("Test case 4 failed\n");
        return FAILED;
    }

    //Test case 4: Different players
    tauler[7][0] = 1;
    tauler[6][1] = 2;
    tauler[5][2] = 2;
    tauler[4][3] = 2;
    if (esConnectaDiagonalAsc(tauler, 0, 7, 1) == 0) {
        printf("Test case 5 passed\n");
    } else {
        printf("Test case 5 failed\n");
        return FAILED;
    }

    printf("TEST - esConnectaSupDreta PASSED\n");
    return PASSED;
}

int test_esConnectaDiagonalSupEsquerra() {
    printf("Starting test - esConnectaDiagonalSupEsquerra\n");
    int tauler[N_TEST][N_TEST] = {0};

    // Test case 1: Diagonal does not win
    tauler[7][0] = 1;
    if (esConnectaDiagonalDesc(tauler, 0, 7, 1) == 0) {
        printf("Test case 1 passed\n");
    } else {
        printf("Test case 1 failed\n");
        return FAILED;
    }

    // Test case 2: Diagonal wins
    tauler[7][0] = 1;
    tauler[6][1] = 1;
    tauler[5][2] = 1;
    tauler[4][3] = 1;
    if (esConnectaDiagonalDesc(tauler, 3, 7, 1) == 1) {
        printf("Test case 2 passed\n");
    } else {
        printf("Test case 2 failed\n");
        return FAILED;
    }

    //Test case 3: Out of bounds - column
    tauler[7][0] = 0;
    tauler[6][0] = 1;

    if (esConnectaDiagonalDesc(tauler, 0, 6, 1) == 0) {
        printf("Test case 3 passed\n");
    } else {
        printf("Test case 3 failed\n");
        return FAILED;
    }

    //Test case 4: Out of bounds - row
    tauler[1][7] = 0;
    tauler[0][7] = 1;

    if (esConnectaDiagonalDesc(tauler, 7, 0, 1) == 0) {
        printf("Test case 4 passed\n");
    } else {
        printf("Test case 4 failed\n");
        return FAILED;
    }

    //Test case 5: Different players
    tauler[7][0] = 1;
    tauler[6][1] = 2;
    tauler[5][2] = 2;
    tauler[4][3] = 2;

    if(esConnectaDiagonalDesc(tauler, 3, 7, 1) == 0) {
        printf("Test case 5 passed\n");
    } else {
        printf("Test case 5 failed\n");
        return FAILED;
    }

    printf("TEST - esConnectaSupEsquerra PASSED\n");
    return PASSED;
}

int test_esConnectaDiagonalInfDreta() {
    printf("Starting test - esConnectaDiagonalSupEsquerra\n");
    int tauler[N_TEST][N_TEST] = {0};

    // Test case 1: Diagonal does not win
    tauler[0][0] = 1;
    if (esConnectaDiagonalInfDreta(tauler, 0, 0, 1) == 0) {
        printf("Test case 1 passed\n");
    } else {
        printf("Test case 1 failed\n");
        return FAILED;
    }

    // Test case 2: Diagonal wins
    tauler[0][0] = 1;
    tauler[1][1] = 1;
    tauler[2][2] = 1;
    tauler[3][3] = 1;
    if (esConnectaDiagonalInfDreta(tauler, 0, 0, 1) == 1) {
        printf("Test case 2 passed\n");
    } else {
        printf("Test case 2 failed\n");
        return FAILED;
    }

    //Test case 3: Out of bounds - column
    tauler[0][6] = 0;
    tauler[1][7] = 1;
    if (esConnectaDiagonalInfDreta(tauler, 7, 1, 1) == 0) {
        printf("Test case 2 passed\n");
    } else {
        printf("Test case 2 failed\n");
        return FAILED;
    }

    //Test case 4: Out of bounds - row
    tauler[6][0] = 0;
    tauler[7][1] = 1;
    if (esConnectaDiagonalInfDreta(tauler, 1, 7, 1) == 0) {
        printf("Test case 4 passed\n");
    } else {
        printf("Test case 4 failed\n");
        return FAILED;
    }

    //Test case 5: Different players
    tauler[0][0] = 1;
    tauler[1][1] = 2;
    tauler[2][2] = 2;
    tauler[3][3] = 2;
    if (esConnectaDiagonalInfDreta(tauler, 0, 0, 1) == 0) {
        printf("Test case 5 passed\n");
    } else {
        printf("Test case 5 failed\n");
        return FAILED;
    }

    printf("TEST - esConnectaDiagonalInfDreta PASSED\n");
    return PASSED;

}

int test_esConnectaDiagonalInfEsquerra() {
    printf("Starting test - esConnectaDiagonalSupEsquerra\n");
    int tauler[N_TEST][N_TEST] = {0};

    // Test case 1: Diagonal does not win
    tauler[0][7] = 1;
    if (esConnectaDiagonalInfEsquerra(tauler, 7, 0, 1) == 0) {
        printf("Test case 1 passed\n");
    } else {
        printf("Test case 1 failed\n");
        return FAILED;
    }

    // Test case 2: Diagonal wins
    tauler[0][7] = 1;
    tauler[1][6] = 1;
    tauler[2][5] = 1;
    tauler[3][4] = 1;
    if (esConnectaDiagonalInfEsquerra(tauler, 4, 3, 1) == 1) {
        printf("Test case 2 passed\n");
    } else {
        printf("Test case 2 failed\n");
        return FAILED;
    }

    //Test case 3: Out of bounds - column
    tauler[0][7] = 0;
    tauler[1][6] = 1;
    if (esConnectaDiagonalInfEsquerra(tauler, 6, 1, 1) == 0) {
        printf("Test case 3 passed\n");
    } else {
        printf("Test case 3 failed\n");
        return FAILED;
    }

    //Test case 4: Out of bounds - row
    tauler[6][0] = 0;
    tauler[7][1] = 1;
    if (esConnectaDiagonalInfEsquerra(tauler, 1, 7, 1) == 0) {
        printf("Test case 4 passed\n");
    } else {
        printf("Test case 4 failed\n");
        return FAILED;
    }

    //Test case 5: Different players
    tauler[0][7] = 1;
    tauler[1][6] = 2;
    tauler[2][5] = 2;
    tauler[3][4] = 2;
    if (esConnectaDiagonalInfEsquerra(tauler, 4, 3, 1) == 0) {
        printf("Test case 5 passed\n");
    } else {
        printf("Test case 5 failed\n");
        return FAILED;
    }

    printf("TEST - esConnectaDiagonalInfEsquerra PASSED\n");
    return PASSED;
}