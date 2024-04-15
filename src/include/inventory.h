/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** inventory.h
*/
#include "../my.h"
#include "../rpg.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>

#ifndef INVENTORY_H
    #define INVENTORY_H

typedef struct inventaire {
    void *item1;
    void *item2;
    void *item3;
    void *item4;
    void *item5;
    sfSprite *inventory;
    sfTexture *Inventory;
    sfSprite *inventory2;
    sfTexture *Inventory2;
} inv_t;

typedef struct weapons_srpite {
    sfTexture *texture;
    sfSprite *sprite;
}set_weapon_t;

typedef struct stats_weapon {
    int attack;
    int accuracy;
    int crit;
    set_weapon_t init;
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
    bool is_visible;
    bool is_visible2;
}Perso_t;

#endif
