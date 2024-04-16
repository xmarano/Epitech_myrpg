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

sfText *init_text(Global_t *m, char *str, int size, int pos_y)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    sfFloatRect text_pos;
    float pos_x;

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, sfBlack);
    sfText_setString(text, str);
    text_pos = sfText_getLocalBounds(text);
    pos_x = (m->menu.wsize.x - text_pos.width) / 2;
    sfText_setPosition(text, (sfVector2f){pos_x, pos_y});
    return text;
}

sfRectangleShape *init_button(sfVector2f size, sfVector2f pos)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setFillColor(shape, sfColor_fromRGB(134, 185, 104));
    sfRectangleShape_setOutlineThickness(shape, 4);
    sfRectangleShape_setOutlineColor(shape, sfColor_fromRGB(22, 40, 12));
    sfRectangleShape_setPosition(shape, pos);
    return shape;
}
