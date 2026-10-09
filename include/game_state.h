// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description :
    /* State shared by every screen of the game */

#ifndef GAME_STATE_H
#define GAME_STATE_H

#define MAX_HEALTH 3

typedef enum {
    LANGUAGE_ENGLISH = 0, // Default.
    LANGUAGE_FRENCH  = 1
} Language;

// Places the player can be in (the numbers are the original ones):
typedef enum {
    AREA_NONE     = 0,
    AREA_CAMPFIRE = 1,
    AREA_FOREST   = 2,
    AREA_TOWN     = 3,
    AREA_LAKE     = 4,
    AREA_PARK     = 5,
    AREA_MALL     = 6
} AreaId;

// Chosen language (a Language value):
extern int languageChosen;

// Chosen save file (between 1 and 3):
extern int saveFileChosen;

// Player's current health (in hearts):
extern int playerHealth;

// Last area the player went through:
extern AreaId lastArea;

#endif // GAME_STATE_H
