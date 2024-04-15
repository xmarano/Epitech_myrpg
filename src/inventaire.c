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

sfSprite *set_weapon(Global_t *m, char *filename, sfVector2f pose, sfVector2f scale)
{
    m->perso.stat_w.sprite = sfSprite_create();
    m->perso.stat_w.texture = sfTexture_createFromFile(filename, NULL);
    sfSprite_setTexture(m->perso.stat_w.sprite, m->perso.stat_w.texture, sfFalse);
    sfSprite_setPosition(m->perso.stat_w.sprite, pose);
    sfSprite_setScale(m->perso.stat_w.sprite, scale);
    sfRenderWindow_drawSprite(m->window, m->perso.stat_w.sprite, NULL);
    sfSprite_destroy(m->perso.stat_w.sprite);
    sfTexture_destroy(m->perso.stat_w.texture);
}

void draw_inventaire(Global_t *m)
{
    sfVector2f pose = {985, 482};
    sfVector2f scale = {1.8, 1.8};

    if (m->perso.is_visible && m->perso.inv.inventory != NULL)
        sfRenderWindow_drawSprite(m->window, m->perso.inv.inventory, NULL);
    if (m->perso.is_visible2 && m->perso.inv.inventory2 != NULL) {
        sfRenderWindow_drawSprite(m->window, m->perso.inv.inventory2, NULL);
        set_weapon(m, "assets/inv/weapons/axe3.png", pose, scale);
        pose.y += 31;
        set_weapon(m, "assets/inv/weapons/spear2.png", pose, scale);
        pose.y += 31;
        set_weapon(m, "assets/inv/weapons/spear3.png", pose, scale);
        pose.y += 31;
        set_weapon(m, "assets/inv/weapons/sword2.png", pose, scale);
        pose.y += 31;
        set_weapon(m, "assets/inv/weapons/sword3.png", pose, scale);
    }
    return;
}

static int what_inv(Global_t *m, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS && !m->perso.is_visible && !m->perso.is_visible2) {
        m->perso.is_visible = true;
        m->perso.is_visible2 = false;
    } else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight && m->perso.is_visible && !m->perso.is_visible2) {
        m->perso.is_visible2 = true;
    } else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft && m->perso.is_visible2) {
        m->perso.is_visible = true;
        m->perso.is_visible2 = false;
    } else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS) {
        m->perso.is_visible = false;
        m->perso.is_visible2 = false;
    }
    sfRenderWindow_setMouseCursorVisible(m->window, sfTrue);
}

sfSprite *set_inv_fond(Global_t *m)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {700, 380};
    sfVector2f scale = {2.5, 2.5};

    m->perso.inv.Inventory = sfTexture_createFromFile("assets/inv/inv_fond.png", NULL);
    sfSprite_setTexture(sprite, m->perso.inv.Inventory, sfFalse);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

sfSprite *set_inv_fond2(Global_t *m)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {950, 380};
    sfVector2f scale = {2.5, 2.5};

    m->perso.inv.Inventory2 = sfTexture_createFromFile("assets/inv/inv_fond2.png", NULL);
    sfSprite_setTexture(sprite, m->perso.inv.Inventory2, sfFalse);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

int inventory(Global_t *m, sfEvent event)
{
    m->perso.inv.inventory = set_inv_fond(m);
    m->perso.inv.inventory2 = set_inv_fond2(m);
    what_inv(m, event);
    return 0;
}
