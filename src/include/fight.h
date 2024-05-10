/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** fight.h
*/

#include "../my.h"
#include "../rpg.h"

#ifndef FIGHT_H
    #define FIGHT_H

typedef struct fight_struct {
    sfSprite *empty_bar_sprite;
    sfIntRect rect_empty_bar;
    sfSprite *hero_lifebar_sprite;
    sfIntRect rect_hero_bar;
    sfSprite *ennemy_bar_sprite;
    sfIntRect rect_ennemy_bar;
    sfSprite *weapon_advantage;
    sfIntRect weapon_advantage_rect;
    sfTexture *globat_texture;
    sfSprite *combat_scene;
} fight_t;

void init_lifebars(fight_t *fight, Global_t *m);
int is_weapon_advantage(Weapons_t *weapon_atk, Weapons_t *weapon_def);
int is_hit(Perso_t *attack, Perso_t *defense, Weapons_t *weapon_atk, Weapons_t *weapon_def);
int double_attack(stchar_t *attack, stchar_t *defense);
int critical_hit(stchar_t *attack, stchar_t *defense, Weapons_t *weapon);
void level_up(stchar_t *stats);
int damage_physical(Perso_t *attacker, Perso_t *defender);
int damage_magical(Perso_t *attacker, Perso_t *defender);

#endif
