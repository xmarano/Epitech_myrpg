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

void load_map(Global_t *m)
{
   
}

void init_w_sprite(Global_t *m)
{
    m->zone1.w1_map = sfSprite_create();
    m->zone1.w1_Map = sfTexture_createFromFile("maps/map1/map1.png", NULL);
    m->zone1.view_w1 = sfView_createFromRect((sfFloatRect){0, 0, 1203, 802});
    m->zone1.view_w1 = sfView_createFromRect((sfFloatRect){0, 0, 1203, 802});
    m->zone1.tab_map = str_to_word_array(get_buff("maps/map1/map1.txt"));
    for (int i = 0; m->zone1.tab_map[i] != NULL; i++) {
        printf("%s\n", m->zone1.tab_map[i]);
        free(m->zone1.tab_map[i]);
    }
    sfSprite_setTexture(m->zone1.w1_map, m->zone1.w1_Map, sfFalse);
    init_sp_perso_boss(m);
}
