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
    #include <time.h>
    #define SPEED 2
    #define FRAME_WIDTH 65
    #define FRAME_HEIGHT 65
    #define TABS_6 "\t\t\t\t\t\t"
    #define TABS_5 "\t\t\t\t\t"
    #define DELAY_BETWEEN_BUYS 100
    #define REFUND 40
    #define set_tx sfTexture_createFromFile
    #define sp_txr sfSprite_setTexture

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
    ENEMY1_SWORD = 13,
    ENEMY2_SWORD = 14,
    ENEMY3_SWORD = 15,
    ENEMY1_SPEAR = 16,
    ENEMY2_SPEAR = 17,
    ENEMY3_SPEAR = 18,
    ENEMY1_AXE = 19,
    ENEMY2_AXE = 20,
    ENEMY3_AXE = 21,
    ENEMY_MAGE = 22,
};

enum WHAT_WEAPONS {
    SLOT1 = 0,
    HEAL = 1,
    SLOT2 = 2,
    SLOT3 = 3,
    SLOT4 = 4,
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
    HEAL_STICK = 28,
    POTION = 29,
};

typedef struct {
    sfRenderWindow *window;
    sfFont *font;
} RenderContext_t;

typedef struct Glob {
    int current;
    int old_current;
    int gold;
    bool load_game_called;
    sfVector2i mouse;
    sfEvent event;
    sfRenderWindow *window;
    Menu_t menu; /* Leo */
    S_t s; /* Leo */
    Option_t o; /* Leo */
    Perso_t perso[23]; /* Yanis */
    Weapons_t weapons[30]; /* Yanis */
    Npc_t npc[20]; /* Yanis */
    Setting_t setting; /* Tom */
    bool show_mouse;
    hub_t hub; /* leo & tom*/
    Loading_t loading; /*Yanis*/
    Dialogue_t dialogue;
    Shop_t shop; /*Yanis*/
    ZoneUniversel_t univ;
    Zone1_t zone1;
    Zone2_t zone2;
    Zone3_t zone3;
    Zone4_t zone4;
    Zone5_t zone5;
    Zone6_t zone6;
    Zone7_t zone7;
    Zone8_t zone8;
} Global_t;

void swap_current(Global_t *m);
void draw_mouse(Global_t *m);
void roy_stats(Perso_t *perso);
void print_boss_barre(Global_t *m, int who, sfView *view);
void xmarano_stats(Perso_t *perso);
void pate_stats(Perso_t *perso);
void infe_stats(Perso_t *perso);
void raca_stats(Perso_t *perso);
int import_weapons_stats(Global_t *m);
void equiped_weapon(Global_t *m, int who);
void check_all_pose(Global_t *m, char **tab, int w);
bool is_empty_slot(Weapons_t *weapon_slo);
void set_stats_b1(Perso_t *perso);
void set_stats_b2(Perso_t *perso);
void set_stats_b3(Perso_t *perso);
void set_stats_b4(Perso_t *perso);
void set_stats_b5(Perso_t *perso);
void set_stats_b6(Perso_t *perso);
void set_stats_b7(Perso_t *perso);
void set_stats_b8(Perso_t *perso);
int setup_stat(Global_t *m);
void init_menu_option(Global_t *m);
void draw_menu_option(Global_t *m, hub_t *hub);
void destroy_menu_option(Global_t *m);
void draw_stats_shop(Global_t *m);
void init_menu(Global_t *m);
void draw_menu(Global_t *m);
void import_weapon_inv(Global_t *m, int w);
void destroy_menu(Global_t *m);
void check_hover_select(Global_t *m);
void init_select_perso(Global_t *m);
void draw_select_perso(Global_t *m);
void destroy_select_perso(Global_t *m);
void destroy_loading(Global_t *m);
void init_loading(Global_t *m);
void loading_screen(Global_t *m);
void save_auto(Global_t *m);
void draw_shop(Global_t *m);
void init_shop(Global_t *m);
void empty_slot(Global_t *m, sfVector2f pose_sp, sfVector2f pose_txt);
void destroy_shop(Global_t *m);
void move_coin(Global_t *m);
void move_hover_rect(Global_t *m, int direction);
void select_perso(Global_t *m);
void init_inventaire(Global_t *m);
void init_pose(Global_t *m);
int inventory(Global_t *m, sfEvent event);
void init_sp_perso_boss(Global_t *m);
sfSprite *init_sprite(char *filename, sfVector2f pos);
sfText *init_text(Global_t *m, char *str, int size, int pos_y);
sfRectangleShape *init_button(Global_t *m, sfVector2f size, int pos_y);
void hover(Global_t *m, sfRectangleShape *shape, sfFloatRect *rect);
void click(Global_t *m, sfFloatRect *rect, int current);
void init_setting(Global_t *m);
void draw_setting(Global_t *m);
void return_and_old_current(Global_t *m, int value);
sfText *init_stats(Global_t *m, int w);
void draw_inventaire(Global_t *m, hub_t *hub);
void event_setting(sfEvent event, Global_t *m);
int set_boss(Global_t *m);
void set_enemy(Global_t *m);
void init_enemy1_axe(Perso_t *perso, char *name, Weapons_t weapon);
void init_enemy2_axe(Perso_t *perso, char *name, Weapons_t weapon);
void init_enemy3_axe(Perso_t *perso, char *name, Weapons_t weapon);
void init_enemy_mage(Perso_t *perso, char *name, Weapons_t weapon);
void init_hub(hub_t *h, Global_t *m);
void passages_mondes(Global_t *m, hub_t *hub);
void draw_hub(Global_t *m, hub_t *h);
void movecharacter(Global_t *m, hub_t *hub);
void destroy_hub(Global_t *m, hub_t *h);
void set_sprite_head_name(Global_t *m, int who);
void set_text_health(Global_t *m, int who);
void set_sprite_mini(Global_t *m, int who);
void set_text_lvl_xd(Global_t *m, int who);
void draw_plus(Global_t *m);
void draw_all_shop(Global_t *m);
void set_others_stats(Global_t *m, int who);
sfSprite *set_inv_fond(Global_t *m);
sfSprite *set_inv_fond2(Global_t *m);
sfSprite *set_cursor(Global_t *m);
void weapons_inv_stat(Global_t *m);
void print_weapon5_stat(Global_t *m, int who);
void print_weapon4_stat(Global_t *m, int who);
void print_weapon3_stat(Global_t *m, int who);
void print_heal_stat(Global_t *m, int who);
void print_weapon1_stat(Global_t *m, int who);
void equiped_weapon(Global_t *m, int who);
void check_globalbounds2(Global_t *m);
void check_the_hover2(Global_t *m);
sfRectangleShape *hoov_inv(Global_t *m, sfVector2f popo,
    sfVector2f siz, float f);
sfRectangleShape *hoov_w(Global_t *m, sfVector2f popo,
    sfVector2f siz, float f);
void destroy_inventaire(Global_t *m);
void readdialoguefromfile(Global_t *m, char *filename,
    char array[MAX_LINES][MAX_CHARS]);
void displaydialogue(Global_t *m, hub_t *hub, int word,
    char array[MAX_LINES][MAX_CHARS]);
sfRectangleShape *init_button2(Global_t *m, sfVector2f size, sfVector2f pos);
sfText *init_text2(sfFont *font, const char *str, int size, sfVector2f pos);
void init_setting3(Global_t *m);
void init_setting2(Global_t *m);
void init_setting(Global_t *m);
void print_save_txt(Global_t *m);
void diff_size(sfVector2i mouse, Global_t *m);
void modify_size(sfVector2i mouse, Global_t *m);
void other_option(sfVector2i mouse, Global_t *m);
void event_setting(sfEvent event, Global_t *m);
void verif_other(Global_t *m);
void verif_thing(Global_t *m);
void synopsis_bool(Global_t *m);
void destroy_all(Global_t *m);
void verif_song(sfVector2i mouse, Global_t *m);
void wordpt(char *str, RenderContext_t *context, const char *num, int position);
void parse_file(const char *filename, RenderContext_t *context, Global_t *m);
void sentencept(char *phrase, RenderContext_t *context, int x, int y);
void draw_dialogue(const char *str, int x, int y, RenderContext_t *context);
void init_pouill_dialog(Global_t *m);
void draw_pouill_dia(Global_t *m, int word, sfVector2f pose, hub_t *hub);
void destroy_dialoque(Global_t *m);
void false_to_true(hub_t *hub);
void passages_mondes5(Global_t *m, hub_t *hub);
void passages_mondes6(Global_t *m, hub_t *hub);
void passages_mondes7(Global_t *m, hub_t *hub);
void passages_mondes8(Global_t *m, hub_t *hub);
void what_dialogue(Global_t *m, int word, hub_t *hub, sfVector2f pose);
void init_w_sprite(Global_t *m);
void destory_all_w_maps(Global_t *m);
void check_position(char **map, char ref, sfSprite *sprite, Global_t *m);
void load_game(Global_t *m, hub_t *hub);
void save_game(Global_t *m);
void update_move_cursor(sfVector2f pos_cursor, Global_t *m);
void move_game_cursor(Global_t *m);
void draw_possible_movement(Global_t *m, sfSprite *spr, Perso_t *perso);
bool is_movement_ok(sfVector2f pos_spr, sfVector2f pos_obj, int i, Global_t *m);
void draw_player_interface(Global_t *m);

    #include "include/fight.h"

void draw_monde1(Global_t *m, fight_t *f);
void print_mini_barre(Global_t *m, fight_t *f);
void print_mini_barre(Global_t *m, fight_t *f);
void draw_monde2(Global_t *m, fight_t *f);
void draw_monde3(Global_t *m, fight_t *f);
void draw_monde4(Global_t *m, fight_t *f);
void draw_monde5(Global_t *m, fight_t *f);
void draw_monde6(Global_t *m, fight_t *f);
void draw_monde7(Global_t *m, fight_t *f);
void draw_monde8(Global_t *m, fight_t *f);

#endif