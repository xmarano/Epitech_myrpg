/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** set_sprite.c
*/

#include "../my.h"
#include "../rpg.h"
#include "../include/perso.h"


sfRectangleShape *hoov(Global_t *m, sfVector2f popo, sfVector2f siz, float f)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setPosition(rect, popo);
    sfRectangleShape_setSize(rect, siz);
    sfRectangleShape_setOutlineColor(rect, sfBlack);
    sfRectangleShape_setOutlineThickness(rect, f);
    return rect;
}

sfSprite *set_cursor(Global_t *m)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {0.3, 0.3};
    sfVector2f pos = {1010, 503};
    sfTexture *Cursor = m->perso->inv.inv_sprite.Cursor;

    Cursor = sfTexture_createFromFile("assets/inv/cursor.png", NULL);
    sfSprite_setTexture(sprite, Cursor, sfFalse);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

sfSprite *set_inv_fond(Global_t *m)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {700, 380};
    sfVector2f scale = {2.9, 2.9};
    sfTexture *Inv = m->perso->inv.inv_sprite.Inventory;

    Inv = sfTexture_createFromFile("assets/inv/inv_fond.png", NULL);
    sfSprite_setTexture(sprite, Inv, sfFalse);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

sfSprite *set_inv_fond2(Global_t *m)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {992, 380};
    sfVector2f scale = {2.9, 2.9};
    sfTexture *Inv2 = m->perso->inv.inv_sprite.Inventory2;

    Inv2 = sfTexture_createFromFile("assets/inv/inv_fond2.png", NULL);
    sfSprite_setTexture(sprite, Inv2, sfFalse);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    return sprite;
}
