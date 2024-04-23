/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "../rpg.h"
#include <SFML/Graphics.h>

void hover_rectangle(Global_t *m, sfRectangleShape *shape)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(m->window);
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(shape);
    if (sfFloatRect_contains(&bounds, mousePos.x, mousePos.y)) {
        sfRectangleShape_setOutlineColor(shape, sfColor_fromRGB(255, 255, 255));
        sfRectangleShape_setOutlineThickness(shape, 5);
    } else {
        sfRectangleShape_setOutlineColor(shape, sfColor_fromRGB(0, 0, 0));
        sfRectangleShape_setOutlineThickness(shape, 0);
    }
}

void hover_text(Global_t *m, sfText *text)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(m->window);
    sfFloatRect bounds = sfText_getGlobalBounds(text);
    if (sfFloatRect_contains(&bounds, mousePos.x, mousePos.y)) {
        sfText_setOutlineColor(text, sfColor_fromRGB(255, 255, 255));
        sfText_setOutlineThickness(text, 5);
    } else {
        sfText_setOutlineColor(text, sfColor_fromRGB(0, 0, 0));
        sfText_setOutlineThickness(text, 0);
    }
}

void check_the_hover2(Global_t *m)
{
    if (m->setting.buttonretour != NULL && &m->setting.se_1 != NULL)
        hover_rectangle(m, m->setting.buttonretour);
    if (m->setting.buttoncred != NULL && &m->setting.se_2 != NULL)
        hover_rectangle(m, m->setting.buttoncred);
    if (m->setting.buttonsynop != NULL && &m->setting.se_3 != NULL)
        hover_rectangle(m, m->setting.buttonsynop);
    if (m->setting.buttonvolum != NULL && &m->setting.se_4 != NULL)
        hover_rectangle(m, m->setting.buttonvolum);
    if (m->setting.buttonwindow != NULL && &m->setting.se_5 != NULL)
        hover_rectangle(m, m->setting.buttonwindow);
    if (m->setting.littlez != NULL && &m->setting.se_6 != NULL)
        hover_text(m, m->setting.littlez);
    if (m->setting.mediumz != NULL && &m->setting.se_7 != NULL)
        hover_text(m, m->setting.mediumz);
    if (m->setting.bigz != NULL && &m->setting.se_8 != NULL)
        hover_text(m, m->setting.bigz);
    if (m->setting.volumeb != NULL && &m->setting.se_9 != NULL)
        hover_text(m, m->setting.volumeb);
    if (m->setting.volumeh != NULL && &m->setting.se_10 != NULL)
        hover_text(m, m->setting.volumeh);
    if (m->setting.cvolume != NULL && &m->setting.se_11 != NULL)
        hover_text(m, m->setting.cvolume);
}

void check_globalbounds2(Global_t *m)
{
    if (m->setting.buttonretour != NULL)
        m->setting.se_1 = sfRectangleShape_getGlobalBounds(m->setting.buttonretour);
    if (m->setting.buttoncred != NULL)
        m->setting.se_2 = sfRectangleShape_getGlobalBounds(m->setting.buttoncred);
    if (m->setting.buttonsynop != NULL)
        m->setting.se_3 = sfRectangleShape_getGlobalBounds(m->setting.buttonsynop);
    if (m->setting.buttonvolum != NULL)
        m->setting.se_4 = sfRectangleShape_getGlobalBounds(m->setting.buttonvolum);
    if (m->setting.buttonwindow != NULL)
        m->setting.se_5 = sfRectangleShape_getGlobalBounds(m->setting.buttonwindow);
    if (m->setting.littlez != NULL)
        m->setting.se_6 = sfText_getGlobalBounds(m->setting.littlez);
    if (m->setting.mediumz != NULL)
        m->setting.se_7 = sfText_getGlobalBounds(m->setting.mediumz);
    if (m->setting.bigz != NULL)
        m->setting.se_8 = sfText_getGlobalBounds(m->setting.bigz);
    if (m->setting.volumeb != NULL)
        m->setting.se_9 = sfText_getGlobalBounds(m->setting.volumeb);
    if (m->setting.volumeh != NULL)
        m->setting.se_10 = sfText_getGlobalBounds(m->setting.volumeh);
    if (m->setting.cvolume != NULL)
        m->setting.se_11 = sfText_getGlobalBounds(m->setting.cvolume);
}
