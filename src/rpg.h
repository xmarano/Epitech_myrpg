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
    sfSprite *background;
} Menu_t;

typedef struct Glob {
    sfVector2i mouse;
    sfRenderWindow *window;
    Menu_t menu;
} Global_t;

void init_menu(Global_t *m);
void draw_menu(Global_t *m);
void destroy_menu(Global_t *m);

#endif
