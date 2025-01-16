// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 15/01/2025

// Description :
    /* Initializes the map screen */

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#define TILE_WIDTH 40
#define TILE_HEIGHT 8
#define FILE_NAME_MAX_LENGTH 20

char* TILE_TOWN[TILE_HEIGHT] = {
    "........................................",
    ". TOWN                                 .",
    ".       ^    #####     ^               .",
    ".            #0#0#           #####  ^  .",
    ".    #####   ##/##  ^        #0#0#     .",
    ". ^  #0#0#               ^   ##/##     .",
    ".    ##/##     ^                   ^   .",
    "........................................"
};

char* TILE_MALL[TILE_HEIGHT] = {
    "........................................",
    ". MALL                                 .",
    ".       ^    ########################  .",
    ".   ^        ########################  .",
    ".         ^  ##0000###000000###0000##  .",
    ". ^          ##0000###00//00###0000##  .",
    ".     ^                               .",
    "........................................"
};

char* TILE_PARK[TILE_HEIGHT] = {
    "........................................",
    ". PARK                                 .",
    ".        ^          ^     ^     o  ^   .",
    ".   ^    |    o  ^  |     |   ^    |   .",
    ".   |     ^      |            |        .",
    ".         |   ^    ^   o   ^     ^     .",
    ".     o       |    |       |     |     .",
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

char* TILE_CAMP[TILE_HEIGHT] = {
    "........................................",
    ". CAMP                                 .",
    ".       ^   ^   #     ^        ^    ^  .",
    ".    ^  | ^ |  # # o  |     ^  |    |  .",
    ".  ^ |    | ^   #         ^ | ^   ^    .",
    ".  |   ^    | ^     o  ^  |   |   |^   .",
    ".      |      |  o     |           |   .",
    "........................................"
};

char** TILE_TYPES[] = {TILE_TOWN, TILE_LAKE, TILE_FOREST, TILE_MALL, TILE_PARK};

// Generates a new random map:
void generateNewMap(char** map[2][3]) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == 0 && j == 0) {
                map[i][j] = TILE_CAMP;
            }else if(i == 2 && j == 3) {
                map[i][j] = TILE_MALL;
            }else{
                int random_index = rand() % 5;
                map[i][j] = TILE_TYPES[random_index];
            }
        }
    }
}

// Shows generated map:
void viewMap(char** map[2][3]) {
    for(int row = 0; row < 2; row++) {
        for(int line = 0; line < TILE_HEIGHT; line++) {
            for(int col = 0; col < 3; col++) {
                printf("%s", map[row][col][line]);
            }
        }
        printf("\n");
    }
}

// Saves map into save file:
void saveMap(char** map[2][3], const char* filename) {
    FILE *file = fopen(filename, "a");

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            int savedTile = -1;
            if (map[i][j] == TILE_CAMP) {
                savedTile = 0;  // CAMP.
            }else if(map[i][j] == TILE_TOWN) {
                savedTile = 1;  // Town.
            }else if(map[i][j] == TILE_LAKE) {
                savedTile = 2;  // Lake.
            }else if(map[i][j] == TILE_FOREST) {
                savedTile = 3;  // Forest.
            }else if(map[i][j] == TILE_MALL) {
                savedTile = 4;  // Mall.
            }else if(map[i][j] == TILE_PARK) {
                savedTile = 5;  // Park.
            }
            fprintf(file, "%d ", savedTile);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

// Loads map:
void loadMap(char** map[2][3], const char* filename) {
    FILE *file = fopen(filename, "r");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int savedTile;
            fscanf(file, "%d", &savedTile);

            switch (savedTile) {
                case 0:
                    map[i][j] = TILE_CAMP;
                    break;
                case 1:
                    map[i][j] = TILE_TOWN;
                    break;
                case 2:
                    map[i][j] = TILE_LAKE;
                    break;
                case 3:
                    map[i][j] = TILE_FOREST;
                    break;
                case 4:
                    map[i][j] = TILE_MALL;
                    break;
                case 5:
                    map[i][j] = TILE_PARK;
                    break;
                default:
                    map[i][j] = TILE_FOREST; // If it bugs.
                    break;
            }
        }
    }
    fclose(file);
}

// Shows the map:
void initMap() {
    clearScreen();

    viewMap(map);

    hudHeader(2);
    hudElements(2);
    healthBar(playerHealth);

    playerInteractCHAR = interactPlayerCHAR();

    switch(playerInteractCHAR) {
        case 'b': // Go back to last screen.
            lastPlayedScreen(lastScreen);
            break;
        case 'f':
            initForestArea();
            break;
        case 't':
            initTownArea();
            break;
        case 'p':
            initParkArea();
            break;
        case 'l':
            initLakeArea();
            break;
        case 'm':
            initMallArea();
            break;
        case 'c':
            initCampFireArea();
            break;

    }
}