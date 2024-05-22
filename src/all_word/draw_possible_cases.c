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

static int check2(char **map, int y, int x, Global_t *m)
{
    char *tab = "PQRSTUWYLM/GJKZDE*";

    for (int i = 0; i < strlen(tab); i++) {
        if (map[x][y] == tab[i])
            return -1;
    }
    return 0;
}

int ligne_sans_obstacle(sfVector2i pos_0, sfVector2i pos_1, char **map, Global_t *m)
{
    int dx = abs(pos_1.x - pos_0.x);
    int sx = pos_0.x < pos_1.x ? 1 : -1;
    int dy = -abs(pos_1.y - pos_0.y);
    int sy = pos_0.y < pos_1.y ? 1 : -1;
    int err = dx + dy, e2;

    while (1) {
        if (check2(map, pos_0.x, pos_0.y, m) == -1)
            return 0;
        if (map[pos_0.y][pos_0.x] == 'X')
            return 0;
        if (pos_0.x == pos_1.x && pos_0.y == pos_1.y) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; pos_0.x += sx; }
        if (e2 <= dx) { err += dx; pos_0.y += sy; }
    }
    return 1;
}

int est_dans_grille(int x, int y)
{
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

void draw_possible_movement(int i, Global_t *m, char **map, sfSprite *spr)
{
    sfVector2f pos = sfSprite_getPosition(spr);

    pos.x /= 40;
    pos.y /= 40;
    for (int dx = -i; dx <= i; dx++) {
        for (int dy = -i; dy <= i; dy++) {
            int nx = pos.x + dx;
            int ny = pos.y + dy;
            if (abs(dx) + abs(dy) <= i && est_dans_grille(nx, ny)) {
                if (ligne_sans_obstacle((sfVector2i){pos.x + 1, pos.y + 1}, (sfVector2i){nx + 1, ny + 1}, map, m)) {
                    draw_squares(m, nx, ny);
                }
            }
        }
    }
}

bool is_movement_ok(sfSprite *spr, int i, char **map, Global_t *m)
{
    sfVector2f pos_curs = sfSprite_getPosition(m->univ.map_cursor_sprite);
    sfVector2f pos_spr = sfSprite_getPosition(spr);

    pos_spr.x = pos_spr.x / 40;
    pos_spr.y = pos_spr.y / 40;
    pos_curs.x = pos_curs.x / 40;
    pos_curs.y = pos_curs.y / 40;
    for (int dx = -i; dx <= i; dx++) {
        int nx = pos_spr.x + dx;
        for (int dy = -i; dy <= i; dy++) {
            int ny = pos_spr.y + dy;
            if (nx == pos_curs.x && ny == pos_curs.y && abs(dx) + abs(dy) <= i) {
                if (ligne_sans_obstacle((sfVector2i){pos_spr.x + 1, pos_spr.y + 1}, (sfVector2i){pos_curs.x + 1, pos_curs.y + 1}, map, m))
                    return true;
            }
        }
    }
    return false;
}
