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
    m->select.fond = init_sprite("assets/menu/menu.jpg", (sfVector2f){0, 0});
    m->select.title = init_text(m, "SELECTIONNEZ UN PERSONNAGE", 100, 0);
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
        sfRenderWindow_drawSprite(m->window, m->select.fond, NULL);
        sfRenderWindow_drawText(m->window, m->select.title, NULL);
    }
}

void destroy_select_perso(Global_t *m)
{
    sfSprite_destroy(m->select.fond);
    sfText_destroy(m->select.title);
    return;
}
