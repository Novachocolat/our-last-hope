// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 14/01/2025

// Description :
    /* Player's name and inputs */

#include <stdio.h>
#include "player.h"
#include "game_state.h"
#include "savegame.h"
#include "text.h"

// Gets player's name:
void getPlayerName(void) {
    char filename[PATH_MAX_LENGTH];

    getSaveInfoPath(filename, sizeof(filename), saveFileChosen);
    readUniqueLine(filename, 1);
}

// Waits for player's input:
char interactPlayerCHAR(void) {
    char interact = 0;

    printTextEnglish(TEXT_STRINGS, STRING_ASK_INTERACTION);
    scanf(" %c", &interact);

    return interact;
}
