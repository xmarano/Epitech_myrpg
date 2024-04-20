/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** set_weapons.c
*/

#include "../my.h"
#include "../rpg.h"
#include "../include/perso.h"

static void empty_slot(Global_t *m, sfVector2f pose_sp, sfVector2f pose_txt)
{
    // int who = m->perso->current_perso;
    // sfSprite *weapon = sfSprite_create();
    // char *filename = m->perso[who].inv_weapon->link_texture;
    // sfTexture *Weapon = sfTexture_createFromFile(filename, NULL);
    // sfText *text = sfText_create();
    // sfFont *font = sfFont_createFromFile("assets/font.ttf");

    // sfSprite_setTexture(weapon, Weapon, sfTrue);
    // sfSprite_setPosition(weapon, pose_sp);
    // sfSprite_setScale(weapon, (sfVector2f){1.9, 1.9});
    // sfRenderWindow_drawSprite(m->window, weapon, NULL);
    // sfText_setString(text, m->perso[who].inv_weapon[SLOT5].name);
    // sfText_setFont(text, font);
    // sfText_setCharacterSize(text, 40);
    // sfText_setFillColor(text, sfBlack);
    // sfText_setPosition(text, pose_txt);
    // sfRenderWindow_drawText(m->window, text, NULL);
    // sfSprite_destroy(weapon);
    // sfTexture_destroy(Weapon);
    // sfText_destroy(text);
    // sfFont_destroy(font);
}

static void weapon_slot5(Global_t *m, int who)
{
    sfSprite *weapon = sfSprite_create();
    char *filename = m->perso[who].inv_weapon[SLOT5].link_texture;
    sfTexture *Weapon = sfTexture_createFromFile(filename, NULL);
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    sfSprite_setTexture(weapon, Weapon, sfTrue);
    sfSprite_setPosition(weapon, (sfVector2f){980, 633});
    sfSprite_setScale(weapon, (sfVector2f){1.9, 1.9});
    sfRenderWindow_drawSprite(m->window, weapon, NULL);
    sfText_setString(text, m->perso[who].inv_weapon[SLOT5].name);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    sfText_setFillColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){1050, 626});
    sfRenderWindow_drawText(m->window, text, NULL);
    sfSprite_destroy(weapon);
    sfTexture_destroy(Weapon);
    sfText_destroy(text);
    sfFont_destroy(font);
}

static void weapon_slot4(Global_t *m, int who)
{
    sfSprite *weapon = sfSprite_create();
    char *filename = m->perso[who].inv_weapon[SLOT4].link_texture;
    sfTexture *Weapon = sfTexture_createFromFile(filename, NULL);
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    sfSprite_setTexture(weapon, Weapon, sfTrue);
    sfSprite_setPosition(weapon, (sfVector2f){980, 595});
    sfSprite_setScale(weapon, (sfVector2f){1.9, 1.9});
    sfRenderWindow_drawSprite(m->window, weapon, NULL);
    sfText_setString(text, m->perso[who].inv_weapon[SLOT4].name);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    sfText_setFillColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){1050, 586});
    sfRenderWindow_drawText(m->window, text, NULL);
    sfSprite_destroy(weapon);
    sfTexture_destroy(Weapon);
    sfText_destroy(text);
    sfFont_destroy(font);
}

static void weapon_slot3(Global_t *m, int who)
{
    sfSprite *weapon = sfSprite_create();
    char *filename = m->perso[who].inv_weapon[SLOT3].link_texture;
    sfTexture *Weapon = sfTexture_createFromFile(filename, NULL);
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    sfSprite_setTexture(weapon, Weapon, sfTrue);
    sfSprite_setPosition(weapon, (sfVector2f){980, 557});
    sfSprite_setScale(weapon, (sfVector2f){1.9, 1.9});
    sfRenderWindow_drawSprite(m->window, weapon, NULL);
    sfText_setString(text, m->perso[who].inv_weapon[SLOT3].name);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    sfText_setFillColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){1050, 546});
    sfRenderWindow_drawText(m->window, text, NULL);
    sfSprite_destroy(weapon);
    sfTexture_destroy(Weapon);
    sfText_destroy(text);
    sfFont_destroy(font);
}

static void weapon_slot2(Global_t *m, int who)
{
    sfSprite *weapon = sfSprite_create();
    char *filename = m->perso[who].inv_weapon[SLOT2].link_texture;
    sfTexture *Weapon = sfTexture_createFromFile(filename, NULL);
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    sfSprite_setTexture(weapon, Weapon, sfTrue);
    sfSprite_setPosition(weapon, (sfVector2f){980, 519});
    sfSprite_setScale(weapon, (sfVector2f){1.9, 1.9});
    sfRenderWindow_drawSprite(m->window, weapon, NULL);
    sfText_setString(text, m->perso[who].inv_weapon[SLOT2].name);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    sfText_setFillColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){1050, 506});
    sfRenderWindow_drawText(m->window, text, NULL);
    sfSprite_destroy(weapon);
    sfTexture_destroy(Weapon);
    sfText_destroy(text);
    sfFont_destroy(font);
}

static void heal_stick(Global_t *m, int who)
{
    sfSprite *weapon = sfSprite_create();
    char *filename = m->perso[who].inv_weapon[HEAL].link_texture;
    sfTexture *Weapon = sfTexture_createFromFile(filename, NULL);
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    sfSprite_setTexture(weapon, Weapon, sfTrue);
    sfSprite_setPosition(weapon, (sfVector2f){980, 481});
    sfSprite_setScale(weapon, (sfVector2f){1.9, 1.9});
    sfRenderWindow_drawSprite(m->window, weapon, NULL);
    sfText_setString(text, m->perso[who].inv_weapon[HEAL].name);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    sfText_setFillColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){1050, 466});
    sfRenderWindow_drawText(m->window, text, NULL);
    sfSprite_destroy(weapon);
    sfTexture_destroy(Weapon);
    sfText_destroy(text);
    sfFont_destroy(font);
}

static void current_weapon(Global_t *m, int who)
{
    sfSprite *weapon = sfSprite_create();
    char *filename = m->perso[who].current_weapon->link_texture;
    sfTexture *Weapon = sfTexture_createFromFile(filename, NULL);
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    sfSprite_setTexture(weapon, Weapon, sfTrue);
    sfSprite_setPosition(weapon, (sfVector2f){980, 443});
    sfSprite_setScale(weapon, (sfVector2f){1.9, 1.9});
    sfRenderWindow_drawSprite(m->window, weapon, NULL);
    sfText_setString(text, m->perso[who].current_weapon->name);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    sfText_setFillColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){1050, 426});
    sfRenderWindow_drawText(m->window, text, NULL);
    sfSprite_destroy(weapon);
    sfTexture_destroy(Weapon);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void weapons_inv_stat(Global_t *m)
{
    int who = m->perso->current_perso;
    sfVector2f err_sprite_pose = {1050, };
    sfVector2f err_text = {};

    printf("%d\n", m->perso[who].num_weapons_in_inv);
    current_weapon(m, who);
    heal_stick(m, who);
    if (m->perso[who].num_weapons_in_inv >= 2)
        weapon_slot2(m, who);
    else
        empty_slot(m, err_sprite_pose, err_text);
    if (m->perso[who].num_weapons_in_inv >= 3)
        weapon_slot3(m, who);
    else
        empty_slot(m, err_sprite_pose, err_text);
    if (m->perso[who].num_weapons_in_inv >= 4)
        weapon_slot4(m, who);
    else
        empty_slot(m, err_sprite_pose, err_text);
    if (m->perso[who].num_weapons_in_inv >= 5)
        weapon_slot5(m, who);
    else
        empty_slot(m, err_sprite_pose, err_text);
    return;
}
