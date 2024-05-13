/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "rpg.h"
#include "include/perso.h"
#include "include/menu.h"

void event_click(Global_t *m)
{
    if (m->event.type == sfEvtClosed || m->current == -1)
        sfRenderWindow_close(m->window);
    if (m->current == 12)
        inventory(m, m->event);
    if (m->current == 13)
        event_setting(m->event, m);
    if (sfKeyboard_isKeyPressed(sfKeyU) == sfTrue && m->current != 100)
        m->current = 100;
}

void rpg(Global_t *m, hub_t *h, fight_t *f)
{
    m->show_mouse = true;
    m->mouse = sfMouse_getPositionRenderWindow(m->window);
    sfRenderWindow_clear(m->window, sfBlack);
    while (sfRenderWindow_pollEvent(m->window, &m->event))
        event_click(m);
    draw_menu(m);
    draw_select_perso(m);
    draw_setting(m);
    draw_shop(m);
    draw_hub(m, h);
    draw_inventaire(m);
    draw_mouse(m);
    init_lifebars(f, m);
    loading_screen(m);
    sfRenderWindow_display(m->window);
}

static void annihilateur2sprite(Global_t *m)
{
    destroy_inventaire(m);
    destroy_menu(m);
    destroy_shop(m);
    destroy_select_perso(m);
    destroy_loading(m);
}

static void initalisateur2sprite(Global_t *m)
{
    import_weapons_stats(m);
    setup_stat(m);
    init_menu(m);
    init_inventaire(m);
    init_shop(m);
    init_pose(m);
    init_loading(m);
}

int main(int argc, char **argv)
{
    Global_t m = {0};
    hub_t h = {0};
    fight_t f = {0};
    sfVideoMode mode = {1920, 1080, 32};

    if (argc != 1)
        return 84;
    m.window = sfRenderWindow_create(mode, "My Rpg", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(m.window, 60);
    initalisateur2sprite(&m);
    init_hub(&h, &m);
    init_select_perso(&m);
    init_lifebars(&m, &f);
    while (sfRenderWindow_isOpen(m.window))
        rpg(&m, &h, &f);
    }
    destroy_hub(&h);
    destroy_fight_struct(&f);
    annihilateur2sprite(&m);
    sfClock_destroy(m.clock);
    sfSprite_destroy(m.menu.cursor);
    sfRenderWindow_destroy(m.window);
    return 0;
}
