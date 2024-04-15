/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** setup_inv.c
*/

#include "my.h"
#include "rpg.h"
#include "menu.h"
#include "include/inventory.h"

sfSprite *set_weapon(Global_t *m, char *filename, sfVector2f size, sfVector2f scale)
{
    sfSprite *sprite = sfSprite_create();

    m->perso.stat_w.init.texture = sfTexture_createFromFile("assets/inv/weapons/axe1.png", NULL);
    sfSprite_setTexture(sprite, m->perso.stat_w.init.texture, sfFalse);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

