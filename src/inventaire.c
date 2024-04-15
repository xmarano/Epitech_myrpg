/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** inventory.c
*/

#include "my.h"
#include "rpg.h"
#include "menu.h"
#include "include/inventory.h"

sfSprite *set_inv_fond(Global_t *m)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {360, 180};

    m->perso.inv.Inventory = sfTexture_createFromFile("../assets/inv_fond.png", NULL);
    sfSprite_setTexture(sprite, m->perso.inv.Inventory, sfFalse);
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

int inventory(Global_t *m, sfEvent event)
{
    m->perso.inv.inventory = set_inv_fond(m);
    return 0;
}
