/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** worlds.h
*/

#ifndef WORLDS_H
    #define WORLDS_H
    #define get_size sfView_getSize
    #include "../rpg.h"

typedef struct hub {
    sfIntRect rect;
    sfSprite *sprite_perso;
    sfTexture *texture_perso;
    sfTexture *texture_hub;
    sfSprite *sprite_hub;
    sfVector2f movement;
    sfTime time;
    sfImage *hitbox;
    sfVector2f pos_sprite;
    sfColor color;
    sfView *view;
    sfView *normal_view;
    sfSprite *pouilleux;
    sfTexture *Pouilleux;
    sfSprite *bulle;
    sfTexture *Bulle;
    sfSprite *dia_pouill;
    sfTexture *Dia_pouill;
    sfSprite *cadre;
    sfTexture *Cadre;
    sfTexture *Cadre2;
    sfIntRect rect_dia;
    sfClock *clock;
    bool is_talking;
    bool prologue_ok;
    sfClock *swap_clock;
    int what_word;
} hub_t;

typedef struct Loading {
    sfSprite *vert;
    sfSprite *fond;
    sfSprite *text;
    sfTexture *Vert;
    sfTexture *Fond;
    sfTexture *Text;
    sfSprite *back_screen;
    sfTexture *Back_screen;
}Loading_t;

typedef struct Shop {
    sfSprite *shop;
    sfTexture *Shop;
    sfRectangleShape *hooved;
    int hovered_index;
    sfSprite *coin;
    sfTexture *Coin;
    sfText *gold;
    sfSprite *fond;
    sfTexture *Fond;
    sfText *text;
    sfFont *Font;
    bool is_select;
    sfSprite *all_head;
    sfSprite *cursor;
    sfSprite *lock;
    bool is_lock;
    sfVector2f cursor_pose;
    int buyer;
    sfSprite *contour;
    sfClock *buy_clock;
    int num_columns;
    int num_rows;
    int spacing_x;
    int spacing_y;
}Shop_t;

typedef struct Zone {
    sfIntRect rect;

    sfSprite *sprite_roy;
    sfSprite *sprite_infe;
    sfSprite *sprite_xmara;
    sfSprite *sprite_pate;
    sfSprite *sprite_raca;
    sfTexture *texture_roy;
    sfTexture *texture_infe;
    sfTexture *texture_xmara;
    sfTexture *texture_pate;
    sfTexture *texture_raca;

    sfSprite *sprite_Boss1;
    sfSprite *sprite_Boss2;
    sfSprite *sprite_Boss3;
    sfSprite *sprite_Boss4;
    sfSprite *sprite_Boss5;
    sfSprite *sprite_Boss6;
    sfSprite *sprite_Boss7;
    sfSprite *sprite_Boss8;
    sfTexture *texture_Boss1;
    sfTexture *texture_Boss2;
    sfTexture *texture_Boss3;
    sfTexture *texture_Boss4;
    sfTexture *texture_Boss5;
    sfTexture *texture_Boss6;
    sfTexture *texture_Boss7;
    sfTexture *texture_Boss8;

    sfSprite *sprite_enemy1_axe;
    sfSprite *sprite_enemy2_axe;
    sfSprite *sprite_enemy3_axe;
    sfSprite *sprite_enemy1_spear;
    sfSprite *sprite_enemy2_spear;
    sfSprite *sprite_enemy3_spear;
    sfSprite *sprite_enemy1_sword;
    sfSprite *sprite_enemy2_sword;
    sfSprite *sprite_enemy3_sword;
    sfSprite *sprite_enemy_mage;
    sfTexture *texture_enemy1_axe;
    sfTexture *texture_enemy2_axe;
    sfTexture *texture_enemy3_axe;
    sfTexture *texture_enemy1_spear;
    sfTexture *texture_enemy2_spear;
    sfTexture *texture_enemy3_spear;
    sfTexture *texture_enemy1_sword;
    sfTexture *texture_enemy2_sword;
    sfTexture *texture_enemy3_sword;
    sfTexture *texture_enemy_mage;
}ZoneUniversel_t;

typedef struct Zone1 {
    sfView *view_w1;
    sfSprite *w1_map;
    sfTexture *w1_Map;
    bool is_w1_clear;
    char **tab_map;
}Zone1_t;

typedef struct Zone2 {
    /* data */
    sfSprite *w2_map;
    sfTexture *w2_Map;
    bool is_w2_clear;
}Zone2_t;

typedef struct Zone3 {
    /* data */
    sfSprite *w3_map;
    sfTexture *w3_Map;
    bool is_w3_clear;
}Zone3_t;

typedef struct Zone4 {
    /* data */
    sfSprite *w4_map;
    sfTexture *w4_Map;
    bool is_w4_clear;
}Zone4_t;

typedef struct Zone5 {
    /* data */
    sfSprite *w5_map;
    sfTexture *w5_Map;
    bool is_w5_clear;
}Zone5_t;

typedef struct Zone6 {
    /* data */
    sfSprite *w6_map;
    sfTexture *w6_Map;
    bool is_w6_clear;
}Zone6_t;

typedef struct Zone7 {
    /* data */
    sfSprite *w7_map;
    sfTexture *w7_Map;
    bool is_w7_clear;
}Zone7_t;

typedef struct Zone8 {
    /* data */
    sfSprite *w8_map;
    sfTexture *w8_Map;
    bool is_w8_clear;
}Zone8_t;

#endif
