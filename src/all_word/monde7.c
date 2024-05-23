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

void draw_monde7(Global_t *m, fight_t *f)
{
    if (m->current == 7) {
        sfRenderWindow_setView(m->window, m->zone7.view_w7);
        sfRenderWindow_drawSprite(m->window, m->zone7.w7_map, NULL);
        //check_all_pose(m, m->zone1.tab_map, 1);
        move_game_cursor(m);
        //all_perso_movement(m);
        //set_new_position(m, m->univ.spr_roy, &m->perso[ROY]);
        //print_boss_barre(m, BOSS7, m->zone7.view_w7);
        //print_mini_barre(m, f);
        return_and_old_current2(m, 7);
    }
}
