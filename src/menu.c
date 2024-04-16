/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** menu.c
*/
#include "rpg.h"
#include "include/menu.h"

void init_menu(Global_t *m)
{
    sfVector2u wsize = sfRenderWindow_getSize(m->window);

    m->menu.background = init_sprite("assets/menu/map_background.png",
    (sfVector2f){0, 0});
    m->menu.title = init_text("MY RPG", 150,
    (sfVector2f){(float)(wsize.x / 2), 25});
}

void draw_menu(Global_t *m)
{
    sfRenderWindow_drawSprite(m->window, m->menu.background, NULL);
    sfRenderWindow_drawText(m->window, m->menu.title, NULL);
}

void destroy_menu(Global_t *m)
{
    sfText_destroy(m->menu.title);
}
