/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** menu_option.c
*/

#include "../rpg.h"
#include "../include/menu.h"

static void check_globalbounds(Global_t *m)
{
    m->o.gb_b1 = sfRectangleShape_getGlobalBounds(m->o.button1);
    m->o.gb_b2 = sfRectangleShape_getGlobalBounds(m->o.button2);
}

void init_menu_option(Global_t *m)
{
    m->o.fond = init_sprite("assets/loading/back.png", (sfVector2f){0, 0});
    m->o.button1 = init_button(m, (sfVector2f){325, 100}, 295);
    m->o.resume = init_text(m, "RESUME", 60, 300);
    m->o.button2 = init_button(m, (sfVector2f){325, 100}, 445);
    m->o.save = init_text(m, "SAVE", 60, 450);
    check_globalbounds(m);
}

static void check_hover(Global_t *m, hub_t *h)
{
    hover(m, m->o.button1, &m->o.gb_b1);
    click(m, &m->o.gb_b1, m->old_current);
    hover(m, m->o.button2, &m->o.gb_b2);
    if (sfFloatRect_contains(&m->menu.gb_b2, m->mouse.x, m->mouse.y))
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRectangleShape_setOutlineColor(m->o.button2, sfWhite);
            save_game(m, h);
            sfRenderWindow_close(m->window);
        } else
            sfRectangleShape_setOutlineColor(m->o.button2, sfBlack);
}

void draw_menu_option(Global_t *m, hub_t *h)
{
    if (m->current == 20) {
        check_hover(m, h);
        sfRenderWindow_setView(m->window, h->normal_view);
        sfRenderWindow_drawSprite(m->window, m->o.fond, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->o.button1, NULL);
        sfRenderWindow_drawText(m->window, m->o.resume, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->o.button2, NULL);
        sfRenderWindow_drawText(m->window, m->o.save, NULL);

        if (sfKeyboard_isKeyPressed(sfKeyH)) {
            sfRenderWindow_setView(m->window, h->view);
            m->current = m->old_current;
        }
    }
}

void destroy_menu_option(Global_t *m)
{
    sfSprite_destroy(m->o.fond);
    sfRectangleShape_destroy(m->o.button1);
    sfText_destroy(m->o.resume);
    sfRectangleShape_destroy(m->o.button2);
    sfText_destroy(m->o.save);
}
