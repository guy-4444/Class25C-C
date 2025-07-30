#include <stdio.h>
#include "mainConst.h"
#include "simpleIntCalculator.h"
#include "chars.h"

int main(void) {
    printf("◍ ◍ ◍ ◍ ◍ ◍ ◍ ◍ ◍ ◍ ◍ ◍\n\n");

    int d, m, y;
    printf("enter data dd.mm.yyyy:");
    scanf("%d.%d.%d", &d, &m, &y);
    printf("day: %d\n", d);
    printf("month: %d\n", m);
    printf("year: %d\n", y);

    printf("\n\n◍ ◍ ◍ ◍ ◍ ◍ ◍ ◍ ◍ ◍ ◍ ◍");
    return 0;
}
