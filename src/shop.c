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

static sfSprite *init_sprit(char *filename, sfVector2f pos, sfVector2f size)
{
    sfTexture *texture = sfTexture_createFromFile(filename, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, size);
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

void destroy_shop(Global_t *m)
{
    sfSprite_destroy(m->shop.shop);
    sfTexture_destroy(m->shop.Shop);
}

void init_shop(Global_t *m)
{
    sfVector2f pose = {440, 240};
    sfVector2f size = {0.5, 0.5};

    m->shop.shop = init_sprit("assets/shop/shop.png", pose, size);
    size.x = size.y = 1.3;
    pose.x = 640;
    pose.y = 440;
    m->weapons[COMMON_SWORD].sprite = init_sprit(m->weapons[COMMON_SWORD].link_texture, pose, size);
}

void draw_shop(Global_t *m)
{
    if (m->current == 9) {
        sfRenderWindow_drawSprite(m->window ,m->shop.shop, NULL);
        sfRenderWindow_drawSprite(m->window, m->weapons[COMMON_SWORD].sprite, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            m->current = 12;
    }
    return;
}
