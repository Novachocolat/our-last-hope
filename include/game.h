// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description :
    /* Game loop and the list of screens it can display */

#ifndef GAME_H
#define GAME_H

// Every screen the game loop can start (the numbers are the original ones):
typedef enum {
    SCREEN_LANGUAGES = 0,
    SCREEN_TITLE     = 1,
    SCREEN_FILES     = 2,
    SCREEN_NAMING    = 3,
    SCREEN_OPENING   = 4,
    SCREEN_CAMPFIRE  = 5,
    SCREEN_FOREST    = 6,
    SCREEN_TOWN      = 7,
    SCREEN_LAKE      = 8,
    SCREEN_PARK      = 9,
    SCREEN_MALL      = 10
} ScreenId;

// Runs the given screen (and the ones it leads to):
void gameLoop(ScreenId startScreen);

#endif // GAME_H
