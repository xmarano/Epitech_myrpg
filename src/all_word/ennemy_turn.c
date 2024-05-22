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

void move_ennemy(Global_t *m, char **map, sfVector2i previous_pos, sfVector2i pos_target)
{
    if (map[pos_target.y][pos_target.x + 1] != 'X') {
        map[pos_target.y][pos_target.x + 1] = map[previous_pos.y + 1][previous_pos.x + 1];
        map[previous_pos.y + 1][previous_pos.x + 1] = m->old_map[previous_pos.y + 1][previous_pos.x + 1];
    }
    else if (map[pos_target.y][pos_target.x - 1] != 'X') {
        map[pos_target.y][pos_target.x - 1] = map[previous_pos.y + 1][previous_pos.x + 1];
        map[previous_pos.y + 1][previous_pos.x + 1] = m->old_map[previous_pos.y + 1][previous_pos.x + 1];
    }
    else if (map[pos_target.y + 1][pos_target.x] != 'X') {
        map[pos_target.y + 1][pos_target.x] = map[previous_pos.y + 1][previous_pos.x + 1];
        map[previous_pos.y + 1][previous_pos.x + 1] = m->old_map[previous_pos.y + 1][previous_pos.x + 1];
    }
    else if (map[pos_target.y - 1][pos_target.x] != 'X') {
        map[pos_target.y - 1][pos_target.x] = map[previous_pos.y + 1][previous_pos.x + 1];
        map[previous_pos.y + 1][previous_pos.x + 1] = m->old_map[previous_pos.y + 1][previous_pos.x + 1];
    }
}

void check_target_ennemy_turn(int i, Global_t *m, char **map, sfSprite *spr)
{
    sfVector2f pos = sfSprite_getPosition(spr);

    // pos.x /= 40;
    // pos.y /= 40;
    // for (int dx = -i; dx <= i; dx++) {
    //     for (int dy = -i; dy <= i; dy++) {
    //         int nx = pos.x + dx;
    //         int ny = pos.y + dy;
    //         if (abs(dx) + abs(dy) <= i && est_dans_grille(nx, ny)) {
    //             if (ligne_sans_obstacle((sfVector2i){pos.x + 1, pos.y + 1}, (sfVector2i){nx + 1, ny + 1}, map, m) && isdigit(map[ny + 1][nx + 1])) {
    //                 printf("%i %i\n", nx, ny);
    //                 move_ennemy(m, map, (sfVector2i){(int)pos.x, (int)pos.y}, (sfVector2i){nx, ny});
    //             }
    //         }
    //     }
    // }
}
