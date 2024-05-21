/*
** EPITECH PROJECT, 2023
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

void print_mini_barre(Global_t *m, fight_t *f)
{
    init_mini_barre(m, f, m->univ.spr_roy, ROY);
    init_mini_barre(m, f, m->univ.spr_xmara, XMARANO);
    // autre
}
