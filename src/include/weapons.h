/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** weapons.h
*/

#ifndef WEAPONS_H
    #define WEAPONS_H

#include "../rpg.h"
    #define MAX_WEAPONS 15
    #define MAX_NAME_LENGTH 50

enum WEAPONS {
    ROY_SWORD = 0,
    INFENIUM_BOOK = 1,
    PATECARBO_BOW = 2,
    XMARANO_SPEAR = 3,
    RACAILLOU_AXE = 4,
};

typedef struct stats_weapon {
    char name[MAX_NAME_LENGTH];
    char weapon_type[MAX_NAME_LENGTH];
    int attack;
    int accuracy;
    int rng;
    int crit;
    int cost;
    sfTexture *texture;
    sfSprite *sprite;
    sfRectangleShape *rect_weapon;
} Weapons_t;

#endif
