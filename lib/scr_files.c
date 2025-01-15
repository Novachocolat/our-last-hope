// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 14/01/2025

// Description :
    /* Retrieves every save files */

#include <stdio.h>
#include "functions.h"

#define PLAYER_NAME_MAX_LENGTH 10
#define FILE_NAME_MAX_LENGTH 20

int saveFileChosen;

struct game_file {
    char player_name[PLAYER_NAME_MAX_LENGTH];
};

// Shows a specific save file:
void showSaveFile(int slot){
    char filename[FILE_NAME_MAX_LENGTH];
    struct game_file info;

    snprintf(filename, sizeof(filename), "saves/save_info%d", slot);
    FILE *file = fopen(filename, "r");

    if(languageChosen == 0) {
        readUniqueLine("assets/lang_en/en_strings.txt", 3 + slot);
    }else{
        readUniqueLine("assets/lang_fr/fr_strings.txt", 3 + slot);
    }

    if(file == NULL) {
        if(languageChosen == 0) {
            fprintf(stderr, "New game\n");
        }else{
            fprintf(stderr, "Nouvelle partie\n");
        }
    }else{
        while(fread(&info, sizeof(struct game_file), 1, file)) {
            if(languageChosen == 0) {
                printf("Name: %s\n", info.player_name);
            }else{
                printf("Nom : %s\n", info.player_name);
            }
        }
    }
    fclose(file);
}

// Show all save files:
void showAllSaveFiles() {
    for(int i = 1; i <= 3; i++) {
        showSaveFile(i);
        new_line(2);
    }
}

// Choose a save file slot:
int whichSaveFile() {
    int save;

    do{
        if(languageChosen == 0) {
            readUniqueLine("assets/lang_en/en_strings.txt", 8);
        }else{
            readUniqueLine("assets/lang_fr/fr_strings.txt", 8);
        }
        scanf("%d", &save);

    }while(save < 1 || save > 3);

    return save;
}

// Delete a save file:
void deleteSaveFile(int slot) {
    char filename[FILE_NAME_MAX_LENGTH];
    snprintf(filename, sizeof(filename), "saves/save_info%d", slot);
    remove(filename);
}

// Handle save file interactions:
void choiceSaveFile() {
    int choice;

    if(languageChosen == 0) {
        readUniqueLine("assets/lang_en/en_strings.txt", 9);
    }else{
        readUniqueLine("assets/lang_fr/fr_strings.txt", 9);
    }
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            initNamingScreen();
            break;
        case 2:
            deleteSaveFile(saveFileChosen);
            initFilesScreen();
            break;
        case 3:
            initFilesScreen();
            break;
    }
}

// Creates save files screen:
void initFilesScreen() {
    clearScreen();

    showAllSaveFiles();
    saveFileChosen = whichSaveFile();
    choiceSaveFile();
}