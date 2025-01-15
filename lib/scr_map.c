// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 15/01/2025

// Description :
    /* Initializes the map screen */

#include <stdio.h>
#include "functions.h"

// Show the map:
void initMap() {
    clearScreen();

    hudHeader(2);
    hudElements(2);
    healthBar(playerHealth);

    playerInteractCHAR = interactPlayerCHAR();

    switch(playerInteractCHAR) {
        case 'b': // Go back to last screen.
            lastPlayedScreen(lastScreen);
            break;
    }
}