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

void set_new_position(Global_t *m, sfSprite *spr, Perso_t *perso)
{
    sfVector2f pos_curs = sfSprite_getPosition(m->univ.map_cursor_sprite);
    sfVector2f pos_spr = sfSprite_getPosition(spr);

    if (m->univ.is_case_visible == 1 && sfKeyboard_isKeyPressed(sfKeySpace) && check_cursor_on_sprite(m, spr) == 0 && is_movement_ok(pos_spr, pos_curs, perso->stat_p.mov, m) == true) {
        m->zone1.tab_map[(int)pos_spr.y / 40 + 1][(int)pos_spr.x / 40 + 1] = ' ';
        m->zone1.tab_map[(int)pos_curs.y / 40 + 1][(int)pos_curs.x / 40 + 1] = '0';
        sfSprite_setPosition(spr, pos_curs);
        m->univ.is_case_visible = 0;
    }
}

void all_perso_movement(Global_t *m)
{
    if (m->univ.is_case_visible == 1)
        draw_possible_movement(m, m->univ.spr_roy, &m->perso[ROY]);
    if (check_cursor_on_sprite(m, m->univ.spr_roy) == 1 || check_cursor_on_sprite(m, m->univ.spr_raca) == 1 || check_cursor_on_sprite(m, m->univ.spr_xmara) == 1 || check_cursor_on_sprite(m, m->univ.spr_infe) == 1 || check_cursor_on_sprite(m, m->univ.spr_pate) == 1) {
        if (sfKeyboard_isKeyPressed(sfKeySpace) && m->univ.is_case_visible == 1)
            m->univ.is_case_visible = 0;
        else if (sfKeyboard_isKeyPressed(sfKeySpace) && m->univ.is_case_visible == 0)
            m->univ.is_case_visible = 1;
    }
    set_new_position(m, m->univ.spr_roy, &m->perso[ROY]);
    set_new_position(m, m->univ.spr_xmara, &m->perso[XMARANO]);
    set_new_position(m, m->univ.spr_raca, &m->perso[RACAILLOU]);
    set_new_position(m, m->univ.spr_pate, &m->perso[PATECARBO]);
    set_new_position(m, m->univ.spr_infe, &m->perso[INFENIUM]);
}

void draw_monde1(Global_t *m, fight_t *f)
{
    if (m->current == 1) {
        sfRenderWindow_setView(m->window, m->zone1.view_w1);
        sfRenderWindow_drawSprite(m->window, m->zone1.w1_map, NULL);
        check_all_pose(m, m->zone1.tab_map, 1);
        move_game_cursor(m);
        all_perso_movement(m);
        set_new_position(m, m->univ.spr_roy, &m->perso[ROY]);
        print_boss_barre(m, BOSS1, m->zone1.view_w1);
        print_mini_barre(m, f);
        return_and_old_current(m, 1);
    }
}
