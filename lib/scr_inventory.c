// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 15/01/2025

// Description :
    /* Show the inventory of the player */

#include <stdio.h>
#include "functions.h"

// Show the map:
void initInventory() {
    clearScreen();

    hudHeader(3);
    hudElements(3);
    healthBar(playerHealth);

    playerInteractCHAR = interactPlayerCHAR();

    switch(playerInteractCHAR) {
        case 'b': // Go back to last screen.
            lastPlayedScreen(lastScreen);
            break;
        case '1': // First object
            break;
        case '2': // Second object
            break;
        case '3': // Third object 
            break;
        case 'e': // Use the object
            break;
        case 'f': // Leave the object's choice
            break;
    }
}

// Function to show the inventory
// void afficherInventaire(Item inventaire[], int taille) {
//     clearScreen();
//     if(languageChosen == 0) {
//         readUniqueLine("assets/lang_en/en_inventory.txt", 1);
//     }else{
//         readUniqueLine("assets/lang_fr/fr_inventory.txt", 1);
//     }
//     for (int i = 0; i < taille; i++) {
//         printf("%d. %s: %d\n", i + 1, inventaire[i].nom, inventaire[i].quantite);
//     }
// }