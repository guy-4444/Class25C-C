#include "L7.h"
#include <stdio.h>

void grades();
void findMax();
void mostCommonGrade();

void startL7() {
    printf("▧ ▧ ▧ ▧ L7 ▧ ▧ ▧ ▧\n");


    // grades();
    // findMax();
    // mostCommonGrade();

    int grades[10] = {70, 80, 40, 90, 70, 90, 70, 30, 30, 40};
    int sz = sizeof(grades) / sizeof(grades[0]);
    printf("sz:%d\n", sz);

}

void mostCommonGrade() {
    int grades[9] = {70, 80, 40, 90, 70, 90, 70, 30, 30};
    int counters[101];
    for (int i = 0; i < 101; ++i) {
        counters[i] = 0;
    }

    for (int i = 0; i < 9; ++i) {
        int grade = grades[i];
        counters[grade]++;
    }

    for (int i = 0; i < 101; ++i) {
        if (counters[i] > 0) {
            printf("\n%d.", i);
            for (int j = 0; j < counters[i]; j++) {
                printf("*");
            }
        }
    }

}

void findMax() {
    int grades[7] = {70, 80, 40, 90, 70, 90, 70};

    int max = grades[0];
    int maxIndex = 0;
    for (int i = 0; i < 7; i++) {
        if (grades[i] >= max) {
            max = grades[i];
            maxIndex = i;
        }
    }

    printf("max: %d\n", max);
    printf("maxIndex: %d\n", maxIndex);
}

void grades() {
    const int SZ = 3;
    int grades[SZ];

    for (int i = 0; i < SZ; i++) {
        printf("enter grade no. %d:", (i + 1));
        int temp;
        scanf("%d", &temp);
        grades[i] = temp;

        printf("%d. %d\n", i, temp);
    }

    printf("- - - - - - - -\n");

    for (int i = 0; i < SZ; ++i) {
        printf("%d. %d\n", i, grades[i]);
    }
}

