#include "mainFunctions.h"
#include <math.h>
#include <stdio.h>

float getFloatFromUser(int num);
float maxNumber(int x, int y);

void startMainFunctions() {

    printf("▧ ▧ ▧ ▧ Main Functions ▧ ▧ ▧ ▧\n");

    int num = 1;
    float x1 = getFloatFromUser(num);
    float y1 = getFloatFromUser(2);
    float x2 = getFloatFromUser(3);
    float y2 = getFloatFromUser(4);
    getFloatFromUser(5);

    // calculating distance
    float distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    printf("distance: %f\n", distance);



    printf("Max number program:\n");
    float a = getFloatFromUser(1);
    float b = getFloatFromUser(2);
    int max = maxNumber(a, b);
}

float getFloatFromUser(int num) {
    printf("enter position for %d:\n", num);
    float x;
    scanf("%f", &x);

    return x;
}

float maxNumber(int x, int y) {
    float temp = x > y ? x : y;
    return temp;
}

















