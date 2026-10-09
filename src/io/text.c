// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description :
    /* Reads a text file */

#include <stdio.h>
#include "text.h"
#include "game_state.h"

#define MAX_LINE_LENGTH 1024
#define TEXT_PATH_MAX_LENGTH 64

static const char *const TEXT_FILE_NAMES[] = {
    [TEXT_HUD]     = "hud",
    [TEXT_OPENING] = "opening",
    [TEXT_STRINGS] = "strings"
};

// Reads an unique line.
void readUniqueLine(const char *filePath, int lineNumber) {
    FILE *file = fopen(filePath, "r");
    if(file == NULL) {
        perror("Couldn't open file.");
        return;
    }

    char buffer[MAX_LINE_LENGTH];
    int count = 0;

    while(fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
        count++;
        if(count == lineNumber) {
            printf("%s", buffer);
            fclose(file);
            return;
        }
    }

    printf("Line %d does not exist.\n", lineNumber);
    fclose(file);
}

// Reads text between a specific start and end line.
void readBetween(const char *filePath, int startLine, int endLine) {
    for(int i = startLine; i <= endLine; i++) {
        readUniqueLine(filePath, i);
    }
}

// Reads a full text.
void readLines(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    if(file == NULL) {
        perror("Couldn't open the file.");
        return;
    }

    char buffer[MAX_LINE_LENGTH];

    while(fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    fclose(file);
}

// Builds the path of a translated text file:
static void getTextPath(char *path, size_t size, TextFile file, int language) {
    const char *code = (language == LANGUAGE_ENGLISH) ? "en" : "fr";

    snprintf(path, size, "assets/lang/%s/%s.txt", code, TEXT_FILE_NAMES[file]);
}

// Reads a line of a translated text, in the chosen language:
void printText(TextFile file, int line) {
    char path[TEXT_PATH_MAX_LENGTH];

    getTextPath(path, sizeof(path), file, languageChosen);
    readUniqueLine(path, line);
}

// Reads lines of a translated text, in the chosen language:
void printTextBetween(TextFile file, int startLine, int endLine) {
    char path[TEXT_PATH_MAX_LENGTH];

    getTextPath(path, sizeof(path), file, languageChosen);
    readBetween(path, startLine, endLine);
}

// Reads a line of a translated text, in English whatever the chosen language:
void printTextEnglish(TextFile file, int line) {
    char path[TEXT_PATH_MAX_LENGTH];

    getTextPath(path, sizeof(path), file, LANGUAGE_ENGLISH);
    readUniqueLine(path, line);
}
