// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description :
    /* Basic console output helpers */

#include <stdio.h>
#include <stdlib.h>
#include "console.h"

// Clears the current screen:
void clearScreen(void) {
    #ifdef _WIN32
        // ! Windows only.
        system("cls");
    #else
        // ! UNIX only.
        system("clear");
    #endif
}

// Creates new lines:
void newLine(int number) {
    for(int i = 0; i < number; i++) {
        printf("\n");
    }
}

// Creates tabulations:
void tab(int number) {
    for(int i = 0; i < number; i++) {
        printf("\t");
    }
}
