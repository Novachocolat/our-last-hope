// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 15/01/2025

// Description :
    /* Show the inventory of the player */

#include "screens.h"
#include "areas.h"
#include "game_state.h"
#include "console.h"
#include "hud.h"
#include "player.h"

// Show the inventory:
void initInventory(void) {
    clearScreen();

    hudHeader(HUD_INVENTORY);
    hudElements(HUD_INVENTORY);
    healthBar(playerHealth);

    switch(interactPlayerCHAR()) {
        case 'b': // Go back to last screen.
            returnToLastArea();
            break;
        // Not implemented yet: '1', '2', '3' (choose an object),
        // 'e' (use the object) and 'f' (leave the object's choice).
    }
}
