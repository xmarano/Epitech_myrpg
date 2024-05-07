/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** lifebar.c
*/

#include "../include/perso.h"
#include "../rpg.h"

// SPRITE DE BASE: 40 HP

void init_lifebars(fight_t *fight, Global_t *m)
{
    if (m->current == 100) {
    fight->globat_texture = sfTexture_createFromFile("assets/fight/combat_visualize.png", NULL);
    fight->empty_bar_sprite = sfSprite_create();
    fight->rect_empty_bar = (sfIntRect){1, 26, 81, 7};
    fight->hero_lifebar_sprite = sfSprite_create();
    fight->combat_scene = sfSprite_create();
    fight->ennemy_bar_sprite = sfSprite_create();

    sfSprite_setTexture(fight->combat_scene, sfTexture_createFromFile("assets/fight/battle_scene.png", NULL), sfFalse);
    sfSprite_setScale(fight->combat_scene, (sfVector2f){8, 6.25});
    sfRenderWindow_drawSprite(m->window, fight->combat_scene, NULL);

    sfSprite_setTexture(fight->empty_bar_sprite, fight->globat_texture, sfFalse);
    sfSprite_setTextureRect(fight->empty_bar_sprite, fight->rect_empty_bar);
    sfSprite_setPosition(fight->empty_bar_sprite, (sfVector2f){100, 900});
    sfSprite_setScale(fight->empty_bar_sprite, (sfVector2f){8, 8});
    sfRenderWindow_drawSprite(m->window, fight->empty_bar_sprite, NULL);


    sfSprite_setPosition(fight->empty_bar_sprite, (sfVector2f){1075, 900});
    sfRenderWindow_drawSprite(m->window, fight->empty_bar_sprite, NULL);
    sfSprite_setTexture(fight->ennemy_bar_sprite, fight->globat_texture, sfFalse);
    fight->rect_ennemy_bar = (sfIntRect){1, 58, 45, 7};
    sfSprite_setTextureRect(fight->ennemy_bar_sprite, fight->rect_ennemy_bar);
    sfSprite_setPosition(fight->ennemy_bar_sprite, (sfVector2f){1075, 900});
    sfSprite_setScale(fight->ennemy_bar_sprite, (sfVector2f){8, 8});
    sfRenderWindow_drawSprite(m->window, fight->ennemy_bar_sprite, NULL);


    sfSprite_setTexture(fight->hero_lifebar_sprite, fight->globat_texture, sfFalse);
    fight->rect_hero_bar = (sfIntRect){1, 50, 45, 7};
    sfSprite_setTextureRect(fight->hero_lifebar_sprite, fight->rect_hero_bar);
    sfSprite_setPosition(fight->hero_lifebar_sprite, (sfVector2f){100, 900});
    sfSprite_setScale(fight->hero_lifebar_sprite, (sfVector2f){8, 8});
    sfRenderWindow_drawSprite(m->window, fight->hero_lifebar_sprite, NULL);


    sfSprite_destroy(fight->empty_bar_sprite);
    sfSprite_destroy(fight->hero_lifebar_sprite);
    sfTexture_destroy(fight->globat_texture);
    sfSprite_destroy(fight->combat_scene);
    printf("Damage :%i\nHit: %i\n", damage_physical(&m->perso[INFENIUM], &m->perso[XMARANO]), is_hit(&m->perso[INFENIUM], &m->perso[XMARANO], m->perso[INFENIUM].current_weapon, m->perso[XMARANO].current_weapon));
    exit(0);
    }
}