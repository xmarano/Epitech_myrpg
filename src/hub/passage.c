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
    m->zone1.is_w1_clear = true;
    m->zone2.is_w2_clear = true;
    if ((hub->color.r == 50 && hub->color.g == 50 && hub->color.b == 50)) {
        sfSprite_setScale(hub->bulle, (sfVector2f){0.07, 0.07});
        sfSprite_setPosition(hub->bulle, (sfVector2f){310, 35});
        sfRenderWindow_drawSprite(m->window, hub->bulle, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            m->shop.is_select = false;
            m->current = 9; // shop
        }
    }
    if (hub->color.r == 255 && hub->color.g == 0 && hub->color.b == 255 && m->zone1.is_w1_clear == false) {
        sfSprite_setScale(hub->bulle, (sfVector2f){0.07, 0.07});
        sfSprite_setPosition(hub->bulle, (sfVector2f){610, 285});
        sfRenderWindow_drawSprite(m->window, hub->bulle, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE) && m->zone1.is_w1_clear == false) {
            printf("word1\n");
            m->current = 1; // w1
        }
    }
    if (hub->color.r == 0 && hub->color.g == 255 && hub->color.b == 0 && m->zone1.is_w1_clear == true && m->zone2.is_w2_clear == false) {
        sfSprite_setScale(hub->bulle, (sfVector2f){0.07, 0.07});
        sfSprite_setPosition(hub->bulle, (sfVector2f){858, -7});
        sfRenderWindow_drawSprite(m->window, hub->bulle, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE) && m->zone2.is_w2_clear == false && m->zone1.is_w1_clear == true) {
            printf("word2\n");
            m->current = 2; // w1
        }
    }
    if (hub->color.r == 255 && hub->color.g == 255 && hub->color.b == 0 && m->zone2.is_w2_clear == true && m->zone3.is_w3_clear == false) {
        sfSprite_setScale(hub->bulle, (sfVector2f){0.07, 0.07});
        sfSprite_setPosition(hub->bulle, (sfVector2f){320, 550});
        sfRenderWindow_drawSprite(m->window, hub->bulle, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE) && m->zone3.is_w3_clear == false && m->zone2.is_w2_clear == true) {
            printf("word3\n");
            m->current = 3; // w1
        }
    }
    return;
}
