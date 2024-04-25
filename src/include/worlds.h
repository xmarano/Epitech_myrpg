/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** worlds.h
*/

#ifndef WORLDS_H
    #define WORLDS_H
    #include "../rpg.h"

typedef struct hub {
    sfIntRect rect;
    sfSprite *sprite_perso;
    sfTexture *texture_perso;
    sfTexture *texture_hub;
    sfSprite *sprite_hub;
    sfVector2f movement;
    sfTime time;
    sfImage *hitbox;
    sfVector2f pos_sprite;
    sfColor color;
    sfView *view;
    sfView *normal_view;
} hub_t;

typedef struct Loading
{
    sfSprite *vert;
    sfSprite *fond;
    sfSprite *text;
    sfTexture *Vert;
    sfTexture *Fond;
    sfTexture *Text;
    sfSprite *back_screen;
    sfTexture *Back_screen;
}Loading_t;

typedef struct Shop
{
    sfSprite *shop;
    sfTexture *Shop;
    sfRectangleShape *hooved;
    int hovered_index;
    sfSprite *coin;
    sfTexture *Coin;
}Shop_t;

typedef struct Zone1
{
    /* data */
}Zone1_t;

typedef struct Zone2
{
    /* data */
}Zone2_t;

typedef struct Zone3
{
    /* data */
}Zone3_t;

typedef struct Zone8
{
    /* data */
}Zone8_t;

#endif
