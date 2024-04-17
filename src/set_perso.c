/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** set_perso.c
*/

#include "include/inventory.h"

void init_Roy(Perso_t *stat, char *name)
{
    stat->name_perso = name;
    stat->stat_p.level = 1;
    stat->stat_p.xp = 0;
    stat->stat_p.hp = 16;
    stat->stat_p.lck = 4;
    // perso->stat_p.skl = ;
    // perso->stat_p.def = def;
    // perso->stat_p.res = res;
    // perso->stat_p.str = str;
    // perso->stat_p.spd = spd;
    // perso->stat_p.mov = mov;
}

int setup_stat(Global_t *m)
{
    Perso_t persos[2];

    init_Roy(&persos[0], "Xmarano");
    //init_stats(&persos[1], "Infenieum");
    for (int i = 0; i < 2; i++) {
        printf("Nom du personnage : %s\n", persos[i].name_perso);
        printf("Level : %d\n", persos[i].stat_p.level);
        printf("XP : %d\n", persos[i].stat_p.xp);
        printf("HP : %d\n", persos[i].stat_p.hp);
        printf("Lck : %d\n", persos[i].stat_p.lck);
        printf("Skl : %d\n", persos[i].stat_p.skl);
        printf("Def : %d\n", persos[i].stat_p.def);
        printf("Res : %d\n", persos[i].stat_p.res);
        printf("Str : %d\n", persos[i].stat_p.str);
        printf("Spd : %d\n", persos[i].stat_p.spd);
        printf("Mov : %d\n", persos[i].stat_p.mov);
        printf("\n");
    }
    return 0;
}
