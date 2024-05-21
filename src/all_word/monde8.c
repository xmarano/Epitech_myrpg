/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** monde1.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"

void draw_monde8(Global_t *m, fight_t *f)
{
    if (m->current == 8) {
        sfRenderWindow_setView(m->window, m->zone8.view_w8);
        sfRenderWindow_drawSprite(m->window, m->zone8.w8_map, NULL);
        //check_all_pose(m, m->zone1.tab_map, 1);
        move_game_cursor(m);
        //all_perso_movement(m);
        //set_new_position(m, m->univ.spr_roy, &m->perso[ROY]);
        print_boss_barre(m, BOSS8, m->zone8.view_w8);
        //print_mini_barre(m, f);
        return_and_old_current2(m, 8);
    }
}
