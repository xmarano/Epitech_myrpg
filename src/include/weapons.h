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

typedef struct stats_weapon {
    char name[MAX_NAME_LENGTH];
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
