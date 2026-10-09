// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 14/01/2025

// Description :
    /* Initializes the naming screen */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "screens.h"
#include "game.h"
#include "game_state.h"
#include "console.h"
#include "savegame.h"
#include "text.h"
#include "world_map.h"

// Creates a new game file:
static void createNewFile(const char *filePath) {
    FILE *file;
    SaveInfo info = {{0}};

    file = fopen(filePath, "a");

    printText(TEXT_STRINGS, STRING_ASK_NAME);

    scanf("%s", info.playerName);

    fwrite(&info, sizeof(SaveInfo), 1, file);
    fclose(file);
}

// Asks player's name:
void initNamingScreen(void) {
    char filename[PATH_MAX_LENGTH];

    clearScreen();

    getSaveInfoPath(filename, sizeof(filename), saveFileChosen);
    createNewFile(filename);

    srand((unsigned int)(time(NULL)));

    generateNewMap(worldMap);

    getMapInfoPath(filename, sizeof(filename), saveFileChosen);
    saveMap(worldMap, filename);
    gameLoop(SCREEN_OPENING);
}
