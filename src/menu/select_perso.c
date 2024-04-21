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
    m->select.gb_b1 = sfRectangleShape_getGlobalBounds(m->select.button1);
    m->select.gb_b2 = sfRectangleShape_getGlobalBounds(m->select.button2);
    m->select.gb_b3 = sfRectangleShape_getGlobalBounds(m->select.button3);
    m->select.gb_b4 = sfRectangleShape_getGlobalBounds(m->select.button4);
    m->select.gb_b5 = sfRectangleShape_getGlobalBounds(m->select.button5);
}

void init_select_perso(Global_t *m)
{
    m->select.fond = init_sprite("assets/menu/menu.jpg", (sfVector2f){0, 0});
    m->select.title = init_text(m, "SELECTIONNEZ UN PERSONNAGE", 100, 0);
    m->select.button1 = init_button(m, (sfVector2f){200, 75}, 200);
    m->select.button2 = init_button(m, (sfVector2f){200, 75}, 300);
    m->select.button3 = init_button(m, (sfVector2f){200, 75}, 400);
    m->select.button4 = init_button(m, (sfVector2f){200, 75}, 500);
    m->select.button5 = init_button(m, (sfVector2f){200, 75}, 600);
    check_globalbounds(m);
}

static void check_hover(Global_t *m)
{
    /*  ROY  */
    hover(m, m->select.button1, &m->select.gb_b1);
    if (sfFloatRect_contains(&m->select.gb_b1, m->mouse.x, m->mouse.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            m->perso->current_perso = ROY;
            m->current = 12;
        }
    }

    /*  XMARANO  */
    hover(m, m->select.button2, &m->select.gb_b2);
    if (sfFloatRect_contains(&m->select.gb_b2, m->mouse.x, m->mouse.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            m->perso->current_perso = XMARANO;
            m->current = 12;
        }
    }

    /*  PATECARBO  */
    hover(m, m->select.button3, &m->select.gb_b3);
    if (sfFloatRect_contains(&m->select.gb_b3, m->mouse.x, m->mouse.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            m->perso->current_perso = PATECARBO;
            m->current = 12;
        }
    }

    /*  INFENIUM  */
    hover(m, m->select.button4, &m->select.gb_b4);
    if (sfFloatRect_contains(&m->select.gb_b4, m->mouse.x, m->mouse.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            m->perso->current_perso = INFENIUM;
            m->current = 12;
        }
    }

    /*  RACAILLOU  */
    hover(m, m->select.button5, &m->select.gb_b5);
    if (sfFloatRect_contains(&m->select.gb_b5, m->mouse.x, m->mouse.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            m->perso->current_perso = RACAILLOU;
            m->current = 12;
        }
    }
}

void draw_select_perso(Global_t *m)
{
    if (m->current == 11) {
        check_hover(m);
        sfRenderWindow_drawSprite(m->window, m->select.fond, NULL);
        sfRenderWindow_drawText(m->window, m->select.title, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->select.button1, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->select.button2, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->select.button3, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->select.button4, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->select.button5, NULL);
    }
}

void destroy_select_perso(Global_t *m)
{
    sfSprite_destroy(m->select.fond);
    sfText_destroy(m->select.title);
}
