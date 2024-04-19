/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** set_boss.c
*/

#include "include/perso.h"
#include "rpg.h"

static void init_boss8(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "BOSS";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/Boss8_sword.png");
    strcpy(perso->texture_link_dialogue, "assets/perso/dialogue/boss/Boss8_dialogue.png");
    strcpy(perso->texture_link_battle, "assets/perso/battle/boss/Boss8_armed.png");
    perso->stat_p.level = 20;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 60;
    perso->stat_p.max_hp = 60;
    perso->stat_p.lck = 21;
    perso->stat_p.skl = 10;
    perso->stat_p.def = 20;
    perso->stat_p.res = 20;
    perso->stat_p.str = 10;
    perso->stat_p.spd = 20;
    perso->stat_p.mov = 0;
}

static void init_boss7(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "BOSS";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/Boss7_axe.png");
    strcpy(perso->texture_link_dialogue, "assets/perso/dialogue/boss/Boss4_d7alogue.png");
    strcpy(perso->texture_link_battle, "assets/perso/battle/boss/Boss7_armed.png");
    perso->stat_p.level = 18;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 56;
    perso->stat_p.max_hp = 56;
    perso->stat_p.lck = 19;
    perso->stat_p.skl = 9;
    perso->stat_p.def = 16;
    perso->stat_p.res = 16;
    perso->stat_p.str = 9;
    perso->stat_p.spd = 18;
    perso->stat_p.mov = 0;
}

static void init_boss6(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "BOSS";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/Boss6_spear.png");
    strcpy(perso->texture_link_dialogue, "assets/perso/dialogue/boss/Boss6_dialogue.png");
    strcpy(perso->texture_link_battle, "assets/perso/battle/boss/Boss6_armed.png");
    perso->stat_p.level = 16;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 50;
    perso->stat_p.max_hp = 50;
    perso->stat_p.lck = 16;
    perso->stat_p.skl = 6;
    perso->stat_p.def = 16;
    perso->stat_p.res = 16;
    perso->stat_p.str = 5;
    perso->stat_p.spd = 11;
    perso->stat_p.mov = 0;
}

static void init_boss5(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "BOSS";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/Boss5_sword.png");
    strcpy(perso->texture_link_dialogue, "assets/perso/dialogue/boss/Boss5_dialogue.png");
    strcpy(perso->texture_link_battle, "assets/perso/battle/boss/Boss5_armed.png");
    perso->stat_p.level = 13;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 41;
    perso->stat_p.max_hp = 41;
    perso->stat_p.lck = 12;
    perso->stat_p.skl = 6;
    perso->stat_p.def = 13;
    perso->stat_p.res = 13;
    perso->stat_p.str = 8;
    perso->stat_p.spd = 15;
    perso->stat_p.mov = 0;
}

static void init_boss4(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "BOSS";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/Boss4_spear.png");
    strcpy(perso->texture_link_dialogue, "assets/perso/dialogue/boss/Boss4_dialogue.png");
    strcpy(perso->texture_link_battle, "assets/perso/battle/boss/Boss4_armed.png");
    perso->stat_p.level = 11;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 35;
    perso->stat_p.max_hp = 35;
    perso->stat_p.lck = 10;
    perso->stat_p.skl = 6;
    perso->stat_p.def = 10;
    perso->stat_p.res = 9;
    perso->stat_p.str = 8;
    perso->stat_p.spd = 14;
    perso->stat_p.mov = 0;
}

static void init_boss3(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "BOSS";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/Boss3_bow.png");
    strcpy(perso->texture_link_dialogue, "assets/perso/dialogue/boss/Boss3_dialogue.png");
    strcpy(perso->texture_link_battle, "assets/perso/battle/boss/Boss3_armed.png");
    perso->stat_p.level = 8;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 29;
    perso->stat_p.max_hp = 29;
    perso->stat_p.lck = 9;
    perso->stat_p.skl = 5;
    perso->stat_p.def = 8;
    perso->stat_p.res = 9;
    perso->stat_p.str = 7;
    perso->stat_p.spd = 12;
    perso->stat_p.mov = 0;
}

static void init_boss2(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "BOSS";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/Boss2_stick.png");
    strcpy(perso->texture_link_dialogue, "assets/perso/dialogue/boss/Boss2_dialogue.png");
    strcpy(perso->texture_link_battle, "assets/perso/battle/boss/Boss2_armed.png");
    perso->stat_p.level = 5;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 23;
    perso->stat_p.max_hp = 23;
    perso->stat_p.lck = 8;
    perso->stat_p.skl = 4;
    perso->stat_p.def = 7;
    perso->stat_p.res = 7;
    perso->stat_p.str = 5;
    perso->stat_p.spd = 10;
    perso->stat_p.mov = 0;
}

static void init_boss1(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "BOSS";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/Boss1_sword.png");
    strcpy(perso->texture_link_dialogue, "assets/perso/dialogue/boss/Boss1_dialogue.png");
    strcpy(perso->texture_link_battle, "assets/perso/battle/boss/Boss1_armed.png");
    perso->stat_p.level = 2;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 20;
    perso->stat_p.max_hp = 20;
    perso->stat_p.lck = 7;
    perso->stat_p.skl = 3;
    perso->stat_p.def = 6;
    perso->stat_p.res = 6;
    perso->stat_p.str = 4;
    perso->stat_p.spd = 9;
    perso->stat_p.mov = 0;
}

int set_boss(Global_t *m)
{
    init_boss1(&m->perso[BOSS1], "BOSS1", m->weapons[BOSS1_SWORD]);
    init_boss2(&m->perso[BOSS2], "BOSS2", m->weapons[BOSS2_STICK]);
    init_boss3(&m->perso[BOSS3], "BOSS3", m->weapons[BOSS3_BOW]);
    init_boss4(&m->perso[BOSS4], "BOSS4", m->weapons[BOSS4_SPEAR]);
    init_boss5(&m->perso[BOSS5], "BOSS5", m->weapons[BOSS5_SWORD]);
    init_boss6(&m->perso[BOSS6], "BOSS6", m->weapons[BOSS6_BOOK]);
    init_boss7(&m->perso[BOSS7], "BOSS7", m->weapons[BOSS7_AXE]);
    init_boss8(&m->perso[BOSS8], "BOSS8", m->weapons[BOSS8_SWORD]);
    return 0;
    // for (int i = 0; i < 13; i++) {
    //     printf("\nStatistiques de %s :\n", m->perso[i].name_perso);
    //     printf("Nom : %s\n", m->perso[i].name_perso);
    //     printf("Type : %s\n", m->perso[i].type);
    //     printf("Link texture_dialogue : %s\n", m->perso[i].texture_link_dialogue);
    //     printf("Link texture_battle : %s\n", m->perso[i].texture_link_battle);
    //     printf("Level : %d\n", m->perso[i].stat_p.level);
    //     printf("XP : %d\n", m->perso[i].stat_p.xp);
    //     printf("HP actuelle: %d\n", m->perso[i].stat_p.current_hp);
    //     printf("HP Max: %d\n", m->perso[i].stat_p.max_hp);
    //     printf("Lck : %d\n", m->perso[i].stat_p.lck);
    //     printf("Skl : %d\n", m->perso[i].stat_p.skl);
    //     printf("Def : %d\n", m->perso[i].stat_p.def);
    //     printf("Res : %d\n", m->perso[i].stat_p.res);
    //     printf("Str : %d\n", m->perso[i].stat_p.str);
    //     printf("Spd : %d\n", m->perso[i].stat_p.spd);
    //     printf("Mov : %d\n", m->perso[i].stat_p.mov);
    //     printf("Statistiques de l'arme de %s :\n", m->perso[i].name_perso);
    //     printf("Nom : %s\n", m->perso[i].current_weapon->name);
    //     printf("Type : %s\n", m->perso[i].current_weapon->weapon_type);
    //     printf("lien texture : %s\n", m->perso[i].current_weapon->link_texture);
    //     printf("Attaque : %d\n", m->perso[i].current_weapon->attack);
    //     printf("Précision : %d\n", m->perso[i].current_weapon->accuracy);
    //     printf("Portée : %d\n", m->perso[i].current_weapon->rng);
    //     printf("Critique : %d\n", m->perso[i].current_weapon->crit);
    //     printf("Coût : %d\n", m->perso[i].current_weapon->cost);
    // }
    return 0;
}
