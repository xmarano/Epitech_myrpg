/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** init_w_sprite.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"

void destory_all_w_maps(Global_t *m)
{

}

void init_w_sprite(Global_t *m)
{
    m->zone1.w1_map = sfSprite_create();
}