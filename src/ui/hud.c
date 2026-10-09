// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description :
    /* Functions relative to the HUD */

#include "hud.h"
#include "game_state.h"
#include "text.h"

// Lines of the "hud" text file:
enum {
    HUD_LINE_CONTROLS_HEADER = 1,
    HUD_LINE_CONTROLS_FIRST  = 2,
    HUD_LINE_CONTROLS_LAST   = 3,
    HUD_LINE_HEALTH_HEADER   = 4,
    HUD_LINE_HEARTS_FULL     = 5, // Then one line per heart lost.
    HUD_LINE_PLACES_HEADER   = 8,
    HUD_LINE_PLACES          = 9,
    HUD_LINE_ITEMS_HEADER    = 10,
    HUD_LINE_ITEMS_FIRST     = 11,
    HUD_LINE_ITEMS_LAST      = 13
};

// Creates the HUD:
void hudHeader(HudType hud) {
    switch(hud) {
        case HUD_AREA:
            printText(TEXT_HUD, HUD_LINE_CONTROLS_HEADER);
            break;
        case HUD_MAP:
            printText(TEXT_HUD, HUD_LINE_PLACES_HEADER);
            break;
        case HUD_INVENTORY:
            printText(TEXT_HUD, HUD_LINE_ITEMS_HEADER);
            break;
    }
}

// Creates specific elements for each HUD:
void hudElements(HudType hud) {
    switch(hud) {
        case HUD_AREA:
            printTextBetween(TEXT_HUD, HUD_LINE_CONTROLS_FIRST, HUD_LINE_CONTROLS_LAST);
            break;
        case HUD_MAP:
            printText(TEXT_HUD, HUD_LINE_PLACES);
            break;
        case HUD_INVENTORY:
            printTextBetween(TEXT_HUD, HUD_LINE_ITEMS_FIRST, HUD_LINE_ITEMS_LAST);
            break;
    }
}

// Shows player's health:
void healthBar(int currentHearts) {
    printText(TEXT_HUD, HUD_LINE_HEALTH_HEADER);

    if(currentHearts >= 1 && currentHearts <= MAX_HEALTH) {
        // The hearts are always read from the English file.
        printTextEnglish(TEXT_HUD, HUD_LINE_HEARTS_FULL + (MAX_HEALTH - currentHearts));
    }
}
