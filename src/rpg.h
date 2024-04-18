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
    #include "include/worlds.h"
    #include "include/perso.h"
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Config.h>
    #define SPEED 4
    #define FRAME_WIDTH 65
    #define FRAME_HEIGHT 65

enum WHO_IS_HE {
    ROY_SWORD, ROY = 0,
    INFENIUM_BOOK, INFENIUM = 1,
    PATECARBO_BOW, PATECARBO = 2,
    XMARANO_SPEAR, XMARANO = 3,
    RACAILLOU_AXE, RACAILLOU = 4,
    BOSS1 = 5,
    BOSS2 = 6,
    BOSS3 = 7,
    BOSS4 = 8,
    BOSS5 = 9,
    BOSS6 = 10,
    BOSS7 = 11,
    BOSS8 = 12,
};

enum WHAT_WEAPONS {
    COMMON_AXE = 5,
    RARE_AXE = 6,
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
    FREEZE_BOOK = 19,
    BOSS1_SWORD = 20,
    BOSS2_STICK = 21,
    BOSS3_BOW = 22,
    BOSS4_SPEAR = 23,
    BOSS5_SWORD = 24,
    BOSS6_BOOK = 25,
    BOSS7_AXE = 26,
    BOSS8_SWORD = 27,
};

typedef struct Glob {
    int current;
    sfVector2i mouse;
    sfRenderWindow *window;
    sfClock *clock;
    Menu_t menu; /* Leo */
    Perso_t perso[13]; /* Yanis */
    Weapons_t weapons[28]; /* Yanis */
    Npc_t npc[20]; /* Yanis */
    Setting_t setting; /* Tom */
    bool show_mouse;
    Hub_t hub;
    Zone1_t zone1;
    Zone2_t zone2;
    Zone3_t zone3;
    //next
    Zone8_t zone8;
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
int set_boss(Global_t *m);
int set_enemy(Global_t *m);

#endif
