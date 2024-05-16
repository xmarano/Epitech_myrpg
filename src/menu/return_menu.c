/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** return_menu.c
*/

#include "../rpg.h"
#include "../include/menu.h"

void load_game(Global_t *m, hub_t *hub)
{
    FILE *file = fopen("assets/save_party/save.txt", "r");
    int gold;

    if (file == NULL) {
        exit(EXIT_FAILURE);
    }
    if (fscanf(file, "%d", &gold) != 1) {
        printf("Erreur\n");
        return;
    }
    m->gold = gold;
    fclose(file);
}

void retour_menu(Global_t *m, hub_t *h)
{
    if (m->current == 20) {
        if (sfKeyboard_isKeyPressed(sfKeyF) && m->load_game_called == false) {
            printf("passed\n");
            load_game(m, h);
            m->load_game_called = true;
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            m->current = m->old_current;
        return;
    }
}
