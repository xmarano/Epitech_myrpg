/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** return_menu.c
*/

#include "../rpg.h"
#include "../include/menu.h"

void retour_menu(Global_t *m, hub_t *h)
{
    if (m->current == 20) {
        if (sfKeyboard_isKeyPressed(sfKeyF)) { // boutton save game é quitter
            save_game(m, h);
            sfRenderWindow_close(m->window);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) // retour en ariere
            m->current = m->old_current;
        // quitter sans sauvgarder
        return;
    }
}
