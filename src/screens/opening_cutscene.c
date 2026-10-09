// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description :
    /* Initializes the opening cutscene */

#include <stdio.h>
#include "screens.h"
#include "areas.h"
#include "game.h"
#include "game_state.h"
#include "console.h"
#include "player.h"
#include "text.h"

// A frame is an image and the lines of the opening text shown with it:
typedef struct {
    const char *image;
    int firstLine;
    int lastLine;
} Frame;

#define FRAME_COUNT 3

static const Frame FRAMES[FRAME_COUNT] = {
    {"assets/art/cutscenes/bunker.txt",       1, 3},
    {"assets/art/cutscenes/radio_emitter.txt", 4, 6},
    {"assets/art/cutscenes/bag.txt",          7, 9}
};

// Plays a specific frame of the opening cutscene (frames start at 1),
// then the next one, or the campfire area after the last one:
static void playFrame(int frame) {
    const Frame *current = &FRAMES[frame - 1];
    int skip;

    do{
        clearScreen();

        // Reads the dialogue
        readLines(current->image);
        printTextBetween(TEXT_OPENING, current->firstLine, current->lastLine);

        if(frame == FRAME_COUNT){
            getPlayerName();
            printf(".");
        }

        newLine(2);

        printText(TEXT_STRINGS, STRING_NEXT);

        scanf("%d", &skip);
        if(skip == 1) {
            if(frame < FRAME_COUNT) {
                playFrame(frame + 1);
            }else{
                enterArea(AREA_CAMPFIRE);
            }
        }
    }while(skip != 1);
}

// Creates opening cutscene screen:
void initOpeningCutscene(void) {
    clearScreen();

    playerHealth = MAX_HEALTH; // Sets player's hearts to max (3).

    playFrame(1);

    gameLoop(SCREEN_CAMPFIRE);
}
