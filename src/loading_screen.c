/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** loading_screen.c
*/

#include "rpg.h"
#include "include/perso.h"
#include "include/menu.h"
#include "include/worlds.h"

static sfSprite *init_sprit(char *filename, sfVector2f pos, sfVector2f size)
{
    sfTexture *texture = sfTexture_createFromFile(filename, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, size);
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

void destroy_loading(Global_t *m)
{
    sfSprite_destroy(m->loading.fond);
    sfSprite_destroy(m->loading.vert);
    sfSprite_destroy(m->loading.text);
    sfSprite_destroy(m->loading.back_screen);
    sfTexture_destroy(m->loading.Fond);
    sfTexture_destroy(m->loading.Vert);
    sfTexture_destroy(m->loading.Text);
    sfTexture_destroy(m->loading.Back_screen);
}

void init_loading(Global_t *m)
{
    m->loading.fond = init_sprit("assets/loading/barre.png", (sfVector2f){760, 480}, (sfVector2f){9, 9});
    m->loading.vert = init_sprit("assets/loading/vert.png", (sfVector2f){760, 480}, (sfVector2f){9, 9});
    m->loading.text = init_sprit("assets/loading/load.png", (sfVector2f){760, 480}, (sfVector2f){9, 9});
    m->loading.back_screen = init_sprit("assets/loading/back.png", (sfVector2f){0, 0}, (sfVector2f){1, 1});
}

void loading_screen(Global_t *m)
{
    sfVector2f vert_pose = {760, 480};
    sfClock *clock = sfClock_create();
    sfTime time;
    float elapsed_time;

    if (m->current == 14) {
        sfRenderWindow_drawSprite(m->window, m->loading.back_screen, NULL);
        sfRenderWindow_drawSprite(m->window, m->loading.text, NULL);
        for (int i = 0; i < 14; ++i) {
            sfSprite_setPosition(m->loading.vert, vert_pose);
            sfRenderWindow_drawSprite(m->window, m->loading.vert, NULL);
            sfRenderWindow_drawSprite(m->window, m->loading.fond, NULL);
            sfRenderWindow_display(m->window);
            time = sfClock_getElapsedTime(clock);
            elapsed_time = sfTime_asSeconds(time);
            while (sfTime_asSeconds(sfClock_getElapsedTime(clock)) - elapsed_time < 0.3f);
            vert_pose.x += 27;
        }
        sfClock_destroy(clock);
        time = sfClock_getElapsedTime(clock);
        elapsed_time = sfTime_asSeconds(time);
        while (sfTime_asSeconds(sfClock_getElapsedTime(clock)) - elapsed_time < 0.2f);
        m->current = 12;
    }
}
