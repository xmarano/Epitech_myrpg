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

void import_emy_in_battle(Global_t *m, int k)
{
    k += 5;
    printf("%s\n", m->perso[m->univ.interface.who].name_perso);
    printf("%s\n", m->perso[k].name_perso);
}

static void attack3(Global_t *m, int i, int j)
{
    char *liste_emy = "PQRSTUWYLM/GJKZDE*";

    for (int k = 0; liste_emy[k] != '\0'; k++) {
        if (m->current_map[i + 1][j] == liste_emy[k]) {
            import_emy_in_battle(m, k);
            return;
        }
        if (m->current_map[i - 1][j] == liste_emy[k]) {
            import_emy_in_battle(m, k);
            return;
        }
        if (m->current_map[i][j + 1] == liste_emy[k]) {
            import_emy_in_battle(m, k);
            return;
        }
        if (m->current_map[i][j - 1] == liste_emy[k]) {
            import_emy_in_battle(m, k);
            return;
        }
    }
}

static void attack2(Global_t *m , int i)
{
    for (int j = 0; m->current_map[i][j] != '\0'; j++) {
        if (m->current_map[i][j] == (m->univ.interface.who + 48)) {
            attack3(m, i, j);
        }
    }
    return;
}

void attack(Global_t *m)
{
    if (m->univ.interface.attack_gpy == true) {
        for (int i = 0; m->current_map[i] != NULL; i++) {
            attack2(m, i);
        }
        m->univ.interface.attack_gpy = false;
    }
    return;
}
