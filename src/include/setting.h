/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** setting.h
*/
#include "../my.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>

#ifndef setting_H
    #define setting_H

typedef struct setting {
    sfSprite *background_s;
    sfSprite *volume_up;
    sfSprite *volume_down;
    sfSprite *volume;
    sfSprite *credit;
    sfSprite *coupe_volume;
    sfSprite *synopsis;
    sfSprite *end;
    sfSprite *size;
    sfText* text_s;
    int toto;
} Setting_t;

#endif