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

void readDialogueFromFile(Global_t *m, char *filename, char array[MAX_LINES][MAX_CHARS_PER_LINE])
{
    FILE *file = fopen(filename, "r");

    m->dialogue.lineCount = 0;
    while (fgets(array[m->dialogue.lineCount],
    MAX_CHARS_PER_LINE, file) != NULL) {
        array[m->dialogue.lineCount]
        [strcspn(array[m->dialogue.lineCount], "\n")] = 0;
        m->dialogue.lineCount++;
        if (m->dialogue.lineCount >= MAX_LINES) {
            break;
        }
    }
    fclose(file);
}

void change_bool(Global_t *m, hub_t *hub, int word)
{
    hub->is_talking = false;
    m->dialogue.waitForEnter = false;
    m->dialogue.currentLine = 0;
    if (word == 0)
        m->hub.prologue_ok = true;
    if (word == 1)
        m->zone1.is_w1_clear = true;
    if (word == 2)
        m->zone2.is_w2_clear = true;
}

static void setup(Global_t *m, sfVector2f pose)
{
    sfText_setFont(m->dialogue.pro_dia, m->setting.fontdi);
    sfText_setColor(m->dialogue.pro_dia, sfBlack);
    sfText_setPosition(m->dialogue.pro_dia, pose);
    sfText_setScale(m->dialogue.pro_dia, (sfVector2f){0.5, 0.5});
}

void displaydialogue(Global_t *m, hub_t *hub, int word, char array[MAX_LINES][MAX_CHARS_PER_LINE])
{
    char *currentLine = array[m->dialogue.currentLine];
    int i = 0;

    while (currentLine[i] != '\0') {
        if (currentLine[strlen(currentLine) - 1] == '.' || currentLine[strlen(currentLine) - 1] == '?')
            m->dialogue.waitForEnter = true;
        if (m->dialogue.waitForEnter == true) {
            if (m->event.type == sfEvtKeyReleased && m->event.key.code == sfKeyReturn)
                m->dialogue.currentLine++;
            m->dialogue.waitForEnter = false;
            break;
        }
        i++;
    }
    if (!m->dialogue.waitForEnter) {
        sfText_setString(m->dialogue.pro_dia, currentLine);
        sfRenderWindow_drawText(m->window, m->dialogue.pro_dia, NULL);
    }
    if (currentLine[strlen(currentLine) - 1] == '!' && sfKeyboard_isKeyPressed(sfKeyEnter))
        change_bool(m, hub, word);
}

void what_dialogue(Global_t *m, int word, hub_t *hub, sfVector2f pose)
{
    pose.x += 20;
    pose.y += 80;
    setup(m, pose);
    if (word == 0)
        displaydialogue(m, hub, word, m->dialogue.lines);
    if (word == 1)
        displaydialogue(m, hub, word, m->dialogue.lines_w1);
    if (word == 2)
        displaydialogue(m, hub, word, m->dialogue.lines_w2);
}
