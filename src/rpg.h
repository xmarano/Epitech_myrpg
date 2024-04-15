/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** rpg.h
*/

#ifndef RPG_H
    #define RPG_H

#include "my.h"
#include "include/menu.h"
#include "include/inventory.h"
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>

typedef struct Glob {
    sfVector2i mouse;
    sfRenderWindow *window;
    Menu_t menu; /* Leo */
    Perso_t perso; /* Yanis */
} Global_t;

void init_menu(Global_t *m);
void draw_menu(Global_t *m);
int inventory(Global_t *m, sfEvent event);
void destroy_menu(Global_t *m);

#endif
