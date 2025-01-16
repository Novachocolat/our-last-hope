// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 16/01/2025

// Description :
    /* Initializes the forest area */

#include <stdio.h>
#include "functions.h"

// Creates the forest scene:
void initForestArea() {
    clearScreen();

    lastScreen = 2;
    
    readLines("img/bg_forest.txt"); // Shows the backdrop image.

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