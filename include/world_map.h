// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 15/01/2025

// Description :
    /* World map: tiles, generation, display and persistence */

#ifndef WORLD_MAP_H
#define WORLD_MAP_H

#define MAP_ROWS 2
#define MAP_COLS 3

// ASCII art of a tile (TILE_HEIGHT lines):
typedef const char *const *Tile;
typedef Tile WorldMap[MAP_ROWS][MAP_COLS];

extern WorldMap worldMap;

void generateNewMap(WorldMap map);
void viewMap(WorldMap map);
void saveMap(WorldMap map, const char *filename);
void loadMap(WorldMap map, const char *filename);

#endif // WORLD_MAP_H
