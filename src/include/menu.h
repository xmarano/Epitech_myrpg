/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** menu.h
*/
#include "../my.h"
#include "../rpg.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>

#ifndef MENU_H
    #define MENU_H

typedef struct Menu {
    sfVector2u wsize;
    sfSprite *map;
    sfSprite *cursor;
    sfText *title;
    sfText *new_game;
    sfText *continuer;
    sfText *settings;
    sfText *exit;
    sfRectangleShape *button1;
    sfRectangleShape *button2;
    sfRectangleShape *button3;
    sfRectangleShape *button4;
    sfFloatRect text;
} Menu_t;

#endif
