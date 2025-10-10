#include "Gaming.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ===== Prototypes ===== */
/* public printers */
static void PrintGame(const Game* g);
static void PrintUser(const User* u);
void PrintPlatform(const Platform* p);

/* public loaders */
int LoadUsersFromFile(Platform* p, const char* fileName);
int LoadGamesFromFile(Platform* p, const char* fileName);
int LoadStatesFromFile(Platform* p, const char* fileName);
int LoadRatingsFromFile(Platform* p, const char* fileName);
int LoadBadgesFromFile(Platform* p, const char* fileName);

/* app entry */
void StartGaming(void);

/* internal helpers (static) */
static int  FindUserStateByGame(const User* u, const Game* g);
static User* AddUser(Platform* p, const char* name);
static Game* AddGame(Platform* p, const char* name, int features);
static User* FindUser(Platform* p, const char* name);
static Game* FindGame(Platform* p, const char* name);
static void AppendOrMergeState(User* u, Game* g, int minutes);
static void EnsureGameRatingsCapacity(Game* g);
static void AddRatingToGame(Game* g, const char* userName, float value, const char* text);
static void AppendBadge(User* u, const char* badge);

/* queries / reports */
float GetAverageRatingByGameName(const Platform* p, const char* gameName);
void  PrintPlayersAndTotalTimeForGame(const Platform* p, const char* gameName);
void  PrintGamesOnlineAndController(const Platform* p);
void  PrintMostPlayedGame(const Platform* p);
void  PrintUsersWhoPlayAgeOfEmpires3(const Platform* p);






void StartGaming() {
    printf("▧ ▧ ▧ ▧ Welcome to Gaming ▧ ▧ ▧ ▧\n");

    Platform p = {0};

    int c1 = LoadUsersFromFile(&p, "gaming_users_input.txt");
    int c2 = LoadGamesFromFile(&p, "gaming_games_input.txt");
    int c3 = LoadStatesFromFile(&p, "gaming_states_input.txt");
    int c4 = LoadRatingsFromFile(&p, "gaming_ratings_input.txt");
    int c5 = LoadBadgesFromFile(&p, "gaming_badges_input.txt");

    printf("%d %d %d %d %d\n", c1, c2, c3, c4, c5);
    PrintPlatform(&p);

    //printf("Avg AOE2: %.2f\n", GetAverageRatingByGameName(&p, "AgeOfEmpires2"));
    //PrintPlayersAndTotalTimeForGame(&p, "GTA");
    //PrintGamesOnlineAndController(&p);
    //PrintMostPlayedGame(&p);
    //PrintUsersWhoPlayAgeOfEmpires3(&p);
}

static void PrintGame(const Game* g) {
    printf("Game: %s | features=%d | ratings=%d/%d\n",
           g->name, g->features, g->ratingsLogicalSize, g->ratingsPhysicalSize);
    for (int i = 0; i < g->ratingsLogicalSize; ++i) {
        const Rating* r = &g->ratings[i];
        printf("  - rating by %s : %.1f (%s)\n", r->userName, r->value, r->text);
    }
}

static void PrintUser(const User* u) {
    printf("User: %s | states=%d | badges=%d\n", u->name, u->statesSize, u->badgesSize);
    for (int i = 0; i < u->statesSize; ++i) {
        const State* s = &u->states[i];
        printf("  * %s : %dmin\n", s->game ? s->game->name : "(null)", s->playingTime);
    }
    if (u->badgesSize > 0) {
        printf("  badges:");
        for (int i = 0; i < u->badgesSize; ++i) printf(" %s", u->badges[i]);
        printf("\n");
    }
}

void PrintPlatform(const Platform* p) {
    printf("=== Games (%d) ===\n", p->gamesSize);
    for (int i = 0; i < p->gamesSize; ++i) PrintGame(&p->games[i]);
    printf("=== Users (%d) ===\n", p->usersSize);
    for (int i = 0; i < p->usersSize; ++i) PrintUser(&p->users[i]);
}


/* returns index in u->states for this game, or -1 if not found */
static int FindUserStateByGame(const User* u, const Game* g) {
    /*
     * * complete here
     */
}

static User* FindUser(Platform* p, const char* name) {
    /*
     * * complete here
     */
}

static Game* FindGame(Platform* p, const char* name) {
    /*
     * * complete here
     */
}

static User* AddUser(Platform* p, const char* name) {
    /*
     * * complete here
     */
}

static Game* AddGame(Platform* p, const char* name, int features) {
    /*
     * * complete here
     */
}

/* merge-by-game: if state exists, add minutes; else append a new state */
static void AppendOrMergeState(User* u, Game* g, int minutes) {
    /*
     * * complete here
     */
}

/* doubles capacity when full: 0→1→2→4→8... */
static void EnsureGameRatingsCapacity(Game* g) {
    /*
     * * complete here
     */
}

/* append one rating (uses exponential growth) */
static void AddRatingToGame(Game* g, const char* userName, float value, const char* text) {
    /*
     * * complete here
     */
}

/* exponential growth for badges (simple doubling) */
static void AppendBadge(User* u, const char* badge) {
    /*
     * * complete here
     */
}

/* ====== LOADERS (match new file formats) ====== */

/* gaming_users_input.txt: one userName per line */
int LoadUsersFromFile(Platform* p, const char* fileName) {
    int count = 0;
    /*
     * * complete here
     */
    return count;
}

/* gaming_games_input.txt: gameName featuresMask */
int LoadGamesFromFile(Platform* p, const char* fileName) {
    int count = 0;
    /*
     * * complete here
     */
    return count;
}

/* gaming_states_input.txt: userName gameName playingTimeMinutes */
int LoadStatesFromFile(Platform* p, const char* fileName) {
    int count = 0;
    /*
     * * complete here
     */
    return count;
}

/* gaming_ratings_input.txt: userName gameName value text */
int LoadRatingsFromFile(Platform* p, const char* fileName) {
    int count = 0;
    /*
     * * complete here
     */
    return count;
}

/* gaming_badges_input.txt: userName badgeName */
int LoadBadgesFromFile(Platform* p, const char* fileName) {
    int count = 0;
    /*
     * * complete here
     */
    return count;
}

/* ===== Queries / Reports ===== */

/* 1) average rating of a game by name (0.0 if none or not found) */
float GetAverageRatingByGameName(const Platform* p, const char* gameName) {
    /*
     * * complete here
     */
}

/* 2) print how many players played some game and total minutes */
void PrintPlayersAndTotalTimeForGame(const Platform* p, const char* gameName) {
    int players = 0;
    long total = 0;
    /*
     * * complete here
     */
    printf("Game '%s' -> players=%d, total_minutes=%ld\n", gameName, players, total);
}

/* 3) print which games are BOTH ONLINE and CONTROLLER */
void PrintGamesOnlineAndController(const Platform* p) {
    printf("Games with ONLINE + CONTROLLER:\n");
    /*
     * * complete here
     */
}

/* 4) print the game with the most total play time */
void PrintMostPlayedGame(const Platform* p) {
    const Game* best = NULL;
    long bestMinutes = -1;

    /*
     * * complete here
     */

    if (best) printf("Most played: %s with %ld minutes total\n", best->name, bestMinutes);
    else      printf("No play data.\n");
}

/* 5) print users that play AgeOfEmpires3 */
void PrintUsersWhoPlayAgeOfEmpires3(const Platform* p) {
    printf("Users who play AgeOfEmpires3:\n");
    /*
     * * complete here
     */
}
