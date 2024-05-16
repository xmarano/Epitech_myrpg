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

void draw_monde1(Global_t *m, hub_t *hub)
{
    if (m->current == 1) {
        sfRenderWindow_setView(m->window, m->zone1.view_w1);
        // for (int i = 0; m->zone1.tab_map[i] != NULL; i++) {
        //     for (int y = 0; m->zone1.tab_map[i][y] != '\0'; y++) {
        //         if (m->zone1.tab_map[i][y] == '0') {
        //             sfSprite_setPosition(m->univ.spr_roy, (sfVector2f){(y - 1) * 40, (i - 1) * 40});
        //         }
        //     }
        // }
        sfRenderWindow_drawSprite(m->window, m->zone1.w1_map, NULL);
        sfRenderWindow_drawSprite(m->window, m->univ.spr_roy, NULL);
    }
}
