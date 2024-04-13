/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** menu.c
*/
#include "rpg.h"

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

void init_menu(sfRenderWindow *window, Sprite_t *s)
{
    s->menu.test = init_text("MY RPG", 50, (sfVector2f){50, 25});
}

void draw_menu(sfRenderWindow *window, Sprite_t *s)
{
    sfRenderWindow_drawText(window, s->menu.test, NULL);
}

void destroy_menu(sfRenderWindow *window, Sprite_t *s)
{
    sfText_destroy(s->menu.test);
}
