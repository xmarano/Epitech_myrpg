/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** reset_win_or_loose.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"

void look_win(Global_t *m)
{
    for (int i = 0; i < 5; i++) {
        m->perso[i].stat_p.current_hp = m->perso[i].stat_p.max_hp;
    }
    m->current = 0; // a deplacer chez leo, curr 23!
}

void look_loose(Global_t *m)
{
    int nbr = 0;

    for (int i = 0; i < 5; i++) {
        if (m->perso[i].stat_p.current_hp <= 0)
            nbr++;
    }
    if (nbr == 5) {
        for (int i = 0; i < 5; i++)
            m->perso[i].stat_p.current_hp = m->perso[i].stat_p.max_hp;
        m->univ.interface.limite_tour = 5;
    }
}
