// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 14/01/2025

// Description :
    /* Initializes the campfire area */

#include <stdio.h>
#include "functions.h"

// Creates the campfire scene:
void initCampFireArea() {
    clearScreen();

    playerHealth = 3;
    lastScreen = 1;
    
    readLines("img/bg_campfire.txt"); // Shows the backdrop image.

    hudHeader(1);
    hudElements(1);
    healthBar(playerHealth);

    playerInteractCHAR = interactPlayerCHAR();

    switch(playerInteractCHAR) {
        case 'm':
            initMap();
            break;
        case 'i':
            initInventory();
            break;
        case 'e':
            // Do something.
            break;
        case 's':
            // Do something.
            break;
    }
}