/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** menu_option.c
*/

#include "../rpg.h"
#include "../include/menu.h"

void init_menu_option(Global_t *m)
{
    m->o.fond = init_sprite("assets/loading/back.png", (sfVector2f){0, 0});
    //check_globalbounds(m);
}

void draw_menu_option(Global_t *m, hub_t *h)
{
    if (m->current == 20) {
        sfRenderWindow_setView(m->window, h->normal_view);
        sfRenderWindow_drawSprite(m->window, m->o.fond, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyH))
            m->current = m->old_current;
        if (sfKeyboard_isKeyPressed(sfKeyF)) {
            save_game(m, h);
            sfRenderWindow_close(m->window);
        }
    }
}

void destroy_menu_option(Global_t *m)
{
    sfSprite_destroy(m->o.fond);
}
