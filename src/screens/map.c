// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 15/01/2025

// Description :
    /* Initializes the map screen */

#include "screens.h"
#include "areas.h"
#include "game_state.h"
#include "console.h"
#include "hud.h"
#include "player.h"
#include "world_map.h"

// Shows the map:
void initMap(void) {
    clearScreen();

    viewMap(worldMap);

    hudHeader(HUD_MAP);
    hudElements(HUD_MAP);
    healthBar(playerHealth);

    switch(interactPlayerCHAR()) {
        case 'b': // Go back to last screen.
            returnToLastArea();
            break;
        case 'f':
            enterArea(AREA_FOREST);
            break;
        case 't':
            enterArea(AREA_TOWN);
            break;
        case 'p':
            enterArea(AREA_PARK);
            break;
        case 'l':
            enterArea(AREA_LAKE);
            break;
        case 'm':
            enterArea(AREA_MALL);
            break;
        case 'c':
            enterArea(AREA_CAMPFIRE);
            break;
    }
}
