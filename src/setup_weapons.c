/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** setup_weapons.c
*/

#include "rpg.h"
#include "include/npc.h"

int import_weapons_stats(Global_t *m)
{
    FILE *file = fopen("assets/weapons/weapons_stat.txt", "r");

    for (int i = 0; i < 20; i++) {
        if (fscanf(file, "%s %s %d %d %d %d %d %s", m->weapons[i].name, m->weapons[i].weapon_type, &m->weapons[i].attack, &m->weapons[i].accuracy,
        &m->weapons[i].rng, &m->weapons[i].crit, &m->weapons[i].cost, &m->weapons[i].link_texture) != 8) {
            printf("Erreur de lecture pour l'arme %d\n", i);
            fclose(file);
            return 84;
        }
        printf("Lecture réussie pour l'arme %d: Nom: %s, Type: %s, Attaque: %d, Précision: %d, Portée: %d, Critique: %d, Coût: %d, Texture: %s\n", i + 1,
        m->weapons[i].name, m->weapons[i].weapon_type, m->weapons[i].attack, m->weapons[i].accuracy,
        m->weapons[i].rng, m->weapons[i].crit, m->weapons[i].cost, m->weapons[i].link_texture);
    }
    fclose(file);
    return 0;
}
