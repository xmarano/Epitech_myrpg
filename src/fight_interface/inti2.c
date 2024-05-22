/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** inti2.c
*/

#include "../include/perso.h"
#include "../rpg.h"

void init_lifebars2(fight_t *fight, Global_t *m)
{
    fight->empty_bar_sprite2 = sfSprite_create();
    fight->hero_lifebar_sprite2 = sfSprite_create();
    fight->ennemy_bar_sprite2 = sfSprite_create();
    sfSprite_setScale(fight->empty_bar_sprite2, (sfVector2f){8, 8});
    sfSprite_setTexture(fight->empty_bar_sprite2, fight->globat_texture, sfFalse);
    sfSprite_setTextureRect(fight->empty_bar_sprite2, fight->rect_empty_bar2);
    sfSprite_setTexture(fight->ennemy_bar_sprite2, fight->globat_texture, sfFalse);
    sfSprite_setTexture(fight->hero_lifebar_sprite2, fight->globat_texture, sfFalse);
}
