/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** shop.c
*/

#include "rpg.h"
#include "include/perso.h"
#include "include/menu.h"
#include "include/worlds.h"

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

void destroy_shop(Global_t *m)
{
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
}

void init_shop_part2(Global_t *m, sfVector2f pose)
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
}

void init_shop(Global_t *m)
{
    sfVector2f pose = {180, 90};
    sfVector2f size = {0.5, 0.5};

    m->shop.shop = init_spritee(m, "assets/shop/shop.png", pose, size);
    m->shop.coin = init_spritee(m, "assets/shop/coin.png", pose, size);
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
}

void move_hover_rect(Global_t *m, int direction) {
    const int num_columns = 4;
    const int num_rows = 4;
    const int spacing_x = 30;
    const int spacing_y = 30;
    const float move_speed = 0.15f;
    int current_index = m->shop.hovered_index;
    int new_index = current_index;
    static sfClock *clock = NULL;
    sfTime elapsed;
    float elapsed_seconds;

    if (!clock)
        clock = sfClock_create();
    elapsed = sfClock_getElapsedTime(clock);
    elapsed_seconds = sfTime_asSeconds(elapsed);
    if (elapsed_seconds < move_speed)
        return;
    sfClock_restart(clock);
    switch (direction) {
        case sfKeyLeft:
            new_index--;
            break;
        case sfKeyRight:
            new_index++;
            break;
        case sfKeyUp:
            new_index -= num_columns;
            break;
        case sfKeyDown:
            new_index += num_columns;
            break;
    }
    if (new_index < 0 || new_index >= num_columns * num_rows)
        return;
    if (clock != NULL) {
        sfClock_destroy(clock);
        clock = NULL;
    }
    int row = new_index / num_columns;
    int column = new_index % num_columns;
    sfVector2f current_position = sfSprite_getPosition(m->weapons[8].sprite);
    sfVector2f new_position = {
        420 + column * (current_position.x - 420 + spacing_x),
        245 + row * (current_position.y - 245 + spacing_y)
    };
    sfRectangleShape_setPosition(m->shop.hooved, new_position);
    m->shop.hovered_index = new_index;
}

static void move_coin(Global_t *m)
{
    static sfClock *clock = NULL;
    static sfIntRect rect = {0, 0, 16, 16};
    sfTime time;
    float seconds;

    if (clock == NULL)
        clock = sfClock_create();
    time = sfClock_getElapsedTime(clock);
    seconds = sfTime_asSeconds(time);
    if (seconds > 0.1) {
        rect.left += 16;
        if (rect.left >= 144)
            rect.left = 0;
        sfSprite_setTextureRect(m->shop.coin, rect);
        sfClock_restart(clock);
    }
    sfRenderWindow_drawSprite(m->window, m->shop.coin, NULL);
}

void draw_shop(Global_t *m)
{
    if (m->current == 9) {
        sfRenderWindow_drawSprite(m->window ,m->shop.shop, NULL);
        move_coin(m);
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
        sfRenderWindow_drawRectangleShape(m->window, m->shop.hooved, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyLeft))
            move_hover_rect(m, sfKeyLeft);
        if (sfKeyboard_isKeyPressed(sfKeyRight))
            move_hover_rect(m, sfKeyRight);
        if (sfKeyboard_isKeyPressed(sfKeyUp))
            move_hover_rect(m, sfKeyUp);
        if (sfKeyboard_isKeyPressed(sfKeyDown))
            move_hover_rect(m, sfKeyDown);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            m->current = 12;
        }
    }
}
