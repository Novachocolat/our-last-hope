// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description :
    /* Initializes game environment */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lib/functions.h"

//! Windows only.
#ifdef _WIN32
#include <windows.h>
#endif

// Stars the game:
int main(int argc, char *argv[]) {
    
// Changes game window name:
#ifdef _WIN32
    SetConsoleTitle("Our Last Hope");
#else
    prinft("\033]0;Our Last Hope\007");
#endif
    setlocale(LC_ALL, "");

    initLanguagesScreen();
    initTitleScreen();
    initFilesScreen();
    initOpeningCutscene();
    initCampFireArea();

    return 0;
}