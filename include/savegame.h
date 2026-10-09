// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 14/01/2025

// Description :
    /* Save files (player info and map) */

#ifndef SAVEGAME_H
#define SAVEGAME_H

#include <stdbool.h>
#include <stddef.h>

#define SAVE_SLOT_COUNT 3
#define PLAYER_NAME_MAX_LENGTH 10
#define PATH_MAX_LENGTH 64

// Content of a player info save file:
typedef struct {
    char playerName[PLAYER_NAME_MAX_LENGTH];
} SaveInfo;

// Builds the path of the player info / map file of a save slot:
void getSaveInfoPath(char *path, size_t size, int slot);
void getMapInfoPath(char *path, size_t size, int slot);

bool saveFileExists(int slot);
void deleteSaveFile(int slot);

#endif // SAVEGAME_H
