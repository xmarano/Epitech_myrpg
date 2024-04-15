/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** init.c
*/
#include "rpg.h"

sfSprite *init_sprite(char *filename, sfVector2f pos)
{
    sfTexture *texture = sfTexture_createFromFile(filename, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

sfText *init_text(char *str, int size, sfVector2f pos)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/text.ttf");

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, sfWhite);
    sfText_setString(text, str);
    sfText_setPosition(text, pos);
    return text;
}
