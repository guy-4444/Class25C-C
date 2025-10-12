#include "MatrixLogic.h"
#include <stdio.h>
#include <stdlib.h>

# define ROWS 6
# define COLS 6

# define SNAKEROWS 10
# define SNAKECOLS 5

# define RACEROWS 3
# define RACECOLS 10

int mini(int a, int b) {
    if (a < b) return a;
    return b;
}

int maxi(int a, int b) {
    if (a > b) return a;
    return b;
}

void print_matrix(const float a[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%.2f ", a[i][j]);
        }
        putchar('\n');
    }
}

void DoubleStar() {
    int map[ROWS][COLS] = {
        {0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 0},
        {0, 1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0},
    };


    int counter = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (map[i][j] == 0) {

            } else {

            }
            if (map[i][j] == 1 && map[i][j+1] == 1) {
                j++;
            }
        }
    }

    printf("%d", counter);
}

int BiggestSquare(int map[ROWS][COLS]) {
    int biggest = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (map[i][j] == 0) continue;

            int maxI = i + 1, maxJ = j + 1;
            while (maxI < ROWS) {
                if (map[maxI][j] == 0) break;
                maxI++;
            }
            maxI -= i;
            while (maxJ < COLS) {
                if (map[i][maxJ] == 0) break;
                maxJ++;
            }
            maxJ -= j;

            int SZ = mini(maxI, maxJ);


            int maxSize = SZ;
            for (int k = 0; k < SZ; ++k) {
                int c = 0;
                for (int l = 0; l < SZ; ++l) {
                    if (map[i+k][j+l] == 0) break;
                    c++;
                }
                maxSize = mini(maxSize, c);
            }
            biggest = maxi(biggest, maxSize);
            printf("(%d,%d) %d %d - %d\n", i, j, maxI, maxJ, maxSize);
        }
    }

    return biggest;
}

void FindSquares() {
    int map1[ROWS][COLS] = {
        {0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 0},
        {0, 1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0},
    };

    int map2[ROWS][COLS] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
    };


    int map3[ROWS][COLS] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1, 1},
    };

    int map4[ROWS][COLS] = {
        {1, 1, 1, 0, 0, 0},
        {1, 1, 1, 0, 0, 0},
        {1, 1, 1, 0, 0, 0},
        {1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1, 1},
    };

    int map5[ROWS][COLS] = {
        {1, 1, 1, 0, 0, 0},
        {1, 1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1, 1},
    };

    int c1 = BiggestSquare(map1);
    // int c2 = BiggestSquare(map2);
    // int c3 = BiggestSquare(map3);
    // int c4 = BiggestSquare(map4);
    // int c5 = BiggestSquare(map5);

    // printf("%d %d %d %d %d", c1, c2, c3, c4, c5);
}

void CalculateRealEstate(float map[ROWS][COLS]) {
    float newMap[ROWS][COLS] = {0};

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {

            float sum = 0;
            float cnt = 0;
            for (int k = -1; k <= 1; ++k) {
                for (int l = -1; l <= 1; ++l) {
                    if (i+k < 0 || i+k >= ROWS || j+l < 0 || j+l >= COLS) continue;
                    sum += map[i+k][j+l];
                    cnt++;
                }
            }
            newMap[i][j] = sum / cnt;
        }
    }

    print_matrix(newMap);
    // return newMap;
}

void RealEstate() {
    float map[ROWS][COLS] = {
        { 3, 1.4, 2, 1, 1, 1},
        { 1, 3, 1.5, 1, 1, 1},
        { 1, 1, 1, 1, 8, 1},
        { 1.5, 1, 1, 1, 1, 1},
        { 1, 1, 0.6, 1, 1, 2},
    };

    float map2[ROWS][COLS] = {
        {0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 3, 0},
        {1, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1},
    };
    print_matrix(map2);
    printf("-------\n");

    CalculateRealEstate(map2);

}

int ScanRow(int map[SNAKEROWS][SNAKECOLS], int i) {
    for (int j = 0; j < SNAKECOLS; j++) {
        if (map[i][j] == 1) return j;
    }
    return -1;
}

int Snake(int map[SNAKEROWS][SNAKECOLS]) {
    int steps = 0;
    int i = 0, j = SNAKECOLS / 2;

    while (i < SNAKEROWS) {
        // Scanning -> j
        int coin = ScanRow(map, i);
        if (coin >= 0) {
            steps += abs(coin - j);
            j = coin;
        }

        steps++;
        i++;
    }

    return steps;
}

void SnakeGame() {
    int map[SNAKEROWS][SNAKECOLS] = {
        {0,0,0,0,0},
        {0,0,0,0,0},
        {1,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,1,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,1,0,0,0},
        {0,0,0,0,0},
    };
    int steps = Snake(map);
    printf("Steps: %d", steps);
}

int Race(int map[RACEROWS][RACECOLS]) {
    int counter = 0;

    int i = 1;
    for (int j = 0; j < RACECOLS-1; ++j) {
        if (map[i][j+1] == 1) {
            if (i > 0 && map[i-1][j] != 1) {
                counter++;
                i = i-1;
            } else if (i < RACEROWS-1 && map[i+1][j] != 1) {
                counter++;
                i = i+1;
            }
        }
        counter++;
    }




    return counter;
}

void RaceGame() {
    int map[RACEROWS][RACECOLS] = {
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    };

    int counter = Race(map);
    printf("counter: %d", counter);
}

void StartMatrixLogic() {
    printf("▧ ▧ ▧ ▧ Welcome to Matrix Logic ▧ ▧ ▧ ▧\n");

    RaceGame();
}
