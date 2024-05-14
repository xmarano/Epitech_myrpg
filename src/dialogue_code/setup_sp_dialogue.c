/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** setup_sp_dialogue.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left < max_value - offset) {
        if (rect->top == 96) {
            rect->top = 80;
            rect->left += 32;
        } else if (rect->top == 80) {
            rect->top += 16;
        }
    } else {
        rect->left = 0;
        rect->top = 80;
    }
}

void draw_pouill_dia(Global_t *m, int word, sfVector2f pose)
{
    sfSprite_setScale(m->hub.dia_pouill, (sfVector2f){2.3, 2.3});
    sfSprite_setPosition(m->hub.dia_pouill, pose);
    sfRenderWindow_drawSprite(m->window, m->hub.dia_pouill, NULL);
    pose.x -= 50;
    pose.y += 150;
    sfSprite_setPosition(m->hub.cadre, pose);
    sfRenderWindow_drawSprite(m->window, m->hub.cadre, NULL);
}

// void draw_pouill_dia(Global_t *m, int word, hub_t *hub, sfVector2f pos)
// {
//     sfVector2f pose;

//     pose = sfSprite_getPosition(hub->sprite_perso);
//     pose.x -= 300;
//     pose.y -= 50;
//     printf("%f ,%f\n", pose.x, pose.y);
//     sfSprite_setScale(m->hub.dia_pouill, (sfVector2f){2.3, 2.3});
//     sfSprite_setPosition(m->hub.dia_pouill, pose);
//     sfRenderWindow_drawSprite(m->window, m->hub.dia_pouill, NULL);
//     pose.x -= 50;
//     pose.y += 150;
//     sfSprite_setPosition(m->hub.cadre, pose);
//     sfRenderWindow_drawSprite(m->window, m->hub.cadre, NULL);
//}

void destroy_dialoque(Global_t *m)
{
    sfSprite_destroy(m->hub.dia_pouill);
    sfTexture_destroy(m->hub.Dia_pouill);
    sfSprite_destroy(m->hub.cadre);
    sfTexture_destroy(m->hub.Cadre);
}

void init_pouill_dialog(Global_t *m)
{
    //m->hub.pouill_clocke = sfClock_create();
    m->hub.dia_pouill = sfSprite_create();
    m->hub.Dia_pouill = sfTexture_createFromFile("assets/perso/dialogue/npc/pouilleux_dialogue.png", NULL);
    sfSprite_setTexture(m->hub.dia_pouill, m->hub.Dia_pouill, sfFalse);
}
