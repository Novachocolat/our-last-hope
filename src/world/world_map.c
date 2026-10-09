// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 15/01/2025

// Description :
    /* World map: generation, display and persistence */

#include <stdio.h>
#include <stdlib.h>
#include "world_map.h"
#include "tiles.h"

WorldMap worldMap;

// Tiles that can be randomly generated (the camp is always the first one):
static const TileId RANDOM_TILES[] = {
    TILE_ID_TOWN, TILE_ID_LAKE, TILE_ID_FOREST, TILE_ID_MALL, TILE_ID_PARK
};
#define RANDOM_TILE_COUNT ((int)(sizeof(RANDOM_TILES) / sizeof(RANDOM_TILES[0])))

// Generates a new random map:
void generateNewMap(WorldMap map) {
    for(int i = 0; i < MAP_ROWS; i++) {
        for(int j = 0; j < MAP_COLS; j++) {
            if(i == 0 && j == 0) {
                map[i][j] = TILE_ART[TILE_ID_CAMP];
            }else{
                int randomIndex = rand() % RANDOM_TILE_COUNT;
                map[i][j] = TILE_ART[RANDOM_TILES[randomIndex]];
            }
        }
    }
}

// Shows generated map:
void viewMap(WorldMap map) {
    for(int row = 0; row < MAP_ROWS; row++) {
        for(int line = 0; line < TILE_HEIGHT; line++) {
            for(int col = 0; col < MAP_COLS; col++) {
                printf("%s", map[row][col][line]);
            }
        }
        printf("\n");
    }
}

// Saves map into save file:
void saveMap(WorldMap map, const char *filename) {
    FILE *file = fopen(filename, "a");
    if(file == NULL) {
        return;
    }

    for(int i = 0; i < MAP_ROWS; i++) {
        for(int j = 0; j < MAP_COLS; j++) {
            int savedTile = -1;
            for(int id = 0; id < TILE_ID_COUNT; id++) {
                if(map[i][j] == TILE_ART[id]) {
                    savedTile = id;
                }
            }
            fprintf(file, "%d ", savedTile);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

// Loads map:
void loadMap(WorldMap map, const char *filename) {
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        return;
    }

    for(int i = 0; i < MAP_ROWS; i++) {
        for(int j = 0; j < MAP_COLS; j++) {
            int savedTile = -1;
            fscanf(file, "%d", &savedTile);

            if(savedTile >= 0 && savedTile < TILE_ID_COUNT) {
                map[i][j] = TILE_ART[savedTile];
            }else{
                map[i][j] = TILE_ART[TILE_ID_FOREST]; // If it bugs.
            }
        }
    }
    fclose(file);
}
