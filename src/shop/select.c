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

    if (who == 0) {
        if (m->perso[XMARANO].num_weapons_in_inv < 5) {
            memcpy(&m->perso[XMARANO].inv_weapon[m->perso[XMARANO].num_weapons_in_inv], &m->weapons[w], sizeof(Weapons_t));
            m->perso[XMARANO].num_weapons_in_inv++;
            printf("buyed\n");
            m->gold -= m->weapons[w].cost;
        }
        return;
    }
    if (who == 1) {
        if (m->perso[ROY].num_weapons_in_inv < 5) {
            memcpy(&m->perso[ROY].inv_weapon[m->perso[ROY].num_weapons_in_inv], &m->weapons[w], sizeof(Weapons_t));
            m->perso[ROY].num_weapons_in_inv++;
            printf("buyed\n");
            m->gold -= m->weapons[w].cost;
        }
        return;
    }
    if (who == 2) {
        if (m->perso[RACAILLOU].num_weapons_in_inv < 5) {
            memcpy(&m->perso[RACAILLOU].inv_weapon[m->perso[RACAILLOU].num_weapons_in_inv], &m->weapons[w], sizeof(Weapons_t));
            m->perso[RACAILLOU].num_weapons_in_inv++;
            printf("buyed\n");
            m->gold -= m->weapons[w].cost;
        }
        return;
    }
    if (who == 3) {
        if (m->perso[PATECARBO].num_weapons_in_inv < 5) {
            memcpy(&m->perso[PATECARBO].inv_weapon[m->perso[PATECARBO].num_weapons_in_inv], &m->weapons[w], sizeof(Weapons_t));
            m->perso[PATECARBO].num_weapons_in_inv++;
            printf("buyed\n");
            m->gold -= m->weapons[w].cost;
        }
        return;
    }
    if (who == 4) {
        if (m->perso[INFENIUM].num_weapons_in_inv < 5) {
            memcpy(&m->perso[INFENIUM].inv_weapon[m->perso[INFENIUM].num_weapons_in_inv], &m->weapons[w], sizeof(Weapons_t));
            m->perso[INFENIUM].num_weapons_in_inv++;
            printf("buyed\n");
            m->gold -= m->weapons[w].cost;
        }
        return;
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
    } else if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
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
