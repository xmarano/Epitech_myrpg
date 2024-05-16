/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** perso_spr.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"

static void init_sp_texture(Global_t *m)
{
    m->univers.sprite_roy = sfSprite_create();
    m->univers.sprite_infe = sfSprite_create();
    m->univers.sprite_xmara = sfSprite_create();
    m->univers.sprite_pate = sfSprite_create();
    m->univers.sprite_raca = sfSprite_create();
    m->univers.texture_roy = sfTexture_createFromFile(m->perso[ROY].texture_battle, NULL);
    m->univers.texture_infe = sfTexture_createFromFile(m->perso[INFENIUM].texture_battle, NULL);
    m->univers.texture_xmara = sfTexture_createFromFile(m->perso[XMARANO].texture_battle, NULL);
    m->univers.texture_pate = sfTexture_createFromFile(m->perso[PATECARBO].texture_battle, NULL);
    m->univers.texture_raca = sfTexture_createFromFile(m->perso[RACAILLOU].texture_battle, NULL);
    sfSprite_setTexture(m->univers.sprite_roy, m->univers.texture_roy, sfTrue);
    sfSprite_setTexture(m->univers.sprite_infe, m->univers.texture_infe, sfTrue);
    sfSprite_setTexture(m->univers.sprite_xmara, m->univers.texture_xmara, sfTrue);
    sfSprite_setTexture(m->univers.sprite_pate, m->univers.texture_pate, sfTrue);
    sfSprite_setTexture(m->univers.sprite_raca, m->univers.texture_raca, sfTrue);
}

void destory_all_w_maps(Global_t *m)
{
    sfSprite_destroy(m->zone1.w1_map);
    sfTexture_destroy(m->zone1.w1_Map);
    sfSprite_destroy(m->univers.sprite_roy);
    sfSprite_destroy(m->univers.sprite_infe);
    sfSprite_destroy(m->univers.sprite_xmara);
    sfSprite_destroy(m->univers.sprite_pate);
    sfSprite_destroy(m->univers.sprite_raca);
    sfTexture_destroy(m->univers.texture_roy);
    sfTexture_destroy(m->univers.texture_infe);
    sfTexture_destroy(m->univers.texture_xmara);
    sfTexture_destroy(m->univers.texture_pate);
    sfTexture_destroy(m->univers.texture_raca);
}

void init_sp_perso_boss(Global_t *m)
{
    m->univers.rect = (sfIntRect){0, 512 + 65 * 2, 65, 65};
    init_sp_texture(m);
    sfSprite_setScale(m->univers.sprite_roy, (sfVector2f){0.61, 0.61});
    sfSprite_setScale(m->univers.sprite_infe, (sfVector2f){0.61, 0.61});
    sfSprite_setScale(m->univers.sprite_xmara, (sfVector2f){0.61, 0.61});
    sfSprite_setScale(m->univers.sprite_pate, (sfVector2f){0.61, 0.61});
    sfSprite_setScale(m->univers.sprite_raca, (sfVector2f){0.61, 0.61});
    sfSprite_setTextureRect(m->univers.sprite_roy, m->univers.rect);
    sfSprite_setTextureRect(m->univers.sprite_infe, m->univers.rect);
    sfSprite_setTextureRect(m->univers.sprite_xmara, m->univers.rect);
    sfSprite_setTextureRect(m->univers.sprite_pate, m->univers.rect);
    sfSprite_setTextureRect(m->univers.sprite_raca, m->univers.rect);
}
