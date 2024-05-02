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
    h->view = sfView_createFromRect((sfFloatRect){0, 0, 1408, 800});
    h->rect = (sfIntRect){0, 512 + 65 * 2, 65, 65};
    h->sprite_perso = sfSprite_create();
    h->texture_hub = sfTexture_createFromFile("maps/map.png", NULL);
    h->sprite_hub = sfSprite_create();
    h->normal_view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    h->movement = (sfVector2f){0, 0};
    h->hitbox = sfImage_createFromFile("maps/map_d.png");
    sfSprite_setTexture(h->sprite_hub, h->texture_hub, sfFalse);
    sfSprite_setTextureRect(h->sprite_perso, h->rect);
    sfSprite_setPosition(h->sprite_perso, (sfVector2f){694, 380});
    sfSprite_setScale(h->sprite_perso, (sfVector2f){0.7, 0.7});
}

void draw_hub(Global_t *m, hub_t *h)
{
    if (m->current == 12) { /* temporaire normalement m->current == 0*/
        if (m->perso->is_visible) {
            if (sfView_getSize(h->view).x < 1920 || sfView_getSize(h->view).y < 1080) {
                sfView_zoom(h->view, 1.05f);
            }
            sfRenderWindow_setView(m->window, h->normal_view);
        } else if (!m->perso->is_visible) {
            if (sfView_getSize(h->view).x > 860 || sfView_getSize(h->view).y > 800) {
                sfView_zoom(h->view, 0.95f);
            }
            sfRenderWindow_setView(m->window, h->view);
        }
        if (h->texture_perso != NULL) {
            sfTexture_destroy(h->texture_perso);
            h->texture_perso = NULL;
        }
        h->texture_perso = sfTexture_createFromFile(m->perso[m->perso->current_perso].texture_battle, NULL);
        sfSprite_setTexture(h->sprite_perso, h->texture_perso, sfTrue);
        sfRenderWindow_drawSprite(m->window, h->sprite_hub, NULL);
        if (!m->perso->is_visible)
            moveCharacter(m, h);
    }
}

void moveCharacter(Global_t *m, hub_t *hub)
{
    int tic = 0;
    float seconds;

    hub->movement = (sfVector2f){0, 0};
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
    hub->what_word = sfImage_getPixel(hub->hitbox, (hub->pos_sprite.x + hub->movement.x + 20), (hub->pos_sprite.y + hub->movement.y + 37));
    if ((hub->what_word.r == 50 && hub->what_word.b == 50 && hub->what_word.g == 50) || sfKeyboard_isKeyPressed(sfKeyH))
            m->current = 9;
    hub->color = sfImage_getPixel(hub->hitbox, (hub->pos_sprite.x + hub->movement.x + 20), (hub->pos_sprite.y + hub->movement.y + 37));
    if (hub->color.r != 255 && hub->pos_sprite.x + hub->movement.x > 0 && hub->pos_sprite.x + hub->movement.x < 1375 && hub->pos_sprite.y + hub->movement.y > 0 && hub->pos_sprite.y + hub->movement.y < 760) {
        sfSprite_move(hub->sprite_perso, hub->movement);
        if (hub->pos_sprite.x + hub->movement.x > 408 && hub->pos_sprite.x + hub->movement.x < 1375 - 408) {
            sfView_move(hub->view, (sfVector2f){hub->movement.x, 0});
        }
        if (hub->pos_sprite.y + hub->movement.y > 217 && hub->pos_sprite.y + hub->movement.y < 750 - 213) {
            sfView_move(hub->view, (sfVector2f){0, hub->movement.y});
        }
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
