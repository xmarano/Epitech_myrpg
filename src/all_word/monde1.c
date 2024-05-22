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
#include <ctype.h>

void draw_monde1(Global_t *m, fight_t *f)
{
    if (m->current == 1) {
        sfRenderWindow_setView(m->window, m->zone1.view_w1);
        sfRenderWindow_drawSprite(m->window, m->zone1.w1_map, NULL);
        check_all_pose(m, m->current_map, 1);
        move_game_cursor(m);
        if (m->univ.interface.limite_tour > 0)
            all_perso_movement(m, m->current_map);
        //print_boss_barre(m, BOSS1, m->zone1.view_w1);
        print_mini_barre(m, f, 1);
        return_and_old_current2(m, 1);
    }
}
