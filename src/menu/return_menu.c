/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** return_menu.c
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
    if (fscanf(file, "%d", &m->gold) != 1) {
        printf("Erreur de lecture!\n");
        sfRenderWindow_close(m->window);
        return;
    }
    m->current = 14;
    fclose(file);
}

void save_game(Global_t *m, hub_t *h)
{
    FILE *file = fopen("assets/save_party/save.txt", "w");

    fprintf(file, "%d", m->gold);
    printf("game saved succesfully!\n");
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
