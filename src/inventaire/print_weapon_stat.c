/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** print_weapon_stat.c
*/

#include "../my.h"
#include "../rpg.h"
#include "../include/perso.h"

void print_weapon4_stat(Global_t *m, int who)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    int rng = m->perso[who].inv_weapon[SLOT4].rng;
    int atk = m->perso[who].inv_weapon[SLOT4].attack;
    int crit = m->perso[who].inv_weapon[SLOT4].crit;
    int accuracy = m->perso[who].inv_weapon[SLOT4].accuracy;
    char str[100];

    sprintf(str, "%s%d\n\n", TABS_5, rng);
    sprintf(str + strlen(str), "%d\t\t\t\t %d\n\n", atk, crit);
    sprintf(str + strlen(str), "%d\t\t\t\t ----", accuracy);
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 35);
    sfText_setFillColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){1065, 635});
    sfRenderWindow_drawText(m->window, text, NULL);
}

void print_weapon3_stat(Global_t *m, int who)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    int rng = m->perso[who].inv_weapon[SLOT3].rng;
    int atk = m->perso[who].inv_weapon[SLOT3].attack;
    int crit = m->perso[who].inv_weapon[SLOT3].crit;
    int accuracy = m->perso[who].inv_weapon[SLOT3].accuracy;
    char str[100];

    sprintf(str, "%s%d\n\n", TABS_5, rng);
    sprintf(str + strlen(str), "%d\t\t\t\t %d\n\n", atk, crit);
    sprintf(str + strlen(str), "%d\t\t\t\t ----", accuracy);
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 35);
    sfText_setFillColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){1065, 635});
    sfRenderWindow_drawText(m->window, text, NULL);
}

void print_weapon2_stat(Global_t *m, int who)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    int rng = m->perso[who].inv_weapon[SLOT2].rng;
    int atk = m->perso[who].inv_weapon[SLOT2].attack;
    int crit = m->perso[who].inv_weapon[SLOT2].crit;
    int accuracy = m->perso[who].inv_weapon[SLOT2].accuracy;
    char str[100];

    sprintf(str, "%s%d\n\n", TABS_5, rng);
    sprintf(str + strlen(str), "%d\t\t\t\t %d\n\n", atk, crit);
    sprintf(str + strlen(str), "%d\t\t\t\t ----", accuracy);
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 35);
    sfText_setFillColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){1065, 635});
    sfRenderWindow_drawText(m->window, text, NULL);
}

void print_heal_stat(Global_t *m, int who)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    int rng = m->perso[who].inv_weapon[HEAL].rng;
    int atk = m->perso[who].inv_weapon[HEAL].attack;
    int crit = m->perso[who].inv_weapon[HEAL].crit;
    int accuracy = m->perso[who].inv_weapon[HEAL].accuracy;
    char str[100];

    sprintf(str, "%s%d\n\n", TABS_5, rng);
    sprintf(str + strlen(str), "%d\t\t\t\t %d\n\n", atk, crit);
    sprintf(str + strlen(str), "%d\t\t\t\t   heal", accuracy);
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 35);
    sfText_setFillColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){1065, 635});
    sfRenderWindow_drawText(m->window, text, NULL);
}

void print_current_stat(Global_t *m, int who)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    int rng = m->perso[who].inv_weapon[SLOT1].rng;
    int atk = m->perso[who].inv_weapon[SLOT1].attack;
    int crit = m->perso[who].inv_weapon[SLOT1].crit;
    int accuracy = m->perso[who].inv_weapon[SLOT1].accuracy;
    char str[100];

    sprintf(str, "%s%d\n\n", TABS_5, rng);
    sprintf(str + strlen(str), "%d\t\t\t\t %d\n\n", atk, crit);
    sprintf(str + strlen(str), "%d\t\t\t\t ----", accuracy);
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 35);
    sfText_setFillColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){1065, 635});
    sfRenderWindow_drawText(m->window, text, NULL);
}
