/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "../rpg.h"
#include <SFML/Graphics.h>

void max_volume(Global_t *m)
{
    float volume = sfMusic_getVolume(m->setting.music);

    if (volume + 10 < 100) {
        volume = volume + 10;
    } else {
        volume = 100;
    }
    sfMusic_setVolume(m->setting.music, volume);
}

void min_volume(Global_t *m)
{
    float volume = sfMusic_getVolume(m->setting.music);

    if (volume - 10 > 0) {
        volume = volume - 10;
    } else {
        volume = 0;
    }
    sfMusic_setVolume(m->setting.music, volume);
}

void stop_song(Global_t *m)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(m->window);
    if (m->setting.cvolume != NULL) {
        sfFloatRect bounds = sfText_getGlobalBounds(m->setting.cvolume);
        if (sfFloatRect_contains(&bounds, mousePos.x, mousePos.y)) {
            sfMusic_setVolume(m->setting.music, 0);
        }
    }
}

void verif_song(Global_t *m)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(m->window);

    if (m->setting.volumeb != NULL) {
        sfFloatRect bounds = sfText_getGlobalBounds(m->setting.volumeb);
        if (sfFloatRect_contains(&bounds, mousePos.x, mousePos.y)) {
            max_volume(m);
        }
    }
    if (m->setting.volumeh != NULL) {
        sfFloatRect bounds = sfText_getGlobalBounds(m->setting.volumeh);
        if (sfFloatRect_contains(&bounds, mousePos.x, mousePos.y)) {
            min_volume(m);
        }
    }
    stop_song(m);
}