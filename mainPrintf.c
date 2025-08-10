#include "mainPrintf.h"
#include <stdio.h>


void startMainPrintf() {
    printf("▧ ▧ ▧ ▧ mainPrintf ▧ ▧ ▧ ▧\n");


    int radius = 123;
    float area = 3.14159265359 * radius * radius;
    printf("|%d|\n", radius);
    printf("|%5d|\n", radius);
    printf("|%-5d|\n", radius);
    printf("|%2d|\n", radius); // push forward


    for (int i = 1; i <= 10; ++i) {
        printf("\n");
        for (int j = 1; j <= 10; ++j) {
            printf(" %04d", i*j);
        }
    }

}
