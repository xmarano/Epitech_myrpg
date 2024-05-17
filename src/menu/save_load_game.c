/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** save_load_game.c
*/

#include "../rpg.h"
#include "../include/menu.h"

static int gestion_err_du_fichier(FILE *file, int c, Global_t *m)
{
    if (file == NULL) {
        printf("fichier de sauvegarde introuvable!\n");
        exit(1);
    }
    c = fgetc(file);
    if (c == EOF) {
        printf("Aucune données de sauvegarde trouvée!\n");
        fclose(file);
        return -1;
    }
    fseek(file, 0, SEEK_SET);
}

void load_game(Global_t *m, hub_t *hub)
{
    FILE *file = fopen("assets/save_party/save.txt", "r");
    int c;

    if (gestion_err_du_fichier(file, c, m) == -1) {
        m->current = 14;
        return;
    }
    fscanf(file, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &m->gold, &m->hub.prologue_ok,
    &m->zone1.is_w1_clear,  &m->zone2.is_w2_clear, &m->zone3.is_w3_clear, &m->zone4.is_w4_clear,
    &m->zone5.is_w5_clear, &m->zone6.is_w6_clear, &m->zone7.is_w7_clear, &m->zone8.is_w8_clear);
    m->current = 14;
    fclose(file);
}

void save_game(Global_t *m, hub_t *h)
{
    FILE *file = fopen("assets/save_party/save.txt", "w");

    fprintf(file, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", m->gold, m->hub.prologue_ok,
    m->zone1.is_w1_clear,  m->zone2.is_w2_clear, m->zone3.is_w3_clear, m->zone4.is_w4_clear,
    m->zone5.is_w5_clear, m->zone6.is_w6_clear, m->zone7.is_w7_clear, m->zone8.is_w8_clear);
    printf("game saved succesfully!\n");
    return;
}
