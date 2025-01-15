// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description :
    /* Initializes the opening cutscene */

//! add French translations.

#include <stdio.h>
#include "functions.h"

// Plays a specific scene of the opening cutscene:
void playFrame(const char *filePath, int startLine, int endLine, void (*nextFrame)()) {
    int skip;

    clearScreen();

    // Reads the dialogue
    readBetween(filePath, startLine, endLine);

    new_line(4);

    if(languageChosen == 0) {
        readUniqueLine("assets/lang_en/en_strings.txt", 12);
    }else{
        readUniqueLine("assets/lang_fr/fr_strings.txt", 12);
    }

    scanf("%d", &skip);
    if(skip == 1 && nextFrame != NULL) {
        nextFrame();
    }
}

// Frame 3:
void frame3() {
    readLines("assets/img/bag.txt");
    if(languageChosen == 0) {
        playFrame("assets/lang_en/en_opening.txt", 10, 14, initCampFireArea);
    }else{
        playFrame("assets/lang_fr/fr_opening.txt", 10, 14, initCampFireArea);
    }
}

// Frame 2:
void frame2() {
    readLines("assets/img/radio_emitter.txt");
    if(languageChosen == 0) {
        playFrame("assets/lang_en/en_opening.txt", 5, 9, frame3);
    }else{
        playFrame("assets/lang_fr/fr_opening.txt", 5, 9, frame3);
    }
}

// Frame 1:
void frame1() {
    readLines("assets/img/city.txt");
    if(languageChosen == 0) {
        playFrame("assets/lang_en/en_opening.txt", 1, 4, frame2);
    }else{
        playFrame("assets/lang_fr/fr_opening.txt", 1, 4, frame2);
    }
}

// Creates opening cutscene screen:
void initOpeningCutscene() {
    clearScreen();

    frame1();

    playerHealth = 3; // Sets player's hearts to max (3).
}