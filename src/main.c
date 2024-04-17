/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "rpg.h"
#include "include/inventory.h"
#include "include/menu.h"

void event_click(sfEvent event, Global_t *m)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(m->window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace)
        m->setting.toto++;
    inventory(m, event);
    event_setting(event, m);
}

void clock(Global_t *m)
{
    sfTime time = sfClock_getElapsedTime(m->clock);
    float seconds;

    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        sfClock_restart(m->clock);
    }
}

void rpg(Global_t *m)
{
    sfEvent event;

    m->show_mouse = true;
    m->mouse = sfMouse_getPositionRenderWindow(m->window);
    sfRenderWindow_clear(m->window, sfWhite);
    while (sfRenderWindow_pollEvent(m->window, &event))
        event_click(event, m);
    clock(m);
    draw_menu(m);
    draw_setting(m);
    draw_inventaire(m);
    draw_mouse(m);
    sfRenderWindow_display(m->window);
}

int main(int argc, char **argv)
{
    Global_t m = {0};
    sfVideoMode mode = {1920, 1080, 32};

    if (argc != 1)
        return 84;
    m.window = sfRenderWindow_create(mode, "My Rpg", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(m.window, 60);
    setup_stat(&m);
    import_weapons_stats(&m);
    init_menu(&m);
    init_setting(&m);
    init_inventaire(&m);
    while (sfRenderWindow_isOpen(m.window))
        rpg(&m);
    destroy_menu(&m);
    sfRenderWindow_destroy(m.window);
    return 0;
}
