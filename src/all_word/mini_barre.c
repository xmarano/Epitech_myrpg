/*
** EP PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** mini_barre.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"
#include "../include/fight.h"

void init_mini_barre(Global_t *m, fight_t *f, sfSprite *sprite, int who)
{
    sfVector2f pose;
    pose = sfSprite_getPosition(sprite);
    pose.x += 6;
    pose.y -= 7;
    f->rect_empty_bar = (sfIntRect){1, 26, m->perso[who].stat_p.max_hp * 2 + 1, 7};
    sfSprite_setTextureRect(f->empty_bar_sprite, f->rect_empty_bar);
    sfSprite_setPosition(f->empty_bar_sprite, pose);
    sfSprite_setScale(f->empty_bar_sprite, (sfVector2f){0.7, 0.7});
    sfRenderWindow_drawSprite(m->window, f->empty_bar_sprite, NULL);
    f->rect_hero_bar = (sfIntRect){1, 50, m->perso[who].stat_p.current_hp * 2 + 1, 7};
    sfSprite_setTextureRect(f->hero_lifebar_sprite, f->rect_hero_bar);
    sfSprite_setPosition(f->hero_lifebar_sprite, pose);
    sfSprite_setScale(f->hero_lifebar_sprite, (sfVector2f){0.7, 0.7});
    sfRenderWindow_drawSprite(m->window, f->hero_lifebar_sprite, NULL);
}

void print_boss_barre3(Global_t *m, fight_t *f, int word)
{
    if (word >= 7 && word <= 8) {
        if (word == 7)
            init_mini_barre(m, f, m->univ.spr_Boss7, BOSS7);
        if (word == 8)
            init_mini_barre(m, f, m->univ.spr_Boss8, BOSS8);
        init_mini_barre(m, f, m->univ.spr_emy3_axe, ENEMY3_AXE);
        init_mini_barre(m, f, m->univ.spr_emy3_spear, ENEMY3_SPEAR);
        init_mini_barre(m, f, m->univ.spr_emy3_sword, ENEMY3_SWORD);
        init_mini_barre(m, f, m->univ.spr_emy_mage, ENEMY_MAGE);
    }
}

void print_boss_barre2(Global_t *m, fight_t *f, int word)
{
    if (word >= 4 && word <= 6) {
        if (word == 4)
            init_mini_barre(m, f, m->univ.spr_Boss4, BOSS4);
        if (word == 5)
            init_mini_barre(m, f, m->univ.spr_Boss5, BOSS5);
        if (word == 6)
            init_mini_barre(m, f, m->univ.spr_Boss6, BOSS6);
        init_mini_barre(m, f, m->univ.spr_emy2_axe, ENEMY2_AXE);
        init_mini_barre(m, f, m->univ.spr_emy2_spear, ENEMY2_SPEAR);
        init_mini_barre(m, f, m->univ.spr_emy2_sword, ENEMY2_SWORD);
    }
    print_boss_barre3(m, f, word);
}

void print_mini_barre(Global_t *m, fight_t *f, int word)
{
    init_mini_barre(m, f, m->univ.spr_roy, ROY);
    init_mini_barre(m, f, m->univ.spr_xmara, XMARANO);
    init_mini_barre(m, f, m->univ.spr_pate, PATECARBO);
    init_mini_barre(m, f, m->univ.spr_infe, INFENIUM);
    init_mini_barre(m, f, m->univ.spr_raca, RACAILLOU);
    if (word >= 1 && word <= 3) {
        if (word == 1)
            init_mini_barre(m, f, m->univ.spr_Boss1, BOSS1);
        if (word == 2)
            init_mini_barre(m, f, m->univ.spr_Boss2, BOSS2);
        if (word == 3)
            init_mini_barre(m, f, m->univ.spr_Boss3, BOSS3);
        init_mini_barre(m, f, m->univ.spr_emy1_axe, ENEMY1_AXE);
        init_mini_barre(m, f, m->univ.spr_emy1_spear, ENEMY1_SPEAR);
        init_mini_barre(m, f, m->univ.spr_emy1_sword, ENEMY1_SWORD);
    }
    print_boss_barre2(m, f, word);
}
