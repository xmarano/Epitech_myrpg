/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** menu.c
*/

#include "rpg.h"

int is_weapon_advantage(Weapons_t *weapon_atk, Weapons_t *weapon_def)
{
    if (strcmp(weapon_atk->name, "sword") == 0) {
        if (strcmp(weapon_def->name, "axe") == 0)
            return 1;
    }
    if (strcmp(weapon_atk->name, "axe") == 0) {
        if (strcmp(weapon_def->name, "spear") == 0)
            return 1;
    }
    if (strcmp(weapon_atk->name, "spear") == 0) {
        if (strcmp(weapon_def->name, "sword") == 0)
            return 1;
    }
    if (strcmp(weapon_atk->name, weapon_def->name) != 0)
        return -1;
    return 0;
}

int is_hit(Perso_t *attack, Perso_t *defense, Weapons_t *weapon_atk, Weapons_t *weapon_def)
{
    int nb1 = rand() % 100;
    int nb2 = rand() % 100;
    int accuracy = weapon_atk->accuracy + attack->stat_p.skl * 2 + attack->stat_p.lck * 2 + is_weapon_advantage(weapon_atk, weapon_def) * 10;
    int avoid = defense->stat_p.spd * 2 + defense->stat_p.lck + defense->current_case->esq_bonus;

    accuracy = accuracy - avoid;
    printf("numbers: %i accuracy: %i\n", ((nb1 + nb2) / 2), accuracy);
    if (accuracy <= 0) {
        return 0;
    }
    if ((nb1 + nb2) / 2 <= accuracy) {
        return 1;
    }
    return 0;
}

int double_attack(stchar_t *attack, stchar_t *defense)
{
    if (attack->spd - defense->spd >= 4)
        return 1;
    return 0;
}

int critical_hit(stchar_t *attack, stchar_t *defense, Weapons_t *weapon)
{
    int nb = rand() % 100;
    int critical_weapon = weapon->crit + attack->skl * 2 - defense->lck;

    if (nb <= critical_weapon) {
        return 3;
    }
    return 1;
}

void level_up(stchar_t *stats)
{
    int rng = rand();

    if (stats->xp >= 100) {
        stats->level += 1;
        stats->xp -= 100;
        if (rng % 2 == 0)
            stats->skl += 1;
        if (rng % 3 == 0)
            stats->def += 1;
        if (rng % 4 == 0)
            stats->max_hp += 1;
        if (rng % 5 == 0)
            stats->lck += 1;
        if (rng % 6 == 0)
            stats->res += 1;
        if (rng % 7 == 0)
            stats->spd += 1;
    }
}

int damage_physical(Perso_t *attacker, Perso_t *defender)
{
    int crit = critical_hit(&attacker->stat_p, &defender->stat_p, attacker->current_weapon);
    int atk = attacker->stat_p.skl + is_weapon_advantage(attacker->current_weapon, defender->current_weapon);
    int def = defender->stat_p.def + defender->current_case->def_bonus;

    return (atk - def) * crit;
}

int damage_magical(Perso_t *attacker, Perso_t *defender)
{
    int crit = critical_hit(&attacker->stat_p, &defender->stat_p, attacker->current_weapon);
    int atk = attacker->stat_p.mag + is_weapon_advantage(attacker->current_weapon, defender->current_weapon);
    int def = defender->stat_p.res + defender->current_case->def_bonus;

    return (atk - def) * crit;
}
/*int main(void)
{
    int test = 0;

    srand(15487923154682323659);
    while (test < 50) {
        if (is_hit(70, 10, 10) == 1)
            printf("hit !\n");
        else
            printf("missed !\n");
        test++;
    }
}*/
