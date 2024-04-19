/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "rpg.h"
#include <SFML/Graphics.h>

void modify_size(sfVector2i mouse, Global_t *m)
{
    sfFloatRect bigzBounds = sfSprite_getGlobalBounds(m->setting.bigz);
    sfFloatRect mediumzBounds = sfSprite_getGlobalBounds(m->setting.mediumz);
    sfFloatRect littlezBounds = sfSprite_getGlobalBounds(m->setting.littlez);

    if (m->setting.displaySizeOptions) {
        if (sfFloatRect_contains(&littlezBounds, mouse.x, mouse.y)) {
            sfMouse_setPositionRenderWindow((sfVector2i){mouse.x, mouse.y},
            m->window);
            sfRenderWindow_setSize(m->window, (sfVector2u){800, 600});
        }
        if (sfFloatRect_contains(&mediumzBounds, mouse.x, mouse.y)) {
            sfMouse_setPositionRenderWindow((sfVector2i){mouse.x, mouse.y},
            m->window);
            sfRenderWindow_setSize(m->window, (sfVector2u){1280, 720});
        }
        if (sfFloatRect_contains(&bigzBounds, mouse.x, mouse.y)) {
            sfMouse_setPositionRenderWindow((sfVector2i){mouse.x, mouse.y},
            m->window);
            sfRenderWindow_setSize(m->window, (sfVector2u){1920, 1080});
        }
    }
}

void event_setting(sfEvent event, Global_t *m)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(m->window);
    sfFloatRect sizeBounds = sfSprite_getGlobalBounds(m->setting.size);
    sfFloatRect textebounds = sfSprite_getGlobalBounds(m->setting.synopsis);
    sfFloatRect creditBounds = sfSprite_getGlobalBounds(m->setting.credit);
    sfFloatRect back = sfSprite_getGlobalBounds(m->setting.retourm);

    if (event.type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(&sizeBounds, mouse.x, mouse.y))
            m->setting.displaySizeOptions = !m->setting.displaySizeOptions;
        if (sfFloatRect_contains(&textebounds, mouse.x, mouse.y))
            m->setting.isSynopsisClicked = !m->setting.isSynopsisClicked;
        if (sfFloatRect_contains(&creditBounds, mouse.x, mouse.y))
            m->setting.creditbool = !m->setting.creditbool;
        if (sfFloatRect_contains(&back, mouse.x, mouse.y))
            m->current = 0;
        modify_size(mouse, m);
    }
}

void init_setting2(Global_t *m)
{
    m->setting.size = init_sprite("assets/setting/size.png",
    (sfVector2f){600, 250});
    m->setting.littlez = init_sprite("assets/setting/littlez.png",
    (sfVector2f){615, 360});
    m->setting.mediumz = init_sprite("assets/setting/mediumz.png",
    (sfVector2f){615, 440});
    m->setting.bigz = init_sprite("assets/setting/bigz.png",
    (sfVector2f){615, 520});
    m->setting.creditbool = false;
    m->setting.txtcredit = init_sprite("assets/setting/txtcredit.png",
    (sfVector2f){1000, 200});
    m->setting.retourm = init_sprite("assets/setting/retourn.png",
    (sfVector2f){20, 20});
}

void init_setting(Global_t *m)
{
    m->setting.background_s = init_sprite("assets/setting/background.png",
    (sfVector2f){0, 0});
    m->setting.credit = init_sprite("assets/setting/credit.png",
    (sfVector2f){200, 600});
    m->setting.synopsis = init_sprite("assets/setting/synopsis.png",
    (sfVector2f){200, 250});
    m->setting.volume = init_sprite("assets/setting/volume.png",
    (sfVector2f){600, 600});
    m->setting.end = init_sprite("assets/setting/end.png",
    (sfVector2f){580, 730});
    m->setting.volume_down = init_sprite("assets/setting/volume_down.png",
    (sfVector2f){680, 730});
    m->setting.volume_up = init_sprite("assets/setting/volume_up.png",
    (sfVector2f){780, 730});
    init_setting2(m);
    m->setting.isSynopsisClicked = false;
    m->setting.test = init_sprite("assets/setting/textsynopsis.png",
    (sfVector2f){1000, 200});
}

void init_inventaire(Global_t *m)
{
    m->perso->inv.inv_sprite.pos_cursor.x = 1010;
    m->perso->inv.inv_sprite.pos_hooved.x = 1050;
    m->perso->inv.inv_sprite.pos_cursor.y = 503;
    m->perso->inv.inv_sprite.pos_hooved.y = 503;
}

void draw_setting(Global_t *m)
{
    if (m->current == 13) {
        sfRenderWindow_drawSprite(m->window, m->setting.background_s, NULL);
        sfRenderWindow_drawSprite(m->window, m->setting.credit, NULL);
        sfRenderWindow_drawSprite(m->window, m->setting.synopsis, NULL);
        sfRenderWindow_drawSprite(m->window, m->setting.volume_down, NULL);
        sfRenderWindow_drawSprite(m->window, m->setting.volume_up, NULL);
        sfRenderWindow_drawSprite(m->window, m->setting.volume, NULL);
        sfRenderWindow_drawSprite(m->window, m->setting.size, NULL);
        sfRenderWindow_drawSprite(m->window, m->setting.end, NULL);
        sfRenderWindow_drawSprite(m->window, m->setting.retourm, NULL);
        if (m->setting.displaySizeOptions) {
            sfRenderWindow_drawSprite(m->window, m->setting.littlez, NULL);
            sfRenderWindow_drawSprite(m->window, m->setting.mediumz, NULL);
            sfRenderWindow_drawSprite(m->window, m->setting.bigz, NULL);
        }
        if (m->setting.isSynopsisClicked)
            sfRenderWindow_drawSprite(m->window, m->setting.test, NULL);
        if (m->setting.creditbool)
            sfRenderWindow_drawSprite(m->window, m->setting.txtcredit, NULL);
    }
}
