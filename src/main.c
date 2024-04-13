/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "rpg.h"

void event_click(sfRenderWindow *window, sfEvent event, Sprite_t *s)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

void rpg(sfRenderWindow *window, Sprite_t *s)
{
    sfEvent event;

    s->mouse = sfMouse_getPositionRenderWindow(window);
    sfRenderWindow_clear(window, sfBlack);
    while (sfRenderWindow_pollEvent(window, &event))
        event_click(window, event, s);
    draw_menu(window, s);
    sfRenderWindow_display(window);
}

int main(int argc, char **argv)
{
    Sprite_t s;
    sfVideoMode mode = {1920 / 3, 1080 / 3, 32};
    sfRenderWindow *window;

    if (argc != 1)
        return 84;
    window = sfRenderWindow_create(mode, "My Rpg", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    init_menu(window, &s);
    while (sfRenderWindow_isOpen(window))
        rpg(window, &s);
    destroy_menu(window, &s);
    sfRenderWindow_destroy(window);
    return 0;
}
