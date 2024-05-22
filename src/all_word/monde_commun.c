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

void set_previous_case(Global_t *m, sfVector2f pos_spr, char **map)
{
    if (isdigit(m->current_map[(int)pos_spr.y / 40 + 1][(int)pos_spr.x / 40 + 1]) == 0)
        map[(int)pos_spr.y / 40 + 1][(int)pos_spr.x / 40 + 1] = m->current_map[(int)pos_spr.y / 40 + 1][(int)pos_spr.x / 40 + 1];
    else {
        map[(int)pos_spr.y / 40 + 1][(int)pos_spr.x / 40 + 1] = ' ';
    }
}

void set_new_position(Global_t *m, sfSprite *spr, Perso_t *perso, char **map)
{
    sfVector2f pos_curs = sfSprite_getPosition(m->univ.map_cursor_sprite);
    sfVector2f pos_spr = sfSprite_getPosition(spr);

    if (perso->case_visble == 1 && sfKeyboard_isKeyPressed(sfKeySpace) && check_cursor_on_sprite(m, spr) == 0 && is_movement_ok(spr, perso->stat_p.mov, map, m) == true) {
        set_previous_case(m, pos_spr, map);
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

void all_ennemy_movement(Global_t *m, char **tab)
{
    check_target_ennemy_turn(m->perso[BOSS1].stat_p.mov, m, m->univ.spr_Boss1, 'P');
    check_target_ennemy_turn(m->perso[BOSS2].stat_p.mov, m, m->univ.spr_Boss2, 'Q');
    check_target_ennemy_turn(m->perso[BOSS3].stat_p.mov, m, m->univ.spr_Boss3, 'R');
    check_target_ennemy_turn(m->perso[BOSS4].stat_p.mov, m, m->univ.spr_Boss4, 'S');
    check_target_ennemy_turn(m->perso[BOSS5].stat_p.mov, m, m->univ.spr_Boss5, 'T');
    check_target_ennemy_turn(m->perso[BOSS6].stat_p.mov, m, m->univ.spr_Boss6, 'U');
    check_target_ennemy_turn(m->perso[BOSS7].stat_p.mov, m, m->univ.spr_Boss7, 'W');
    check_target_ennemy_turn(m->perso[BOSS8].stat_p.mov, m, m->univ.spr_Boss8, 'Y');
    check_target_ennemy_turn(m->perso[ENEMY1_SWORD].stat_p.mov, m, m->univ.spr_emy1_sword, 'L');
    check_target_ennemy_turn(m->perso[ENEMY2_SWORD].stat_p.mov, m, m->univ.spr_emy2_sword, 'M');
    check_target_ennemy_turn(m->perso[ENEMY3_SWORD].stat_p.mov, m, m->univ.spr_emy3_sword, '/');
    check_target_ennemy_turn(m->perso[ENEMY1_SPEAR].stat_p.mov, m, m->univ.spr_emy1_spear, 'G');
    check_target_ennemy_turn(m->perso[ENEMY2_SPEAR].stat_p.mov, m, m->univ.spr_emy2_spear, 'J');
    check_target_ennemy_turn(m->perso[ENEMY3_SPEAR].stat_p.mov, m, m->univ.spr_emy3_spear, 'K');
    check_target_ennemy_turn(m->perso[ENEMY1_AXE].stat_p.mov, m, m->univ.spr_emy1_axe, 'Z');
    check_target_ennemy_turn(m->perso[ENEMY2_AXE].stat_p.mov, m, m->univ.spr_emy2_axe, 'D');
    check_target_ennemy_turn(m->perso[ENEMY3_AXE].stat_p.mov, m, m->univ.spr_emy3_axe, 'E');
    check_target_ennemy_turn(m->perso[ENEMY_MAGE].stat_p.mov, m, m->univ.spr_emy_mage, '*');
}