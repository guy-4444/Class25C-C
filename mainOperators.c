#include "mainOperators.h"
#include <stdio.h>


const double MIN_SALARY = 6000;


void mainOperators() {
    printf("▧ ▧ ▧ ▧ Operators App ▧ ▧ ▧ ▧\n");

    double salary = 1000;
    int under18 = 0;

    int aboveMin = salary > MIN_SALARY;
    int exception = salary <= MIN_SALARY;

    if (!exception) {
        printf("No need to pay tax at all\n");
    }


    int zx = 0;


}
