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

static void set_pose_perso(char **map, char ref, sfSprite *sprite, int i)
{
    for (int y = 0; map[i][y] != '\0'; y++) {
        if (map[i][y] == ref) {
            sfSprite_setPosition(sprite,
            (sfVector2f){(y - 1) * 40, (i - 1) * 40});
        }
    }
}

void check_position(char **map, char ref, sfSprite *sprite, Global_t *m)
{
    for (int i = 0; map[i] != NULL; i++) {
        set_pose_perso(map, ref, sprite, i);
    }
    sfRenderWindow_drawSprite(m->window, sprite, NULL);
}

void draw_monde1(Global_t *m)
{
    if (m->current == 1) {
        sfRenderWindow_setView(m->window, m->zone1.view_w1);
        sfRenderWindow_drawSprite(m->window, m->zone1.w1_map, NULL);
        check_position(m->zone1.tab_map, '0', m->univ.spr_roy, m);
        check_position(m->zone1.tab_map, '1', m->univ.spr_xmara, m);
    }
}
