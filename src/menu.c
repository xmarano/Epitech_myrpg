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
    sfRenderWindow_setMouseCursorVisible(m->window, sfFalse);
    m->clock = sfClock_create();
    m->menu.wsize = sfRenderWindow_getSize(m->window);
    m->menu.map = init_sprite("assets/menu/map.png", (sfVector2f){0, 0});
    m->menu.cursor = init_sprite("assets/menu/cursor.png", (sfVector2f){0, 0});
    m->menu.title = init_text("MY RPG", 150, (sfVector2f){m->menu.wsize.x / 2, 25});
}

void draw_menu(Global_t *m)
{
    sfSprite_setScale(m->menu.map, (sfVector2f){2.0f, 2.0f});
    sfRenderWindow_drawSprite(m->window, m->menu.map, NULL);
    sfRenderWindow_drawText(m->window, m->menu.title, NULL);
}

void destroy_menu(Global_t *m)
{
    sfSprite_destroy(m->menu.map);
    sfSprite_destroy(m->menu.cursor);
    sfText_destroy(m->menu.title);
}

void draw_mouse(Global_t *m)
{
    sfVector2f pos_c = {m->mouse.x, m->mouse.y};

    sfSprite_setPosition(m->menu.cursor, pos_c);
    if (m->show_mouse == true && m->mouse.y > 0 && m->mouse.x > - 1)
        sfRenderWindow_drawSprite(m->window, m->menu.cursor, NULL);
}
