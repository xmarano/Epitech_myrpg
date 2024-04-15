/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** inventory.h
*/

#ifndef INVENTORY_H
    #define INVENTORY_H

#include "../my.h"
#include "../rpg.h"

typedef struct inventaire {
    void *item1;
    void *item2;
    void *item3;
    void *item4;
    void *item5;
} inv_t;

typedef struct stats_weapon {
    int attack;
    int accuracy;
    int crit;
    sfSprite *fond;
    sfTexture *Fond;
} stweapon_t;

typedef struct stats_mob {
    int level;
    int xp;
    int hp;
    int lck;
    int def;
    int res;
    int atk;
    int spd;
    int mvmt;
} stmob_t;

typedef struct Perso {
    char *name;
    char *type_weapon;
    stweapon_t stat_w;
    stmob_t stat_p;
    inv_t inv;
}Perso_t;

int inventory(Global_t *m, sfEvent event);

#endif
