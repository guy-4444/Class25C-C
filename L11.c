#include "L11.h"
#include <stdio.h>
#include <string.h>

#define NA -1

typedef struct {
    char name[30];
    int biology;
    int c;
    int java;
} Student;

int capitalizeName(Student s) {
    s.name[0] -= 32;
}

int average(Student s) {
    return (s.biology + s.c + s.java) / 3;
}

void printStudent(Student s) {
    printf("Name: %s\n", s.name);
    printf("biology: %d\n", s.biology);
    printf("c: %d\n", s.c);
    printf("java: %d\n", s.java);
}

void startL11() {
    printf("▧ ▧ ▧ ▧ L11 ▧ ▧ ▧ ▧\n");

    Student a = {"Ran", NA, NA, NA};
    a.biology = 90;

    Student b;
    strcpy(b.name, "may");
    b.biology = 100;

    printStudent(b);
    capitalizeName(b);
    printStudent(b);
}
