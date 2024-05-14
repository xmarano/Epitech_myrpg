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

static void passages_mondes8(Global_t *m, hub_t *hub)
{
    if (hub->color.r == 0 && hub->color.g == 0 && hub->color.b == 100
    && m->zone7.is_w7_clear == true && m->zone8.is_w8_clear == false) {
        sfSprite_setPosition(hub->bulle, (sfVector2f){1175, -7});
        sfRenderWindow_drawSprite(m->window, hub->bulle, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            m->current = 8;
        }
    }
}

void passages_mondes6_7(Global_t *m, hub_t *hub)
{
    if (hub->color.r == 100 && hub->color.g == 0 && hub->color.b == 0
    && m->zone5.is_w5_clear == true && m->zone6.is_w6_clear == false) {
        sfSprite_setPosition(hub->bulle, (sfVector2f){1305, 540});
        sfRenderWindow_drawSprite(m->window, hub->bulle, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            m->current = 6;
        }
    }
    if (hub->color.r == 0 && hub->color.g == 100 && hub->color.b == 0
    && m->zone6.is_w6_clear == true && m->zone7.is_w7_clear == false) {
        sfSprite_setPosition(hub->bulle, (sfVector2f){1340, 380});
        sfRenderWindow_drawSprite(m->window, hub->bulle, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            m->current = 7;
        }
    }
}

void passages_mondes4_5(Global_t *m, hub_t *hub)
{
    if (hub->color.r == 0 && hub->color.g == 255 && hub->color.b == 255
    && m->zone3.is_w3_clear == true && m->zone4.is_w4_clear == false) {
        sfSprite_setPosition(hub->bulle, (sfVector2f){325, 675});
        sfRenderWindow_drawSprite(m->window, hub->bulle, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            m->current = 4;
        }
    }
    if (hub->color.r == 0 && hub->color.g == 0 && hub->color.b == 255
    && m->zone4.is_w4_clear == true && m->zone5.is_w5_clear == false) {
        sfSprite_setPosition(hub->bulle, (sfVector2f){25, 165});
        sfRenderWindow_drawSprite(m->window, hub->bulle, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            m->current = 5;
        }
    }
}

void passages_mondes2_3(Global_t *m, hub_t *hub)
{
    if (hub->color.r == 0 && hub->color.g == 255 && hub->color.b == 0
    && m->zone1.is_w1_clear == true && m->zone2.is_w2_clear == false) {
        sfSprite_setPosition(hub->bulle, (sfVector2f){858, -7});
        sfRenderWindow_drawSprite(m->window, hub->bulle, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            m->current = 2;
        }
    }
    if (hub->color.r == 150 && hub->color.g == 150 && hub->color.b == 0
    && m->zone2.is_w2_clear == true && m->zone3.is_w3_clear == false) {
        sfSprite_setPosition(hub->bulle, (sfVector2f){320, 550});
        sfRenderWindow_drawSprite(m->window, hub->bulle, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            m->current = 3;
        }
    }
}

static void passages_mondes1(Global_t *m, hub_t *hub)
{
    if ((hub->color.r == 50 && hub->color.g == 50 && hub->color.b == 50)) {
        sfSprite_setPosition(hub->bulle, (sfVector2f){310, 35});
        sfRenderWindow_drawSprite(m->window, hub->bulle, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            m->shop.is_select = false;
            m->current = 9;
        }
    }
    if (hub->color.r == 150 && hub->color.g == 0 && hub->color.b == 0
    && m->zone1.is_w1_clear == false) {
        sfSprite_setPosition(hub->bulle, (sfVector2f){625, 285});
        sfRenderWindow_drawSprite(m->window, hub->bulle, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE)) {
            m->current = 1;
        }
    }
}

void passages_mondes(Global_t *m, hub_t *hub)
{
    passages_mondes1(m, hub);
    passages_mondes2_3(m, hub);
    passages_mondes4_5(m, hub);
    passages_mondes6_7(m, hub);
    passages_mondes8(m, hub);
    return;
}
