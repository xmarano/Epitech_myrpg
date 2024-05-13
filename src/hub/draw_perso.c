/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** draw_perso.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"

static int movement2(hub_t *hub, int tic)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        hub->movement.x -= SPEED;
        hub->rect.top = 515 + 65;
        tic = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        hub->movement.x += SPEED;
        hub->rect.top = 511 + 65 * 3;
        tic = 1;
    }
    return tic;
}

static int movement(hub_t *hub)
{
    int tic = 0;

    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        hub->movement.y -= SPEED;
        hub->rect.top = 515;
        tic = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        hub->movement.y += SPEED;
        hub->rect.top = 512 + 65 * 2;
        tic = 1;
    }
    return movement2(hub, tic);
}

void draw_pouilleux(Global_t *m, hub_t *h)
{
    sfSprite_setPosition(h->pouilleux, (sfVector2f){550, 330});
    if (m->zone1.is_w1_clear == true)
        sfSprite_setPosition(h->pouilleux, (sfVector2f){830, 0});
    if (m->zone2.is_w2_clear == true)
        sfSprite_setPosition(h->pouilleux, (sfVector2f){289, 595});
    if (m->zone3.is_w3_clear == true)
        sfSprite_setPosition(h->pouilleux, (sfVector2f){300, 705});
    if (m->zone4.is_w4_clear == true)
        sfSprite_setPosition(h->pouilleux, (sfVector2f){0, 210});
    if (m->zone5.is_w5_clear == true)
        sfSprite_setPosition(h->pouilleux, (sfVector2f){1342, 635});
    if (m->zone6.is_w6_clear == true)
        sfSprite_setPosition(h->pouilleux, (sfVector2f){1342, 405});
    if (m->zone7.is_w7_clear == true)
        sfSprite_setPosition(h->pouilleux, (sfVector2f){1160, 0});
    if (m->zone8.is_w8_clear == true)
        sfSprite_setPosition(h->pouilleux, (sfVector2f){-100, -100});
    sfRenderWindow_drawSprite(m->window, h->pouilleux, NULL);
}

void les_colisions(Global_t *m, hub_t *hub)
{
    if (hub->color.r != 255 && hub->pos_sprite.x + hub->movement.x > 0 &&
    hub->pos_sprite.x + hub->movement.x < 1375 && hub->pos_sprite.y +
    hub->movement.y > 0 && hub->pos_sprite.y + hub->movement.y < 760) {
        sfSprite_move(hub->sprite_perso, hub->movement);
        if (hub->pos_sprite.x + hub->movement.x > 408 && hub->pos_sprite.x +
        hub->movement.x < 1375 - 408) {
            sfView_move(hub->view, (sfVector2f){hub->movement.x, 0});
        }
        if (hub->pos_sprite.y + hub->movement.y > 217 && hub->pos_sprite.y +
        hub->movement.y < 750 - 213) {
            sfView_move(hub->view, (sfVector2f){0, hub->movement.y});
        }
    }
}

static void passages_mondes(Global_t *m, hub_t *hub)
{
    return;
}

void movecharacter2(Global_t *m, hub_t *hub)
{
    hub->pos_sprite = sfSprite_getPosition(hub->sprite_perso);
    hub->what_word = sfImage_getPixel(hub->hitbox, (hub->pos_sprite.x +
    hub->movement.x + 20), (hub->pos_sprite.y + hub->movement.y + 37));
    if ((hub->what_word.r == 50 && hub->what_word.g == 50 &&
    hub->what_word.b == 50) || sfKeyboard_isKeyPressed(sfKeyH)) {
        m->shop.is_select = false;
        m->current = 9;
    }
    hub->color = sfImage_getPixel(hub->hitbox, (hub->pos_sprite.x +
    hub->movement.x + 20), (hub->pos_sprite.y + hub->movement.y + 37));
    les_colisions(m, hub);
    passages_mondes(m, hub);
    sfSprite_setTextureRect(hub->sprite_perso, hub->rect);
    sfRenderWindow_drawSprite(m->window, hub->sprite_perso, NULL);
    draw_pouilleux(m, hub);
}

void movecharacter(Global_t *m, hub_t *hub)
{
    float seconds;
    int tic;

    hub->movement = (sfVector2f){0, 0};
    tic = movement(hub);
    hub->time = sfClock_getElapsedTime(m->clock);
    seconds = hub->time.microseconds / 1000000.0;
    if (seconds > 0.09) {
        if (hub->rect.left < (64 * 8) && tic == 1)
            hub->rect.left += 64;
        else
            hub->rect.left = 0;
        sfClock_restart(m->clock);
    }
    movecharacter2(m, hub);
}
