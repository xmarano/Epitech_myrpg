/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** rpg.h
*/

#ifndef RPG_H
    #define RPG_H
    #include "my.h"
    #include "include/npc.h"
    #include "include/setting.h"
    #include "include/weapons.h"
    #include "include/menu.h"
    #include "include/perso.h"
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Config.h>

enum WHO_IS_HE {
    ROY_SWORD, ROY = 0,
    INFENIUM_BOOK, INFENIUM = 1,
    PATECARBO_BOW, PATECARBO = 2,
    XMARANO_SPEAR, XMARANO = 3,
    RACAILLOU_AXE, RACAILLOU = 4,
};

enum WHAT_WEAPONS {
    COMMON_AXE = 5,
    RARE_AXE= 6,
    LEGENDARY_AXE = 7,
    COMMON_SWORD = 8,
    RARE_SWORD = 9,
    LEGENDARY_SWORD = 10,
    COMMON_SPEAR = 11,
    RARE_SPEAR = 12,
    LEGENDARY_SPEAR = 13,
    COMMON_BOW = 14,
    RARE_BOW = 15,
    LEGENDARY_BOW = 16,
    FIRE_BOOK = 17,
    THUNDER_BOOK = 18,
    FREEZE_BOOK = 19
};

typedef struct Glob {
    int current;
    sfVector2i mouse;
    sfRenderWindow *window;
    sfClock *clock;
    Menu_t menu; /* Leo */
    Perso_t perso[5]; /* Yanis */
    Weapons_t weapons[20]; /* Yanis */
    Npc_t npc[20]; /* Yanis */
    Setting_t setting; /* Tom */
    bool show_mouse;
} Global_t;

void draw_mouse(Global_t *m);
int import_weapons_stats(Global_t *m);
int setup_stat(Global_t *m);
void init_menu(Global_t *m);
void draw_menu(Global_t *m);
void destroy_menu(Global_t *m);
void init_inventaire(Global_t *m);
int inventory(Global_t *m, sfEvent event);
sfSprite *init_sprite(char *filename, sfVector2f pos);
sfText *init_text(Global_t *m, char *str, int size, int pos_y);
sfRectangleShape *init_button(Global_t *m, sfVector2f size, int pos_y);
void hover(Global_t *m, sfRectangleShape *shape, sfFloatRect *rect);
void click(Global_t *m, sfFloatRect *rect, int current);
void init_setting(Global_t *m);
void draw_setting(Global_t *m);
void draw_inventaire(Global_t *m);
void event_setting(sfEvent event, Global_t *m);

#endif
