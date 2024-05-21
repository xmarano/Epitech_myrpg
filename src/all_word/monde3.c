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

void draw_monde3(Global_t *m, fight_t *f)
{
    if (m->current == 3) {
        sfRenderWindow_setView(m->window, m->zone3.view_w3);
        sfRenderWindow_drawSprite(m->window, m->zone3.w3_map, NULL);
        //check_all_pose(m, m->zone1.tab_map, 1);
        move_game_cursor(m);
        //all_perso_movement(m);
        //set_new_position(m, m->univ.spr_roy, &m->perso[ROY]);
        print_boss_barre(m, BOSS3, m->zone3.view_w3);
        //print_mini_barre(m, f);
        return_and_old_current2(m, 3);
    }
}
