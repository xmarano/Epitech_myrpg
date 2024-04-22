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

#ifndef SETTING_H
    #define SETTING_H

typedef struct setting {
    sfFont *font;
    sfVector2u window_size;
    sfText *background_s;
    sfText *titre;
    sfText *credit;
    sfText *synopsis;

    sfText *volumetxt;
    sfText *volumehaut;
    sfText *volumebas;
    sfText *volumecoupe;

    sfText *retour;

    sfText *sizewindows;
    sfText *littlez;
    sfText *mediumz;
    sfText *bigz;
    sfText *test;
    sfText *txtcredit;

    sfText *volumeb;
    sfText *volumeh;
    sfText *cvolume;

    sfText *creditpara;
    sfRectangleShape *creditrect;
    sfText *synopsypara;

    sfRectangleShape *buttonsynop;
    sfRectangleShape *buttoncred;
    sfRectangleShape *buttonvolum;
    sfRectangleShape *buttonretour;
    sfRectangleShape *buttonwindow;
    sfRectangleShape *buttonsett;

    bool displaySizeOptions;
    bool volumeclicked;
    bool creditbool;
    bool back;
    bool synopbool; 

    sfVector2i mouse;
    sfFloatRect creditBounds;
} Setting_t;


#endif
