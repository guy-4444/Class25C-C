#include "Coffeka.h"
#include <stdio.h>
#include <string.h>

#define MAX_NAME 30




typedef struct {
    char name[MAX_NAME];
    int grains;
    int milk;
    int water;
    int isHot;
    float price;
} Coffee;

void Caffeine(Coffee c) {
    // return grams * some const
}

void printCoffee(Coffee c) {
    printf("%s: grains=%d, milk=%d, water=%d, %s, price=%.2f\n",
       c.name, c.grains, c.milk, c.water, c.isHot ? "Hot" : "Cold", c.price);
}

void printCoffeeP(Coffee* c) {
    printf("%s: grains=%d, milk=%d, water=%d, %s, price=%.2f\n",
       c->name, c->grains, c->milk, c->water, c->isHot ? "Hot" : "Cold", c->price);
}

void ExtraMilk(Coffee* c) {
    c->milk *= 1.5;
}

void startCoffeka() {
    printf("▧ ▧ ▧ ▧ Welcome to Coffeka ▧ ▧ ▧ ▧\n");

    Coffee menu[] = {
        {"Espresso",        8,   0,  30, 1, 1.0},
        {"Double Espresso", 16,  0,  60, 1, 1.8},
        {"Americano",       8,   0, 100, 1, 1.5},
        {"Macchiato",       8,  15,  30, 1, 1.8},
        {"Cappuccino",      8, 100,  30, 1, 2.5},
        {"Latte",           8, 150,  30, 1, 3.0},
        {"Flat White",      8, 120,  30, 1, 2.8},
        {"Mocha",           8, 120,  30, 1, 3.2},
        {"Iced Coffee",     8,   0, 150, 0, 2.2},
        {"Iced Latte",      8, 150,  60, 0, 3.0},
    };


    printf("May:\n");
    Coffee may = menu[4];
    printCoffee(may);
    ExtraMilk(&may);
    printCoffee(may);

    printf("Shaked:\n");
    Coffee shaked = menu[5];
    printCoffee(shaked);
    ExtraMilk(&shaked);
    printCoffee(shaked);

    printf("Lidor:\n");
    Coffee lidor = menu[5];
    printCoffee(lidor);


    while (1) {
        int SZ = sizeof(menu) / sizeof(menu[0]);
        printf("\nItems in menu:  %d", SZ);
        printf("\nchoose what to drink:");
        for (int i = 0; i < SZ; i++) {
            printf("\npress  %d for %s", i, menu[i].name);
        }
        printf("\npress -1 to exit\n");
        int choise;
        scanf("%d", &choise);

        int extraMilk = 0;
        if (menu[choise].milk > 0) {
            printf("extra milk?: (0/1)");
            scanf("%d", &extraMilk);
        }


        if (choise == -1) {
            break;
        }

        Coffee c = menu[choise];
        if (extraMilk) {
            ExtraMilk(&c);
        }
        printCoffee(c);
    }


}




// Caffeine - return Caffeine level
// printCoffee - gets coffe and prints coffee details
// function that get array of coffee and print all of them
// sell - gets coffee and discount > prints the price
