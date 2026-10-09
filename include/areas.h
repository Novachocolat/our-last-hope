// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 14/01/2025

// Description :
    /* Areas the player can explore */

#ifndef AREAS_H
#define AREAS_H

#include "game_state.h"

// Shows an area and handles the player's choice:
void enterArea(AreaId area);

// Goes back to the last area the player went through:
void returnToLastArea(void);

#endif // AREAS_H
