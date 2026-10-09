// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 15/01/2025

// Description :
    /* ASCII art of the map tiles */

#include "tiles.h"

static const char *const TILE_TOWN[TILE_HEIGHT] = {
    "........................................",
    ". TOWN                                 .",
    ".       ^    #####     ^               .",
    ".            #0#0#           #####  ^  .",
    ".    #####   ##/##  ^        #0#0#     .",
    ". ^  #0#0#               ^   ##/##     .",
    ".    ##/##     ^                   ^   .",
    "........................................"
};
static const char *const TILE_MALL[TILE_HEIGHT] = {
    "........................................",
    ". MALL                                 .",
    ".       ^    ########################  .",
    ".   ^        ########################  .",
    ".         ^  ##0000###000000###0000##  .",
    ". ^          ##0000###00//00###0000##  .",
    ".     ^                               .",
    "........................................"
};
static const char *const TILE_PARK[TILE_HEIGHT] = {
    "........................................",
    ". PARK                                 .",
    ".        ^          ^     ^     o  ^   .",
    ".   ^    |    o  ^  |     |   ^    |   .",
    ".   |     ^      |            |        .",
    ".         |   ^    ^   o   ^     ^     .",
    ".     o       |    |       |     |     .",
    "........................................"
};
static const char *const TILE_LAKE[TILE_HEIGHT] = {
    "........................................",
    ". LAKE                                 .",
    ".            ~^~^     ~^~^       ~^~^  .",
    ".  ~^~^    ~^~^          ~^~^          .",
    ".                    ~^~^         ~^~^ .",
    ".       ~^~^     ~^~^       ~^~^       .",
    ".                                      .",
    "........................................"
};
static const char *const TILE_FOREST[TILE_HEIGHT] = {
    "........................................",
    ". FOREST                               .",
    ".        ^    ^     ^     ^        ^   .",
    ".   ^    |    |  ^  |     |   ^    |   .",
    ".   |     ^      |     ^      |        .",
    ".     ^   |   ^    ^   |   ^     ^     .",
    ".     |       |    |       |     |     .",
    "........................................"
};
static const char *const TILE_CAMP[TILE_HEIGHT] = {
    "........................................",
    ". CAMP                                 .",
    ".       ^   ^   #     ^        ^    ^  .",
    ".    ^  | ^ |  # # o  |     ^  |    |  .",
    ".  ^ |    | ^   #         ^ | ^   ^    .",
    ".  |   ^    | ^     o  ^  |   |   |^   .",
    ".      |      |  o     |           |   .",
    "........................................"
};

const char *const *const TILE_ART[TILE_ID_COUNT] = {
    [TILE_ID_CAMP]   = TILE_CAMP,
    [TILE_ID_TOWN]   = TILE_TOWN,
    [TILE_ID_LAKE]   = TILE_LAKE,
    [TILE_ID_FOREST] = TILE_FOREST,
    [TILE_ID_MALL]   = TILE_MALL,
    [TILE_ID_PARK]   = TILE_PARK
};
