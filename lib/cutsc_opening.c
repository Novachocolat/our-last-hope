// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description :
    /* Initializes the opening cutscene */

#include <stdio.h>
#include "functions.h"

// Plays a specific scene of the opening cutscene:
void playFrame(const char *filePath, int startLine, int endLine, void (*nextFrame)(), const char *image) {
    int skip;

    do{
        clearScreen();

        // Reads the dialogue
        readLines(image);
        readBetween(filePath, startLine, endLine);

        newLine(2);

        if(languageChosen == 0) {
            readUniqueLine("assets/lang_en/en_strings.txt", 12);
        }else{
            readUniqueLine("assets/lang_fr/fr_strings.txt", 12);
        }

        scanf("%d", &skip);
        if(skip == 1 && nextFrame != NULL) {
            nextFrame();
        }
    }while(skip != 1);
}

// Frame 3:
void frame3() {
    if(languageChosen == 0) {
        playFrame("assets/lang_en/en_opening.txt", 7, 9, initCampFireArea, "img/bag.txt");
    }else{
        playFrame("assets/lang_fr/fr_opening.txt", 7, 9, initCampFireArea, "img/bag.txt");
    }
}

// Frame 2:
void frame2() {
    if(languageChosen == 0) {
        playFrame("assets/lang_en/en_opening.txt", 4, 6, frame3, "img/radio_emitter.txt");
    }else{
        playFrame("assets/lang_fr/fr_opening.txt", 4, 6, frame3, "img/radio_emitter.txt");
    }
}

// Frame 1:
void frame1() {
    if(languageChosen == 0) {
        playFrame("assets/lang_en/en_opening.txt", 1, 3, frame2, "img/bunker.txt");
    }else{
        playFrame("assets/lang_fr/fr_opening.txt", 1, 3, frame2, "img/bunker.txt");
    }
}

// Creates opening cutscene screen:
void initOpeningCutscene() {
    clearScreen();

    playerHealth = 3; // Sets player's hearts to max (3).

    frame1();

    gameLoop(5);
}