// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description :
    /* Initializes game environment */

#include <stdio.h>
#include <locale.h>
#include <time.h>
#include "lib/functions.h"

//! Windows only.
#ifdef _WIN32
#include <windows.h>
#endif

void sleep_seconds(int seconds) {
    struct timespec req = { .tv_sec = seconds, .tv_nsec = 0 };
    nanosleep(&req, NULL);
}

void gameLoop(int currentScreen) {
    int running = 1;

    while(running) {
        
        switch(currentScreen) {
            case 0:
                initLanguagesScreen();
                break;
            case 1:
                initTitleScreen();
                break;
            case 2:
                initFilesScreen();
                break;
            case 3:
                initNamingScreen();
                break;
            case 4:
                initOpeningCutscene();
                break;
            case 5:
                initCampFireArea();
                break;
            default:
                running = 0;
                break;
        }
    }
}

// Stars the game:
int main(int argc, char *argv[]) {
    
    // Changes game window name:
    #ifdef _WIN32
        SetConsoleTitle("Our Last Hope");
    #else
        printf("\033]0;Our Last Hope\007");
    #endif

    setlocale(LC_ALL, "");

    gameLoop(0);

    return 0;
}