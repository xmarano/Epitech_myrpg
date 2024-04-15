/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** rpg.h
*/
#include "my.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#ifndef RPG_H
    #define RPG_H

/* Debut inventaire */

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

/* Fin inventaire */

typedef struct Menu {
    sfText *test;
    sfSprite *background;
} Menu_t;

typedef struct Glob {
    sfVector2i mouse;
    sfRenderWindow *window;
    Menu_t menu;
    Perso_t perso; /* Yanis */
} Global_t;

void init_menu(Global_t *m);
void draw_menu(Global_t *m);
void destroy_menu(Global_t *m);

#endif
