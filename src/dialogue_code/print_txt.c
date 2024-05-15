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
    if (word == 3)
        m->zone3.is_w3_clear = true;
    if (word == 4)
        m->zone4.is_w4_clear = true;
    if (word == 5)
        m->zone5.is_w5_clear = true;
    if (word == 6)
        m->zone6.is_w6_clear = true;
    if (word == 7)
        m->zone7.is_w7_clear = true;
    if (word == 8)
        m->zone8.is_w8_clear = true;
}

static void setup(Global_t *m, sfVector2f pose)
{
    sfText_setFont(m->dialogue.pro_dia, m->setting.fontdi);
    sfText_setColor(m->dialogue.pro_dia, sfBlack);
    sfText_setPosition(m->dialogue.pro_dia, pose);
    sfText_setScale(m->dialogue.pro_dia, (sfVector2f){0.4, 0.6});
}

void displaydialogue(Global_t *m, hub_t *hub, int word, char array[MAX_LINES][MAX_CHARS_PER_LINE])
{
    char *currentLine = array[m->dialogue.currentLine];
    int i = 0;
    static bool enterPressed = false;
    static sfClock *clock = NULL;
    sfTime elapsedTime;
    float seconds;

    if (clock == NULL)
        clock = sfClock_create();
    elapsedTime = sfClock_getElapsedTime(clock);
    seconds = sfTime_asSeconds(elapsedTime);
    if (sfKeyboard_isKeyPressed(sfKeyEnter) && seconds > 0.5)
        enterPressed = false;
    while (currentLine[i] != '\0') {
        if (currentLine[strlen(currentLine) - 1] == '.' || currentLine[strlen(currentLine) - 1] == '?')
            m->dialogue.waitForEnter = true;
        if (m->dialogue.waitForEnter && sfKeyboard_isKeyPressed(sfKeyEnter) && !enterPressed) {
            m->dialogue.currentLine++;
            enterPressed = true;
            sfClock_restart(clock);
        }
        m->dialogue.waitForEnter = false;
        break;
        i++;
    }
    if (!m->dialogue.waitForEnter) {
        sfText_setString(m->dialogue.pro_dia, currentLine);
        sfRenderWindow_drawText(m->window, m->dialogue.pro_dia, NULL);
    }
    if (currentLine[strlen(currentLine) - 1] == '!' && sfKeyboard_isKeyPressed(sfKeyEnter)) {
        sfClock_destroy(clock);
        clock = NULL;
        change_bool(m, hub, word);
    }
}

void what_dialogue(Global_t *m, int word, hub_t *hub, sfVector2f pose)
{
    setup(m, pose);
    if (word == 0)
        displaydialogue(m, hub, word, m->dialogue.lines);
    if (word == 1)
        displaydialogue(m, hub, word, m->dialogue.lines_w1);
    if (word == 2)
        displaydialogue(m, hub, word, m->dialogue.lines_w2);
    if (word == 3)
        displaydialogue(m, hub, word, m->dialogue.lines_w3);
    if (word == 4)
        displaydialogue(m, hub, word, m->dialogue.lines_w4);
    if (word == 5)
        displaydialogue(m, hub, word, m->dialogue.lines_w5);
    if (word == 6)
        displaydialogue(m, hub, word, m->dialogue.lines_w6);
    if (word == 7)
        displaydialogue(m, hub, word, m->dialogue.lines_w7);
    if (word == 8)
        displaydialogue(m, hub, word, m->dialogue.lines_w8);
}
