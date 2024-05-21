/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** player_interface.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"

void dest_p_interface(Global_t *m)
{
    //next
}

void init_player_interface(Global_t *m)
{
    m->univ.interface.fond_interf = sfSprite_create();
    m->univ.interface.Fond_interf = sfTexture_createFromFile("assets/fight/fond_interface.png", NULL);
    sfSprite_setTexture(m->univ.interface.fond_interf, m->univ.interface.Fond_interf, sfFalse);
}

void draw_player_interface(Global_t *m)
{
    sfVector2f pose_sp;

    if (m->univ.interface.select_inteface) {
        pose_sp = sfSprite_getPosition(m->univ.spr_roy);
        pose_sp.x += 50;
        pose_sp.y -= 90;
        sfSprite_setPosition(m->univ.interface.fond_interf, pose_sp);
        sfRenderWindow_drawSprite(m->window, m->univ.interface.fond_interf, NULL);
    }
}
