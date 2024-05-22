/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** init_all_pose.c
*/

#include "../rpg.h"
#include "../include/menu.h"

void check_all_pose3(Global_t *m, char **tab, int word)
{
    if (word >= 7 && word <= 8) {
        if (word == 7)
            check_position(tab, 'W', m->univ.spr_Boss7, m);
        if (word == 8)
            check_position(tab, 'Y', m->univ.spr_Boss8, m);
        check_position(tab, 'E', m->univ.spr_emy3_axe, m);
        check_position(tab, 'K', m->univ.spr_emy3_spear, m);
        check_position(tab, '/', m->univ.spr_emy3_sword, m);
        check_position(tab, '*', m->univ.spr_emy_mage, m);
    }
}

void check_all_pose2(Global_t *m, char **tab, int word)
{
    if (word >= 4 && word <= 6) {
        if (word == 4)
            check_position(tab, 'S', m->univ.spr_Boss4, m);
        if (word == 5)
            check_position(tab, 'T', m->univ.spr_Boss5, m);
        if (word == 6)
            check_position(tab, 'U', m->univ.spr_Boss6, m);
        check_position(tab, 'D', m->univ.spr_emy2_axe, m);
        check_position(tab, 'J', m->univ.spr_emy2_spear, m);
        check_position(tab, 'M', m->univ.spr_emy2_sword, m);
    }
    check_all_pose3(m, tab, word);
}

void check_all_pose(Global_t *m, char **tab, int word)
{
    check_position(tab, '0', m->univ.spr_roy, m);
    check_position(tab, '1', m->univ.spr_infe, m);
    check_position(tab, '2', m->univ.spr_pate, m);
    check_position(tab, '3', m->univ.spr_xmara, m);
    check_position(tab, '4', m->univ.spr_raca, m);
    if (word >= 1 && word <= 3) {
        if (word == 1)
            check_position(tab, 'P', m->univ.spr_Boss1, m);
        if (word == 2)
            check_position(tab, 'Q', m->univ.spr_Boss2, m);
        if (word == 3)
            check_position(tab, 'R', m->univ.spr_Boss3, m);
        check_position(tab, 'Z', m->univ.spr_emy1_axe, m);
        check_position(tab, 'G', m->univ.spr_emy1_spear, m);
        check_position(tab, 'L', m->univ.spr_emy1_sword, m);
    }
    check_all_pose2(m, tab, word);
}
