// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 14/01/2025

// Description :
    /* Initializes the player */

#include <stdio.h>
#include "functions.h"

// Retrieves player's health:
int playerHealth;

void healthBar(int current_hearts) {
    if(languageChosen == 0) {
        readUniqueLine("assets/lang_en/en_hud.txt", 4);
    }else{
        readUniqueLine("assets/lang_fr/fr_hud.txt", 4);
    }
    
    if(current_hearts == 3) {
        readUniqueLine("assets/lang_en/en_hud.txt", 5);
    }else if(current_hearts == 2) {
        readUniqueLine("assets/lang_en/en_hud.txt", 6);
    }else if(current_hearts == 1) {
        readUniqueLine("assets/lang_en/en_hud.txt", 7);
    }
}

// Waits for player's input:
char interactPlayer() {
    char interact;

    readUniqueLine("assets/lang_en/en_strings.txt", 10);
    scanf("%c", &interact);

    return interact;
}