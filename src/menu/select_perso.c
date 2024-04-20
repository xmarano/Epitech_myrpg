/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** select_perso.c
*/
#include "../rpg.h"
#include "../include/menu.h"

static void check_globalbounds(Global_t *m)
{
    return;
}

void init_select_perso(Global_t *m)
{
    m->menu.wsize = sfRenderWindow_getSize(m->window);
    m->menu.map = init_sprite("assets/menu/menu.jpg", (sfVector2f){0, 0});
    m->menu.title = init_text(m, "SELECTION DU PERSONNAGE", 125, 0);
    check_globalbounds(m);
}

static void check_hover(Global_t *m)
{
    return;
}

void draw_select_perso(Global_t *m)
{
    if (m->current == 11) {
        check_hover(m);
        sfRenderWindow_drawSprite(m->window, m->menu.map, NULL);
    }
}

void destroy_select_perso(Global_t *m)
{
    return;
}
