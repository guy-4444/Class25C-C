#include "AirAfeka.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char row;
    int seat;
    int luggage;
} Passenger;

typedef struct {
    char* name;
    int maxKg;
    int seats;
} Plane;

typedef struct {
    char* company;
    char* no;
    char* departure;
    char* destination;
    Plane* plane;
    int numOfPassengers;
    Passenger* passengers;
} Flight;

typedef struct {
    int numOfFlights;
    Flight* flights;
} DB;

void PrintPlane(const Plane *pl);
void PrintPassenger(const Passenger *ps);
void PrintFlight(const Flight *fl);

void addPassengerToFlight(Flight* flight, char* name, char row, int seat, int luggage) {
    // create new Passenger instance
    Passenger p = {name, row, seat, luggage};

    int newSize = flight->numOfPassengers + 1;
    Passenger* t = (Passenger*) realloc(flight->passengers, newSize * sizeof(Passenger));
    t[flight->numOfPassengers] = p;
    flight->passengers = t;
    flight->numOfPassengers++;
}

void initFlight(Flight* flight, char* company, char* flightNo, char* departure, char* destination, Plane* plane) {
    flight->company = company;
    flight->no = flightNo;
    flight->departure = departure;
    flight->destination = destination;
    flight->plane = plane;
    flight->numOfPassengers = 0;
    flight->passengers = NULL;
}

void createNewFlight(DB* db, char* company, char* flightNo, char* departure, char* destination, Plane* plane) {
    Flight f;
    initFlight(&f, company, flightNo, departure, destination, plane);

    int newSize = db->numOfFlights + 1;
    Flight* t = (Flight*) realloc(db->flights, sizeof(Flight) * newSize);
    t[db->numOfFlights] = f;
    db->flights = t;
    db->numOfFlights++;
}

void PrintSeat(Flight* flight, char* name) {
    for (int i = 0; i < flight->numOfPassengers; ++i) {
        char* str = flight->passengers[i].name;
        if (strcmp(str, name) == 0) {
            printf("Seat of %s: %c%d\n", str, flight->passengers[i].row, flight->passengers[i].seat);
            return;
        }
    }
    printf("No Passenger found!\n");
}

int CanAbroad(Flight* flight) {
    int max = flight->plane->maxKg;
    int sum = 0;
    for (int i = 0; i < flight->numOfPassengers; i++) {
        sum += flight->passengers[i].luggage;
    }

    return sum < max;
}

// TLV_NYC.txt
void AddPassengersFromFile(Flight* flight, char* fileName) {
    FILE *file = fopen(fileName, "r");
    if (!file) { perror("fopen"); return; }

    char name[50];
    char row;
    int seat;
    int luggage;

    while (fscanf(file, "%49s %c %d %d", name, &row, &seat, &luggage) == 4) {
        // duplicate the string into new array of chars -> return new pointer
        char *dup = strdup(name);
        addPassengerToFlight(flight, dup, row, seat, luggage);
    }

    fclose(file);
}

void startAirAfeka() {
    printf("▧ ▧ ▧ ▧ Welcome to AirAfeka ▧ ▧ ▧ ▧\n");

    DB db;
    db.numOfFlights = 0;
    db.flights = NULL;

    Plane p1 = {"Boeing-747", 100, 300};
    Plane p2 = {"Airbus-A380", 200, 400};


    createNewFlight(&db, "El-Al", "EE123", "TLV", "NYC", &p1);


    printf("----------\n");
    // PrintFlight(&f1);
    //
    // addPassengerToFlight(&f1, "Elad-Elimelech", 'B', 1, 60);
    // addPassengerToFlight(&f1, "May-Haker", 'C', 6, 30);
    // printf("----------\n");
    // PrintFlight(&f1);
    //
    // printf("----------\n");
    // PrintSeat(&f1, "Elad-Elimelech");
    // PrintSeat(&f1, "May-Haker");
    // PrintSeat(&f1, "Guy");
    //
    // printf("----------\n");
    // printf("can abroad: %d\n", CanAbroad(&f1));
    // addPassengerToFlight(&f1, "Noa", 'C', 5, 30);
    // printf("can abroad: %d", CanAbroad(&f1));


    printf("----------\n");
    AddPassengersFromFile(&db.flights[0], "TLV_NYC.txt");
    printf("----------\n");
    PrintFlight(&db.flights[0]);
}



void PrintPlane(const Plane *pl) {
    if (!pl) { puts("Plane: (null)"); return; }
    printf("Plane: name=\"%s\", seats=%d, maxKg=%d\n", pl->name, pl->seats, pl->maxKg);
}

void PrintPassenger(const Passenger *ps) {
    if (!ps) { puts("Passenger: (null)"); return; }
    printf("Passenger: name=\"%s\", seat=%c-%d, luggage=%d kg\n", ps->name, ps->row, ps->seat, ps->luggage);
}

void PrintFlight(const Flight *fl) {
    if (!fl) { puts("Flight: (null)"); return; }
    printf("Flight: company=\"%s\", no=\"%s\"\n", fl->company, fl->no);

    printf("  ");
    PrintPlane(fl->plane);

    printf("  Passengers (%d):\n", fl->numOfPassengers);
    for (int i = 0; i < fl->numOfPassengers; i++) {
        printf("    #%d: ", i + 1);
        PrintPassenger(&fl->passengers[i]);
    }
}


// examples:
// get average lagguge kg
// how many passengers fly today to X