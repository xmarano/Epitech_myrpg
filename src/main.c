/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "rpg.h"
#include "include/inventory.h"
#include "include/menu.h"

void draw_inventaire(Global_t *m)
{
    if (m->perso.is_visible && m->perso.inv.inventory != NULL)
        sfRenderWindow_drawSprite(m->window, m->perso.inv.inventory, NULL);
    if (m->perso.is_visible2 && m->perso.inv.inventory2 != NULL) {
        sfRenderWindow_drawSprite(m->window, m->perso.inv.inventory2, NULL);
        sfRenderWindow_drawSprite(m->window, m->perso.stat_w.init.sprite, NULL);
    }
}

void event_click(sfEvent event, Global_t *m)
{
    if (event.type == sfEvtKeyPressed && (event.key.code == sfKeyS ||
    event.key.code == sfKeyLeft || event.key.code == sfKeyRight)) {
        inventory(m, event);
    }
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(m->window);
}

void rpg(Global_t *m)
{
    sfEvent event;

    m->mouse = sfMouse_getPositionRenderWindow(m->window);
    sfRenderWindow_clear(m->window, sfBlack);
    while (sfRenderWindow_pollEvent(m->window, &event))
        event_click(event, m);
    draw_menu(m);
    draw_inventaire(m);
    sfRenderWindow_display(m->window);
}

int main(int argc, char **argv)
{
    Global_t m;
    sfVideoMode mode = {1920, 1080, 32};

    if (argc != 1)
        return 84;
    m.window = sfRenderWindow_create(mode, "My Rpg", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(m.window, 60);
    init_menu(&m);
    while (sfRenderWindow_isOpen(m.window))
        rpg(&m);
    destroy_menu(&m);
    sfRenderWindow_destroy(m.window);
    return 0;
}
