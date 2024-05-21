/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** event_interface.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"

void add_hp(Global_t *m, int who)
{
    m->perso[who].stat_p.current_hp += 10;
    if (m->perso[who].stat_p.current_hp > m->perso[who].stat_p.max_hp)
        m->perso[who].stat_p.current_hp = m->perso[who].stat_p.max_hp;
    printf("potion used!\n");
}

void hp_up(Global_t *m)
{
    int who = m->univ.interface.who;

    for (int j = 0; j < 5; j++) {
        if (strcmp(m->perso[who].inv_weapon[j].name, "Potion") == 0) {
            add_hp(m, who);
            memset(&m->perso[who].inv_weapon[j], 0, sizeof(Weapons_t));
            m->perso[who].inv_weapon[j].is_empty = true;
        }
    }
}

void attack(Global_t *m)
{
    if (m->univ.interface.attack_gpy == true) {
        printf("caca\n");
        m->univ.interface.attack_gpy = false;
    }
    return;
}
