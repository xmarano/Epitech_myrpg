/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** set_perso.c
*/

#include "include/inventory.h"

static void init_Racaillou(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Mage";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
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

static void init_Xmarano(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Knight";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
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

static void init_PateCarbo(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Archer";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
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

static void init_Infenium(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Paladin";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
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

static void init_Roy(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Lord";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
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
    init_Roy(&m->perso[0], "ROY", m->weapons[ROY_SWORD]);
    init_Infenium(&m->perso[1], "Infenieum", m->weapons[INFENIUM_BOOK]);
    init_PateCarbo(&m->perso[3], "PateCarbo", m->weapons[PATECARBO_BOW]);
    init_Xmarano(&m->perso[2], "Xmarano", m->weapons[XMARANO_SPEAR]);
    init_Racaillou(&m->perso[4], "Racaillou", m->weapons[RACAILLOU_AXE]);
    for (int i = 0; i < 5; i++) {
        printf("\nStatistiques de %s :\n", m->perso[i].name_perso);
        printf("Nom : %s\n", m->perso[i].name_perso);
        printf("Type : %s\n", m->perso[i].type);
        printf("Level : %d\n", m->perso[i].stat_p.level);
        printf("XP : %d\n", m->perso[i].stat_p.xp);
        printf("HP : %d\n", m->perso[i].stat_p.hp);
        printf("Lck : %d\n", m->perso[i].stat_p.lck);
        printf("Skl : %d\n", m->perso[i].stat_p.skl);
        printf("Def : %d\n", m->perso[i].stat_p.def);
        printf("Res : %d\n", m->perso[i].stat_p.res);
        printf("Str : %d\n", m->perso[i].stat_p.str);
        printf("Spd : %d\n", m->perso[i].stat_p.spd);
        printf("Mov : %d\n", m->perso[i].stat_p.mov);
        printf("\nStatistiques de l'arme de %s :\n", m->perso[i].name_perso);
        printf("Nom : %s\n", m->perso[i].current_weapon->name);
        printf("Attaque : %d\n", m->perso[i].current_weapon->attack);
        printf("Précision : %d\n", m->perso[i].current_weapon->accuracy);
        printf("Portée : %d\n", m->perso[i].current_weapon->rng);
        printf("Critique : %d\n", m->perso[i].current_weapon->crit);
        printf("Coût : %d\n", m->perso[i].current_weapon->cost);
    }
    return 0;
}
