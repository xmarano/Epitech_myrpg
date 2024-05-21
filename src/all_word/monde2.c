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

void draw_monde2(Global_t *m, fight_t *f)
{
    if (m->current == 2) {
        sfRenderWindow_setView(m->window, m->zone2.view_w2);
        sfRenderWindow_drawSprite(m->window, m->zone2.w2_map, NULL);
        check_all_pose(m, m->zone2.tab_map, 2);
        move_game_cursor(m);
        print_boss_barre(m, BOSS2, m->zone2.view_w2);
        return_and_old_current2(m, 2);
    }
}
