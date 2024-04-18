/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** set_perso.c
*/

#include "include/perso.h"

static void init_racaillou(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Mage";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/Racaillou_axe.png");
    strcpy(perso->texture_link_dialogue, "assets/perso/dialogue/hero/Racaillou_dialogue.png");
    strcpy(perso->texture_link_battle, "assets/perso/battle/hero/Racaillou_armed.png");
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

static void init_xmarano(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Knight";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/Xmarano_spear.png");
    strcpy(perso->texture_link_dialogue, "assets/perso/dialogue/hero/Xmarano_dialogue.png");
    strcpy(perso->texture_link_battle, "assets/perso/battle/hero/Xmarano_armed.png");
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

static void init_patecarbo(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Archer";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/Patecarbo_bow.png");
    strcpy(perso->texture_link_dialogue, "assets/perso/dialogue/hero/Patecarbo_dialogue.png");
    strcpy(perso->texture_link_battle, "assets/perso/battle/hero/Patecarbo_armed.png");
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

static void init_infenium(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Paladin";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/Infenium_book.png");
    strcpy(perso->texture_link_dialogue, "assets/perso/dialogue/hero/Infenium_dialogue.png");
    strcpy(perso->texture_link_battle, "assets/perso/battle/hero/Infenium_armed.png");
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

static void init_roy(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Lord";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/Roy_sword.png");
    strcpy(perso->texture_link_dialogue, "assets/perso/dialogue/hero/Roy_dialogue.png");
    strcpy(perso->texture_link_battle, "assets/perso/battle/hero/Roy_armed.png");
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
    init_roy(&m->perso[0], "ROY", m->weapons[ROY_SWORD]);
    init_infenium(&m->perso[1], "Infenieum", m->weapons[INFENIUM_BOOK]);
    init_patecarbo(&m->perso[3], "PateCarbo", m->weapons[PATECARBO_BOW]);
    init_xmarano(&m->perso[2], "Xmarano", m->weapons[XMARANO_SPEAR]);
    init_racaillou(&m->perso[4], "Racaillou", m->weapons[RACAILLOU_AXE]);
    // for (int i = 0; i < 5; i++) {
    //     printf("\nStatistiques de %s :\n", m->perso[i].name_perso);
    //     printf("Nom : %s\n", m->perso[i].name_perso);
    //     printf("Type : %s\n", m->perso[i].type);
    //     printf("Link texture_dialogue : %s\n", m->perso[i].texture_link_dialogue);
    //     printf("Link texture_battle : %s\n", m->perso[i].texture_link_battle);
    //     printf("Level : %d\n", m->perso[i].stat_p.level);
    //     printf("XP : %d\n", m->perso[i].stat_p.xp);
    //     printf("HP : %d\n", m->perso[i].stat_p.hp);
    //     printf("Lck : %d\n", m->perso[i].stat_p.lck);
    //     printf("Skl : %d\n", m->perso[i].stat_p.skl);
    //     printf("Def : %d\n", m->perso[i].stat_p.def);
    //     printf("Res : %d\n", m->perso[i].stat_p.res);
    //     printf("Str : %d\n", m->perso[i].stat_p.str);
    //     printf("Spd : %d\n", m->perso[i].stat_p.spd);
    //     printf("Mov : %d\n", m->perso[i].stat_p.mov);
    //     printf("\nStatistiques de l'arme de %s :\n", m->perso[i].name_perso);
    //     printf("Nom : %s\n", m->perso[i].current_weapon->name);
    //     printf("Type : %s\n", m->perso[i].current_weapon->weapon_type);
    //     printf("lien texture : %s\n", m->perso[i].current_weapon->link_texture);
    //     printf("Attaque : %d\n", m->perso[i].current_weapon->attack);
    //     printf("Précision : %d\n", m->perso[i].current_weapon->accuracy);
    //     printf("Portée : %d\n", m->perso[i].current_weapon->rng);
    //     printf("Critique : %d\n", m->perso[i].current_weapon->crit);
    //     printf("Coût : %d\n", m->perso[i].current_weapon->cost);
    // }
    //printf("lien dialogue_texture : %s\n", m->perso[INFENIUM].texture_link_dialogue);
    return 0;
}
