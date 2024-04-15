/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** inv.h
*/

#ifndef INV_H
    #define INV_H

#include "include/menu.h"
#include "include/inventory.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>


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

#endif
