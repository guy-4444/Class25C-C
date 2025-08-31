#include "L9.h"
#include <stdio.h>

int avg(int rows, int cols, int mat[][cols], int studentID) {
    int sum = 0;
    int cnt = 0;

    for (int i = 0; i < rows; i++) {
        int g = mat[i][studentID];
        if (g != -1) {
            sum += g;
            cnt += 1;
        }
    }

    int result = sum / cnt;
    return result;
}

void getPositionFromUser(int input[]) {
    printf("Enter bomb:\n");
    int x, y;
    scanf("%d %d", &x, &y);
    input[0] = x;
    input[1] = y;
    // scanf("%d %d", &input[0], &input[1]);
}

void startL9() {
    printf("▧ ▧ ▧ ▧ L9 ▧ ▧ ▧ ▧\n");

    int input[2] = {1, 5};
    getPositionFromUser(input);
    printf("(%d, %d) Hit!", input[0], input[1]);


    int map[][6] = {
        {0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 0},
    };
    char names[] = {'N', 'L', 'S', 'E', 'A'};
    char subjects[] = {'I', 'J', 'C', 'P'};

    int mat[][6] = {
        {90, 92, 95, 80, 99, 89},
        {90, 91, 95, -1, 97, 87},
        {90, 91, 95, -1, 98, 88},
        {90, 95, 95, -1, -1, 83},
        {25, 95, 95, -1, 93, 83},
    };

    int totalSizeInBytes = sizeof(mat);
    int totalElements = sizeof(mat) / sizeof(mat[0][0]);
    int rows = sizeof(mat) / sizeof(mat[0]);
    int cols = sizeof(mat[0]) / sizeof(mat[0][0]);


    printf("\ntotalSizeInBytes: %d", totalSizeInBytes);
    printf("\ntotalElements: %d", totalElements);
    printf("\nrows: %d", rows);
    printf("\ncols: %d", cols);


    int result = avg(rows, cols, mat, 4);
    printf("\nresult: %d", result);

    // printf("   ");
    // for (int j = 0; j < 5; ++j) {
    //     printf("%c  ", names[j]);
    // }
    // printf("\n");
    // for (int i = 0; i < 4; ++i) {
    //     printf("%c: ", subjects[i]);
    //     for (int j = 0; j < 5; ++j) {
    //         printf("%d ", mat[i][j]);
    //     }
    //     printf("\n");
    // }

}
