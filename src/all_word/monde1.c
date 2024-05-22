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
        if (!m->univ.interface.go_fight)
            move_game_cursor(m);
        if (m->univ.interface.limite_tour > 0 && !m->univ.interface.go_fight)
            all_perso_movement(m, m->current_map);
        if (m->univ.interface.limite_tour == 0 && !m->univ.interface.go_fight)
            all_ennemy_movement(m, m->current_map);
        //print_boss_barre(m, BOSS1, m->zone1.view_w1);
        print_mini_barre(m, f, 1);
        if (m->perso[BOSS1].stat_p.current_hp <= 0) {
            m->zone1.is_w1_clear = true;
            m->current = 0;
        }
        return_and_old_current2(m, 1);
    }
}
