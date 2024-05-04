/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** select.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"

void import_weapon_inv(Global_t *m, int w)
{
    int who = m->shop.buyer;
    Perso_t *character;
    Weapons_t *weap;

    if (who == 0)
        character = &m->perso[XMARANO];
    if (who == 1)
        character = &m->perso[ROY];
    if (who == 2)
        character = &m->perso[RACAILLOU];
    if (who == 3)
        character = &m->perso[PATECARBO];
    if (who == 4)
        character = &m->perso[INFENIUM];
    weap = character->inv_weapon;
    for (int i = 0; i < 5; i++) {
        if (weap[i].is_empty == true) {
            memcpy(&weap[i], &m->weapons[w], sizeof(Weapons_t));
            m->gold -= m->weapons[w].cost;
            weap[i].is_empty = false;
            return;
        }
    }
}

void select_perso(Global_t *m)
{
    static sfClock *clock = NULL;
    sfTime elapsed;
    float elapsed_seconds;
    static int cursor_position = 0;

    if (!clock)
        clock = sfClock_create();
    elapsed = sfClock_getElapsedTime(clock);
    elapsed_seconds = sfTime_asSeconds(elapsed);
    if (elapsed_seconds < 0.15f)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        if (cursor_position < 4) {
            cursor_position++;
            m->shop.cursor_pose.x += 40;
            sfSprite_setPosition(m->shop.cursor, m->shop.cursor_pose);
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        if (cursor_position > 0) {
            cursor_position--;
            m->shop.cursor_pose.x -= 40;
            sfSprite_setPosition(m->shop.cursor, m->shop.cursor_pose);
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
        m->shop.buyer = cursor_position;
        m->shop.is_select = true;
    }
    sfClock_restart(clock);
    if (m->shop.is_select == false) {
        sfClock_destroy(clock);
        clock = NULL;
    }
}
