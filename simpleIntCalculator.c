#include <stdio.h>

void simpleIntCalculatorMain() {
    printf("▧ ▧ ▧ ▧ Calculator App ▧ ▧ ▧ ▧\n");

    int EMPTY = -99990949;
    int a = 6;
    int b = 0;
    char op = '/';

    printf("enter 2 numbers: \n");
    scanf("%d %d", &a, &b);
    printf("enter operation (+ - * /):\n");
    scanf(" %c", &op);
    printf("here your input: %d, %d, %c\n", a, b, op);

    int result = EMPTY;

    if (op == '+') {
        result = a + b;
    } else if (op == '-') {
        result = a - b;
    } else if (op == '*') {
        result = a * b;
    } else if (op == '/') {
        if (b != 0) {
            result = a / b;
        } else {
            printf("Can't divide by 0\n");
        }
    } else {
        printf("Invalid operation\n");
    }

    if (result != EMPTY) {
        printf("the result is %d\n", result);
    }
}


















