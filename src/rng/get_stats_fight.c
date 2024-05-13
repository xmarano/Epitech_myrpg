/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** put_damage.c
*/

#include "../rpg.h"

int get_crit_rate(Perso_t *atk, Perso_t *def)
{
    if (atk->current_weapon->crit
    + atk->stat_p.skl * 2 - def->stat_p.lck <= 0)
        return 0;
    return atk->current_weapon->crit
    + atk->stat_p.skl * 2 - def->stat_p.lck;
}

int get_hit_rate(Perso_t *atk, Perso_t *def)
{
    int accuracy = atk->current_weapon->accuracy + atk->stat_p.skl * 2 +
    atk->stat_p.lck * 2 +
    is_weapon_advantage(atk->current_weapon, def->current_weapon) * 10;
    int avoid = def->stat_p.spd * 2 + def->stat_p.lck;
    //+ defense->current_case->esq_bonus;

    return accuracy - avoid;
}