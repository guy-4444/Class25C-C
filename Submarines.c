#include "Submarines.h"
#include <stdio.h>

#define SEA 0
#define SUB 1
#define SEAB 2
#define SUBB 3
#define CONTINUE_MORE_SUBS_LEFT 0
#define NO_SUBS_LEFT 1
#define OUT_OF_BOMBS 2

const int MAX_BOMBS = 5;


void GetPoint(int input[]);
void PrintMatrix(int rows, int cols, int mat[][cols]);
void HitOrMiss(int rows, int cols, int map[][cols], int i, int j);
int IsGameOver(int rows, int cols, int map[][cols], int numOfBombs);

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
    PrintMatrix(rows, cols, map);

    int numOfBombs = MAX_BOMBS;

    while (1) {
        // get ij from user
        int input[2];
        GetPoint(input);
        printf("%d %d", input[0], input[1]);

        // hit/miss/already
        HitOrMiss(rows, cols, map, input[0], input[1]);
        PrintMatrix(rows, cols, map);
        // game over - if game over stop loop
        numOfBombs--;
        int isGameOver = IsGameOver(rows, cols, map, numOfBombs);
        if (isGameOver != 0) {
            if (isGameOver == NO_SUBS_LEFT) {
                printf("Game is over! - Winner\n");
            } else if (isGameOver == OUT_OF_BOMBS) {
                printf("Game is over! - Out of bombs\n");
            }
            break;
        }
    }
}

void GetPoint(int input[]) {
    printf("enter x and y point:\n");
    int x, y;
    scanf("%d %d", &x, &y);
    input[0] = x;
    input[1] = y;
}

void HitOrMiss(int rows, int cols, int map[][cols], int i, int j) {
    int state = map[i][j];
    if (state == SEA) {
        map[i][j] = SEAB;
        printf("(%d,%d) Miss\n", i, j);
    } else if (state == SUB) {
        map[i][j] = SUBB;
        printf("(%d,%d) Hit\n", i, j);
    } else if (state == SEAB || state == SUBB) {
        printf("(%d,%d) Already Bombed\n", i, j);
    }
}

int IsGameOver(int rows, int cols, int map[][cols], int numOfBombs) {
    int subsLeft = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (map[i][j] == 1) {
                subsLeft = 1;
                break;
            }
        }
    }
    if (subsLeft == 0) {
        return NO_SUBS_LEFT;
    }

    if (numOfBombs == 0) {
        return OUT_OF_BOMBS;
    }

    return CONTINUE_MORE_SUBS_LEFT;
}

void PrintMatrix(int rows, int cols, int mat[][cols]) {
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