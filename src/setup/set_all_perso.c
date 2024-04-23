/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** set_perso.c
*/

#include "../include/perso.h"
#include "../rpg.h"

static void init_raca(Perso_t *perso, char *name, Weapons_t weapon[])
{
    perso->name_perso = name;
    perso->type = "Mage";
    memcpy(perso->current_weapon, &weapon[RACAILLOU_AXE], sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/Racaillou_axe.png");
    memcpy(&perso->inv_weapon[SLOT1], &weapon[RACAILLOU_AXE], sizeof(Weapons_t));
    memcpy(&perso->inv_weapon[HEAL], &weapon[HEAL_STICK], sizeof(Weapons_t));
    strcpy(perso->texture_dialogue, "assets/perso/dialogue/hero/Racaillou_dialogue.png");
    strcpy(perso->texture_battle, "assets/perso/battle/hero/Racaillou_armed.png");
    perso->num_weapons_in_inv = 2;
    perso->is_hero = true;
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

static void initxmarano(Perso_t *perso, char *name, Weapons_t weapon[])
{
    perso->name_perso = name;
    perso->type = "Knight";
    memcpy(perso->current_weapon, &weapon[XMARANO_SPEAR], sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/Xmarano_spear.png");
    memcpy(&perso->inv_weapon[SLOT1], &weapon[XMARANO_SPEAR], sizeof(Weapons_t));
    memcpy(&perso->inv_weapon[HEAL], &weapon[HEAL_STICK], sizeof(Weapons_t));
    strcpy(perso->texture_dialogue, "assets/perso/dialogue/hero/Xmarano_dialogue.png");
    strcpy(perso->texture_battle, "assets/perso/battle/hero/Xmarano_armed.png");
    perso->num_weapons_in_inv = 2;
    perso->is_hero = true;
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

static void init_pate(Perso_t *perso, char *name, Weapons_t weapon[])
{
    perso->name_perso = name;
    perso->type = "Archer";
    memcpy(perso->current_weapon, &weapon[PATECARBO_BOW], sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/Patecarbo_bow.png");
    memcpy(&perso->inv_weapon[SLOT1], &weapon[PATECARBO_BOW], sizeof(Weapons_t));
    memcpy(&perso->inv_weapon[HEAL], &weapon[HEAL_STICK], sizeof(Weapons_t));
    strcpy(perso->texture_dialogue, "assets/perso/dialogue/hero/Patecarbo_dialogue.png");
    strcpy(perso->texture_battle, "assets/perso/battle/hero/Patecarbo_armed.png");
    perso->num_weapons_in_inv = 2;
    perso->is_hero = true;
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
    perso->stat_p.spd = 4;
    perso->stat_p.mov = 5;
}

static void initinfenium(Perso_t *perso, char *name, Weapons_t weapon[])
{
    perso->name_perso = name;
    perso->type = "Paladin";
    memcpy(perso->current_weapon, &weapon[INFENIUM_BOOK], sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/Infenium_book.png");
    memcpy(&perso->inv_weapon[SLOT1], &weapon[INFENIUM_BOOK], sizeof(Weapons_t));
    memcpy(&perso->inv_weapon[HEAL], &weapon[HEAL_STICK], sizeof(Weapons_t));
    strcpy(perso->texture_dialogue, "assets/perso/dialogue/hero/Infenium_dialogue.png");
    strcpy(perso->texture_battle, "assets/perso/battle/hero/Infenium_armed.png");
    perso->num_weapons_in_inv = 2;
    perso->is_hero = true;
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

static void initroy(Perso_t *perso, char *name, Weapons_t weapon[])
{
    perso->name_perso = name;
    perso->type = "Lord";
    perso->is_hero = true;
    memcpy(perso->current_weapon, &weapon[ROY], sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/Roy_sword.png");
    memcpy(&perso->inv_weapon[SLOT1], &weapon[ROY_SWORD], sizeof(Weapons_t));
    memcpy(&perso->inv_weapon[HEAL], &weapon[HEAL_STICK], sizeof(Weapons_t));
    //memcpy(&perso->inv_weapon[1], &weapon[COMMON_BOW], sizeof(Weapons_t)); ex ajouter une arme dans inv
    strcpy(perso->texture_dialogue, "assets/perso/dialogue/hero/Roy_dialogue.png");
    strcpy(perso->texture_battle, "assets/perso/battle/hero/Roy_armed.png");
    perso->num_weapons_in_inv = 2; //!\ modifier cette valeurs quand on ajoute une arme dans l'inventaire !
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

    initroy(&m->perso[ROY], "ROY", m->weapons);
    initinfenium(&m->perso[INFENIUM], "Infenium", m->weapons);
    init_pate(&m->perso[PATECARBO], "PateCarbo", m->weapons);
    initxmarano(&m->perso[XMARANO], "Xmarano", m->weapons);
    init_raca(&m->perso[RACAILLOU], "Racaillou", m->weapons);
    set_boss(m);
    set_enemy(m);
    return 0;
}
