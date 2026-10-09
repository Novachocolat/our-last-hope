// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 15/01/2025

// Description :
    /* Kinds of map tiles and their ASCII art */

#ifndef TILES_H
#define TILES_H

#define TILE_WIDTH 40
#define TILE_HEIGHT 8

// Kinds of tiles (the numbers are the ones written in the map save files):
typedef enum {
    TILE_ID_CAMP   = 0,
    TILE_ID_TOWN   = 1,
    TILE_ID_LAKE   = 2,
    TILE_ID_FOREST = 3,
    TILE_ID_MALL   = 4,
    TILE_ID_PARK   = 5,
    TILE_ID_COUNT
} TileId;

// ASCII art of each kind of tile (TILE_HEIGHT lines of TILE_WIDTH characters):
extern const char *const *const TILE_ART[TILE_ID_COUNT];

#endif // TILES_H
