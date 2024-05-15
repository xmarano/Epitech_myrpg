/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** print_txt.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"

static void ptr_dia(Global_t *m, int word)
{

}

void what_dialogue(Global_t *m, int word)
{
    if (word == 1)
        ptr_dia(m, word);
}
