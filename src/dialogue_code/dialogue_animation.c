/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** dialogue_animatoin.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"

static void change_bool(Global_t *m, hub_t *hub, int word)
{
    hub->is_talking = false;
    m->dialogue.currentLine = 0;
    if (word == 0) {
        m->hub.prologue_ok = true;
        return;
    }
    sfRenderWindow_setView(m->window, hub->normal_view);
    if (word == 1)
        m->current = 1;
    // if (word == 2)
    //     m->zone2.is_w2_clear = true;
    // if (word == 3)
    //     m->zone3.is_w3_clear = true;
    // if (word == 4)
    //     m->zone4.is_w4_clear = true;
    // if (word == 5)
    //     m->zone5.is_w5_clear = true;
    // if (word == 6)
    //     m->zone6.is_w6_clear = true;
    // if (word == 7)
    //     m->zone7.is_w7_clear = true;
    // if (word == 8)
    //     m->zone8.is_w8_clear = true;
}

void readdialoguefromfile(Global_t *m, char *filename,
    char array[MAX_LINES][MAX_CHARS])
{
    FILE *file = fopen(filename, "r");

    m->dialogue.lineCount = 0;
    while (fgets(array[m->dialogue.lineCount],
    MAX_CHARS, file) != NULL) {
        array[m->dialogue.lineCount]
        [strcspn(array[m->dialogue.lineCount], "\n")] = 0;
        m->dialogue.lineCount++;
        if (m->dialogue.lineCount >= MAX_LINES) {
            break;
        }
    }
    fclose(file);
}

static void handle_enter_keypress(Global_t *m, sfClock *clock,
    bool *enterPressed)
{
    sfTime elapsedTime = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(elapsedTime);

    if (sfKeyboard_isKeyPressed(sfKeyEnter) && seconds > 0.5)
        *enterPressed = false;
}

static void display_currentline(Global_t *m, char array[MAX_LINES][MAX_CHARS])
{
    char *currentLine = array[m->dialogue.currentLine];

    sfText_setString(m->dialogue.pro_dia, currentLine);
    sfRenderWindow_drawText(m->window, m->dialogue.pro_dia, NULL);
}

static void move_to_nextline(Global_t *m, bool *enterPressed, sfClock *clock,
    char array[MAX_LINES][MAX_CHARS])
{
    char *currentLine = array[m->dialogue.currentLine];

    if (currentLine[strlen(currentLine) - 1] == '.'
    || currentLine[strlen(currentLine) - 1] == '?')
        m->dialogue.waitForEnter = true;
    if (m->dialogue.waitForEnter && sfKeyboard_isKeyPressed(sfKeyEnter) &&
    !*enterPressed) {
        m->dialogue.currentLine++;
        *enterPressed = true;
        sfClock_restart(clock);
    }
    m->dialogue.waitForEnter = false;
}

void displaydialogue(Global_t *m, hub_t *hub, int word,
    char array[MAX_LINES][MAX_CHARS])
{
    char *currentLine = array[m->dialogue.currentLine];
    int i = 0;
    static bool enterPressed = false;
    static sfClock *clock = NULL;

    if (clock == NULL)
        clock = sfClock_create();
    handle_enter_keypress(m, clock, &enterPressed);
    move_to_nextline(m, &enterPressed, clock, array);
    display_currentline(m, array);
    if (currentLine[strlen(currentLine) - 1] == '!' && sfKeyboard_isKeyPressed(sfKeyEnter)) {
        sfClock_destroy(clock);
        clock = NULL;
        change_bool(m, hub, word);
    }
}
