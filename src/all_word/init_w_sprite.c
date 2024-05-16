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

void load_texte_map(Global_t *m)
{
    m->zone1.view_w1 = sfView_createFromRect((sfFloatRect){0, 0, 1203, 802});
    m->zone1.tab_map = str_to_word_array(get_buff("maps/map1/map1.txt"));
    m->zone2.view_w2 = sfView_createFromRect((sfFloatRect){0, 0, 1204, 799});
    m->zone2.tab_map = str_to_word_array(get_buff("maps/map2/map2.txt"));
    m->zone3.view_w3 = sfView_createFromRect((sfFloatRect){0, 0, 1204, 802});
    m->zone3.tab_map = str_to_word_array(get_buff("maps/map3/map3.txt"));
    m->zone4.view_w4 = sfView_createFromRect((sfFloatRect){0, 0, 1205, 800});
    m->zone4.tab_map = str_to_word_array(get_buff("maps/map4/map4.txt"));
    m->zone5.view_w5 = sfView_createFromRect((sfFloatRect){0, 0, 1205, 800});
    m->zone5.tab_map = str_to_word_array(get_buff("maps/map5/map5.txt"));
    m->zone6.view_w6 = sfView_createFromRect((sfFloatRect){0, 0, 1207, 799});
    m->zone6.tab_map = str_to_word_array(get_buff("maps/map6/map6.txt"));
    m->zone7.view_w7 = sfView_createFromRect((sfFloatRect){0, 0, 1205, 800});
    m->zone7.tab_map = str_to_word_array(get_buff("maps/map7/map7.txt"));
    m->zone8.view_w8 = sfView_createFromRect((sfFloatRect){0, 0, 1200, 801});
    m->zone8.tab_map = str_to_word_array(get_buff("maps/map8/map8.txt"));
}

void load_sprite_map(Global_t *m)
{
    m->zone1.w1_map = sfSprite_create();
    m->zone1.w1_Map = sfTexture_createFromFile("maps/map1/map1.png", NULL);
    m->zone2.w2_map = sfSprite_create();
    m->zone2.w2_Map = sfTexture_createFromFile("maps/map2/map2.png", NULL);
    m->zone3.w3_map = sfSprite_create();
    m->zone3.w3_Map = sfTexture_createFromFile("maps/map3/map3.png", NULL);
    m->zone4.w4_map = sfSprite_create();
    m->zone4.w4_Map = sfTexture_createFromFile("maps/map4/map4.png", NULL);
    m->zone5.w5_map = sfSprite_create();
    m->zone5.w5_Map = sfTexture_createFromFile("maps/map5/map5.png", NULL);
    m->zone6.w6_map = sfSprite_create();
    m->zone6.w6_Map = sfTexture_createFromFile("maps/map6/map6.png", NULL);
    m->zone7.w7_map = sfSprite_create();
    m->zone7.w7_Map = sfTexture_createFromFile("maps/map7/map7.png", NULL);
    m->zone8.w8_map = sfSprite_create();
    m->zone8.w8_Map = sfTexture_createFromFile("maps/map8/map8.png", NULL);
}

void init_w_sprite(Global_t *m)
{
    load_sprite_map(m);
    load_texte_map(m);
    sfSprite_setTexture(m->zone1.w1_map, m->zone1.w1_Map, sfFalse);
    init_sp_perso_boss(m);
}
