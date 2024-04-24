/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** shop.c
*/

#include "rpg.h"
#include "include/perso.h"
#include "include/menu.h"
#include "include/worlds.h"

void init_shop(Global_t *m)
{
    return;
}

void draw_shop(Global_t *m)
{
    if (m->current == 9) {
        //printf("shop\n");
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            m->current = 12;
    }
    return;
}
