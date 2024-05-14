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
    sfFloatRect bounds = sfText_getGlobalBounds(m->setting.cvolume);

    if (m->setting.cvolume != NULL) {
        if (sfFloatRect_contains(&bounds, mousePos.x, mousePos.y)) {
            sfMusic_setVolume(m->setting.music, 0);
        }
    }
}

void verif_song(sfVector2i mouse, Global_t *m)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(m->window);
    sfFloatRect downvol = sfText_getGlobalBounds(m->setting.volumeb);
    sfFloatRect upvol = sfText_getGlobalBounds(m->setting.volumeh);
    sfFloatRect coupvol = sfText_getGlobalBounds(m->setting.cvolume);

    if (sfFloatRect_contains(&downvol, mousePos.x, mousePos.y))
        max_volume(m);
    if (sfFloatRect_contains(&upvol, mousePos.x, mousePos.y))
        min_volume(m);
    if (sfFloatRect_contains(&coupvol, mousePos.x, mousePos.y))
        stop_song(m);
}
