/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "rpg.h"
#include "include/perso.h"
#include "include/menu.h"
#include "my.h"

static void init_dev(int argc, char **argv, Global_t *m, hub_t *h)
{
    m->show_mouse = true;
    if (argc == 2) {
        if (strcmp(argv[1], "dev") == 0) {
            m->gold = 100000;
            m->hub.prologue_ok = true;
            m->current = 0;
        }
    }
}

void event_click(Global_t *m, hub_t *h, fight_t *f)
{
    if (m->current == 12 && m->load_game_called == false) {
        load_game(m, h);
        m->load_game_called = true;
    }
    if (m->event.type == sfEvtClosed || m->current == -1)
        sfRenderWindow_close(m->window);
    if (m->current == 0 || m->current == 1)
        inventory(m, m->event);
    if (m->current == 13)
        event_setting(m->event, m);
    if (sfKeyboard_isKeyPressed(sfKeyU) == sfTrue && m->current != 100)
        m->current = 100;
    if (sfKeyboard_isKeyPressed(sfKeyW) == sfTrue) {
        m->perso->current_perso = 3;
        RenderContext context = {m->window, m->setting.fontdi};
        parseFile("dialogue/chap1.txt", &context, m->perso->current_perso);
    }
}

static void draw_mondes(Global_t *m, hub_t *h)
{
    draw_monde1(m);
    draw_monde2(m);
    draw_monde3(m);
    draw_monde4(m);
    draw_monde5(m);
    draw_monde6(m);
    draw_monde7(m);
    draw_monde8(m);
}

void rpg(Global_t *m, hub_t *h, fight_t *f)
{
    m->mouse = sfMouse_getPositionRenderWindow(m->window);
    sfRenderWindow_clear(m->window, sfBlack);
    while (sfRenderWindow_pollEvent(m->window, &m->event))
        event_click(m, h, f);
    draw_menu(m);
    draw_select_perso(m);
    draw_menu_option(m, h);
    draw_setting(m);
    draw_mondes(m, h);
    draw_shop(m);
    draw_hub(m, h);
    draw_inventaire(m, h);
    draw_mouse(m);
    //print_fight_scene(m, f, &m->perso[ROY], &m->perso[ENEMY1_AXE]);
    loading_screen(m);
    sfRenderWindow_display(m->window);
}

void annihilateur2sprite(Global_t *m, hub_t *h, fight_t *f)
{
    destroy_hub(m, h);
    destroy_fight_struct(f);
    destroy_inventaire(m);
    destroy_menu(m);
    destroy_select_perso(m);
    destroy_menu_option(m);
    destroy_shop(m);
    destory_all_w_maps(m);
    destroy_loading(m);
    destroy_dialoque(m);
}

static void initalisateur2sprite(Global_t *m, hub_t *h, fight_t *f)
{
    import_weapons_stats(m);
    init_pouill_dialog(m);
    init_hub(h, m);
    setup_stat(m);
    init_w_sprite(m);
    init_menu(m);
    init_select_perso(m);
    init_menu_option(m);
    init_inventaire(m);
    init_shop(m);
    init_pose(m);
    init_loading(m);
    init_lifebars(f, m);
}

int main(int argc, char **argv)
{
    Global_t m = {0};
    hub_t h = {0};
    fight_t f = {0};
    sfVideoMode mode = {1920, 1080, 32};

    if (argc >= 3)
        return 84;
    m.window = sfRenderWindow_create(mode, "My Rpg", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(m.window, 60);
    initalisateur2sprite(&m, &h, &f);
    set_dmg(&f, &m, &m.perso[ROY], &m.perso[ENEMY1_AXE]);
    init_dev(argc, argv, &m, &h);
    while (sfRenderWindow_isOpen(m.window)) {
       rpg(&m, &h, &f);
    }
    annihilateur2sprite(&m, &h, &f);
    sfRenderWindow_destroy(m.window);
    return 0;
}
