// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Imports all of the functions needed to launch the game.
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// External values:
    // Retrieves chosen language (0 being English (default), 1 being French):
    extern int languageChosen;

    // Retrieves chosen save file (between 1 and 3):
    extern int saveFileChosen;

    // Retrieves player's current health:
    extern int playerHealth;

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

    // sc_campfire.c
void initCampFireArea();

// Specific functions:
    // reading.c
void readUniqueLine();
void readBetween();
void readLines();

    // screen.c
void clearScreen();
void new_line();
void tab();
void hud();

    // player.c
void healthBar();
char interactPlayer();

#endif // FUNCTIONS_H
