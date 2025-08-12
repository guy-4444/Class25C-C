#include "L5.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define randnum(min, max) \
 ((rand() % (int)(((max) + 1) - (min))) + (min))

void whileWithFlag();
void whileWithBreak();
void forWithBreak();
void doubleForWithBreak();
void forWithContinueAndBreak();

void startL5() {
    printf("▧ ▧ ▧ ▧ L5 ▧ ▧ ▧ ▧\n");

    // whileWithFlag();
    // whileWithBreak();
    // forWithBreak();
    // doubleForWithBreak();
    forWithContinueAndBreak();


    // for (int i = 0; i < 10; ++i) {
    //     if ("Zarim") {
    //         printf("Zarim");
    //         continue;
    //     }
    //     if ("!Bagrut School") {
    //         printf("Mikchoi");
    //         continue;
    //     }
    //
    //    for (int j = 0; j < 30; ++j) {
    //        if ("Tel Aviv") {
    //            printf("Name");
    //            break;
    //        }
    //    }
    // }

}

void whileWithFlag() {
    srand(time(NULL));

    int flag = 1;
    int distance = 0;
    int numOfSteps = 0;

    while (flag) { // (flag == 1)
        int leftStep = randnum(1, 2);
        int rightStep = randnum(1, 2);

        distance += leftStep + rightStep;
        numOfSteps += 2;

        if (distance >= 100) {
            flag = 0;
        }
    }

    printf("numOfSteps: %d ", numOfSteps);
}

void whileWithBreak() {
    srand(time(NULL));

    int distance = 0;
    int numOfSteps = 0;

    while (1) {
        int leftStep = randnum(1, 4);
        int rightStep = randnum(1, 4);

        distance += leftStep + rightStep;
        numOfSteps += 2;

        if (distance >= 100) {
            break;
        }
    }

    printf("numOfSteps: %d ", numOfSteps);
}

void forWithBreak() {
    for (int i = 1; i < 1000; i++) {
        if (i % 5 == 0 && i % 7 == 0 && i % 3 == 0) {
            printf("%d ", i);
            break;
        }
    }
}

void doubleForWithBreak() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; ++j) {
            if (j > i * 2) {
                break;
            }
            printf("(%d,%d) ", i, j);
        }
        printf("\n");
    }
}

void forWithContinueAndBreak() {
    printf("break:\n");
    for (int j = 0; j < 10; ++j) {
      for(int i = 0; i < 10; i++) {
          if (i == j) {
                printf("(▧,▧) ");
                break;
            }

            printf("(%d,%d) ", i, j);
        }
        printf("\n");
    }

    printf("\n");
    printf("continue:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; ++j) {
            if (i == j) {
                printf("(▧,▧) ");
                continue;
            }

            printf("(%d,%d) ", i, j);
        }
        printf("\n");
    }
}


/**

run while you find number that divide by 5 and 19 without remain ( % 5 == 0) - choose for or while

run in double loop until i*j > 300 (limits 0..100)


*/





