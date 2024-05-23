/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** what_word_dia.c
*/

#include "rpg.h"
#include "include/perso.h"
#include "include/menu.h"
#include "my.h"

void what_world_dia(Global_t *m)
{
    RenderContext_t context = {m->window, m->setting.fontdi};

    if (m->dialogue.start_dialogue == 1) {
        m->current_combat = 1;
        m->current_boss = 5;
        m->old_map = str_to_word_array(get_buff("maps/map1/map1.txt"));
        m->current_map = str_to_word_array(get_buff("maps/map1/map1.txt"));
        parse_file("dialogue/chap1.txt", &context, m, 1);
        return;
    }
    if (m->dialogue.start_dialogue == 2) {
        m->current_combat = 2;
        m->current_boss = 6;
        m->old_map = str_to_word_array(get_buff("maps/map2/map2.txt"));
        m->current_map = str_to_word_array(get_buff("maps/map2/map2.txt"));
        parse_file("dialogue/chap2.txt", &context, m, 2);
        return;
    }
}
