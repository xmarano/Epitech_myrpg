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
    m->menu.background = init_sprite("assets/menu/map_background.png", (sfVector2f){0, 0});
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
