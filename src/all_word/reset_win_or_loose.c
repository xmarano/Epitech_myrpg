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
    for (int j = 13; j < 23; j++) {
        m->perso[j].stat_p.current_hp = m->perso[j].stat_p.max_hp;
    }
    m->univ.interface.limite_tour = 5;
    m->univ.interface.attack_gpy2 = false;
    m->univ.interface.attack_gpy = false;
    m->univ.interface.go_fight = false;
    sfMusic_pause(m->setting.music);
    sfMusic_play(m->hub.music);
    m->current = 0; // a deplacer chez leo, curr 24!
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
        for (int j = 13; j < 23; j++) {
            m->perso[j].stat_p.current_hp = m->perso[j].stat_p.max_hp;
        }
        m->univ.interface.attack_gpy2 = false;
        m->univ.interface.attack_gpy = false;
        m->univ.interface.go_fight = false;
        m->univ.interface.limite_tour = 5;
        sfMusic_pause(m->setting.music);
        sfMusic_play(m->hub.music);
        m->current = 0; // a deplacer chez leo, curr 25!
    }
}
