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

int ligne_sans_obstacle(sfVector2i pos_0, sfVector2i pos_1, char **map) {
    int dx = abs(pos_1.x - pos_0.x);
    int sx = pos_0.x < pos_1.x ? 1 : -1;
    int dy = -abs(pos_1.y - pos_0.y);
    int sy = pos_0.y < pos_1.y ? 1 : -1; 
    int err = dx + dy, e2;

    while (1) {
        if (map[pos_0.y + 1][pos_0.x + 1] == 'L' ||
        map[pos_0.y + 1][pos_0.x + 1] == 'R' ||
        map[pos_0.y + 1][pos_0.x + 1] == 'M')
            return 0;
        if (pos_0.x == pos_1.x && pos_0.y == pos_1.y) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; pos_0.x += sx; }
        if (e2 <= dx) { err += dx; pos_0.y += sy; }
    }
    return 1;
}

int est_dans_grille(int x, int y) {
    return x >= 0 && x < 30 && y >= 0 && y < 20;
}

void draw_squares(Global_t *m, int nx, int ny)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect, (sfVector2f){40, 40});
    sfRectangleShape_setPosition(rect, (sfVector2f){nx * 40, ny * 40});
    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(100, 206, 250, 150));
    sfRectangleShape_setOutlineColor(rect, sfWhite);
    sfRectangleShape_setOutlineThickness(rect, 1);
    sfRenderWindow_drawRectangleShape(m->window, rect, NULL);
    sfRectangleShape_destroy(rect);
}

void mettre_en_evidence_cases(int x, int y, int i, Global_t *m)
{
    for (int dx = -i; dx <= i; dx++) {
        for (int dy = -i; dy <= i; dy++) {
            int nx = x + dx;
            int ny = y + dy;
            if (abs(dx) + abs(dy) <= i && est_dans_grille(nx, ny)) {
                if (ligne_sans_obstacle((sfVector2i){x, y}, (sfVector2i){nx, ny}, m->zone1.tab_map)) {
                    draw_squares(m, nx, ny);
                }
            }
        }
    }
}

void draw_possible_movement(Global_t *m, sfSprite *spr, Perso_t *perso)
{
    sfVector2f pos = sfSprite_getPosition(spr);

    pos.x /= 40;
    pos.y /= 40;
    mettre_en_evidence_cases(pos.x, pos.y, perso->stat_p.mov, m);
}

bool is_movement_ok(sfVector2f pos_spr, sfVector2f pos_obj, int i, Global_t *m)
{
    pos_spr.x = pos_spr.x / 40;
    pos_spr.y = pos_spr.y / 40;
    pos_obj.x = pos_obj.x / 40;
    pos_obj.y = pos_obj.y / 40;
    for (int dx = -i; dx <= i; dx++) {
        for (int dy = -i; dy <= i; dy++) {
            int nx = pos_spr.x + dx;
            int ny = pos_spr.y + dy;
            if (nx == pos_obj.x && ny == pos_obj.y && abs(dx) + abs(dy) <= i) {
                if (ligne_sans_obstacle((sfVector2i){pos_spr.x, pos_spr.y}, (sfVector2i){pos_obj.x, pos_obj.y}, m->zone1.tab_map))
                    return true;
            }
        }
    }
    return false;
}