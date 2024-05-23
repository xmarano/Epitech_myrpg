/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** lifebar.c
*/

#include "../include/perso.h"
#include "../rpg.h"

static void print2(Perso_t *atk, Perso_t *def, Global_t *m, fight_t *f)
{
    if (def->stat_p.mag > def->stat_p.str && def->stat_p.current_hp > 0)
        atk->stat_p.current_hp -= damage_magical(def, atk);
    else if (def->stat_p.current_hp > 0)
        atk->stat_p.current_hp -= damage_physical(def, atk);
    if (def->stat_p.current_hp < 0)
        def->stat_p.current_hp = 0;
    if (atk->stat_p.current_hp < 0)
        atk->stat_p.current_hp = 0;
    f->has_def_attacked = sfTrue;
    get_fight_exp(atk, def);
}

static void print1(Perso_t *atk, Perso_t *def, Global_t *m, fight_t *f)
{
    if (atk->stat_p.mag > atk->stat_p.str)
        def->stat_p.current_hp -= damage_magical(atk, def);
    else
        def->stat_p.current_hp -= damage_physical(atk, def);
    if (def->stat_p.current_hp < 0)
        def->stat_p.current_hp = 0;
    if (atk->stat_p.current_hp < 0)
        atk->stat_p.current_hp = 0;
    f->is_fight = sfFalse;
}

static void reset(Global_t *m, fight_t *f, sfClock *clock)
{
    m->univ.interface.go_fight = false;
    f->is_fight = true;
    f->has_def_attacked = false;
}

void draw_spr(Perso_t *atk, Perso_t *def, Global_t *m, fight_t *f)
{
    if (atk->stat_p.current_hp > 0)
        sfRenderWindow_drawSprite(m->window, f->sprite_atk, NULL);
    else
        sfRenderWindow_drawSprite(m->window, f->dead_head, NULL);
    if (def->stat_p.current_hp > 0)
        sfRenderWindow_drawSprite(m->window, f->sprite_def, NULL);
    else
        sfRenderWindow_drawSprite(m->window, f->dead_head2, NULL);
}

void print_sprites(Perso_t *atk, Perso_t *def, Global_t *m, fight_t *f)
{
    static sfClock *clock = NULL;
    sfTime time;
    float seconds;

    if (clock == NULL)
        clock = sfClock_create();
    time = sfClock_getElapsedTime(clock);
    seconds = sfTime_asSeconds(time);
    draw_spr(atk, def, m, f);
    if (seconds > 1.3f && seconds < 1.6f)
        draw_slash(m, f);
    if (seconds > 1.3f && f->is_fight == sfTrue)
        print1(atk, def, m, f);
    if (seconds > 3.0f && f->has_def_attacked == sfFalse)
        print2(atk, def, m, f);
    if (seconds > 5.0f) {
        reset(m, f, clock);
        sfClock_restart(clock);
        sfClock_destroy(clock);
        destroy_fight_sprites(f);
        clock = NULL;
    }
}
