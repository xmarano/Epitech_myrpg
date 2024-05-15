/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** print_txt.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"

Dialogue_t readDialogueFromFile(Global_t *m, char *filename)
{
    FILE *file = fopen(filename, "r");

    m->dialogue.lineCount = 0;
    while (fgets(m->dialogue.lines[m->dialogue.lineCount],
    MAX_CHARS_PER_LINE, file) != NULL) {
        m->dialogue.lines[m->dialogue.lineCount]
        [strcspn(m->dialogue.lines[m->dialogue.lineCount], "\n")] = 0;
        m->dialogue.lineCount++;
        if (m->dialogue.lineCount >= MAX_LINES) {
            break;
        }
    }
    fclose(file);
    return m->dialogue;
}

void displayprologue(Global_t *m, hub_t *hub)
{
    sfVector2f position = {400, 500};
    sfText_setFont(m->dialogue.pro_dia, m->setting.fontdi);
    sfText_setColor(m->dialogue.pro_dia, sfBlack);
    sfText_setPosition(m->dialogue.pro_dia, position);
    sfText_setScale(m->dialogue.pro_dia, (sfVector2f){0.6, 0.6});

    int i = 0;
    char *currentLine = m->dialogue.lines[m->dialogue.currentLine];
    char displayedText[MAX_CHARS_PER_LINE] = "";
    while (currentLine[i] != '\0') {
        char letter[2] = {currentLine[i], '\0'};
        strcat(displayedText, letter);
        sfText_setString(m->dialogue.pro_dia, displayedText);
        sfRenderWindow_drawText(m->window, m->dialogue.pro_dia, NULL);
        //sfSleep(sfMilliseconds(50));
        if (currentLine[i] == '*') {
            if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
                m->dialogue.currentLine++;
                return;
            }
        }
        i++;
    }
    m->dialogue.currentLine++;
    if (currentLine[0] == '$' || m->dialogue.currentLine >=
    m->dialogue.lineCount) {
        m->hub.prologue_ok = true;
        hub->is_talking = false;
    }
}

void what_dialogue(Global_t *m, int word, hub_t *hub)
{
    if (word == 0) {
        displayprologue(m, hub);
    }
}
