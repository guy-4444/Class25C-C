#include "Coffeka.h"
#include <stdio.h>
#include <string.h>

#define MAX_NAME 30
#define MAX_PHONE 10
#define BONUS_THRESHOLD 8.0
#define EXTRA_BONUS 300.0
#define CLIENT_TYPE_DEFAULT 0
#define CLIENT_TYPE_STUDENT 1
#define CLIENT_TYPE_SOLDIER 2
#define CLIENT_TYPE_ELDERLY 3
#define CLIENT_TYPE_DEFAULT_DISC 1.0
#define CLIENT_TYPE_STUDENT_DISC 0.8
#define CLIENT_TYPE_SOLDIER_DISC 0.5
#define CLIENT_TYPE_ELDERLY_DISC 0.7

typedef struct {
    char name[MAX_NAME];
    int age;
    float salary;
    float rating;
} Employee;

typedef struct {
    char name[MAX_NAME];
    int grains;
    int milk;
    int water;
    int isHot;
    float price;
    Employee *employee;
} Coffee;

typedef struct {
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    int extraMilk;
    int type;  // 0 - default,  1 - student, 2 - soldier, 3 - eldery
    int numOfPurchases;
    Coffee purchases[100];
} Client;

void Caffeine(Coffee c) {
    // return grams * some const
}

void printCoffee(Coffee c) {
    printf("%s: grains=%d, milk=%d, water=%d, %s, price=%.2f\n",
           c.name, c.grains, c.milk, c.water, c.isHot ? "Hot" : "Cold", c.price);
}

void printCoffeeP(Coffee *c) {
    printf("%s: grains=%d, milk=%d, water=%d, %s, price=%.2f\n",
           c->name, c->grains, c->milk, c->water, c->isHot ? "Hot" : "Cold", c->price);
}

void ExtraMilk(Coffee *c) {
    c->milk *= 1.5;
}

// void L12() {
//     printf("May:\n");
//     Coffee may = menu[4];
//     printCoffee(may);
//     ExtraMilk(&may);
//     printCoffee(may);
//
//     printf("Shaked:\n");
//     Coffee shaked = menu[5];
//     printCoffee(shaked);
//     ExtraMilk(&shaked);
//     printCoffee(shaked);
//
//     printf("Lidor:\n");
//     Coffee lidor = menu[5];
//     printCoffee(lidor);
//
//
//     while (1) {
//         int SZ = sizeof(menu) / sizeof(menu[0]);
//         printf("\nItems in menu:  %d", SZ);
//         printf("\nchoose what to drink:");
//         for (int i = 0; i < SZ; i++) {
//             printf("\npress  %d for %s", i, menu[i].name);
//         }
//         printf("\npress -1 to exit\n");
//         int choise;
//         scanf("%d", &choise);
//
//         int extraMilk = 0;
//         if (menu[choise].milk > 0) {
//             printf("extra milk?: (0/1)");
//             scanf("%d", &extraMilk);
//         }
//
//
//         if (choise == -1) {
//             break;
//         }
//
//         Coffee c = menu[choise];
//         if (extraMilk) {
//             ExtraMilk(&c);
//         }
//         printCoffee(c);
//     }
// }

void printSalary(Employee *e, float hours) {
    float sum = e->salary * hours;

    if (e->rating >= BONUS_THRESHOLD) {
        sum += EXTRA_BONUS;
    }

    printf("%s: %.2f\n", e->name, sum);
}

void purchase(Client* client, Coffee menuItem, Employee* pEmployee) {
    int i = client->numOfPurchases; // client's purchase index
    client->purchases[i] = menuItem;
    client->purchases[i].employee = pEmployee; // assign employee pointer to the purchased coffee

    int type = client->type;
    if (type == CLIENT_TYPE_STUDENT) {
        client->purchases[i].price *= CLIENT_TYPE_STUDENT_DISC;
    } else if (type == CLIENT_TYPE_SOLDIER) {
        client->purchases[i].price *= CLIENT_TYPE_SOLDIER_DISC;
    } else if (type == CLIENT_TYPE_ELDERLY) {
        client->purchases[i].price *= CLIENT_TYPE_ELDERLY_DISC;
    }

    int productContainsMilk = (client->purchases[i].milk > 0) ? 1 : 0;
    int isUserWantExtraMilk = client->extraMilk;

    if (productContainsMilk && isUserWantExtraMilk) {
        ExtraMilk(&(client->purchases[i]));
    }

    float employeeRating = client->purchases[i].employee->rating;


    client->numOfPurchases += 1;
    char *employeeName = client->purchases[i].employee->name;
    char *message = (employeeRating >= BONUS_THRESHOLD) ? "Thanks :)" : "not tasty...";
    printf("%s purchase from %s: \n%s\n", client->name, employeeName, message);
    printCoffee(client->purchases[client->numOfPurchases - 1]);
}

void startCoffeka() {
    printf("▧ ▧ ▧ ▧ Welcome to Coffeka ▧ ▧ ▧ ▧\n");

    Employee e1 = {"Arye", 25, 40.0};
    Employee e2 = {"Elad", 26, 45.0};
    Employee e3 = {"Tair", 23, 38.0};
    e1.rating = 7.5;
    e2.rating = 9.0;
    e3.rating = 4.0;

    Coffee menu[] = {
        {"Espresso", 8, 0, 30, 1, 1.0},
        {"Double Espresso", 16, 0, 60, 1, 1.8},
        {"Americano", 8, 0, 100, 1, 1.5},
        {"Macchiato", 8, 15, 30, 1, 1.8},
        {"Cappuccino", 8, 100, 30, 1, 2.5},
        {"Latte", 8, 150, 30, 1, 3.0},
        {"Flat White", 8, 120, 30, 1, 2.8},
        {"Black", 8, 0, 30, 1, 3.2},
        {"Iced Coffee", 8, 0, 150, 0, 2.2},
        {"Iced Latte", 8, 150, 60, 0, 3.0}
    };


    Client clients[] = {
        {"Zohar Cohen", "0501234567", 1, CLIENT_TYPE_STUDENT, 0},
        {"Oren", "0501234527", 0, CLIENT_TYPE_DEFAULT, 0},
        {"Katya", "0501234467", 1, CLIENT_TYPE_SOLDIER, 0},
        {"Guy", "0501234467", 0, CLIENT_TYPE_ELDERLY, 0},
    };

    int clientsSize = sizeof(clients) / sizeof(clients[0]);
    int purchasesSize = sizeof(clients[0].purchases) / sizeof(clients[0].purchases[0]);

    for (int i = 0; i < clientsSize; ++i) {
        for (int j = 0; j < purchasesSize; ++j) {
            strcpy(clients[i].purchases[j].name, "-");
        }
    }


    // purchase(&clients[0], menu[4], &e1);
    // purchase(&clients[3], menu[0], &e3);
    // purchase(&clients[3], menu[0], &e2);

    purchase(&clients[2], menu[3], &e1);
    e1.rating = 9.0;
    purchase(&clients[2], menu[3], &e1);




    printf("hii");
}


// Caffeine - return Caffeine level
// printCoffee - gets coffe and prints coffee details
// function that get array of coffee and print all of them
// sell - gets coffee and discount > prints the price
