/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** set_perso.c
*/

#include "../include/perso.h"
#include "../rpg.h"

static void init_racaillou(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Mage";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/Racaillou_axe.png");
    for (int i = 0; i < 4; i++)
        memset(&perso->inv_weapon[i], 0, sizeof(Weapons_t));
    strcpy(perso->texture_dialogue, "assets/perso/dialogue/hero/Racaillou_dialogue.png");
    strcpy(perso->texture_battle, "assets/perso/battle/hero/Racaillou_armed.png");
    perso->num_weapons_in_inv = 0;
    perso->stat_p.level = 1;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 15;
    perso->stat_p.max_hp = 15;
    perso->stat_p.lck = 7;
    perso->stat_p.mag = 1;
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
    for (int i = 0; i < 4; i++)
        memset(&perso->inv_weapon[i], 0, sizeof(Weapons_t));
    strcpy(perso->texture_dialogue, "assets/perso/dialogue/hero/Xmarano_dialogue.png");
    strcpy(perso->texture_battle, "assets/perso/battle/hero/Xmarano_armed.png");
    perso->num_weapons_in_inv = 0;
    perso->stat_p.level = 1;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 20;
    perso->stat_p.max_hp = 20;
    perso->stat_p.lck = 2;
    perso->stat_p.mag = 1;
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
    for (int i = 0; i < 4; i++)
        memset(&perso->inv_weapon[i], 0, sizeof(Weapons_t));
    strcpy(perso->texture_dialogue, "assets/perso/dialogue/hero/Patecarbo_dialogue.png");
    strcpy(perso->texture_battle, "assets/perso/battle/hero/Patecarbo_armed.png");
    perso->num_weapons_in_inv = 0;
    perso->stat_p.level = 1;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 18;
    perso->stat_p.max_hp = 18;
    perso->stat_p.lck = 3;
    perso->stat_p.skl = 4;
    perso->stat_p.mag = 1;
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
    for (int i = 0; i < 4; i++)
        memset(&perso->inv_weapon[i], 0, sizeof(Weapons_t));
    strcpy(perso->texture_dialogue, "assets/perso/dialogue/hero/Infenium_dialogue.png");
    strcpy(perso->texture_battle, "assets/perso/battle/hero/Infenium_armed.png");
    perso->num_weapons_in_inv = 0;
    perso->stat_p.level = 1;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 22;
    perso->stat_p.max_hp = 22;
    perso->stat_p.lck = 10;
    perso->stat_p.skl = 14;
    perso->stat_p.mag = 9;
    perso->stat_p.def = 9;
    perso->stat_p.res = 8;
    perso->stat_p.str = 1;
    perso->stat_p.spd = 11;
    perso->stat_p.mov = 8;
}

static void init_roy(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Lord";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/Roy_sword.png");
    for (int i = 0; i < 4; i++)
        memset(&perso->inv_weapon[i], 0, sizeof(Weapons_t));
    // memcpy(&perso->inv_weapon[SLOT1], weapon[INFENIUM_BOOK], sizeof(Weapons_t)); //ajouter une armes dans un inventaire /!\ [ne par retirer du mode commentaire]
    // m->perso[]m->current_perso->num_weapons_in_inv += 1; /!\ [ne par retirer du mode commentaire]
    strcpy(perso->texture_dialogue, "assets/perso/dialogue/hero/Roy_dialogue.png");
    strcpy(perso->texture_battle, "assets/perso/battle/hero/Roy_armed.png");
    perso->num_weapons_in_inv = 0;
    perso->stat_p.level = 1;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 18;
    perso->stat_p.max_hp = 18;
    perso->stat_p.lck = 7;
    perso->stat_p.mag = 1;
    perso->stat_p.skl = 5;
    perso->stat_p.def = 5;
    perso->stat_p.res = 0;
    perso->stat_p.str = 5;
    perso->stat_p.spd = 7;
    perso->stat_p.mov = 5;
}

int setup_stat(Global_t *m)
{
    init_roy(&m->perso[ROY], "ROY", m->weapons[ROY_SWORD]);
    init_infenium(&m->perso[INFENIUM], "Infenieum", m->weapons[INFENIUM_BOOK]);
    init_patecarbo(&m->perso[PATECARBO], "PateCarbo", m->weapons[PATECARBO_BOW]);
    init_xmarano(&m->perso[XMARANO], "Xmarano", m->weapons[XMARANO_SPEAR]);
    init_racaillou(&m->perso[RACAILLOU], "Racaillou", m->weapons[RACAILLOU_AXE]);
    set_boss(m);
    set_enemy(m);
    return 0;
}
