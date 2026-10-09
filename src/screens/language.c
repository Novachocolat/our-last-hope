// Created by: PACE--BOULNOIS Lysandre and MELOCCO David
// Created on: 13/01/2025

// Description :
    /* Initializes the language selection screen */

#include <stdio.h>
#include "screens.h"
#include "game.h"
#include "game_state.h"
#include "console.h"
#include "text.h"

// Retrieves chosen language (0 being English (default), 1 being French):
static int chosenLanguage(void) {
    int lang;

    newLine(4);
    printTextEnglish(TEXT_STRINGS, STRING_LANGUAGE_PROMPT);
    scanf("%d", &lang);

    return lang;
}

// Creates language selection screen:
void initLanguagesScreen(void) {
    do{
        clearScreen();
        printTextEnglish(TEXT_STRINGS, STRING_CHOOSE_LANGUAGE);
        printTextEnglish(TEXT_STRINGS, STRING_LANGUAGE_OPTIONS);

        languageChosen = chosenLanguage();
    }while(languageChosen != LANGUAGE_ENGLISH && languageChosen != LANGUAGE_FRENCH);

    gameLoop(SCREEN_TITLE);
}
