// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description :
    /* Initializes game environment */

#include <stdio.h>
#include <locale.h>
#include "game.h"

//! Windows only.
#ifdef _WIN32
#include <windows.h>
#endif

// Starts the game:
int main(void) {

    // Changes game window name:
    #ifdef _WIN32
        SetConsoleTitle("Our Last Hope");
    #else
        printf("\033]0;Our Last Hope\007");
    #endif

    setlocale(LC_ALL, "");

    gameLoop(SCREEN_LANGUAGES);

    return 0;
}
