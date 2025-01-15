// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 14/01/2025

// Description :
    /* Initializes the naming screen */

#include <stdio.h>
#include "functions.h"

#define PLAYER_NAME_MAX_LENGTH 10
#define FILE_NAME_MAX_LENGTH 20

struct game_file {
    char player_name[PLAYER_NAME_MAX_LENGTH];
};

// Creates a new game file (first slot):
void createNewFile(const char *file_path) {
    FILE *file;
    struct game_file info;

    file = fopen(file_path, "a");

    if(languageChosen == 0) {
        readUniqueLine("assets/lang_en/en_strings.txt", 11);
    }else{
        readUniqueLine("assets/lang_fr/fr_strings.txt", 11);
    }

    scanf("%11s", &info.player_name);

    fwrite(&info, sizeof(struct game_file), 1, file);
    fclose(file);
}

// Asks player's name:
void initNamingScreen() {
    clearScreen();

    switch(saveFileChosen) {
        case 1:
            createNewFile("saves/save_info1");
            break;
        case 2:
            createNewFile("saves/save_info2");
            break;
        case 3:
            createNewFile("saves/save_info3");
            break;
    }

    gameLoop(4);
}