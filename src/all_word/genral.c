/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** get_old_current.c
*/

#include "../rpg.h"
#include "../include/menu.h"

static void draw(Global_t *m)
{
    //sfRenderWindow_drawText(m->window, m->univ.boss_name, NULL);
    sfRenderWindow_drawRectangleShape(m->window, m->univ.barre_fond, NULL);
    sfRenderWindow_drawRectangleShape(m->window, m->univ.barre_de_vie, NULL);
    sfRenderWindow_drawSprite(m->window, m->univ.image_barre, NULL);
}

void print_boss_barre(Global_t *m, int who, sfView *view)
{
    float pourcentage_vie = (float)m->perso[who].stat_p.current_hp
    / (float)m->perso[who].stat_p.max_hp;
    sfVector2f veiw_size = sfView_getSize(view);
    sfVector2f barres_position;

    barres_position.x = (veiw_size.x - 400) / 2;
    barres_position.y = 36;
    sfRectangleShape_setPosition(m->univ.barre_de_vie, barres_position);
    sfRectangleShape_setPosition(m->univ.barre_fond, barres_position);
    barres_position.x = (veiw_size.x - 505) / 2;
    barres_position.y = 6;
    sfSprite_setPosition(m->univ.image_barre, barres_position);
    sfRectangleShape_setSize(m->univ.barre_de_vie,
    (sfVector2f){400 * pourcentage_vie, 30});
    draw(m);
}

static void set_pose_perso(char **map, char ref, sfSprite *sprite, int i)
{
    for (int y = 0; map[i][y] != '\0'; y++) {
        if (map[i][y] == ref) {
            sfSprite_setPosition(sprite,
            (sfVector2f){(y - 1) * 40, (i - 1) * 40});
        }
    }
}

void check_position(char **map, char ref, sfSprite *sprite, Global_t *m)
{
    for (int i = 0; map[i] != NULL; i++) {
        set_pose_perso(map, ref, sprite, i);
    }
    sfRenderWindow_drawSprite(m->window, sprite, NULL);
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
