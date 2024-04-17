/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** set_perso.c
*/

#include "include/inventory.h"

static void init_Racaillou(Perso_t *perso, char *name)
{
    perso->name_perso = name;
    perso->type = "Mage";
    perso->stat_p.level = 1;
    perso->stat_p.xp = 0;
    perso->stat_p.hp = 15;
    perso->stat_p.lck = 7;
    perso->stat_p.skl = 5;
    perso->stat_p.def = 2;
    perso->stat_p.res = 8;
    perso->stat_p.str = 7;
    perso->stat_p.spd = 7;
    perso->stat_p.mov = 5;
}

static void init_Xmarano(Perso_t *perso, char *name)
{
    perso->name_perso = name;
    perso->type = "Knight";
    perso->stat_p.level = 1;
    perso->stat_p.xp = 0;
    perso->stat_p.hp = 20;
    perso->stat_p.lck = 2;
    perso->stat_p.skl = 4;
    perso->stat_p.def = 11;
    perso->stat_p.res = 0;
    perso->stat_p.str = 7;
    perso->stat_p.spd = 3;
    perso->stat_p.mov = 4;
}

static void init_PateCarbo(Perso_t *perso, char *name)
{
    perso->name_perso = name;
    perso->type = "Archer";
    perso->stat_p.level = 1;
    perso->stat_p.xp = 0;
    perso->stat_p.hp = 18;
    perso->stat_p.lck = 3;
    perso->stat_p.skl = 4;
    perso->stat_p.def = 4;
    perso->stat_p.res = 0;
    perso->stat_p.str = 4;
    perso->stat_p.spd = 3;
    perso->stat_p.mov = 5;
}

static void init_Infenium(Perso_t *perso, char *name)
{
    perso->name_perso = name;
    perso->type = "Paladin";
    perso->stat_p.level = 1;
    perso->stat_p.xp = 0;
    perso->stat_p.hp = 22;
    perso->stat_p.lck = 10;
    perso->stat_p.skl = 14;
    perso->stat_p.def = 9;
    perso->stat_p.res = 8;
    perso->stat_p.str = 9;
    perso->stat_p.spd = 11;
    perso->stat_p.mov = 8;
}

static void init_Roy(Perso_t *perso, char *name)
{
    perso->name_perso = name;
    perso->type = "Lord";
    perso->stat_p.level = 1;
    perso->stat_p.xp = 0;
    perso->stat_p.hp = 18;
    perso->stat_p.lck = 7;
    perso->stat_p.skl = 5;
    perso->stat_p.def = 5;
    perso->stat_p.res = 0;
    perso->stat_p.str = 5;
    perso->stat_p.spd = 7;
    perso->stat_p.mov = 5;
}

int setup_stat(Global_t *m)
{
    init_Roy(&m->perso[0], "ROY");
    init_Infenium(&m->perso[1], "Infenieum");
    init_Xmarano(&m->perso[2], "Xmarano");
    init_PateCarbo(&m->perso[3], "PateCarbo");
    init_Racaillou(&m->perso[4], "Racaillou");
    return 0;
}
