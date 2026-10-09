// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 14/01/2025

// Description :
    /* Retrieves every save files */

#include <stdio.h>
#include "screens.h"
#include "game.h"
#include "game_state.h"
#include "console.h"
#include "savegame.h"
#include "text.h"
#include "world_map.h"

// Choices of a selected save file:
enum {
    FILE_ACTION_PLAY   = 1,
    FILE_ACTION_DELETE = 2,
    FILE_ACTION_BACK   = 3
};

// Shows a specific save file:
static void showSaveFile(int slot) {
    char filename[PATH_MAX_LENGTH];
    SaveInfo info;
    char line[100];

    getSaveInfoPath(filename, sizeof(filename), slot);
    FILE *file = fopen(filename, "r");

    printText(TEXT_STRINGS, STRING_FILE_BASE + slot);

    if(file == NULL) {
        if(languageChosen == LANGUAGE_ENGLISH) {
            fprintf(stderr, "New game\n");
        }else{
            fprintf(stderr, "Nouvelle partie\n");
        }
        return;
    }

    if(fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%9s", info.playerName);
        if(languageChosen == LANGUAGE_ENGLISH) {
            printf("Name: %s\n", info.playerName);
        }else{
            printf("Nom : %s\n", info.playerName);
        }
    }
    fclose(file);
}

// Shows all save files:
static void showAllSaveFiles(void) {
    for(int i = 1; i <= SAVE_SLOT_COUNT; i++) {
        showSaveFile(i);
        newLine(2);
    }
}

// Chooses a save file slot:
static int whichSaveFile(void) {
    int save;

    do{
        printText(TEXT_STRINGS, STRING_ASK_FILE);
        scanf("%d", &save);

    }while(save < 1 || save > SAVE_SLOT_COUNT);

    return save;
}

// Handle save file interactions:
static void choiceSaveFile(void) {
    int choice;

    printText(TEXT_STRINGS, STRING_ASK_FILE_ACTION);
    scanf("%d", &choice);

    switch(choice) {
        case FILE_ACTION_PLAY:
            if(!saveFileExists(saveFileChosen)) {
                gameLoop(SCREEN_NAMING);
            }else{
                char filename[PATH_MAX_LENGTH];

                getMapInfoPath(filename, sizeof(filename), saveFileChosen);

                loadMap(worldMap, filename);

                gameLoop(SCREEN_CAMPFIRE);
            }
            break;
        case FILE_ACTION_DELETE:
            deleteSaveFile(saveFileChosen);
            initFilesScreen();
            break;
        case FILE_ACTION_BACK:
            initFilesScreen();
            break;
    }
}

// Creates save files screen:
void initFilesScreen(void) {
    clearScreen();

    showAllSaveFiles();
    saveFileChosen = whichSaveFile();
    choiceSaveFile();
}
