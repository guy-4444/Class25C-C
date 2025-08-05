#include "L3.h"
#include <stdio.h>


void startL3() {
    printf("▧ ▧ ▧ ▧ L3 ▧ ▧ ▧ ▧\n");

    // char ch;
    // printf("enter char:");
    // scanf("%c", &ch);
    //
    // if ('A' <= ch && ch <= 'Z') {
    //     printf("Upper");
    // } else if (97 <= ch && ch <= 122) {
    //     printf("Lower");
    // } else if ('0' <= ch && ch <= '9') {
    //     printf("Number");
    // }

    printf("ender your grade:");
    int grade;
    scanf("%d", &grade);
    char gradeChar = '0';

    if (grade >= 90) {
        gradeChar = 'A';
    } else if (grade >= 80) {
        gradeChar = 'B';
    } else if (grade >= 70) {
        gradeChar = 'C';
    } else if (grade >= 60) {
        gradeChar = 'D';
    } else if (grade >= 0) {
        gradeChar = 'F';
    }

    printf("Your Grade: %c\n", gradeChar);



    switch (gradeChar) {
        case 'A':
            printf("Well Done!!\n");
            break;
        case 'B':
            printf("Good\n");
            break;
        case 'C':
            printf("Not Nice\n");
            break;
        case 'D':
            printf("Bad\n");
            break;
        case 'F':
            printf("Failed\n");
            break;
        default:
            printf("NA\n");
    }


    /**
    // another version:
    if (grade >= 90) printf("A\n");
    else if (grade >= 80) printf("B\n");
    else if (grade >= 70) printf("C\n");
    else if (grade >= 60) printf("D\n");
    else if (grade >= 0) printf("Failed\n");
    **/

}
/**
enter shape C, S, R, T
enter dimensions (double)
C - r
S - l
R - a b
T - b h

enter type 1 for perimeter/ 2 for area

print beautiful values (two digits after dot)


The perimeter is 56.42
**/
