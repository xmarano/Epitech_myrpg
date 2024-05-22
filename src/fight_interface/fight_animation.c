/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** lifebar.c
*/

#include "../include/perso.h"
#include "../rpg.h"

void print_sprites(Perso_t *atk, Perso_t *def, Global_t *m, fight_t *f)
{
    float seconds;
    sfTime time = sfClock_getElapsedTime(f->clock_lifebar);

    seconds = time.microseconds / 1000000.0;
    sfRenderWindow_drawSprite(m->window, f->sprite_atk, NULL);
    sfRenderWindow_drawSprite(m->window, f->sprite_def, NULL);
    if (f->is_fight == sfTrue && seconds > 2) {
        if (atk->stat_p.mag > atk->stat_p.str)
            f->dmg_def_received = damage_magical(atk, def);
        else
            f->dmg_def_received = damage_physical(atk, def);
        if (def->stat_p.current_hp < 0)
            def->stat_p.current_hp = 0;
        if (atk->stat_p.current_hp < 0)
            atk->stat_p.current_hp = 0;
        f->is_fight = sfFalse;
    }
    if (seconds > 6 && f->has_def_attacked == sfFalse) {
        if (def->stat_p.mag > def->stat_p.str)
            f->dmg_atk_received = damage_magical(def, atk);
        else
            f->dmg_atk_received = damage_physical(def, atk);
        if (def->stat_p.current_hp < 0)
            def->stat_p.current_hp = 0;
        if (atk->stat_p.current_hp < 0)
            atk->stat_p.current_hp = 0;
        sfClock_restart(f->clock_lifebar);
        f->has_def_attacked = sfTrue;
    }
}
