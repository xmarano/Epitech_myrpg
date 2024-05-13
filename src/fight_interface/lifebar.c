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
    fight->globat_texture = sfTexture_createFromFile("assets/fight/combat_visualize.png", NULL);
    fight->empty_bar_sprite = sfSprite_create();
    fight->rect_empty_bar = (sfIntRect){1, 26, 81, 7};
    fight->hero_lifebar_sprite = sfSprite_create();
    fight->combat_scene = sfSprite_create();
    fight->ennemy_bar_sprite = sfSprite_create();
    fight->font = sfFont_createFromFile("assets/font.ttf");

    sfSprite_setTexture(fight->combat_scene, sfTexture_createFromFile("assets/fight/battle_scene.png", NULL), sfFalse);
    sfSprite_setScale(fight->combat_scene, (sfVector2f){8, 6.25});

    sfSprite_setScale(fight->empty_bar_sprite, (sfVector2f){8, 8});
    sfSprite_setTexture(fight->empty_bar_sprite, fight->globat_texture, sfFalse);
    sfSprite_setTextureRect(fight->empty_bar_sprite, fight->rect_empty_bar);


    sfSprite_setTexture(fight->ennemy_bar_sprite, fight->globat_texture, sfFalse);
    sfSprite_setPosition(fight->ennemy_bar_sprite, (sfVector2f){1075, 900});
    sfSprite_setScale(fight->ennemy_bar_sprite, (sfVector2f){8, 8});


    sfSprite_setTexture(fight->hero_lifebar_sprite, fight->globat_texture, sfFalse);
    sfSprite_setPosition(fight->hero_lifebar_sprite, (sfVector2f){100, 900});
    sfSprite_setScale(fight->hero_lifebar_sprite, (sfVector2f){8, 8});

    //printf("Damage :%i\nHit: %i\n", damage_physical(&m->perso[INFENIUM], &m->perso[XMARANO]), is_hit(&m->perso[INFENIUM], &m->perso[XMARANO], m->perso[INFENIUM].current_weapon, m->perso[XMARANO].current_weapon));
}

void draw_text(sfVector2f pos, char *msg, Global_t *m, fight_t *f)
{
    sfText *text = sfText_create();

    sfText_setPosition(text, pos);
    sfText_setFont(text, f->font);
    sfText_setString(text, msg);
    sfText_setCharacterSize(text, 100);
    sfRenderWindow_drawText(m->window, text, NULL);
    sfText_destroy(text);
}

void draw_stats(Perso_t *atk, Perso_t *def, Global_t *m, fight_t *f)
{
    int crit = atk->current_weapon->crit + atk->stat_p.skl * 2 - def->stat_p.lck;

    printf("%i\n", crit);
    draw_text((sfVector2f){50, 600}, my_inttostr(crit), m, f);
}

void print_fight_scene(Global_t *m, fight_t *fight, Perso_t *atk, Perso_t *def)
{
    sfRenderWindow_drawSprite(m->window, fight->combat_scene, NULL);
    sfSprite_setPosition(fight->empty_bar_sprite, (sfVector2f){100, 900});
    fight->rect_empty_bar = (sfIntRect){1, 26, atk->stat_p.max_hp * 2 + 1, 7};
    sfSprite_setTextureRect(fight->empty_bar_sprite, fight->rect_empty_bar);
    sfRenderWindow_drawSprite(m->window, fight->empty_bar_sprite, NULL);
    sfSprite_setPosition(fight->empty_bar_sprite, (sfVector2f){1075, 900});
    fight->rect_empty_bar = (sfIntRect){1, 26, def->stat_p.max_hp * 2 + 1, 7};
    sfSprite_setTextureRect(fight->empty_bar_sprite, fight->rect_empty_bar);
    sfRenderWindow_drawSprite(m->window, fight->empty_bar_sprite, NULL);
    fight->rect_ennemy_bar = (sfIntRect){1, 58, def->stat_p.current_hp * 2 + 1, 7};
    sfSprite_setTextureRect(fight->ennemy_bar_sprite, fight->rect_ennemy_bar);
    sfRenderWindow_drawSprite(m->window, fight->ennemy_bar_sprite, NULL);
    fight->rect_hero_bar = (sfIntRect){1, 50, atk->stat_p.current_hp * 2 + 1, 7};
    sfSprite_setTextureRect(fight->hero_lifebar_sprite, fight->rect_hero_bar);
    sfRenderWindow_drawSprite(m->window, fight->hero_lifebar_sprite, NULL);
    draw_text((sfVector2f){25, 30}, atk->name_perso, m, fight);
    draw_text((sfVector2f){1525, 30}, def->name_perso, m, fight);
    draw_stats(atk, def, m, fight);
}

void destroy_fight_struct(fight_t *fight)
{
    sfSprite_destroy(fight->empty_bar_sprite);
    sfSprite_destroy(fight->hero_lifebar_sprite);
    sfTexture_destroy(fight->globat_texture);
    sfSprite_destroy(fight->combat_scene);
    sfSprite_destroy(fight->ennemy_bar_sprite);
    sfFont_destroy(fight->font);
}