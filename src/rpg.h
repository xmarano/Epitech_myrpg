/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** rpg.h
*/
#include "my.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#ifndef RPG_H
    #define RPG_H

typedef struct Menu {
    sfText *test;
} Menu_t;

typedef struct Sprite {
    sfVector2i mouse;
    Menu_t menu;
} Sprite_t;

void init_menu(sfRenderWindow *window, Sprite_t *s);
void draw_menu(sfRenderWindow *window, Sprite_t *s);
void destroy_menu(sfRenderWindow *window, Sprite_t *s);
#endif
