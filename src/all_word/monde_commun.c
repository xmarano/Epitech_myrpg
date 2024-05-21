/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** monde_commun.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"
#include <ctype.h>

int check_cursor_on_sprite(Global_t *m, sfSprite *spr)
{
    sfVector2f pos_curs = sfSprite_getPosition(m->univ.map_cursor_sprite);
    sfVector2f pos_spr = sfSprite_getPosition(spr);

    if (pos_curs.x == pos_spr.x && pos_curs.y == pos_spr.y)
        return 1;
    return 0;
}

void set_new_position(Global_t *m, sfSprite *spr, Perso_t *perso, char **map)
{
    sfVector2f pos_curs = sfSprite_getPosition(m->univ.map_cursor_sprite);
    sfVector2f pos_spr = sfSprite_getPosition(spr);

    if (perso->case_visble == 1 && sfKeyboard_isKeyPressed(sfKeySpace) && check_cursor_on_sprite(m, spr) == 0 && is_movement_ok(spr, perso->stat_p.mov, map, m) == true) {
        map[(int)pos_spr.y / 40 + 1][(int)pos_spr.x / 40 + 1] = ' ';
        if (isdigit(map[(int)pos_curs.y / 40 + 1][(int)pos_curs.x / 40 + 1]) == 0) {
            if (strcmp(perso->name_perso, "ROY") == 0) {
                map[(int)pos_curs.y / 40 + 1][(int)pos_curs.x / 40 + 1] = '0';
                m->univ.interface.who = 0;
            }
            if (strcmp(perso->name_perso, "Infenium") == 0) {
                map[(int)pos_curs.y / 40 + 1][(int)pos_curs.x / 40 + 1] = '1';
                m->univ.interface.who = 1;
            }
            if (strcmp(perso->name_perso, "Racaillou") == 0) {
                map[(int)pos_curs.y / 40 + 1][(int)pos_curs.x / 40 + 1] = '4';
                m->univ.interface.who = 4;
            }
            if (strcmp(perso->name_perso, "PateCarbo") == 0) {
                map[(int)pos_curs.y / 40 + 1][(int)pos_curs.x / 40 + 1] = '2';
                m->univ.interface.who = 2;
            }
            if (strcmp(perso->name_perso, "Xmarano") == 0) {
                map[(int)pos_curs.y / 40 + 1][(int)pos_curs.x / 40 + 1] = '3';
                m->univ.interface.who = 3;
            }
        }
        for (int i = 0; map[i] != NULL; i++)
            printf("%s\n", map[i]);
        m->univ.interface.select_inteface = true;
    }
}

void draw_visible_cases(Global_t *m, sfSprite *spr, Perso_t *perso, char **map)
{
    sfTime time = sfClock_getElapsedTime(m->univ.clock_select_perso);
    float seconds = sfTime_asMilliseconds(time) / 1000.0;

    if (perso->case_visble == 1)
        draw_possible_movement(perso->stat_p.mov, m, map, spr);
    if (seconds > 0.3) {
        if (check_cursor_on_sprite(m, spr) == 1) {
            if (sfKeyboard_isKeyPressed(sfKeySpace) && perso->case_visble == true) {
                perso->case_visble = false;
                sfClock_restart(m->univ.clock_select_perso);
                return;
            }
            if (sfKeyboard_isKeyPressed(sfKeySpace) && perso->case_visble == false) {
                perso->case_visble = true;
                sfClock_restart(m->univ.clock_select_perso);
                m->univ.interface.where = 0;
            }
        }
    }
}

void all_perso_movement(Global_t *m, char **tab)
{
    if (!m->univ.interface.select_inteface) {
        draw_visible_cases(m, m->univ.spr_roy, &m->perso[ROY], tab);
        draw_visible_cases(m, m->univ.spr_xmara, &m->perso[XMARANO], tab);
        draw_visible_cases(m, m->univ.spr_raca, &m->perso[RACAILLOU], tab);
        draw_visible_cases(m, m->univ.spr_pate, &m->perso[PATECARBO], tab);
        draw_visible_cases(m, m->univ.spr_infe, &m->perso[INFENIUM], tab);
    }
    set_new_position(m, m->univ.spr_roy, &m->perso[ROY], tab);
    set_new_position(m, m->univ.spr_xmara, &m->perso[XMARANO], tab);
    set_new_position(m, m->univ.spr_raca, &m->perso[RACAILLOU], tab);
    set_new_position(m, m->univ.spr_pate, &m->perso[PATECARBO], tab);
    set_new_position(m, m->univ.spr_infe, &m->perso[INFENIUM], tab);
}
