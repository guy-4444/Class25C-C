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
    Plane* plane;
    int numOfPassengers;
    Passenger* passengers;
} Flight;

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

void initFlight(Flight* flight, char* company, char* flightNo, Plane* plane) {
    flight->company = company;
    flight->no = flightNo;
    flight->plane = plane;
    flight->numOfPassengers = 0;
    flight->passengers = NULL;
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
    FILE *f = fopen(fileName, "r");   // open for reading
    if (!f) { perror("fopen"); return; }

    char line[256];                         // fixed-size buffer
    int lineNo = 1;

    while (fgets(line, sizeof line, f)) {   // reads one line (up to 255 chars)
        printf("%d: %s", lineNo++, line);   // 'line' already includes '\n' if it fit
        // add passenger to the filght
    }

    fclose(f);
}

void startAirAfeka() {
    printf("▧ ▧ ▧ ▧ Welcome to AirAfeka ▧ ▧ ▧ ▧\n");

    Plane p = {"Boeing-747", 100, 300};

    Flight TlvToNyc;

    initFlight(&TlvToNyc, "El-Al", "EE123", &p);
    printf("----------\n");
    PrintFlight(&TlvToNyc);

    addPassengerToFlight(&TlvToNyc, "Elad-Elimelech", 'B', 1, 60);
    addPassengerToFlight(&TlvToNyc, "May-Haker", 'C', 6, 30);
    printf("----------\n");
    PrintFlight(&TlvToNyc);

    printf("----------\n");
    PrintSeat(&TlvToNyc, "Elad-Elimelech");
    PrintSeat(&TlvToNyc, "May-Haker");
    PrintSeat(&TlvToNyc, "Guy");

    printf("----------\n");
    printf("can abroad: %d\n", CanAbroad(&TlvToNyc));
    addPassengerToFlight(&TlvToNyc, "Noa", 'C', 5, 30);
    printf("can abroad: %d", CanAbroad(&TlvToNyc));



    printf("----------\n");
    AddPassengersFromFile(&TlvToNyc, "TLV_NYC.txt");
    printf("----------\n");
    PrintFlight(&TlvToNyc);


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
    for (int i = 0; i < fl->numOfPassengers; ++i) {
        printf("    #%d: ", i + 1);
        PrintPassenger(&fl->passengers[i]);
    }
}


// examples:
// get average lagguge kg
// how many passengers fly today to X