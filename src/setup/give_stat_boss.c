/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** give_stat_emy.c
*/

#include "../my.h"
#include "../rpg.h"
#include "../include/perso.h"

void set_stats_b4(Perso_t *perso)
{
    perso->stat_p.level = 11;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 5;
    perso->stat_p.max_hp = 30;
    perso->stat_p.lck = 10;
    perso->stat_p.mag = 1;
    perso->stat_p.skl = 6;
    perso->stat_p.def = 10;
    perso->stat_p.res = 9;
    perso->stat_p.str = 8;
    perso->stat_p.spd = 14;
    perso->stat_p.mov = 0;
}

void set_stats_b3(Perso_t *perso)
{
    perso->stat_p.level = 8;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 9;
    perso->stat_p.max_hp = 27;
    perso->stat_p.lck = 9;
    perso->stat_p.skl = 5;
    perso->stat_p.mag = 1;
    perso->stat_p.def = 8;
    perso->stat_p.res = 9;
    perso->stat_p.str = 7;
    perso->stat_p.spd = 12;
    perso->stat_p.mov = 0;
}

void set_stats_b2(Perso_t *perso)
{
    perso->stat_p.level = 5;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 3;
    perso->stat_p.max_hp = 25;
    perso->stat_p.lck = 8;
    perso->stat_p.skl = 4;
    perso->stat_p.def = 7;
    perso->stat_p.mag = 1;
    perso->stat_p.res = 7;
    perso->stat_p.str = 5;
    perso->stat_p.spd = 10;
    perso->stat_p.mov = 0;
}

void set_stats_b1(Perso_t *perso)
{
    perso->stat_p.level = 2;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 6;
    perso->stat_p.max_hp = 23;
    perso->stat_p.lck = 7;
    perso->stat_p.skl = 3;
    perso->stat_p.mag = 1;
    perso->stat_p.def = 6;
    perso->stat_p.res = 6;
    perso->stat_p.str = 4;
    perso->stat_p.spd = 9;
    perso->stat_p.mov = 0;
}
