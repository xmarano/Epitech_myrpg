/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** passage.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"

void passages_mondes(Global_t *m, hub_t *hub)
{
    if ((hub->color.r == 50 && hub->color.g == 50 && hub->color.b == 50)) {
        sfSprite_setScale(hub->bulle, (sfVector2f){0.07, 0.07});
        sfSprite_setPosition(hub->bulle, (sfVector2f){310, 35});
        sfRenderWindow_drawSprite(m->window, hub->bulle, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            m->shop.is_select = false;
            m->current = 9;
        }
    }
    if (hub->color.r == 255 && hub->color.g == 0 && hub->color.b == 255) {
        sfSprite_setScale(hub->bulle, (sfVector2f){0.07, 0.07});
        sfSprite_setPosition(hub->bulle, (sfVector2f){570, 290});
        sfRenderWindow_drawSprite(m->window, hub->bulle, NULL);
    }
    return;
}
