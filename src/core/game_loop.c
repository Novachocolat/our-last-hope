// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description :
    /* Runs the screens of the game */

#include "game.h"
#include "areas.h"
#include "screens.h"

void gameLoop(ScreenId currentScreen) {
    int running = 1;

    while(running) {

        switch(currentScreen) {
            case SCREEN_LANGUAGES:
                initLanguagesScreen();
                break;
            case SCREEN_TITLE:
                initTitleScreen();
                break;
            case SCREEN_FILES:
                initFilesScreen();
                break;
            case SCREEN_NAMING:
                initNamingScreen();
                break;
            case SCREEN_OPENING:
                initOpeningCutscene();
                break;
            case SCREEN_CAMPFIRE:
                enterArea(AREA_CAMPFIRE);
                break;
            case SCREEN_FOREST:
                enterArea(AREA_FOREST);
                break;
            case SCREEN_TOWN:
                enterArea(AREA_TOWN);
                break;
            case SCREEN_LAKE:
                enterArea(AREA_LAKE);
                break;
            case SCREEN_PARK:
                enterArea(AREA_PARK);
                break;
            case SCREEN_MALL:
                enterArea(AREA_MALL);
                running = 0; // Kept from the original code (no `break` before `default`): the loop stops after the mall.
                break;
            default:
                running = 0;
                break;
        }
    }
}
