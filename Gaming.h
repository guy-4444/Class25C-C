void StartGaming();

/* ===== Feature bit masks ===== */
#define FEAT_ONLINE      1   /* 0b00001 */
#define FEAT_COOP        2   /* 0b00010 */
#define FEAT_CROSSPLAY   4   /* 0b00100 */
#define FEAT_VR          8   /* 0b01000 */
#define FEAT_CONTROLLER 16   /* 0b10000 */

typedef struct {
    char userName[20];
    float value;
    char* text;
} Rating;

typedef struct {
    char* name;
    int features; // binary mask
    int ratingsLogicalSize; // Actual element size
    int ratingsPhysicalSize; // Array size in memory
    Rating* ratings;
} Game;

typedef struct {
    Game* game;
    int playingTime; // in minutes
} State;

typedef struct {
    char* name;
    int statesSize;
    State* states;
    int badgesSize;
    char** badges;
} User;

typedef struct {
    User* users;
    int usersSize;
    Game* games;
    int gamesSize;
} Platform;