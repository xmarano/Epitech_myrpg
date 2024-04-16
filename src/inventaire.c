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
    sfVector2f pose = {1050, 503};
    sfVector2f scale = {1.8, 1.8};

    if (m->perso.is_visible && m->perso.inv.inventory != NULL) {
        m->show_mouse = false;
        sfRenderWindow_drawSprite(m->window, m->perso.inv.inventory, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->perso.inv.rect_inv, NULL);
    }
    if (m->perso.is_visible2 && m->perso.inv.inventory2 != NULL) {
        sfRenderWindow_drawSprite(m->window, m->perso.inv.inventory2, NULL);
        set_weapon(m, "assets/inv/weapons/axe3.png", pose, scale);
        pose.y += 34;
        set_weapon(m, "assets/inv/weapons/spear2.png", pose, scale);
        pose.y += 34;
        set_weapon(m, "assets/inv/weapons/spear3.png", pose, scale);
        pose.y += 34;
        set_weapon(m, "assets/inv/weapons/sword2.png", pose, scale);
        pose.y += 34;
        set_weapon(m, "assets/inv/weapons/sword3.png", pose, scale);
        sfRenderWindow_drawSprite(m->window, m->perso.inv.cursor, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->perso.stat_w.rect_weapon, NULL);
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
        m->perso.inv.cursor_dpl = 0;
        m->perso.inv.pos_cursor = (sfVector2f){1010, 503};
        m->perso.inv.pos_hooved = (sfVector2f){1050, 503};
    }
    return 0;
}

sfRectangleShape *hooved(Global_t *m, sfVector2f popo, sfVector2f size, float f)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setPosition(rect, popo);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setOutlineColor(rect, sfBlack);
    sfRectangleShape_setOutlineThickness(rect, f);
    return rect;
}

sfSprite *set_cursor(Global_t *m)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {0.3, 0.3};
    sfVector2f pos = {1010, 503};

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
    sfVector2f scale = {2.9, 2.9};

    m->perso.inv.Inventory = sfTexture_createFromFile("assets/inv/inv_fond.png", NULL);
    sfSprite_setTexture(sprite, m->perso.inv.Inventory, sfFalse);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

sfSprite *set_inv_fond2(Global_t *m)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {995, 380};
    sfVector2f scale = {2.9, 2.9};

    m->perso.inv.Inventory2 = sfTexture_createFromFile("assets/inv/inv_fond2.png", NULL);
    sfSprite_setTexture(sprite, m->perso.inv.Inventory2, sfFalse);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

void move_cursor_up(Global_t *m)
{
    if (m->perso.inv.pos_hooved.y <= 367) {
        m->perso.inv.pos_hooved.y = 367;
        m->perso.inv.pos_cursor.y = 367;
        return;
    }
    m->perso.inv.pos_cursor.x = 1010;
    m->perso.inv.pos_cursor.y = 503 - m->perso.inv.cursor_dpl;
    m->perso.inv.pos_hooved.x = 1050;
    m->perso.inv.pos_hooved.y = 503 - m->perso.inv.cursor_dpl;
    sfSprite_setPosition(m->perso.inv.cursor, m->perso.inv.pos_cursor);
    sfRectangleShape_setPosition(m->perso.stat_w.rect_weapon, m->perso.inv.pos_hooved);
}

void move_cursor_down(Global_t *m)
{
    int max = 503 + (34 * 4);

    if (m->perso.inv.pos_hooved.y >= 639) {
        m->perso.inv.pos_hooved.y = 639;
        m->perso.inv.pos_cursor.y = 639;
        return;
    }
    m->perso.inv.pos_cursor.x = 1010;
    m->perso.inv.pos_cursor.y = 503 + m->perso.inv.cursor_dpl;
    m->perso.inv.pos_hooved.x = 1050;
    m->perso.inv.pos_hooved.y = 503 + m->perso.inv.cursor_dpl;
    sfSprite_setPosition(m->perso.inv.cursor, m->perso.inv.pos_cursor);
    sfRectangleShape_setPosition(m->perso.stat_w.rect_weapon, m->perso.inv.pos_hooved);
}

int inventory(Global_t *m, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyS) || sfKeyboard_isKeyPressed(sfKeyLeft) || sfKeyboard_isKeyPressed(sfKeyRight) || sfKeyboard_isKeyPressed(sfKeyDown) || sfKeyboard_isKeyPressed(sfKeyUp)) {
        m->perso.inv.inventory = set_inv_fond(m);
        m->perso.inv.inventory2 = set_inv_fond2(m);
        m->perso.inv.cursor = set_cursor(m);
        m->perso.stat_w.rect_weapon = hooved(m, (sfVector2f){1050, 503}, (sfVector2f){16 * 1.8, 16 * 1.8}, 2.1);
        m->perso.inv.rect_inv = hooved(m, (sfVector2f){700, 380}, (sfVector2f){700, 453}, 6.0);
        what_inv(m, event);
        if (sfKeyboard_isKeyPressed(sfKeyDown)) {
            m->perso.inv.cursor_dpl += 34;
            move_cursor_down(m);
            printf("pose cursor = (%f;%f)\n", m->perso.inv.pos_cursor.x, m->perso.inv.pos_cursor.y);
        }
        if (sfKeyboard_isKeyPressed(sfKeyUp)) {
            m->perso.inv.cursor_dpl -= 34;
            move_cursor_up(m);
        }
    }
    return 0;
}
