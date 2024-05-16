/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "rpg.h"
#include "include/perso.h"
#include "include/menu.h"

void annihilateur2sprite(Global_t *m, hub_t *h, fight_t *f)
{
    destroy_hub(m, h);
    printf("hub_destroyed\n");
    destroy_fight_struct(f);
    printf("fight_destroyed\n");
    destroy_inventaire(m);
    printf("inv_destroyed\n");
    destroy_menu(m);
    printf("menu_destroyed\n");
    destroy_shop(m);
    printf("shop_destroyed\n");
    destory_all_w_maps(m);
    printf("maps_destroyed\n");
    destroy_select_perso(m);
    printf("selet_destroyed\n");
    destroy_loading(m);
    printf("load_destroyed\n");
    destroy_dialoque(m);
    printf("dialogue_destroyed\n");
}

void event_click(Global_t *m, hub_t *h, fight_t *f)
{
    if (m->event.type == sfEvtClosed || m->current == -1) {
        annihilateur2sprite(m, h, f);
        sfRenderWindow_close(m->window);
        sfRenderWindow_destroy(m->window);
        printf("window_destroyed\n");
    }
    printf("here\n");
    if (m->current == 12)
        inventory(m, m->event);
    if (m->current == 13)
        event_setting(m->event, m);
    if (sfKeyboard_isKeyPressed(sfKeyU) == sfTrue && m->current != 100)
        m->current = 100;
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue) {
        m->perso->current_perso = 3;
        parseFile("dialogue/chap1.txt", m->window, m->setting.fontdi, m->perso->current_perso);
    }
}

static void draw_mondes(Global_t *m, hub_t *h)
{
    draw_monde1(m, h);
}

void rpg(Global_t *m, hub_t *h, fight_t *f)
{
    m->show_mouse = true;
    m->mouse = sfMouse_getPositionRenderWindow(m->window);
    sfRenderWindow_clear(m->window, sfBlack);
    while (sfRenderWindow_pollEvent(m->window, &m->event))
        event_click(m, h, f);
    draw_menu(m);
    draw_select_perso(m);
    draw_setting(m);
    draw_mondes(m, h);
    draw_shop(m);
    draw_hub(m, h);
    draw_inventaire(m);
    draw_mouse(m);
    //print_fight_scene(m, f, &m->perso[ROY], &m->perso[ENEMY1_AXE]);
    loading_screen(m);
    sfRenderWindow_display(m->window);
}

static void initalisateur2sprite(Global_t *m, hub_t *h)
{
    import_weapons_stats(m);
    init_pouill_dialog(m);
    init_hub(h, m);
    setup_stat(m);
    init_w_sprite(m);
    init_menu(m);
    init_inventaire(m);
    init_shop(m);
    init_pose(m);
    init_loading(m);
}

int main(int argc, char **argv)
{
    Global_t m = {0};
    hub_t h = {0};
    fight_t f = {0};
    sfVideoMode mode = {1920, 1080, 32};

    if (argc != 1)
        return 84;
    m.window = sfRenderWindow_create(mode, "My Rpg", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(m.window, 60);
    initalisateur2sprite(&m, &h);
    init_select_perso(&m);
    init_lifebars(&f, &m);
    set_dmg(&f, &m, &m.perso[ROY], &m.perso[ENEMY1_AXE]);
    while (sfRenderWindow_isOpen(m.window)) {
        rpg(&m, &h, &f);
    }
    annihilateur2sprite(&m, &h, &f);
    free(m.zone1.tab_map);
    destroy_hub(&m, &h);
    destroy_fight_struct(&f);
    annihilateur2sprite(&m);
    sfClock_destroy(m.clock);
    sfSprite_destroy(m.menu.cursor);
    sfRenderWindow_destroy(m.window);
    return 0;
}
