/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** save_txt.c
*/

#include "../rpg.h"
#include "../include/menu.h"

void suite_ptr_saving(Global_t *m, sfTime elapsed, float seconds)
{
    elapsed = sfClock_getElapsedTime(m->o.txt_clock);
    seconds = sfTime_asSeconds(elapsed);
    if (seconds < 2.0f) {
        sfText_setFillColor(m->menu.save_txt, sfBlack);
        sfText_setString(m->menu.save_txt, "Saving game...");
        sfRenderWindow_drawText(m->window, m->menu.save_txt, NULL);
    } else {
        m->o.is_saved = 2;
        sfClock_restart(m->o.txt_clock);
    }
}

void suite_ptr(Global_t *m, sfTime elapsed, float seconds)
{
    elapsed = sfClock_getElapsedTime(m->o.txt_clock);
    seconds = sfTime_asSeconds(elapsed);
    if (seconds < 1.0f) {
        sfText_setString(m->menu.save_txt, "Game saved !");
        sfRenderWindow_drawText(m->window, m->menu.save_txt, NULL);
    } else {
        m->o.is_saved = 0;
    }
}

void print_save_txt(Global_t *m)
{
    sfTime elapsed;
    float seconds;

    if (m->o.is_saved == 1) {
        suite_ptr_saving(m, elapsed, seconds);
    } else if (m->o.is_saved == 2) {
        suite_ptr(m, elapsed, seconds);
    }
}
