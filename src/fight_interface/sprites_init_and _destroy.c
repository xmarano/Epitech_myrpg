/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** lifebar.c
*/

#include "../include/perso.h"
#include "../rpg.h"

void destroy_fight_sprites(fight_t *f)
{
    sfSprite_destroy(f->sprite_atk);
    sfSprite_destroy(f->sprite_def);
    sfTexture_destroy(f->texture_atk);
    sfTexture_destroy(f->texture_def);
}

void init_fight_sprites(Perso_t *atk, Perso_t *def, fight_t *f, Global_t *m)
{
    f->sprite_atk = sfSprite_create();
    f->texture_atk = sfTexture_createFromFile(atk->texture_battle, NULL);
    f->sprite_def = sfSprite_create();
    f->texture_def = sfTexture_createFromFile(def->texture_battle, NULL);
    f->has_def_attacked = sfFalse;

    sfSprite_setTexture(f->sprite_atk, f->texture_atk, sfFalse);
    sfSprite_setTextureRect(f->sprite_atk, (sfIntRect){0, 511 + 65 * 3, 65, 65});
    sfSprite_setPosition(f->sprite_atk, (sfVector2f){500, 450});
    sfSprite_setScale(f->sprite_atk, (sfVector2f){3, 3});
    sfSprite_setTexture(f->sprite_def, f->texture_def, sfFalse);
    sfSprite_setTextureRect(f->sprite_def, (sfIntRect){0, 511 + 65, 65, 65});
    sfSprite_setPosition(f->sprite_def, (sfVector2f){1225, 450});
    sfSprite_setScale(f->sprite_def, (sfVector2f){3, 3});
}