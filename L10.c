#include "L10.h"
#include <stdio.h>


void inc(int num) {
    num++;
}

void incP(int* num) {
    (*num)++;
}

void swap(int* pA,  int* pB) {
    int t = *pA;
    *pA = *pB;
    *pB = t;
}

void startL10() {
    printf("▧ ▧ ▧ ▧ L10 ▧ ▧ ▧ ▧\n");

    // int n = 5;
    // int* pN = &n;
    // int x = *pN;
    // int* newAddress = pN;
    // n++;
    // (*pN)++;
    // (*pN)++;
    // (*newAddress)++;




    int n = 10;
    incP(&n);
    printf("%d\n", n);

    int a = 5, b = 3;
    printf("%d, %d\n", a, b);

    swap(&a, &b);
    printf("%d, %d\n", a, b);



}
