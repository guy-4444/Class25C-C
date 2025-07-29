#include <stdio.h>

#define G_FACTOR 9.81
const double VAT = 1.18;

void mainConst() {
    printf("▧ ▧ ▧ ▧ Const ▧ ▧ ▧ ▧\n");


    float mass = 7.5;
    float weight = mass * G_FACTOR;
    printf("weight = %f\n", weight);

    float priceBefore = 200.0;
    float priceAfter = priceBefore * VAT;
    printf("priceAfter = %f\n", priceAfter);
}
