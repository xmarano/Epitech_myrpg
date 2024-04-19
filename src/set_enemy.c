/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** set_enemy.c
*/

#include "rpg.h"
#include "include/perso.h"

static void init_enemy_mage(Perso_t *perso, char *name, Weapons_t weapon)
{
    perso->name_perso = name;
    perso->type = "Enemy";
    memcpy(perso->current_weapon, &weapon, sizeof(Weapons_t));
    strcpy(perso->current_weapon->link_texture, "assets/weapons/Thunder_book.png");
    strcpy(perso->texture_link_dialogue, "NULL");
    strcpy(perso->texture_link_battle, "assets/perso/battle/enemy/enemy_mage.png");
    perso->stat_p.level = 7;
    perso->stat_p.xp = 0;
    perso->stat_p.current_hp = 25;
    perso->stat_p.max_hp = 25;
    perso->stat_p.lck = 7;
    perso->stat_p.skl = 7;
    perso->stat_p.def = 4;
    perso->stat_p.res = 2;
    perso->stat_p.str = 13;
    perso->stat_p.spd = 8;
    perso->stat_p.mov = 5;
}

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
    init_enemy1_spear(&m->perso[ENEMY1_SPEAR], "Enemy1_spear", m->weapons[COMMON_SPEAR]);
    init_enemy2_spear(&m->perso[ENEMY2_SPEAR], "Enemy2_spear", m->weapons[RARE_SPEAR]);
    init_enemy3_spear(&m->perso[ENEMY3_SPEAR], "Enemy3_spear", m->weapons[LEGENDARY_SPEAR]);
    init_enemy1_axe(&m->perso[ENEMY1_AXE], "Enemy1_axe", m->weapons[COMMON_AXE]);
    init_enemy2_axe(&m->perso[ENEMY2_AXE], "Enemy2_axe", m->weapons[RARE_AXE]);
    init_enemy3_axe(&m->perso[ENEMY3_AXE], "Enemy3_axe", m->weapons[LEGENDARY_AXE]);
    init_enemy_mage(&m->perso[ENEMY_MAGE], "Enemy_mage", m->weapons[THUNDER_BOOK]);
    for (int i = 0; i < 23; i++) {
        printf("\nStatistiques de %s :\n", m->perso[i].name_perso);
        printf("Nom : %s\n", m->perso[i].name_perso);
        printf("Type : %s\n", m->perso[i].type);
        printf("Link texture_dialogue : %s\n", m->perso[i].texture_link_dialogue);
        printf("Link texture_battle : %s\n", m->perso[i].texture_link_battle);
        printf("Level : %d\n", m->perso[i].stat_p.level);
        printf("XP : %d\n", m->perso[i].stat_p.xp);
        printf("HP actuelle: %d\n", m->perso[i].stat_p.current_hp);
        printf("HP Max: %d\n", m->perso[i].stat_p.max_hp);
        printf("Lck : %d\n", m->perso[i].stat_p.lck);
        printf("Skl : %d\n", m->perso[i].stat_p.skl);
        printf("Def : %d\n", m->perso[i].stat_p.def);
        printf("Res : %d\n", m->perso[i].stat_p.res);
        printf("Str : %d\n", m->perso[i].stat_p.str);
        printf("Spd : %d\n", m->perso[i].stat_p.spd);
        printf("Mov : %d\n", m->perso[i].stat_p.mov);
        printf("Statistiques de l'arme de %s :\n", m->perso[i].name_perso);
        printf("Nom : %s\n", m->perso[i].current_weapon->name);
        printf("Type : %s\n", m->perso[i].current_weapon->weapon_type);
        printf("lien texture : %s\n", m->perso[i].current_weapon->link_texture);
        printf("Attaque : %d\n", m->perso[i].current_weapon->attack);
        printf("Précision : %d\n", m->perso[i].current_weapon->accuracy);
        printf("Portée : %d\n", m->perso[i].current_weapon->rng);
        printf("Critique : %d\n", m->perso[i].current_weapon->crit);
        printf("Coût : %d\n", m->perso[i].current_weapon->cost);
    }
    return 0;
}
