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
    m->o.button1 = init_button(m, (sfVector2f){325, 100}, 295);
    //check_globalbounds(m);
}

void draw_menu_option(Global_t *m, hub_t *h)
{
    if (m->current == 20) {
        sfRenderWindow_drawSprite(m->window, m->o.fond, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->o.button1, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyH)) {
            sfRenderWindow_setView(m->window, h->view);
            m->current = m->old_current;
        }
        if (sfKeyboard_isKeyPressed(sfKeyF)) {
            save_game(m, h);
            sfRenderWindow_close(m->window);
        }
    }
}

void destroy_menu_option(Global_t *m)
{
    sfSprite_destroy(m->o.fond);
    sfRectangleShape_destroy(m->o.button1);
}
