// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 14/01/2025

// Description :
    /* Initializes the campfire area */

#include <stdio.h>
#include "functions.h"

// Creates the footer specific to that scene:
void initHUD() {
    if(languageChosen == 0) {
        readBetween("assets/lang_en/en_hud.txt", 2, 3);
    }else{
        readBetween("assets/lang_fr/fr_hud.txt", 2, 3);
    }
}

// Creates the campfire scene:
void initCampFireArea() {
    clearScreen();
    
    readLines("img/bg_campfire.txt"); // Shows the backdrop image.

    hud();
    initHUD();
    healthBar(playerHealth);

    interactPlayer();
}
