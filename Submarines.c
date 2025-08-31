#include "Submarines.h"
#include <stdio.h>

void printMatrix(int rows, int cols, int mat[][cols]);

void startSubmarines() {
    printf("▧ ▧ ▧ ▧ Submarines Game ▧ ▧ ▧ ▧\n");

    int map[][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
    };
    int rows = sizeof(map) / sizeof(map[0]);
    int cols = sizeof(map[0]) / sizeof(map[0][0]);
    printMatrix(rows, cols, map);


}

void getPoint( ) {

}

int hitOrMiss( ) {

}

int isGameOver( ) {

}

void printMatrix(int rows, int cols, int mat[][cols]) {
    printf("    ");
    for (int j = 0; j < cols; ++j) {
        printf("%d ", j);
    }
    printf("\n---");
    for (int i = 0; i < cols; ++i) {
        printf("--");
    }
    printf("\n");

    for (int i = 0; i < rows; ++i) {
        printf("%d | ", i);
        for (int j = 0; j < cols; ++j) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}