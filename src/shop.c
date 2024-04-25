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

static sfSprite *init_sprit(char *filename, sfVector2f pos, sfVector2f size)
{
    sfTexture *texture = sfTexture_createFromFile(filename, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, size);
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

void destroy_shop(Global_t *m)
{
    sfSprite_destroy(m->shop.shop);
    sfTexture_destroy(m->shop.Shop);
}

void init_shop(Global_t *m)
{
    sfVector2f pose = {200, 90};
    sfVector2f size = {0.5, 0.5};

    m->shop.shop = init_sprit("assets/shop/shop.png", pose, size);
    size.x = size.y = 1.3;
    pose.x = 300;
    pose.y = 195;
    m->weapons[COMMON_SWORD].sprite = init_sprit(m->weapons[COMMON_SWORD].link_texture, pose, size);
    pose.x += 35;
    m->weapons[COMMON_BOW].sprite = init_sprit(m->weapons[COMMON_BOW].link_texture, pose, size);
    pose.x += 30;
    m->weapons[COMMON_SPEAR].sprite = init_sprit(m->weapons[COMMON_SPEAR].link_texture, pose, size);
    pose.x += 30;
    m->weapons[COMMON_AXE].sprite = init_sprit(m->weapons[COMMON_AXE].link_texture, pose, size);
    pose.y = 425;
    pose.x = 300;
    m->weapons[RARE_SWORD].sprite = init_sprit(m->weapons[RARE_SWORD].link_texture, pose, size);
    pose.x += 30;
    m->weapons[RARE_BOW].sprite = init_sprit(m->weapons[RARE_BOW].link_texture, pose, size);
    pose.x += 30;
    m->weapons[RARE_SPEAR].sprite = init_sprit(m->weapons[RARE_SPEAR].link_texture, pose, size);
    pose.x += 30;
    m->weapons[RARE_AXE].sprite = init_sprit(m->weapons[RARE_AXE].link_texture, pose, size);
    pose.y = 455;
    pose.x = 300;
    m->weapons[LEGENDARY_SWORD].sprite = init_sprit(m->weapons[LEGENDARY_SWORD].link_texture, pose, size);
    pose.x += 30;
    m->weapons[LEGENDARY_BOW].sprite = init_sprit(m->weapons[LEGENDARY_BOW].link_texture, pose, size);
    pose.x += 30;
    m->weapons[LEGENDARY_SPEAR].sprite = init_sprit(m->weapons[LEGENDARY_SPEAR].link_texture, pose, size);
    pose.x += 30;
    m->weapons[LEGENDARY_AXE].sprite = init_sprit(m->weapons[LEGENDARY_AXE].link_texture, pose, size);//!
    pose.y = 485;
    pose.x = 300;
    m->weapons[THUNDER_BOOK].sprite = init_sprit(m->weapons[THUNDER_BOOK].link_texture, pose, size);
    pose.x += 30;
    m->weapons[FIRE_BOOK].sprite = init_sprit(m->weapons[FIRE_BOOK].link_texture, pose, size);
    pose.x += 30;
    m->weapons[FREEZE_BOOK].sprite = init_sprit(m->weapons[FREEZE_BOOK].link_texture, pose, size);
    pose.y = 515;
    pose.x = 300;
    m->weapons[POTION].sprite = init_sprit(m->weapons[POTION].link_texture, pose, size);
}

void draw_shop(Global_t *m)
{
    if (m->current == 9) {
        sfRenderWindow_drawSprite(m->window ,m->shop.shop, NULL);
        sfRenderWindow_drawSprite(m->window, m->weapons[COMMON_SWORD].sprite, NULL);
        sfRenderWindow_drawSprite(m->window, m->weapons[COMMON_BOW].sprite, NULL);
        sfRenderWindow_drawSprite(m->window, m->weapons[COMMON_SPEAR].sprite, NULL);
        sfRenderWindow_drawSprite(m->window, m->weapons[COMMON_AXE].sprite, NULL);
        sfRenderWindow_drawSprite(m->window, m->weapons[RARE_SWORD].sprite, NULL);//!
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
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            m->current = 12;
    }
    return;
}
