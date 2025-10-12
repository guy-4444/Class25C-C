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
    for (int i = 0; i < g->ratingsLogicalSize; i++) {
        const Rating* r = &g->ratings[i];
        printf("  - rating by %s : %.1f (%s)\n", r->userName, r->value, r->text);
    }
}

static void PrintUser(const User* u) {
    printf("User: %s | states=%d | badges=%d\n", u->name, u->statesSize, u->badgesSize);
    for (int i = 0; i < u->statesSize; i++) {
        const State* s = &u->states[i];
        printf("  * %s : %dmin\n", s->game ? s->game->name : "(null)", s->playingTime);
    }
    if (u->badgesSize > 0) {
        printf("  badges:");
        for (int i = 0; i < u->badgesSize; i++) printf(" %s", u->badges[i]);
        printf("\n");
    }
}

void PrintPlatform(const Platform* p) {
    printf("=== Games (%d) ===\n", p->gamesSize);
    for (int i = 0; i < p->gamesSize; i++) PrintGame(&p->games[i]);
    printf("=== Users (%d) ===\n", p->usersSize);
    for (int i = 0; i < p->usersSize; i++) PrintUser(&p->users[i]);
}


/* returns index in u->states for this game, or -1 if not found */
static int FindUserStateByGame(const User* u, const Game* g) {
    for (int i = 0; i < u->statesSize; i++) {
        if (u->states[i].game == g) return i;
    }
    return -1;
}

static User* FindUser(Platform* p, const char* name) {
    for (int i = 0; i < p->usersSize; i++)
        if (strcmp(p->users[i].name, name) == 0) return &p->users[i];
    return NULL;
}

static Game* FindGame(Platform* p, const char* name) {
    for (int i = 0; i < p->gamesSize; i++)
        if (strcmp(p->games[i].name, name) == 0) return &p->games[i];
    return NULL;
}

static User* AddUser(Platform* p, const char* name) {
    int nSZ = p->usersSize + 1;
    User* t = (User*)realloc(p->users, nSZ * sizeof(User));
    if (!t) return NULL;
    p->users = t;
    
    User* u = &p->users[p->usersSize];
    u->name = strdup(name);
    u->statesSize = 0;
    u->states = NULL;
    u->badgesSize = 0;
    u->badges = NULL;
    p->usersSize = nSZ;
    return u;
}

static Game* AddGame(Platform* p, const char* name, int features) {
    int nSZ = p->gamesSize + 1;
    Game* t = (Game*)realloc(p->games, nSZ * sizeof(Game));
    if (!t) return NULL; // Sanity check
    p->games = t;
    
    Game* g = &p->games[p->gamesSize];
    g->name = strdup(name);
    g->features = features;
    g->ratingsLogicalSize = 0;
    g->ratingsPhysicalSize = 0;
    g->ratings = NULL;
    p->gamesSize = nSZ;
    return g;
}

/* merge-by-game: if state exists, add minutes; else append a new state */
static void AppendOrMergeState(User* u, Game* g, int minutes) {
    int idx = FindUserStateByGame(u, g);
    if (idx >= 0) {
        u->states[idx].playingTime += minutes;
        return;
    }

    int nSZ = u->statesSize + 1;
    State* t = (State*)realloc(u->states, nSZ * sizeof(State));
    if (!t) return;
    u->states = t;

    u->states[u->statesSize].game = g;
    u->states[u->statesSize].playingTime = minutes;
    u->statesSize = nSZ;
}

/* doubles capacity when full: 0→1→2→4→8... */
static void EnsureGameRatingsCapacity(Game* g) {
    if (g->ratingsLogicalSize < g->ratingsPhysicalSize) return;

    int newCap = (g->ratingsPhysicalSize == 0) ? 1 : g->ratingsPhysicalSize * 2;
    Rating* t = (Rating*)realloc(g->ratings, newCap * sizeof(Rating));
    if (!t) return; /* keep it simple */
    g->ratings = t;
    g->ratingsPhysicalSize = newCap;
}

/* append one rating (uses exponential growth) */
static void AddRatingToGame(Game* g, const char* userName, float value, const char* text) {
    EnsureGameRatingsCapacity(g);
    if (g->ratingsLogicalSize >= g->ratingsPhysicalSize) return; // alloc failed

    Rating* r = &g->ratings[g->ratingsLogicalSize];
    strcpy(r->userName, userName);   // safe under your 19-char guarantee
    r->value = value;
    r->text = strdup(text);          // owns the string

    g->ratingsLogicalSize++;
}

/* exponential growth for badges (simple doubling) */
static void AppendBadge(User* u, const char* badge) {
    int nSZ = u->badgesSize + 1;
    char** t = (char**)realloc(u->badges, nSZ * sizeof(char*));
    if (!t) return;
    u->badges = t;
    u->badges[u->badgesSize] = strdup(badge);
    u->badgesSize = nSZ;
}

/* ====== LOADERS (match new file formats) ====== */

/* gaming_users_input.txt: one userName per line */
int LoadUsersFromFile(Platform* p, const char* fileName) {
    int count = 0;
    FILE* f = fopen(fileName, "r");
    if (!f) return 0;
    char name[256];
    while (fscanf(f, "%255s", name) == 1) {
        if (!FindUser(p, name)) {
            AddUser(p, name);
            count++;
        }
    }
    fclose(f);
    return count;
}

/* gaming_games_input.txt: gameName featuresMask */
int LoadGamesFromFile(Platform* p, const char* fileName) {
    int count = 0;
    FILE* f = fopen(fileName, "r");
    if (!f) return 0;
    char name[256];
    int features;
    while (fscanf(f, "%255s %d", name, &features) == 2) {
        Game* g = FindGame(p, name);
        if (!g) {
            AddGame(p, name, features);
            count++;
        }
        else { g->features = features; } /* refresh if already exists */
    }
    fclose(f);
    return count;
}

/* gaming_states_input.txt: userName gameName playingTimeMinutes */
int LoadStatesFromFile(Platform* p, const char* fileName) {
    int count = 0;
    FILE* f = fopen(fileName, "r");
    if (!f) return 0;

    char user[256], game[256];
    int minutes;

    while (fscanf(f, "%255s %255s %d", user, game, &minutes) == 3) {
        // Sanity checks
        User* u = FindUser(p, user);
        if (!u) u = AddUser(p, user);
        Game* g = FindGame(p, game);
        if (!g) g = AddGame(p, game, 0);

        if (u && g) {
            AppendOrMergeState(u, g, minutes);
            count++;
        }
    }
    fclose(f);
    return count;
}

/* gaming_ratings_input.txt: userName gameName value text */
int LoadRatingsFromFile(Platform* p, const char* fileName) {
    int count = 0;
    FILE* f = fopen(fileName, "r");
    if (!f) return 0;

    char user[20], game[256], text[256];
    float value;

    while (fscanf(f, "%19s %255s %f %255s", user, game, &value, text) == 4) {
        Game* g = FindGame(p, game);
        if (!g) g = AddGame(p, game, 0); /* features default 0 if not preloaded */
        if (g) {
            AddRatingToGame(g, user, value, text);
            count++;
        }
    }
    fclose(f);
    return count;
}

/* gaming_badges_input.txt: userName badgeName */
int LoadBadgesFromFile(Platform* p, const char* fileName) {
    int count = 0;
    FILE* f = fopen(fileName, "r");
    if (!f) return 0;

    char user[256], badge[256];

    while (fscanf(f, "%255s %255s", user, badge) == 2) {
        User* u = FindUser(p, user);
        if (!u) u = AddUser(p, user);
        if (u) {
            AppendBadge(u, badge);
            count++;
        }
    }
    fclose(f);
    return count;
}

/* ===== Queries / Reports ===== */

/* 1) average rating of a game by name (0.0 if none or not found) */
float GetAverageRatingByGameName(const Platform* p, const char* gameName) {
    for (int i = 0; i < p->gamesSize; i++) {
        const Game* g = &p->games[i];
        if (strcmp(g->name, gameName) == 0) {
            if (g->ratingsLogicalSize == 0) return 0.0f;
            float sum = 0.0f;
            for (int k = 0; k < g->ratingsLogicalSize; ++k) sum += g->ratings[k].value;
            return sum / (float)g->ratingsLogicalSize;
        }
    }
    return 0.0f;
}

/* 2) print how many players played some game and total minutes */
void PrintPlayersAndTotalTimeForGame(const Platform* p, const char* gameName) {
    const Game* target = NULL;
    for (int i = 0; i < p->gamesSize; i++) {
        if (strcmp(p->games[i].name, gameName) == 0) { target = &p->games[i]; break; }
    }
    if (!target) {
        printf("Game '%s' not found.\n", gameName);
        return;
    }

    int players = 0;
    long total = 0;
    for (int u = 0; u < p->usersSize; ++u) {
        const User* usr = &p->users[u];
        for (int s = 0; s < usr->statesSize; ++s) {
            const State* st = &usr->states[s];
            if (st->game == target) {
                ++players;
                total += st->playingTime;
                break; /* each user counted once; minutes already merged by game */
            }
        }
    }
    printf("Game '%s' -> players=%d, total_minutes=%ld\n", gameName, players, total);
}

/* 3) print which games are BOTH ONLINE and CONTROLLER */
void PrintGamesOnlineAndController(const Platform* p) {
    printf("Games with ONLINE + CONTROLLER:\n");
    for (int i = 0; i < p->gamesSize; i++) {
        const Game* g = &p->games[i];
        if ((g->features & FEAT_ONLINE) && (g->features & FEAT_CONTROLLER)) {
            printf("  - %s (features=%d)\n", g->name, g->features);
        }
    }
}

/* 4) print the game with the most total play time */
void PrintMostPlayedGame(const Platform* p) {
    const Game* best = NULL;
    long bestMinutes = -1;

    for (int gi = 0; gi < p->gamesSize; ++gi) {
        const Game* g = &p->games[gi];
        long sum = 0;
        for (int ui = 0; ui < p->usersSize; ++ui) {
            const User* u = &p->users[ui];
            for (int si = 0; si < u->statesSize; ++si) {
                const State* st = &u->states[si];
                if (st->game == g) sum += st->playingTime;
            }
        }
        if (sum > bestMinutes) { bestMinutes = sum; best = g; }
    }

    if (best) printf("Most played: %s with %ld minutes total\n", best->name, bestMinutes);
    else      printf("No play data.\n");
}

/* 5) print users that play AgeOfEmpires3 */
void PrintUsersWhoPlayAgeOfEmpires3(const Platform* p) {
    const Game* aoe3 = NULL;
    for (int i = 0; i < p->gamesSize; i++) {
        if (strcmp(p->games[i].name, "AgeOfEmpires3") == 0) { aoe3 = &p->games[i]; break; }
    }
    if (!aoe3) { printf("AgeOfEmpires3 not found.\n"); return; }

    printf("Users who play AgeOfEmpires3:\n");
    for (int ui = 0; ui < p->usersSize; ++ui) {
        User* u = &p->users[ui];
        for (int si = 0; si < u->statesSize; ++si) {
            if (u->states[si].game == aoe3) {
                printf("  - %s (%d min)\n", u->name, u->states[si].playingTime);
                break;
            }
        }
    }
}
