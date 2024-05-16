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

void draw_monde1(Global_t *m)
{
    if (m->current == 1) {
        sfRenderWindow_setView(m->window, m->zone1.view_w1);
        sfRenderWindow_drawSprite(m->window, m->zone1.w1_map, NULL);
        check_position(m->zone1.tab_map, '0', m->univ.spr_roy, m);
        check_position(m->zone1.tab_map, '1', m->univ.spr_xmara, m);
        return_and_old_current(m, 1);
    }
}
