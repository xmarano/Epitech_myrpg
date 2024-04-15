/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** inventory.c
*/

#include "my.h"
#include "rpg.h"
#include "menu.h"
#include "include/inventory.h"

void draw_inventaire(Global_t *m)
{
    if (m->perso.is_visible && m->perso.inv.inventory != NULL)
        sfRenderWindow_drawSprite(m->window, m->perso.inv.inventory, NULL);
    if (m->perso.is_visible2 && m->perso.inv.inventory2 != NULL) {
        sfRenderWindow_drawSprite(m->window, m->perso.inv.inventory2, NULL);
        sfRenderWindow_drawSprite(m->window, m->perso.stat_w.init.sprite, NULL);
    }
}

void what_inv(Global_t *m, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS && !m->perso.is_visible && !m->perso.is_visible2) {
        m->perso.is_visible = true;
        m->perso.is_visible2 = false;
    } else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight && m->perso.is_visible && !m->perso.is_visible2) {
        m->perso.is_visible = false;
        m->perso.is_visible2 = true;
    } else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft && !m->perso.is_visible && m->perso.is_visible2) {
        m->perso.is_visible = true;
        m->perso.is_visible2 = false;
    } else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS) {
        m->perso.is_visible = false;
        m->perso.is_visible2 = false;
    }
}

sfSprite *set_inv_fond(Global_t *m)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {700, 380};
    sfVector2f scale = {2.3, 2.3};

    m->perso.inv.Inventory = sfTexture_createFromFile("assets/inv/inv_fond.png", NULL);
    sfSprite_setTexture(sprite, m->perso.inv.Inventory, sfFalse);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

sfSprite *set_inv_fond2(Global_t *m)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {800, 380};
    sfVector2f scale = {2.5, 2.5};

    m->perso.inv.Inventory2 = sfTexture_createFromFile("assets/inv/inv_fond2.png", NULL);
    sfSprite_setTexture(sprite, m->perso.inv.Inventory2, sfFalse);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

int inventory(Global_t *m, sfEvent event)
{
    sfVector2f pose = {830, 490};
    sfVector2f scale = {2.2, 2.2};

    m->perso.inv.inventory = set_inv_fond(m);
    m->perso.inv.inventory2 = set_inv_fond2(m);
    m->perso.stat_w.init.sprite = set_weapon(m, "assets/inv/weapons/axe3.png", pose, scale);
    what_inv(m, event);
    return 0;
}
