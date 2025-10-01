#include "Bitwise.h"

#include <stdio.h>
#include <stdlib.h>

void printB(int n) {
    int num_bits = sizeof(int) * 2;
    char *string = malloc(num_bits + 1);
    if (!string) {
        printf("%s", "na\n");
    }
    for (int i = num_bits - 1; i >= 0; i--) {
        string[i] = (n & 1) + '0';
        n >>= 1;
    }
    string[num_bits] = '\0';
    printf("%s\n", string);
}

void printC(char n) {
    int num_bits = sizeof(char) * 8;
    char *string = malloc(num_bits + 1);
    if (!string) {
        printf("%s", "na\n");
    }
    for (int i = num_bits - 1; i >= 0; i--) {
        string[i] = (n & 1) + '0';
        n >>= 1;
    }
    string[num_bits] = '\0';
    printf("%s\n", string);
}

// no vegan, add car
void foo(int* st) {
    *st |= 0b00000010;
    *st &= 0b11011111;
}

void startBitwise() {
    // printf("%d\n", a);

    int mask = 0b00000000000000000000000011111111;
    int a    = 0b1010;
    int b    = 0b0110;

    a = a & mask;
    // printB(a);

    a = ~(a ^ b);
    a = ~~a;

    // a = a >> 2;
    // a = a << 2;
    // printB(a);


    int leaf = 0b100;

    int st1 = 0b00101001;
    int st2 = 0b10100000;

    printB(st2);

    // st2 |= leaf;
    foo(&st2);
    printB(st2);










}
