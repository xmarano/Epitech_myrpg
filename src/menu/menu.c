/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** menu.c
*/
#include "../rpg.h"

static void check_globalbounds(Global_t *m)
{
    m->menu.gb_b1 = sfRectangleShape_getGlobalBounds(m->menu.button1);
    m->menu.gb_b2 = sfRectangleShape_getGlobalBounds(m->menu.button2);
    m->menu.gb_b3 = sfRectangleShape_getGlobalBounds(m->menu.button3);
    m->menu.gb_b4 = sfRectangleShape_getGlobalBounds(m->menu.button4);
}

void init_menu(Global_t *m)
{
    sfRenderWindow_setMouseCursorVisible(m->window, sfFalse);
    m->current = 10;
    m->clock = sfClock_create();
    m->menu.wsize = sfRenderWindow_getSize(m->window);
    m->menu.map = init_sprite("assets/menu/menu.jpg", (sfVector2f){0, 0});
    m->menu.cursor = init_sprite("assets/menu/cursor.png", (sfVector2f){0, 0});
    m->menu.title = init_text(m, "MY RPG", 125, 0);
    m->menu.new_game = init_text(m, "NEW GAME", 60, 300);
    m->menu.continuer = init_text(m, "CONTINUE", 60, 450);
    m->menu.settings = init_text(m, "SETTINGS", 50, 700);
    m->menu.exit = init_text(m, "EXIT", 35, 800);
    m->menu.button1 = init_button(m, (sfVector2f){325, 100}, 295);
    m->menu.button2 = init_button(m, (sfVector2f){325, 100}, 445);
    m->menu.button3 = init_button(m, (sfVector2f){270, 83}, 695);
    m->menu.button4 = init_button(m, (sfVector2f){190, 58}, 795);
    check_globalbounds(m);
}

static void check_hover(Global_t *m)
{
    hover(m, m->menu.button1, &m->menu.gb_b1);
    if (sfFloatRect_contains(&m->menu.gb_b1, m->mouse.x, m->mouse.y))
        if (sfMouse_isButtonPressed(sfMouseLeft))
            m->current = 11;
    hover(m, m->menu.button2, &m->menu.gb_b2);
    click(m, &m->menu.gb_b2, 12);
    hover(m, m->menu.button3, &m->menu.gb_b3);
    if (sfFloatRect_contains(&m->menu.gb_b3, m->mouse.x, m->mouse.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            m->current = 13;
            init_setting(m);
        }
    }
    hover(m, m->menu.button4, &m->menu.gb_b4);
    click(m, &m->menu.gb_b4, -1);
}

void draw_menu(Global_t *m)
{
    if (m->current == 10) {
        check_hover(m);
        sfRenderWindow_drawSprite(m->window, m->menu.map, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->menu.button1, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->menu.button2, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->menu.button3, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->menu.button4, NULL);
        sfRenderWindow_drawText(m->window, m->menu.title, NULL);
        sfRenderWindow_drawText(m->window, m->menu.new_game, NULL);
        sfRenderWindow_drawText(m->window, m->menu.continuer, NULL);
        sfRenderWindow_drawText(m->window, m->menu.settings, NULL);
        sfRenderWindow_drawText(m->window, m->menu.exit, NULL);
    }
}

void destroy_menu(Global_t *m)
{
    sfSprite_destroy(m->menu.map);
    sfText_destroy(m->menu.title);
    sfText_destroy(m->menu.new_game);
    sfText_destroy(m->menu.continuer);
    sfText_destroy(m->menu.settings);
    sfText_destroy(m->menu.exit);
    sfRectangleShape_destroy(m->menu.button1);
    sfRectangleShape_destroy(m->menu.button2);
    sfRectangleShape_destroy(m->menu.button3);
    sfRectangleShape_destroy(m->menu.button4);
}

void draw_mouse(Global_t *m)
{
    sfVector2f pos_c = {m->mouse.x, m->mouse.y};

    sfSprite_setPosition(m->menu.cursor, pos_c);
    if (m->show_mouse == true && m->mouse.y > -1 && m->mouse.x > -1
    && m->current != 12 && m->current != 9)
        sfRenderWindow_drawSprite(m->window, m->menu.cursor, NULL);
}
