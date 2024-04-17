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

typedef struct inv2_sprite {
    sfSprite *inventory;
    sfTexture *Inventory;
    sfSprite *inventory2;
    sfTexture *Inventory2;
    sfSprite *cursor;
    sfTexture *Cursor;
    sfVector2f pos_cursor;
    sfVector2f pos_hooved;
    sfRectangleShape *rect_inv;
}inv2_sprite_t;

typedef struct inventaire {
    char *item1;
    char *item2;
    char *item3;
    char *item4;
    char *item5;
    inv2_sprite_t inv_sprite;
} inv_t;

typedef struct stats_weapon {
    char *name;
    int attack;
    int accuracy;
    int crit;
    int cost;
    int rng;
    sfTexture *texture;
    sfSprite *sprite;
    sfRectangleShape *rect_weapon;
} stweapon_t;

typedef struct stats_char {
    int level;
    int xp;
    int hp;
    int lck;
    int skl;
    int def;
    int res;
    int str;
    int spd;
    int mov;
} stchar_t;

typedef struct Perso {
    char *name_perso;
    int exp;
    stweapon_t stat_w;
    stchar_t stat_p;
    inv_t inv;
    bool is_visible;
    bool is_visible2;
}Perso_t;

#endif
