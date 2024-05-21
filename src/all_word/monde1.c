/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** monde1.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"
#include <ctype.h>

/*void init_placements(Global_t *m)
{
    for (int z = 0; &m->perso[z] != NULL; z++) {
        for (int i = 1; m->zone1.tab_map[i] != NULL; i++) {
            for (int y = 1; m->zone1.tab_map[i][y] != NULL; y++)
        }
    }
}*/

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

    if (perso->case_visble == 1 && sfKeyboard_isKeyPressed(sfKeySpace) && check_cursor_on_sprite(m, spr) == 0 && is_movement_ok(pos_spr, pos_curs, perso->stat_p.mov, m) == true) {
        map[(int)pos_spr.y / 40 + 1][(int)pos_spr.x / 40 + 1] = ' ';
        if (isdigit(map[(int)pos_curs.y / 40 + 1][(int)pos_curs.x / 40 + 1]) == 0) {
        if (strcmp(perso->name_perso, "ROY") == 0)
            map[(int)pos_curs.y / 40][(int)pos_curs.x / 40 + 1] = '0';
        if (strcmp(perso->name_perso, "Infenium") == 0)
            map[(int)pos_curs.y / 40][(int)pos_curs.x / 40 + 1] = '1';
        if (strcmp(perso->name_perso, "Racaillou") == 0)
            map[(int)pos_curs.y / 40][(int)pos_curs.x / 40 + 1] = '4';
        if (strcmp(perso->name_perso, "PateCarbo") == 0)
            map[(int)pos_curs.y / 40][(int)pos_curs.x / 40 + 1] = '2';
        if (strcmp(perso->name_perso, "Xmarano") == 0)
            map[(int)pos_curs.y / 40][(int)pos_curs.x / 40 + 1] = '3';
        }
        m->univ.is_case_visible = 0;
        draw_player_interface(m);
    }
    for (int i = 0; map[i] != NULL; i++) {
        printf("%s\n", map[i]);
    }
}

void draw_visible_cases(Global_t *m, sfSprite *spr, Perso_t *perso)
{
    sfTime time = sfClock_getElapsedTime(m->univ.clock_select_perso);
    float seconds = sfTime_asMilliseconds(time) / 1000.0;

    if (perso->case_visble == 1)
        draw_possible_movement(m, spr, perso);
    if (seconds > 0.05) {
        if (check_cursor_on_sprite(m, spr) == 1) {
            if (sfKeyboard_isKeyPressed(sfKeySpace) && perso->case_visble == 1) {
                perso->case_visble = 0;
                sfClock_restart(m->univ.clock_select_perso);
            } else if (sfKeyboard_isKeyPressed(sfKeySpace) && perso->case_visble == 0) {
                perso->case_visble = 1;
                sfClock_restart(m->univ.clock_select_perso);
            }
        }
    }
}

void all_perso_movement(Global_t *m)
{
    draw_visible_cases(m, m->univ.spr_roy, &m->perso[ROY]);
    draw_visible_cases(m, m->univ.spr_xmara, &m->perso[XMARANO]);
    draw_visible_cases(m, m->univ.spr_raca, &m->perso[RACAILLOU]);
    draw_visible_cases(m, m->univ.spr_pate, &m->perso[PATECARBO]);
    draw_visible_cases(m, m->univ.spr_infe, &m->perso[INFENIUM]);
    set_new_position(m, m->univ.spr_roy, &m->perso[ROY], m->zone1.tab_map);
    set_new_position(m, m->univ.spr_xmara, &m->perso[XMARANO], m->zone1.tab_map);
    set_new_position(m, m->univ.spr_raca, &m->perso[RACAILLOU], m->zone1.tab_map);
    set_new_position(m, m->univ.spr_pate, &m->perso[PATECARBO], m->zone1.tab_map);
    set_new_position(m, m->univ.spr_infe, &m->perso[INFENIUM], m->zone1.tab_map);
}

void draw_monde1(Global_t *m, fight_t *f)
{
    if (m->current == 1) {
        sfRenderWindow_setView(m->window, m->zone1.view_w1);
        sfRenderWindow_drawSprite(m->window, m->zone1.w1_map, NULL);
        check_all_pose(m, m->zone1.tab_map, 1);
        move_game_cursor(m);
        all_perso_movement(m);
        print_boss_barre(m, BOSS1, m->zone1.view_w1);
        print_mini_barre(m, f);
        return_and_old_current(m, 1);
    }
}
