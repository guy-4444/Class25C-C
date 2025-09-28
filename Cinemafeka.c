#include "Cinemafeka.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* name;
    int age;
} Actor;

typedef struct {
    char* title;
    int duration;
    int numOfActors;
    Actor* actors;
} Movie;

void PrintActor(Actor* actor) {
    if (!actor) {
        printf("   - (null actor)\n");
        return;
    }
    const char* name = actor->name ? actor->name : "(unnamed)";
    printf("   - %s, age %d\n", name, actor->age);
}

void PrintMovie(Movie* movie) {
    printf("\n--");

    if (!movie) {
        printf("(null movie)\n");
        return;
    }
    const char* title = movie->title ? movie->title : "(untitled)";
    printf("Movie: %s\n", title);
    printf("Duration: %d minutes\n", movie->duration);

    if (!movie->actors) {
        printf("Cast: (none)\n");
        return;
    }

    printf("Cast:\n");
    // Expect a sentinel-terminated array: last actor has name == NULL
    for (int i = 0; movie->actors[i].name != NULL; ++i) {
        PrintActor(&movie->actors[i]);
    }
}

void BuildActor(Actor* actors, int index, char* str, int age) {
    actors[index].name = str;
    actors[index].age = age;
}

void BuildMovie(Movie* movies, int index, char* str, int duration) {
    movies[index].title = str;
    movies[index].duration = duration;
    movies[index].numOfActors = 0;
    movies[index].actors = 0;

    // printf("▧ ▧ ▧\n");
    // PrintMovie(&movies[index]);
    // printf("▧ ▧ ▧\n");
}

void AddActorToMovie(Movie* movie, Actor* actor) {
    int newCount = movie->numOfActors + 1;
    Actor* grown = (Actor*)realloc(movie->actors, newCount * sizeof(Actor));

    movie->actors[movie->numOfActors] = *actor;
    movie->actors = grown;
    movie->numOfActors = newCount;
}

void startCinemafeka() {
    printf("▧ ▧ ▧ ▧ Welcome to Cinemafeka ▧ ▧ ▧ ▧\n");

    int SZ = 4;
    Actor* actors = (Actor*) calloc(5,(sizeof(Actor)));
    BuildActor(actors, 0, "Tom Hanks", 60);
    BuildActor(actors, 1, "John Travolta", 70);
    BuildActor(actors, 2, "Samuel L. Jackson", 80);
    BuildActor(actors, 3, "Liam Neeson", 56);
    BuildActor(actors, 4, "Gal Gadot", 45);
    Movie* movies = (Movie*) calloc(SZ,(sizeof(Movie)));


    PrintMovie(&movies[0]);
    BuildMovie(movies, 0, "Forrest Gump", 154);
    AddActorToMovie(&movies[0], &actors[0]);

    PrintMovie(&movies[0]);

    // for (int i = 0; i < SZ; i++) {
    //     PrintMovie(&movies[i]);
    // }

    // for (int i = 0; i < 5; ++i) {
    //     PrintActor(&actors[i]);
    // }

}

