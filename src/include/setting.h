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
    sfSprite *background;
    sfSprite *volume_up;
    sfSprite *volume_down;
    sfSprite *coupe_all;
    sfSprite *credit;
    sfSprite *histoire;
    sfSprite *guide;
} Setting_t;

#endif