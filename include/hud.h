// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description :
    /* HUD displayed under each screen */

#ifndef HUD_H
#define HUD_H

typedef enum {
    HUD_AREA      = 1,
    HUD_MAP       = 2,
    HUD_INVENTORY = 3
} HudType;

void hudHeader(HudType hud);
void hudElements(HudType hud);
void healthBar(int currentHearts);

#endif // HUD_H
