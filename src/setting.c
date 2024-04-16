/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "rpg.h"
#include <SFML/Graphics.h>

void init_setting(Global_t *m)
{
    m->setting.background_s = init_sprite("assets/setting/background.png", (sfVector2f){0, 0});
    m->setting.credit = init_sprite("assets/setting/credit.png", (sfVector2f){200, 600});
    m->setting.synopsis = init_sprite("assets/setting/synopsis.png", (sfVector2f){200, 250});
    m->setting.size = init_sprite("assets/setting/size.png", (sfVector2f){600, 250});
    m->setting.littlez = init_sprite("assets/setting/littlez.png", (sfVector2f){615, 360});
    m->setting.mediumz = init_sprite("assets/setting/mediumz.png", (sfVector2f){615, 440});
    m->setting.bigz = init_sprite("assets/setting/bigz.png", (sfVector2f){615, 520});
    m->setting.volume = init_sprite("assets/setting/volume.png", (sfVector2f){600, 600});
    m->setting.end = init_sprite("assets/setting/end.png", (sfVector2f){580, 730});
    m->setting.volume_down = init_sprite("assets/setting/volume_down.png", (sfVector2f){680, 730});
    m->setting.volume_up = init_sprite("assets/setting/volume_up.png", (sfVector2f){780, 730});
    m->setting.toto = 0;
}

void draw_size(Global_t *m)
{
    sfRenderWindow_drawSprite(m->window, m->setting.littlez, NULL);
    sfRenderWindow_drawSprite(m->window, m->setting.mediumz, NULL);
    sfRenderWindow_drawSprite(m->window, m->setting.bigz, NULL);
}

void draw_setting(Global_t *m)
{
    if (m->setting.toto % 2 == 1) {
        sfRenderWindow_drawSprite(m->window, m->setting.background_s, NULL);
        sfRenderWindow_drawSprite(m->window, m->setting.credit, NULL);
        sfRenderWindow_drawSprite(m->window, m->setting.synopsis, NULL);
        sfRenderWindow_drawSprite(m->window, m->setting.volume_down, NULL);
        sfRenderWindow_drawSprite(m->window, m->setting.volume_up, NULL);
        sfRenderWindow_drawSprite(m->window, m->setting.volume, NULL);
        sfRenderWindow_drawSprite(m->window, m->setting.size, NULL);
        sfRenderWindow_drawSprite(m->window, m->setting.end, NULL);
    }
}

void move_size(sfEvent event, Global_t *m)
{
    if (event.type == sfEvtMouseButtonPressed) {
        sfVector2i mouse = sfMouse_getPositionRenderWindow(m->window);
        sfFloatRect bigzBounds = sfSprite_getGlobalBounds(m->setting.bigz);
        sfFloatRect mediumzBounds = sfSprite_getGlobalBounds(m->setting.mediumz);
        sfFloatRect littlezBounds = sfSprite_getGlobalBounds(m->setting.littlez);

        if (sfFloatRect_contains(&bigzBounds, mouse.x, mouse.y)) {
            sfRenderWindow_setSize(m->window, (sfVector2u){1920, 1080});
        }
        if (sfFloatRect_contains(&mediumzBounds, mouse.x, mouse.y)) {
            sfRenderWindow_setSize(m->window, (sfVector2u){1280, 720});
        }
        if (sfFloatRect_contains(&littlezBounds, mouse.x, mouse.y)) {
            sfRenderWindow_setSize(m->window, (sfVector2u){800, 600});
        }
    }
}

void event_setting(sfEvent event, Global_t *m)
{
    if (event.type == sfEvtMouseButtonPressed) {
        sfVector2i mouse = sfMouse_getPositionRenderWindow(m->window);
        sfFloatRect sizeBounds = sfSprite_getGlobalBounds(m->setting.size);

        if (sfFloatRect_contains(&sizeBounds, mouse.x, mouse.y)) {
            m->setting.toto = (m->setting.toto + 1) % 2;
        }
    }
}