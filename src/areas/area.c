// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 14/01/2025

// Description :
    /* Initializes the areas (campfire, forest, town, lake, park and mall) */

#include "areas.h"
#include "game_state.h"
#include "screens.h"
#include "console.h"
#include "hud.h"
#include "player.h"
#include "text.h"

// Backdrop image of each area:
static const char *const BACKDROPS[] = {
    [AREA_CAMPFIRE] = "assets/art/backgrounds/campfire.txt",
    [AREA_FOREST]   = "assets/art/backgrounds/forest.txt",
    [AREA_TOWN]     = "assets/art/backgrounds/town.txt",
    [AREA_LAKE]     = "assets/art/backgrounds/lake.txt",
    [AREA_PARK]     = "assets/art/backgrounds/park.txt",
    [AREA_MALL]     = "assets/art/backgrounds/mall.txt"
};

// Creates the scene of an area:
void enterArea(AreaId area) {
    clearScreen();

    if(area == AREA_CAMPFIRE) {
        playerHealth = MAX_HEALTH;
    }
    lastArea = area;

    readLines(BACKDROPS[area]); // Shows the backdrop image.

    hudHeader(HUD_AREA);
    hudElements(HUD_AREA);
    healthBar(playerHealth);

    switch(interactPlayerCHAR()) {
        case 'm':
            initMap();
            break;
        case 'i':
            initInventory();
            break;
        // Not implemented yet: 'e' (interact) and 's' (save).
    }
}

// Goes back to the last area the player went through:
void returnToLastArea(void) {
    if(lastArea != AREA_NONE) {
        enterArea(lastArea);
    }
}
