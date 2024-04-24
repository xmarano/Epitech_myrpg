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

void destroy_shop(Global_t *m)
{
    sfSprite_destroy(m->shop.shop);
    sfTexture_destroy(m->shop.Shop);
    return;
}

void init_shop(Global_t *m)
{
    m->shop.shop = sfSprite_create();
    m->shop.Shop = sfTexture_createFromFile("assets/shop/shop.png", NULL);
    sfSprite_setScale(m->shop.shop, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(m->shop.shop, (sfVector2f){463, 240});
    sfSprite_setTexture(m->shop.shop, m->shop.Shop, sfFalse);
    return;
}

void draw_shop(Global_t *m)
{
    if (m->current == 9) {
        sfRenderWindow_drawSprite(m->window ,m->shop.shop, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            m->current = 12;
    }
    return;
}
