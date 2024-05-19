/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** menu_option.c
*/

#include "../rpg.h"
#include "../include/menu.h"

void return_and_old_current(Global_t *m, int value)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        m->old_current = value;
        m->current = 20;
    }
}

static void check_globalbounds(Global_t *m)
{
    m->o.gb_b1 = sfRectangleShape_getGlobalBounds(m->o.button1);
    m->o.gb_b2 = sfRectangleShape_getGlobalBounds(m->o.button2);
    m->o.gb_b3 = sfRectangleShape_getGlobalBounds(m->o.button3);
    m->o.gb_b4 = sfRectangleShape_getGlobalBounds(m->o.button4);
}

void init_menu_option(Global_t *m)
{
    m->o.fond = init_sprite("assets/loading/back.png", (sfVector2f){0, 0});
    m->o.button1 = init_button(m, (sfVector2f){325, 100}, 295);
    m->o.button2 = init_button(m, (sfVector2f){325, 100}, 445);
    m->o.button3 = init_button(m, (sfVector2f){325, 100}, 595);
    m->o.button4 = init_button(m, (sfVector2f){400, 100}, 745);
    m->o.text1 = init_text(m, "RESUME", 60, 300);
    m->o.text2 = init_text(m, "SAVE", 60, 450);
    m->o.text2_1 = init_text(m, "SAVED", 60, 450);
    m->o.text3 = init_text(m, "SETTINGS", 60, 600);
    m->o.text4 = init_text(m, "SAVE & QUIT", 60, 750);
    sfText_setColor(m->o.text2_1, sfColor_fromRGB(0, 125, 0));
    check_globalbounds(m);
}

static void check_hover(Global_t *m, hub_t *h)
{
    hover(m, m->o.button1, &m->o.gb_b1);
    click(m, &m->o.gb_b1, 0);
    hover(m, m->o.button2, &m->o.gb_b2);
    if (sfFloatRect_contains(&m->o.gb_b2, m->mouse.x, m->mouse.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRectangleShape_setOutlineColor(m->o.button2, sfWhite);
            save_game(m);
            m->o.is_saved = 1;
        } else
            sfRectangleShape_setOutlineColor(m->o.button2, sfBlack);
    }
    hover(m, m->o.button3, &m->o.gb_b3);
    if (sfFloatRect_contains(&m->o.gb_b3, m->mouse.x, m->mouse.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            m->old_current = m->current;
            m->current = 13;
            init_setting(m);
        }
    }
    hover(m, m->o.button4, &m->o.gb_b4);
    if (sfFloatRect_contains(&m->o.gb_b4, m->mouse.x, m->mouse.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            save_game(m);
            usleep(1000000);
            m->current = 10;
        }
    }
}

void draw_menu_option(Global_t *m, hub_t *h)
{
    if (m->current == 20) {
        check_hover(m, h);
        sfRenderWindow_setView(m->window, h->normal_view);
        sfRenderWindow_drawSprite(m->window, m->o.fond, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->o.button1, NULL);
        sfRenderWindow_drawText(m->window, m->o.text1, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->o.button2, NULL);
        if (m->o.is_saved == 1)
            sfRenderWindow_drawText(m->window, m->o.text2_1, NULL);
        else
            sfRenderWindow_drawText(m->window, m->o.text2, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->o.button3, NULL);
        sfRenderWindow_drawText(m->window, m->o.text3, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->o.button4, NULL);
        sfRenderWindow_drawText(m->window, m->o.text4, NULL);
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
    sfRectangleShape_destroy(m->o.button2);
    sfRectangleShape_destroy(m->o.button3);
    sfRectangleShape_destroy(m->o.button4);
    sfText_destroy(m->o.text1);
    sfText_destroy(m->o.text2);
    sfText_destroy(m->o.text2_1);
    sfText_destroy(m->o.text3);
    sfText_destroy(m->o.text4);
}
