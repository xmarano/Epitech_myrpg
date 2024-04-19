/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** hub.c
*/
#include "rpg.h"
#include "include/perso.h"
#include "include/menu.h"
#include "include/worlds.h"

void init_hub (hub_t *h, Global_t *m)
{
    h->rect = (sfIntRect){0, 520 + 65 * 2, 65, 65};
    h->sprite_perso = sfSprite_create();
    h->texture_hub = sfTexture_createFromFile("maps/hub.png", NULL);
    h->sprite_hub = sfSprite_create();
    h->texture_perso = sfTexture_createFromFile(m->perso[ROY].texture_battle, NULL);
    h->movement = (sfVector2f){0, 0};
    h->hitbox = sfImage_createFromFile("maps/hub_detour.png");

    sfSprite_setTexture(h->sprite_hub, h->texture_hub, sfFalse);
    sfSprite_setScale(h->sprite_hub, (sfVector2f){2.5, 2.5});
    sfSprite_setTexture(h->sprite_perso, h->texture_perso, sfTrue);
    sfSprite_setTextureRect(h->sprite_perso, h->rect);
    sfSprite_setPosition(h->sprite_perso, (sfVector2f){800, 500}) ; 
}

void draw_hub(Global_t *m, hub_t *h)
{
    sfRenderWindow_drawSprite(m->window, h->sprite_hub, NULL);
    moveCharacter(m, h);
}

void moveCharacter(Global_t *m, hub_t *hub) {
    int tic = 0;
    float seconds;

    hub->movement = (sfVector2f){0, 0};
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        hub->movement.y -= SPEED;
        hub->rect.top = 520;
        tic = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        hub->movement.y += SPEED;
        hub->rect.top = 520 + 65 * 2;
        tic = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        hub->movement.x -= SPEED;
        hub->rect.top = 520 + 65;
        tic = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        hub->movement.x += SPEED;
        hub->rect.top = 520 + 65 * 3;
        tic = 1;
    }
    hub->time = sfClock_getElapsedTime(m->clock);
    seconds = hub->time.microseconds / 1000000.0;
    if (seconds > 0.09) {
        if (hub->rect.left < (64 * 8) && tic == 1)
            hub->rect.left += 64;
        else
            hub->rect.left = 0;
        sfClock_restart(m->clock);
    }
    hub->pos_sprite = sfSprite_getPosition(hub->sprite_perso);
    hub->color = sfImage_getPixel(hub->hitbox, (hub->pos_sprite.x + hub->movement.x) / 2.5, (hub->pos_sprite.y + hub->movement.y) / 2.5);
    if (hub->color.r != 255 && hub->pos_sprite.x + hub->movement.x > 0 && hub->pos_sprite.x + hub->movement.x < 1920 && hub->pos_sprite.y + hub->movement.y > 0 && hub->pos_sprite.y + hub->movement.y < 1080) {
        sfSprite_move(hub->sprite_perso, hub->movement);
    }
    sfSprite_setTextureRect(hub->sprite_perso, hub->rect);
    sfRenderWindow_drawSprite(m->window, hub->sprite_perso, NULL);
}

void destroy_hub(hub_t *h)
{
    sfImage_destroy(h->hitbox);
    sfSprite_destroy(h->sprite_hub);
    sfSprite_destroy(h->sprite_perso);
    sfTexture_destroy(h->texture_hub);
    sfTexture_destroy(h->texture_perso);
}