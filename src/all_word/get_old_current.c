/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** get_old_current.c
*/

#include "../rpg.h"
#include "../include/menu.h"

void return_and_old_current(Global_t *m, int value)
{
    if (sfKeyboard_isKeyPressed(sfKeyBack)) {
        m->old_current = value;
        m->current = 20;
    }
}
