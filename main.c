#include <stdio.h>

int main(void) {
    printf("▧ ▧ ▧ ▧ Calculator App ▧ ▧ ▧ ▧\n");

    int a, b, op;
    printf("a: %d, b: %d\n", a, b);

    printf("enter first number:\n");
    scanf("%d", &a);
    printf("enter second number:\n");
    scanf("%d", &b);

    printf("enter operation (1 for +, 2 for -):\n");
    scanf("%d", &op);

    printf("a: %d, b: %d\n", a, b);
    printf("operation: %d\n", op);

    int result = -1;

    if (op == 1) {
        result = a + b;
    }

    if (op == 2) {
        result = a - b;
    }

    printf("result = %d\n", result);


    return 0;
}