// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description :
    /* Initializes the title screen */

#include <stdio.h>
#include "screens.h"
#include "game.h"
#include "console.h"
#include "text.h"

// Creates title screen:
void initTitleScreen(void) {
    int option = 0;

    do{
        clearScreen();

        readLines(ART_TITLE);
        newLine(2);

        printText(TEXT_STRINGS, STRING_START);

        scanf("%d", &option);
    }while(option != 1);

    gameLoop(SCREEN_FILES);
}
