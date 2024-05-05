/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** other.c
*/

#include "../my.h"
#include "../rpg.h"
#include "../include/perso.h"

bool is_empty_slot(Weapons_t *weapon_slot)
{
    return weapon_slot->is_empty != true;
}

void equiped_weapon(Global_t *m, int who)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    char *weapon_name = m->perso[who].current_weapon->name;
    char str[30];

    sprintf(str, "Equiped :  %s", weapon_name);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 33);
    sfText_setColor(text, sfBlack);
    sfText_setString(text, str);
    sfText_setPosition(text, (sfVector2f){940, 365});
    sfRenderWindow_drawText(m->window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}
