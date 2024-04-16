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

void set_weapon(Global_t *m, char *filename, sfVector2f pose, sfVector2f scale)
{
    sfSprite_destroy(m->perso.stat_w.sprite);
    sfTexture_destroy(m->perso.stat_w.texture);
    m->perso.stat_w.sprite = sfSprite_create();
    m->perso.stat_w.texture = sfTexture_createFromFile(filename, NULL);
    sfSprite_setTexture(m->perso.stat_w.sprite, m->perso.stat_w.texture, sfFalse);
    sfSprite_setPosition(m->perso.stat_w.sprite, pose);
    sfSprite_setScale(m->perso.stat_w.sprite, scale);
    sfRenderWindow_drawSprite(m->window, m->perso.stat_w.sprite, NULL);
}

void draw_inventaire(Global_t *m)
{
    sfVector2f pose = {985, 482};
    sfVector2f scale = {1.8, 1.8};

    if (m->perso.is_visible && m->perso.inv.inventory != NULL) {
        m->show_mouse = false;
        sfRenderWindow_drawSprite(m->window, m->perso.inv.inventory, NULL);
    }
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
        sfRenderWindow_drawSprite(m->window, m->perso.inv.cursor, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->perso.stat_w.rect, NULL);
    }
    if (!m->perso.is_visible && !m->perso.is_visible2) {
        m->show_mouse = true;
    }
}

static int what_inv(Global_t *m, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS && !m->perso.is_visible && !m->perso.is_visible2) {
        m->perso.is_visible = true;
        m->perso.is_visible2 = false;
    } else if (sfKeyboard_isKeyPressed(sfKeyRight) && m->perso.is_visible && !m->perso.is_visible2) {
        m->perso.is_visible2 = true;
    } else if (sfKeyboard_isKeyPressed(sfKeyLeft) && m->perso.is_visible2) {
        m->perso.is_visible = true;
        m->perso.is_visible2 = false;
    } else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS) {
        m->perso.is_visible = false;
        m->perso.is_visible2 = false;
        m->perso.inv.cursor_up = 0;
        m->perso.inv.cursor_down = 0;
    }
    return 0;
}

sfRectangleShape *hooved(Global_t *m)
{
    sfVector2f popo = {985, 482};
    sfVector2f size = {16 * 1.8, 16 * 1.8};
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setPosition(rect, popo);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setOutlineColor(rect, sfBlack);
    sfRectangleShape_setOutlineThickness(rect, 2.1);
    return rect;
}

sfSprite *set_cursor(Global_t *m)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {0.3, 0.3};
    sfVector2f pos = {958, 480};

    m->perso.inv.Cursor = sfTexture_createFromFile("assets/inv/cursor.png", NULL);
    sfSprite_setTexture(sprite, m->perso.inv.Cursor, sfFalse);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    return sprite;
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

void move_cursor_up(Global_t *m)
{
    m->perso.inv.pos_cursor.x = 958;
    m->perso.inv.pos_cursor.y = 480 - m->perso.inv.cursor_up;
    m->perso.inv.pos_hooved.x = 985;
    m->perso.inv.pos_hooved.y = 480 - m->perso.inv.cursor_up;
    sfSprite_setPosition(m->perso.inv.cursor, m->perso.inv.pos_cursor);
    sfRectangleShape_setPosition(m->perso.stat_w.rect, m->perso.inv.pos_hooved);
}

void move_cursor_down(Global_t *m)
{
    m->perso.inv.pos_cursor.x = 958;
    m->perso.inv.pos_cursor.y = 480 + m->perso.inv.cursor_down;
    m->perso.inv.pos_hooved.x = 985;
    m->perso.inv.pos_hooved.y = 480 + m->perso.inv.cursor_down;
    sfSprite_setPosition(m->perso.inv.cursor, m->perso.inv.pos_cursor);
    sfRectangleShape_setPosition(m->perso.stat_w.rect, m->perso.inv.pos_hooved);
}

int inventory(Global_t *m, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyS) || sfKeyboard_isKeyPressed(sfKeyLeft) || sfKeyboard_isKeyPressed(sfKeyRight) || sfKeyboard_isKeyPressed(sfKeyDown) || sfKeyboard_isKeyPressed(sfKeyUp)) {
        m->perso.inv.inventory = set_inv_fond(m);
        m->perso.inv.inventory2 = set_inv_fond2(m);
        m->perso.inv.cursor = set_cursor(m);
        m->perso.stat_w.rect = hooved(m);
        what_inv(m, event);
        if (sfKeyboard_isKeyPressed(sfKeyDown)) {
            m->perso.inv.cursor_down += 34;
            move_cursor_down(m);
        }
    }
    return 0;
}
