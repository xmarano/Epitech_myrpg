/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** rpg.h
*/


#ifndef RPG_H
    #define RPG_H
#include "my.h"
#include "include/setting.h"
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
    Setting_t setting; /* Tom */
    bool displaySizeOptions;
} Global_t;

void init_menu(Global_t *m);
void draw_menu(Global_t *m);
void destroy_menu(Global_t *m);
void inventory(Global_t *m, sfEvent event);
sfSprite *init_sprite(char *filename, sfVector2f pos);
sfText *init_text(char *str, int size, sfVector2f pos);
void init_setting(Global_t *m);
void draw_setting(Global_t *m);
void draw_inventaire(Global_t *m);
void event_setting(sfEvent event, Global_t *m);

#endif
