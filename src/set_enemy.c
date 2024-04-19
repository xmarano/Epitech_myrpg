/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** set_enemy.c
*/

#include "rpg.h"
#include "include/perso.h"

static void init_enemy3_axe(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Enemy";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/axe3.png");
    strcpy(perso->texture_link_dialogue, "NULL");
    strcpy(perso->texture_link_battle, "assets/perso/battle/enemy/enemy3_axe.png");
    perso->stat_p.level = 7;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 31;
    perso->stat_p.max_hp = 31;
    perso->stat_p.lck = 7;
    perso->stat_p.skl = 7;
    perso->stat_p.def = 4;
    perso->stat_p.res = 2;
    perso->stat_p.str = 13;
    perso->stat_p.spd = 8;
    perso->stat_p.mov = 5;
}

static void init_enemy2_axe(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Enemy";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/axe2.png");
    strcpy(perso->texture_link_dialogue, "NULL");
    strcpy(perso->texture_link_battle, "assets/perso/battle/enemy/enemy2_axe.png");
    perso->stat_p.level = 3;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 27;
    perso->stat_p.max_hp = 27;
    perso->stat_p.lck = 7;
    perso->stat_p.skl = 7;
    perso->stat_p.def = 4;
    perso->stat_p.res = 2;
    perso->stat_p.str = 8;
    perso->stat_p.spd = 5;
    perso->stat_p.mov = 5;
}

static void init_enemy1_axe(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Enemy";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/axe1.png");
    strcpy(perso->texture_link_dialogue, "NULL");
    strcpy(perso->texture_link_battle, "assets/perso/battle/enemy/enemy1_axe.png");
    perso->stat_p.level = 1;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 20;
    perso->stat_p.max_hp = 20;
    perso->stat_p.lck = 6;
    perso->stat_p.skl = 5;
    perso->stat_p.def = 2;
    perso->stat_p.res = 0;
    perso->stat_p.str = 6;
    perso->stat_p.spd = 6;
    perso->stat_p.mov = 5;
}


static void init_enemy3_spear(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Enemy";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/spear3.png");
    strcpy(perso->texture_link_dialogue, "NULL");
    strcpy(perso->texture_link_battle, "assets/perso/battle/enemy/enemy3_spear.png");
    perso->stat_p.level = 7;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 30;
    perso->stat_p.max_hp = 30;
    perso->stat_p.lck = 7;
    perso->stat_p.skl = 7;
    perso->stat_p.def = 6;
    perso->stat_p.res = 2;
    perso->stat_p.str = 9;
    perso->stat_p.spd = 6;
    perso->stat_p.mov = 5;
}

static void init_enemy2_spear(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Enemy";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/spear2.png");
    strcpy(perso->texture_link_dialogue, "NULL");
    strcpy(perso->texture_link_battle, "assets/perso/battle/enemy/enemy2_spear.png");
    perso->stat_p.level = 3;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 22;
    perso->stat_p.max_hp = 22;
    perso->stat_p.lck = 7;
    perso->stat_p.skl = 7;
    perso->stat_p.def = 4;
    perso->stat_p.res = 0;
    perso->stat_p.str = 8;
    perso->stat_p.spd = 5;
    perso->stat_p.mov = 5;
}

static void init_enemy1_spear(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Enemy";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/spear1.png");
    strcpy(perso->texture_link_dialogue, "NULL");
    strcpy(perso->texture_link_battle, "assets/perso/battle/enemy/enemy1_spear.png");
    perso->stat_p.level = 1;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 15;
    perso->stat_p.max_hp = 15;
    perso->stat_p.lck = 6;
    perso->stat_p.skl = 5;
    perso->stat_p.def = 2;
    perso->stat_p.res = 0;
    perso->stat_p.str = 4;
    perso->stat_p.spd = 6;
    perso->stat_p.mov = 5;
}


static void init_enemy3_sword(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Enemy";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/sword3.png");
    strcpy(perso->texture_link_dialogue, "NULL");
    strcpy(perso->texture_link_battle, "assets/perso/battle/enemy/enemy3_sword.png");
    perso->stat_p.level = 7;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 30;
    perso->stat_p.max_hp = 30;
    perso->stat_p.lck = 7;
    perso->stat_p.skl = 7;
    perso->stat_p.def = 6;
    perso->stat_p.res = 2;
    perso->stat_p.str = 9;
    perso->stat_p.spd = 6;
    perso->stat_p.mov = 5;
}

static void init_enemy2_sword(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Enemy";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/sword2.png");
    strcpy(perso->texture_link_dialogue, "NULL");
    strcpy(perso->texture_link_battle, "assets/perso/battle/enemy/enemy2_sword.png");
    perso->stat_p.level = 3;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 22;
    perso->stat_p.max_hp = 22;
    perso->stat_p.lck = 7;
    perso->stat_p.skl = 7;
    perso->stat_p.def = 4;
    perso->stat_p.res = 0;
    perso->stat_p.str = 8;
    perso->stat_p.spd = 5;
    perso->stat_p.mov = 5;
}

static void init_enemy1_sword(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Enemy";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/sword1.png");
    strcpy(perso->texture_link_dialogue, "NULL");
    strcpy(perso->texture_link_battle, "assets/perso/battle/enemy/enemy1_sword.png");
    perso->stat_p.level = 1;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 15;
    perso->stat_p.max_hp = 15;
    perso->stat_p.lck = 6;
    perso->stat_p.skl = 5;
    perso->stat_p.def = 2;
    perso->stat_p.res = 0;
    perso->stat_p.str = 4;
    perso->stat_p.spd = 6;
    perso->stat_p.mov = 5;
}

int set_enemy(Global_t *m)
{
    init_enemy1_sword(&m->perso[ENEMY1_SWORD], "Enemy1_sword", m->weapons[COMMON_SWORD]);
    init_enemy2_sword(&m->perso[ENEMY2_SWORD], "Enemy2_sword", m->weapons[RARE_SWORD]);
    init_enemy3_sword(&m->perso[ENEMY3_SWORD], "Enemy3_sword", m->weapons[LEGENDARY_SWORD]);
    init_enemy1_spear(&m->perso[ENEMY1_SPEAR], "Xmarano", m->weapons[COMMON_SPEAR]);
    init_enemy2_spear(&m->perso[ENEMY2_SPEAR], "Xmarano", m->weapons[RARE_SPEAR]);
    init_enemy3_spear(&m->perso[ENEMY3_SPEAR], "Xmarano", m->weapons[LEGENDARY_SPEAR]);
    init_enemy1_axe(&m->perso[XMARANO], "Xmarano", m->weapons[XMARANO_axe]);
    init_enemy2_axe(&m->perso[XMARANO], "Xmarano", m->weapons[XMARANO_axe]);
    init_enemy3_axe(&m->perso[XMARANO], "Xmarano", m->weapons[XMARANO_SPEAR]);
    init_enemy_mage(&m->perso[XMARANO], "Xmarano", m->weapons[XMARANO_SPEAR]);
    return 0;
}
