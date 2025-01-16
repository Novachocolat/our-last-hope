// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Imports all of the functions needed to launch the game.
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <time.h>

// External values:

    extern int currentScreen;
    // Retrieves chosen language (0 being English (default), 1 being French):
    extern int languageChosen;

    // Retrieves chosen save file (between 1 and 3):
    extern int saveFileChosen;

    // Retrieves player's current health:
    extern int playerHealth;

    // Retrieves player's interaction (only int):
    extern int playerInteractINT;

    // Retrieves player's interaction (only character):
    extern char playerInteractCHAR;

    // Retrieves player's last screen played:
    extern int lastScreen;

    extern char** map[3][3];

// game.c
void gameLoop();

// Mains functions:
    // scr_languages.c
void initLanguagesScreen();

    // scr_title.c
void initTitleScreen();

    // scr_files.c
void initFilesScreen();

    // scr_naming.c
void initNamingScreen();

    // cutsc_opening.c
void initOpeningCutscene();

    // area_campfire.c
void initCampFireArea();

    // scr_map.c
void initMap();
void generateNewMap();
void viewMap();
void saveMap();
void loadMap();

    // scr_inventory.c
void initInventory();

// Specific functions:
    // reading.c
void readUniqueLine();
void readBetween();
void readLines();

    // screen.c
void clearScreen();
void newLine();
void tab();
void hudHeader();
void hudElements();
void lastPlayedScreen();

    // player.c
void healthBar();
int interactPlayerINT();
char interactPlayerCHAR();

#endif // FUNCTIONS_H