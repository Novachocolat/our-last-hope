// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 14/01/2025

// Description :
    /* Save files (player info and map) */

#include <stdio.h>
#include "savegame.h"

#define SAVE_DIR "data/saves"

// Builds the path of the player info file of a save slot:
void getSaveInfoPath(char *path, size_t size, int slot) {
    snprintf(path, size, SAVE_DIR "/save_info%d", slot);
}

// Builds the path of the map file of a save slot:
void getMapInfoPath(char *path, size_t size, int slot) {
    snprintf(path, size, SAVE_DIR "/map_info%d", slot);
}

// Checks if a save file already existing:
bool saveFileExists(int slot) {
    char filename[PATH_MAX_LENGTH];
    getSaveInfoPath(filename, sizeof(filename), slot);
    FILE *file = fopen(filename, "r");

    if(file != NULL) {
        fclose(file);
        return true;
    }
    return false;
}

// Deletes a save file:
void deleteSaveFile(int slot) {
    char filename[PATH_MAX_LENGTH];
    getSaveInfoPath(filename, sizeof(filename), slot);
    remove(filename);
}
