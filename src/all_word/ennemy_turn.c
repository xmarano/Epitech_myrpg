/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** game_cursor.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"
#include <ctype.h>

void set_previous_case_ennemy(Global_t *m, sfVector2f pos_spr, char **map)
{
    if (m->current_map[(int)pos_spr.y / 40 + 1][(int)pos_spr.x / 40 + 1] != 'Z')
        map[(int)pos_spr.y / 40 + 1][(int)pos_spr.x / 40 + 1] = m->old_map[(int)pos_spr.y / 40 + 1][(int)pos_spr.x / 40 + 1];
    else {
        map[(int)pos_spr.y / 40 + 1][(int)pos_spr.x / 40 + 1] = ' ';
    }
}

void move_ennemy(Global_t *m, sfVector2i previous_pos, sfVector2i pos_target, char patern)
{
    if (m->current_map[pos_target.y][pos_target.x + 1] != 'X' && !isdigit(m->current_map[pos_target.y][pos_target.x + 1])) {
        m->current_map[pos_target.y][pos_target.x + 1] = patern;
        if (m->current_map[previous_pos.y][previous_pos.x] == patern)
            m->current_map[previous_pos.y][previous_pos.x] = ' ';
    } else if (m->current_map[pos_target.y][pos_target.x - 1] != 'X' && !isdigit(m->current_map[pos_target.y][pos_target.x - 1])) {
        m->current_map[pos_target.y][pos_target.x - 1] = patern;
        if (m->current_map[previous_pos.y][previous_pos.x] == patern)
            m->current_map[previous_pos.y][previous_pos.x] = ' ';
    } else if (m->current_map[pos_target.y + 1][pos_target.x] != 'X' && !isdigit(m->current_map[pos_target.y + 1][pos_target.x])) {
        m->current_map[pos_target.y + 1][pos_target.x] = patern;
        if (m->current_map[previous_pos.y][previous_pos.x] == patern)
            m->current_map[previous_pos.y][previous_pos.x] = ' ';
    } else if (m->current_map[pos_target.y - 1][pos_target.x] != 'X' && !isdigit(m->current_map[pos_target.y - 1][pos_target.x + 1])) {
        m->current_map[pos_target.y - 1][pos_target.x] = patern;
        if (m->current_map[previous_pos.y][previous_pos.x] == patern)
            m->current_map[previous_pos.y][previous_pos.x] = ' ';
    }
}

void check_target_ennemy_turn(int i, Global_t *m, sfSprite *spr, char patern)
{
    sfVector2f pos = sfSprite_getPosition(spr);

    pos.x /= 40;
    pos.y /= 40;
    for (int dx = -i; dx <= i; dx++) {
        for (int dy = -i; dy <= i; dy++) {
            int nx = pos.x + dx;
            int ny = pos.y + dy;
            if (abs(dx) + abs(dy) <= i && est_dans_grille(nx, ny)) {
                if (ligne_sans_obstacle((sfVector2i){pos.x + 1, pos.y + 1}, (sfVector2i){nx + 1, ny + 1}, m->current_map, m) && isdigit(m->current_map[ny + 1][nx + 1])) {
                    move_ennemy(m, (sfVector2i){(int)pos.x + 1, (int)pos.y + 1}, (sfVector2i){nx + 1, ny + 1}, patern);
                    return;
                }
            }
        }
    }
}
