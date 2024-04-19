/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** set_weapons.c
*/

#include "../my.h"
#include "../rpg.h"
#include "../include/perso.h"

static void weapon_slot1(Global_t *m, int who)
{
    sfSprite *weapon = sfSprite_create();
    char *filename = m->perso[who].current_weapon->link_texture;
    sfTexture *Weapon = sfTexture_createFromFile(filename, NULL);

    sfSprite_setTexture(weapon, Weapon, sfTrue);
    sfSprite_setPosition(weapon, (sfVector2f){980, 443});
    sfSprite_setScale(weapon, (sfVector2f){1.9, 1.9});
    sfRenderWindow_drawSprite(m->window, weapon, NULL);
    sfSprite_destroy(weapon);
    sfTexture_destroy(Weapon);
}

void weapons_inv_stat(Global_t *m)
{
    int who = m->perso->current_perso;

    weapon_slot1(m, who);
    //if (m->current) // weapon acheter au shop
}
