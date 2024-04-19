/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** inventory.c
*/

#include "my.h"
#include "rpg.h"
#include "menu.h"
#include "include/perso.h"

void set_text_lvl_xd(Global_t *m, int who)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    int level = m->perso[who].stat_p.level;
    int xp = m->perso[who].stat_p.xp;
    char str[20];

    sprintf(str, "%d\t%d", level, xp);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    sfText_setColor(text, sfBlue);
    sfText_setString(text, str);
    sfText_setPosition(text, (sfVector2f){778, 720});
    sfRenderWindow_drawText(m->window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

void set_sprite_mini(Global_t *m, int who)
{
    sfIntRect current_hero_head = {12, 713, 46, 59};
    sfSprite *sprite_perso = sfSprite_create();
    char *filename = m->perso[who].texture_battle;
    sfTexture *texture_perso = sfTexture_createFromFile(filename, NULL);

    sfSprite_setTexture(sprite_perso, texture_perso, sfTrue);
    sfSprite_setTextureRect(sprite_perso, current_hero_head);
    sfSprite_setPosition(sprite_perso, (sfVector2f){913, 715});
    sfSprite_setScale(sprite_perso, (sfVector2f){1.3, 1.3});
    sfRenderWindow_drawSprite(m->window, sprite_perso, NULL);
}

void set_text_health(Global_t *m, int who)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    int current_hp = m->perso[who].stat_p.current_hp;
    int max_hp = m->perso[who].stat_p.max_hp;
    char str[20];

    sprintf(str, "%d\t%d", current_hp, max_hp);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 35);
    sfText_setColor(text, sfRed);
    sfText_setString(text, str);
    sfText_setPosition(text, (sfVector2f){783, 775});
    sfRenderWindow_drawText(m->window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

void set_sprite_head_name(Global_t *m, int who)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    sfIntRect current_hero_head = {0, 0, 96, 80};
    sfSprite *sprite_perso = sfSprite_create();
    char *filename = m->perso[who].texture_dialogue;
    sfTexture *texture_perso = sfTexture_createFromFile(filename, NULL);

    sfSprite_setTexture(sprite_perso, texture_perso, sfTrue);
    sfSprite_setTextureRect(sprite_perso, current_hero_head);
    sfSprite_setPosition(sprite_perso, (sfVector2f){730, 425});
    sfSprite_setScale(sprite_perso, (sfVector2f){2.5, 2.5});
    sfRenderWindow_drawSprite(m->window, sprite_perso, NULL);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    sfText_setColor(text, sfBlack);
    sfText_setString(text, m->perso[who].name_perso);
    sfText_setPosition(text, (sfVector2f){770, 620});
    sfRenderWindow_drawText(m->window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

void draw_inventaire(Global_t *m)
{
    m->perso->current_perso = ROY; // valeur a chager pour swap de perso
    if (m->perso->is_visible && m->perso->inv.inv_sprite.inventory != NULL) {
        m->show_mouse = false;
        sfRenderWindow_drawSprite(m->window, m->perso->inv.inv_sprite.inventory, NULL);
        set_sprite_head_name(m, m->perso->current_perso);
        set_text_lvl_xd(m, m->perso->current_perso);
        set_sprite_mini(m, m->perso->current_perso);
        set_text_health(m, m->perso->current_perso);
        sfRenderWindow_drawRectangleShape(m->window, m->perso->inv.inv_sprite.rect_inv, NULL);
    }
    if (m->perso->is_visible2 && m->perso->inv.inv_sprite.inventory2 != NULL) {
        sfRenderWindow_drawSprite(m->window, m->perso->inv.inv_sprite.inventory2, NULL);
        // draw sprite here
        // set_stat_text(m, PATECARBO);
        sfRenderWindow_drawSprite(m->window, m->perso->inv.inv_sprite.cursor, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->perso->inv.inv_sprite.hooved_weapon, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->perso->inv.inv_sprite.rect_inv, NULL);
    }
    if (!m->perso->is_visible && !m->perso->is_visible2) {
        m->show_mouse = true;
    }
}

static void reset(Global_t *m)
{
    m->perso->inv.inv_sprite.pos_cursor = (sfVector2f){1010, 503};
    m->perso->inv.inv_sprite.pos_hooved = (sfVector2f){1050, 503};
}

static int what_inv(Global_t *m, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyE && !m->perso->is_visible && !m->perso->is_visible2) {
        m->perso->is_visible = true;
        m->perso->is_visible2 = false;
    } else if (sfKeyboard_isKeyPressed(sfKeyRight) && m->perso->is_visible && !m->perso->is_visible2) {
        m->perso->is_visible2 = true;
    } else if (sfKeyboard_isKeyPressed(sfKeyLeft) && m->perso->is_visible2) {
        m->perso->is_visible = true;
        m->perso->is_visible2 = false;
        reset(m);
    } else if (sfKeyboard_isKeyPressed(sfKeyRight) && !m->perso->is_visible && m->perso->is_visible2) {
        m->perso->is_visible2 = false;
        m->perso->is_visible = true;
    } else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyE) {
        m->perso->is_visible = false;
        m->perso->is_visible2 = false;
        reset(m);
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

static sfSprite *set_inv_fond2(Global_t *m)
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
    if ((sfKeyboard_isKeyPressed(sfKeyE) && (m->current == 11)) || sfKeyboard_isKeyPressed(sfKeyLeft) || sfKeyboard_isKeyPressed(sfKeyRight) || sfKeyboard_isKeyPressed(sfKeyDown)) {
        m->perso->inv.inv_sprite.inventory = set_inv_fond(m);
        m->perso->inv.inv_sprite.inventory2 = set_inv_fond2(m);
        m->perso->inv.inv_sprite.cursor = set_cursor(m);
        m->perso->inv.inv_sprite.hooved_weapon = hooved(m, (sfVector2f){1050, 503}, (sfVector2f){16 * 1.8, 16 * 1.8}, 2.1);
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
            sfRectangleShape_setPosition(m->perso->inv.inv_sprite.hooved_weapon, m->perso->inv.inv_sprite.pos_hooved);
        }
    }
    return 0;
}
