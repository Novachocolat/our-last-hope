// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description :
    /* Functions relative to the game screen */

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// Clears the current screen:
void clearScreen() {
    #ifdef _WIN32
        // ! Windows only.
        system("cls");
    #else
        // ! UNIX only.
        system("clear");
    #endif
}

// Creates a new line:
void new_line(int number) {
    for(int i = 0; i < number; i++) {
        printf("\n");
    }
}

// Creates a tabulation:
void tab(int number) {
    for (int i = 0; i < number; i++) {
        printf("\t");
    }
}

// Creates the hud:
void hud() {
    if(languageChosen == 0) {
        readUniqueLine("assets/lang_en/en_hud.txt", 1);
    }else{
        readUniqueLine("assets/lang_fr/fr_hud.txt", 1);
    }
}

// Creates the health bar:
void health_bar() {
    if(languageChosen == 0) {
        readUniqueLine("assets/lang_en/en_hud.txt", 4);
    }else{
        readUniqueLine("assets/lang_fr/fr_hud.txt", 4);
    }
}