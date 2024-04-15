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
    sfTexture *texture = sfTexture_createFromFile("assets/", NULL);

    return sprite;
}

int inventory(Global_t *m, sfEvent event)
{
    m->perso.inv.inventory = set_inv_fond(m);
    return 0;
}
