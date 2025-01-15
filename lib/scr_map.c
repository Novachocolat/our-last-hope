// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 15/01/2025

// Description :
    /* Initializes the map screen */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

#define TILE_WIDTH 40
#define TILE_HEIGHT 8

char* TILE_CITY[TILE_HEIGHT] = {
    "........................................",
    ". CITY                                 .",
    ".       ^    #####     ^               .",
    ".            #0#0#           #####  ^  .",
    ".    #####   ##/##  ^        #0#0#     .",
    ". ^  #0#0#               ^   ##/##     .",
    ".    ##/##     ^                   ^   .",
    "........................................"
};

char* TILE_LAKE[TILE_HEIGHT] = {
    "........................................",
    ". LAKE                                 .",
    ".            ~^~^     ~^~^       ~^~^  .",
    ".  ~^~^    ~^~^          ~^~^          .",
    ".                    ~^~^         ~^~^ .",
    ".       ~^~^     ~^~^       ~^~^       .",
    ".                                      .",
    "........................................"
};

char* TILE_FOREST[TILE_HEIGHT] = {
    "........................................",
    ". FOREST                               .",
    ".        ^    ^     ^     ^        ^   .",
    ".   ^    |    |  ^  |     |   ^    |   .",
    ".   |     ^      |     ^      |        .",
    ".     ^   |   ^    ^   |   ^     ^     .",
    ".     |       |    |       |     |     .",
    "........................................"
};

char* TILE_BASE[TILE_HEIGHT] = {
    "........................................",
    ". BASE                                 .",
    ".       ^   ^   #     ^        ^    ^  .",
    ".    ^  | ^ |  #  #   |     ^  |    |  .",
    ".  ^ |    | ^             ^ | ^   ^    .",
    ".  |   ^    | ^        ^  |   |   |^   .",
    ".      |      |        |           |   .",
    "........................................"
};

char** TILE_TYPES[] = {TILE_CITY, TILE_LAKE, TILE_FOREST};

// Generates a new random map:
void generateNewMap(char** map[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == 1 && j == 1) {
                map[i][j] = TILE_BASE;
            }else{
                int random_index = rand() % 3;
                map[i][j] = TILE_TYPES[random_index];
            }
        }
    }
}

// View generated map:
void viewMap(char** map[3][3]) {
    for(int row = 0; row < 3; row++) {
        for(int line = 0; line < TILE_HEIGHT; line++) {
            for(int col = 0; col < 3; col++) {
                printf("%s", map[row][col][line]);
            }
        }
        printf("\n");
    }
}

// Show the map:
void initMap() {
    clearScreen();

    srand(time(NULL));

    char** map[3][3];

    generateNewMap(map);

    viewMap(map);

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