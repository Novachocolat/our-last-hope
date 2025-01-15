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
void newLine(int number) {
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

// Saves the last played screen:
int lastScreen;

void lastPlayedScreen(int screen) {
    switch(screen) {
        // Area
        case 1:
            initCampFireArea();
    }
}

// Creates the HUD:
void hudHeader(int lastScreen) {
    switch(lastScreen) {
        case 1:
        // Area:
            if(languageChosen == 0) {
                readUniqueLine("assets/lang_en/en_hud.txt", 1);
            }else{
                readUniqueLine("assets/lang_fr/fr_hud.txt", 1);
            }
            break;
        
        case 2:
        // Map:
            if(languageChosen == 0) {
                readUniqueLine("assets/lang_en/en_hud.txt", 8);
            }else{
                readUniqueLine("assets/lang_fr/fr_hud.txt", 8);
            }
            break;
        
        case 3:
        // Inventory:
            if(languageChosen == 0) {
                readUniqueLine("assets/lang_en/en_hud.txt", 10);
            }else{
                readUniqueLine("assets/lang_fr/fr_hud.txt", 10);
            }
            break;
    }
}

// Creates specific elements for each HUD:
void hudElements(int lastScene) {
    switch(lastScene) {
        case 1:
        // Area:
            if(languageChosen == 0) {
                readBetween("assets/lang_en/en_hud.txt", 2, 3);
            }else{
                readBetween("assets/lang_fr/fr_hud.txt", 2, 3);
            }
            break;

        case 2:
        // Map:
            if(languageChosen == 0) {
                readUniqueLine("assets/lang_en/en_hud.txt", 9);
            }else{
                readUniqueLine("assets/lang_fr/fr_hud.txt", 9);
            }
            break;

        case 3:
        // Inventory:
            if(languageChosen == 0) {
                readBetween("assets/lang_en/en_hud.txt", 11, 13);
            }else{
                readBetween("assets/lang_fr/fr_hud.txt", 11, 13);
            }
            break;
    }
}