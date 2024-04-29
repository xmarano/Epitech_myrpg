/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** shop.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"

static sfSprite *init_spritee(Global_t *m, char *filename, sfVector2f pos, sfVector2f size)
{
    sfTexture *texture = sfTexture_createFromFile(filename, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite ,texture, sfTrue);
    sfSprite_setScale(sprite, size);
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

static sfSprite *init_spr(Global_t *m, char *filename, sfVector2f pos, int w)
{
    m->weapons[w].texture = sfTexture_createFromFile(filename, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, m->weapons[w].texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){1.3, 1.3});
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

static sfText *init_gold(Global_t *m, sfVector2f pos)
{
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    sfText *text = sfText_create();
    char str[30];

    sfText_setFont(text, font);
    sfText_setColor(text, sfRed);
    sfText_setCharacterSize(text, 18);
    sfText_setPosition(text, pos);
    return text;
}

void destroy_shop(Global_t *m)
{
    sfSprite_destroy(m->shop.all_head);
    //sfSprite_destroy(m->shop.cursor);
    sfSprite_destroy(m->shop.shop);
    sfTexture_destroy(m->shop.Shop);
    for (int i = 5; i <= 20; ++i) {
        sfSprite_destroy(m->weapons[i].sprite);
        sfTexture_destroy(m->weapons[i].texture);
    }
    sfSprite_destroy(m->weapons[POTION].sprite);
    sfTexture_destroy(m->weapons[POTION].texture);
    sfRectangleShape_destroy(m->shop.hooved);
    sfSprite_destroy(m->shop.coin);
    sfTexture_destroy(m->shop.Coin);
    sfSprite_destroy(m->shop.lock);
}

static void init_shop_part2(Global_t *m, sfVector2f pose)
{
    pose.y = 304;
    pose.x = 419;
    m->weapons[10].sprite = init_spr(m, m->weapons[10].link_texture, pose, 10);
    pose.x += 30;
    m->weapons[16].sprite = init_spr(m, m->weapons[16].link_texture, pose, 16);
    pose.x += 30;
    m->weapons[13].sprite = init_spr(m, m->weapons[13].link_texture, pose, 13);
    pose.x += 30;
    m->weapons[7].sprite = init_spr(m, m->weapons[7].link_texture, pose, 7);
    pose.y = 334;
    pose.x = 420;
    m->weapons[18].sprite = init_spr(m, m->weapons[18].link_texture, pose, 18);
    pose.x += 30;
    m->weapons[17].sprite = init_spr(m, m->weapons[17].link_texture, pose, 17);
    pose.x += 30;
    m->weapons[19].sprite = init_spr(m, m->weapons[19].link_texture, pose, 19);
    pose.x += 30;
    m->weapons[29].sprite = init_spr(m, m->weapons[29].link_texture, pose, 29);
    m->shop.hooved = sfRectangleShape_create();
    sfRectangleShape_setSize(m->shop.hooved, (sfVector2f){19, 19});
    sfRectangleShape_setPosition(m->shop.hooved, (sfVector2f){422, 247});
    sfRectangleShape_setFillColor(m->shop.hooved, sfTransparent);
    sfRectangleShape_setOutlineThickness(m->shop.hooved, 2);
    sfRectangleShape_setOutlineColor(m->shop.hooved, sfBlack);
    m->shop.is_select = -1;
}

void init_shop(Global_t *m)
{
    sfVector2f pose = {180, 90};
    sfVector2f size = {0.5, 0.5};

    m->shop.cursor_pose.x = 340;
    m->shop.cursor_pose.y = 190;
    m->shop.shop = init_spritee(m, "assets/shop/shop.png", pose, size);
    m->shop.coin = init_spritee(m, "assets/shop/coin.png", pose, size);
    m->shop.all_head = init_spritee(m, "assets/shop/all_perso.png", (sfVector2f){320, 150}, (sfVector2f){0.6, 0.6});
    m->shop.cursor = init_spritee(m, "assets/shop/cursor.png", m->shop.cursor_pose, (sfVector2f){0.2, 0.2});
    m->shop.fond = init_spritee(m, "assets/shop/shop_fond.png", (sfVector2f){0, 0}, (sfVector2f){1, 1});
    m->shop.lock = init_spritee(m, "assets/shop/lock.png", (sfVector2f){-300, -300}, (sfVector2f){0.5, 0.5});
    m->shop.gold = init_gold(m, (sfVector2f){578, 193});
    size.x = size.y = 1.3;
    pose.x = 420;
    pose.y = 245;
    m->weapons[8].sprite = init_spr(m, m->weapons[8].link_texture, pose, 8);
    pose.x += 30;
    pose.y -= 1;
    m->weapons[14].sprite = init_spr(m, m->weapons[14].link_texture, pose, 14);
    pose.x += 30;
    m->weapons[11].sprite = init_spr(m, m->weapons[11].link_texture, pose, 11);
    pose.x += 30;
    m->weapons[5].sprite = init_spr(m, m->weapons[5].link_texture, pose, 5);
    pose.y = 274;
    pose.x = 419;
    m->weapons[9].sprite = init_spr(m, m->weapons[9].link_texture, pose, 9);
    pose.x += 30;
    m->weapons[15].sprite = init_spr(m, m->weapons[15].link_texture, pose, 15);
    pose.x += 30;
    m->weapons[12].sprite = init_spr(m, m->weapons[12].link_texture, pose, 12);
    pose.x += 30;
    m->weapons[6].sprite = init_spr(m, m->weapons[6].link_texture, pose, 6);
    init_shop_part2(m, pose);
    m->shop.is_select = false;
    m->shop.is_lock = false;
}

void draw_shop(Global_t *m)
{
    if (m->current == 9) {
        sfRenderWindow_drawSprite(m->window, m->shop.fond, NULL);
        sfRenderWindow_drawSprite(m->window, m->shop.shop, NULL);
        sfRenderWindow_drawSprite(m->window, m->weapons[COMMON_SWORD].sprite, NULL);
        sfRenderWindow_drawSprite(m->window, m->weapons[COMMON_BOW].sprite, NULL);
        sfRenderWindow_drawSprite(m->window, m->weapons[COMMON_SPEAR].sprite, NULL);
        sfRenderWindow_drawSprite(m->window, m->weapons[COMMON_AXE].sprite, NULL);
        sfRenderWindow_drawSprite(m->window, m->weapons[RARE_SWORD].sprite, NULL);
        sfRenderWindow_drawSprite(m->window, m->weapons[RARE_BOW].sprite, NULL);
        sfRenderWindow_drawSprite(m->window, m->weapons[RARE_SPEAR].sprite, NULL);
        sfRenderWindow_drawSprite(m->window, m->weapons[RARE_AXE].sprite, NULL);
        sfRenderWindow_drawSprite(m->window, m->weapons[LEGENDARY_SWORD].sprite, NULL);
        sfRenderWindow_drawSprite(m->window, m->weapons[LEGENDARY_BOW].sprite, NULL);
        sfRenderWindow_drawSprite(m->window, m->weapons[LEGENDARY_SPEAR].sprite, NULL);
        sfRenderWindow_drawSprite(m->window, m->weapons[LEGENDARY_AXE].sprite, NULL);
        sfRenderWindow_drawSprite(m->window, m->weapons[THUNDER_BOOK].sprite, NULL);
        sfRenderWindow_drawSprite(m->window, m->weapons[FIRE_BOOK].sprite, NULL);
        sfRenderWindow_drawSprite(m->window, m->weapons[FREEZE_BOOK].sprite, NULL);
        sfRenderWindow_drawSprite(m->window, m->weapons[POTION].sprite, NULL);
        sfRenderWindow_drawSprite(m->window, m->shop.all_head, NULL);
        move_coin(m);
        sfRenderWindow_drawRectangleShape(m->window, m->shop.hooved, NULL);
        sfText_setString(m->shop.gold, my_inttostr(m->gold));
        sfRenderWindow_drawText(m->window, m->shop.gold, NULL);
        draw_stats_shop(m);
        sfRenderWindow_drawText(m->window, m->shop.text, NULL);
        sfRenderWindow_drawSprite(m->window, m->shop.cursor, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyR))
            m->shop.is_select = false;
        if (m->shop.is_select == false)
            select_perso(m);
        if (m->shop.is_select == true) {
            if (sfKeyboard_isKeyPressed(sfKeyLeft))
                move_hover_rect(m, sfKeyLeft);
            if (sfKeyboard_isKeyPressed(sfKeyRight))
                move_hover_rect(m, sfKeyRight);
            if (sfKeyboard_isKeyPressed(sfKeyUp))
                move_hover_rect(m, sfKeyUp);
            if (sfKeyboard_isKeyPressed(sfKeyDown))
                move_hover_rect(m, sfKeyDown);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            m->current = 12;
            m->shop.is_select = -1;
        }
    }
}
