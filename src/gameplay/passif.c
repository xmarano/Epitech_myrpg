/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** passif.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"

void passif_mage(Global_t *m)
{
    for (int i = 13; i < 23; i++) {
        m->perso[i].stat_p.current_hp += 10;
        if (m->perso[i].stat_p.current_hp > m->perso[i].stat_p.max_hp)
            m->perso[i].stat_p.current_hp = m->perso[i].stat_p.max_hp;
    }
}

void passif_infenium(Global_t *m)
{
    if (m->perso[INFENIUM].stat_p.current_hp <= 0)
        return;
    for (int i = 0; i < 5; i++) {
        if (m->perso[i].stat_p.current_hp > 0)
            m->perso[i].stat_p.current_hp += 1;
        if (m->perso[i].stat_p.current_hp > m->perso[i].stat_p.max_hp)
            m->perso[i].stat_p.current_hp = m->perso[i].stat_p.max_hp;
    }
}
