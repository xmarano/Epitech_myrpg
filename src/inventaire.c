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

void set_weapon_sprite(Global_t *m, char *filename, sfVector2f pose, sfVector2f scale)
{
    sfSprite_destroy(m->weapons->sprite);
    sfTexture_destroy(m->weapons->texture);
    m->weapons->sprite = sfSprite_create();
    m->weapons->texture = sfTexture_createFromFile(filename, NULL);
    sfSprite_setTexture(m->weapons->sprite, m->weapons->texture, sfFalse);
    sfSprite_setPosition(m->weapons->sprite, pose);
    sfSprite_setScale(m->weapons->sprite, scale);
    sfRenderWindow_drawSprite(m->window, m->weapons->sprite, NULL);
}

void draw_inventaire(Global_t *m)
{
    sfVector2f pose = {1050, 503};
    sfVector2f scale = {1.8, 1.8};

    if (m->perso->is_visible && m->perso->inv.inv_sprite.inventory != NULL) {
        m->show_mouse = false;
        sfRenderWindow_drawSprite(m->window, m->perso->inv.inv_sprite.inventory, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->perso->inv.inv_sprite.rect_inv, NULL);
    }
    if (m->perso->is_visible2 && m->perso->inv.inv_sprite.inventory2 != NULL) {
        sfRenderWindow_drawSprite(m->window, m->perso->inv.inv_sprite.inventory2, NULL);
        // draw sprite here
        sfRenderWindow_drawSprite(m->window, m->perso->inv.inv_sprite.cursor, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->weapons->rect_weapon, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->perso->inv.inv_sprite.rect_inv, NULL);
    }
    if (!m->perso->is_visible && !m->perso->is_visible2) {
        m->show_mouse = true;
    }
}

static int what_inv(Global_t *m, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS && !m->perso->is_visible && !m->perso->is_visible2) {
        m->perso->is_visible = true;
        m->perso->is_visible2 = false;
    } else if (sfKeyboard_isKeyPressed(sfKeyRight) && m->perso->is_visible && !m->perso->is_visible2) {
        m->perso->is_visible2 = true;
    } else if (sfKeyboard_isKeyPressed(sfKeyLeft) && m->perso->is_visible2) {
        m->perso->is_visible = true;
        m->perso->is_visible2 = false;
        m->perso->inv.inv_sprite.pos_cursor = (sfVector2f){1010, 503};
        m->perso->inv.inv_sprite.pos_hooved = (sfVector2f){1050, 503};
    } else if (sfKeyboard_isKeyPressed(sfKeyRight) && !m->perso->is_visible && m->perso->is_visible2) {
        m->perso->is_visible2 = false;
        m->perso->is_visible = true;
    } else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyS) {
        m->perso->is_visible = false;
        m->perso->is_visible2 = false;
        m->perso->inv.inv_sprite.pos_cursor = (sfVector2f){1010, 503};
        m->perso->inv.inv_sprite.pos_hooved = (sfVector2f){1050, 503};
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

    m->perso->inv.inv_sprite.Cursor = sfTexture_createFromFile("assets/inv/cursor.png", NULL);
    sfSprite_setTexture(sprite, m->perso->inv.inv_sprite.Cursor, sfFalse);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

sfSprite *set_inv_fond(Global_t *m)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {700, 380};
    sfVector2f scale = {2.9, 2.9};

    m->perso->inv.inv_sprite.Inventory = sfTexture_createFromFile("assets/inv/inv_fond.png", NULL);
    sfSprite_setTexture(sprite, m->perso->inv.inv_sprite.Inventory, sfFalse);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

sfSprite *set_inv_fond2(Global_t *m)
{
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = {992, 380};
    sfVector2f scale = {2.9, 2.9};

    m->perso->inv.inv_sprite.Inventory2 = sfTexture_createFromFile("assets/inv/inv_fond2.png", NULL);
    sfSprite_setTexture(sprite, m->perso->inv.inv_sprite.Inventory2, sfFalse);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

int inventory(Global_t *m, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(sfKeyS) || sfKeyboard_isKeyPressed(sfKeyLeft) || sfKeyboard_isKeyPressed(sfKeyRight) || sfKeyboard_isKeyPressed(sfKeyDown)) {
        m->perso->inv.inv_sprite.inventory = set_inv_fond(m);
        m->perso->inv.inv_sprite.inventory2 = set_inv_fond2(m);
        m->perso->inv.inv_sprite.cursor = set_cursor(m);
        m->weapons->rect_weapon = hooved(m, (sfVector2f){1050, 503}, (sfVector2f){16 * 1.8, 16 * 1.8}, 2.1);
        m->perso->inv.inv_sprite.rect_inv = hooved(m, (sfVector2f){700, 380}, (sfVector2f){683, 450}, 6.0);
        what_inv(m, event);
        if (sfKeyboard_isKeyPressed(sfKeyDown)) {
            if (m->perso->inv.inv_sprite.pos_hooved.y < 639) {
                m->perso->inv.inv_sprite.pos_cursor.y += 34;
                m->perso->inv.inv_sprite.pos_hooved.y += 34;
            } else {
                m->perso->inv.inv_sprite.pos_cursor.y = 503;
                m->perso->inv.inv_sprite.pos_hooved.y = 503;
            }
            sfSprite_setPosition(m->perso->inv.inv_sprite.cursor, m->perso->inv.inv_sprite.pos_cursor);
            sfRectangleShape_setPosition(m->weapons->rect_weapon, m->perso->inv.inv_sprite.pos_hooved);
        }
    }
    return 0;
}
