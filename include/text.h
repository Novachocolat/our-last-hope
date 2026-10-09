// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description :
    /* Reads text files (translated texts and ASCII art) */

#ifndef TEXT_H
#define TEXT_H

// Translated text files (assets/lang/<en|fr>/<name>.txt):
typedef enum {
    TEXT_HUD,
    TEXT_OPENING,
    TEXT_STRINGS
} TextFile;

// Lines of the "strings" text file:
enum {
    STRING_CHOOSE_LANGUAGE   = 1,
    STRING_LANGUAGE_OPTIONS  = 2,
    STRING_START             = 3,
    STRING_FILE_BASE         = 3,  // File header of slot N is line STRING_FILE_BASE + N.
    STRING_ASK_FILE          = 8,
    STRING_ASK_FILE_ACTION   = 9,
    STRING_ASK_INTERACTION   = 10,
    STRING_ASK_NAME          = 11,
    STRING_NEXT              = 12,
    STRING_LANGUAGE_PROMPT   = 13
};

// Art files:
#define ART_TITLE "assets/art/title.txt"

// Generic readers:
void readUniqueLine(const char *filePath, int lineNumber);
void readBetween(const char *filePath, int startLine, int endLine);
void readLines(const char *filePath);

// Readers of translated texts, in the chosen language:
void printText(TextFile file, int line);
void printTextBetween(TextFile file, int startLine, int endLine);

// Reader of translated texts that is always in English:
void printTextEnglish(TextFile file, int line);

#endif // TEXT_H
