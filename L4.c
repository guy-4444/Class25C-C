#include "L4.h"
#include <stdio.h>

// Ternary If
// Loops

void tryTernaryIf(int area);
void forLoopExamples();
void starLoop();

void startL4() {
    printf("▧ ▧ ▧ ▧ L4 ▧ ▧ ▧ ▧\n");

    //tryTernaryIf(200);
    //forLoopExamples();
    starLoop();
}

void tryTernaryIf(int area) {
    // regular if:
    int biggerThan100;
    if (area > 100) {
        biggerThan100 = 1;
    } else {
        biggerThan100 = 0;
    }
    printf("biggerThan100: %d", biggerThan100);

    // short ternary if:
    int biggerThan200 = (area > 200) ? 1 : 0;
    printf("biggerThan200: %d", biggerThan200);

    char res = biggerThan200 ? 'y' : 'n';
}

void forLoopExamples() {
    printf("\ni = 0; i < 5  ++: ");
    for (int i = 0; i < 5; i++) {
        printf("%3d", i);
    }
    printf("\ni = 0; i <= 5 ++: ");
    for (int i = 0; i <= 5; i++) {
        printf("%3d", i);
    }
    printf("\ni = 5; i > 0  --: ");
    for (int i = 5; i > 0; i--) {
        printf("%3d", i);
    }
    printf("\ni = 5; i >= 0 --: ");
    for (int i = 5; i >= 0; i--) {
        printf("%3d", i);
    }
    printf("\n");
}

void starLoop() {
    printf("enter star number: ");

    int STAR;
    scanf("%d", &STAR);

    for (int i = 0; i < STAR; i++) {
        printf("*");
    }
    printf("\n\n");

    for (int i = 0; i < STAR; i++) {
        for (int j = 0; j < STAR; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < STAR; i++) {
        for (int j = 0; j < STAR - i; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < STAR; i++) {
        for (int j = 0; j < i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");


    for (int i = 0; i < STAR; i++) {
        for (int j = 0; j < STAR - i - 1; j++) {
            printf("□");
        }
        
        for (int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }

        for (int j = 0; j < STAR - i - 1; j++) {
            printf("□");
        }

        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < STAR; i++) {
        for (int j = 0; j < i; j++) {
            printf("□");
        }

        for (int j = 0; j < 2 * STAR - 1 - (2 * i); j++) {
            printf("*");
        }

        for (int j = 0; j < i; j++) {
            printf("□");
        }

        printf("\n");
    }
    printf("\n");


}




/**

Exercise 1: Star Pyramids

Exercise 2: Tax bill
scan num of products
for each product scan name (char) and price - print line (index. name price)(2. S 54.3₪)
total vat
total with vat

Exercise 3:
Scan num of squares
for each scan square length and symbol

for example:

3 *:
***
***
***

4 &:
&&&&
&&&&
&&&&
&&&&





 **/




