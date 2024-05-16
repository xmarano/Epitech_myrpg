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

    if (file == NULL) {
        exit(EXIT_FAILURE);
    }
    if (fscanf(file, "%d", &m->gold) != 1) {
        printf("Erreur\n");
        return;
    }
    m->current = 14;
    fclose(file);
}

void save_game(Global_t *m, hub_t *h)
{
    FILE *file = fopen("assets/save_party/save.txt", "w");

    fprintf(file, "%d", m->gold);
    printf("game_saved\n");
    return;
}

void retour_menu(Global_t *m, hub_t *h)
{
    if (m->current == 20) {
        if (sfKeyboard_isKeyPressed(sfKeyF)) { //save game
            save_game(m, h);
            sfRenderWindow_close(m->window);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) // retour en ariere
            m->current = m->old_current;
        return;
    }
}
