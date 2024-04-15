/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** menu.c
*/

#include "rpg.h"
#include "include/inventory.h"
#include "include/menu.h"

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

sfSprite *init_sprite(char *filename, sfVector2f pos)
{
    sfTexture *texture = sfTexture_createFromFile(filename, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

void init_menu(Global_t *m)
{
    m->menu.background = init_sprite("assets/fond.jpg", (sfVector2f){0, 0});
    m->menu.test = init_text("MY RPG", 50, (sfVector2f){50, 25});
}

void draw_menu(Global_t *m)
{
    sfRenderWindow_drawSprite(m->window, m->menu.background, NULL);
    sfRenderWindow_drawText(m->window, m->menu.test, NULL);
}

void destroy_menu(Global_t *m)
{
    sfText_destroy(m->menu.test);
}
