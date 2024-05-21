/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** player_interface.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"

void dest_p_interface(Global_t *m)
{
    //,nest
}

void init_player_interface(Global_t *m)
{
    m->univ.interface.fond_interf = sfSprite_create();
    m->univ.interface.Fond_interf = sfTexture_createFromFile("assets/fight/fond_interface.png", NULL);
    m->univ.interface.cursor = sfSprite_create();
    m->univ.interface.Cursor =sfTexture_createFromFile("assets/inv/cursor.png", NULL);
    sfSprite_setTexture(m->univ.interface.fond_interf, m->univ.interface.Fond_interf, sfFalse);
    sfSprite_setTexture(m->univ.interface.cursor, m->univ.interface.Cursor, sfFalse);
    sfSprite_setScale(m->univ.interface.cursor, (sfVector2f){0.2, 0.2});
}

void place_interface(Global_t *m)
{
    sfVector2f pose_sp;

    if (m->univ.interface.who == 0)
        pose_sp = sfSprite_getPosition(m->univ.spr_roy);
    if (m->univ.interface.who == 1)
        pose_sp = sfSprite_getPosition(m->univ.spr_infe);
    if (m->univ.interface.who == 2)
        pose_sp = sfSprite_getPosition(m->univ.spr_pate);
    if (m->univ.interface.who == 3)
        pose_sp = sfSprite_getPosition(m->univ.spr_xmara);
    if (m->univ.interface.who == 4)
        pose_sp = sfSprite_getPosition(m->univ.spr_raca);
    pose_sp.x += 50;
    pose_sp.y -= 90;
    sfSprite_setPosition(m->univ.interface.fond_interf, pose_sp);
    sfRenderWindow_drawSprite(m->window, m->univ.interface.fond_interf, NULL);
}

void moove_cursor(Global_t *m)
{
    sfVector2f pose_curs;
    static int cursor_position = 0;
    const int max_position = 2;
    const float y_increment = 48.0f;
    const float initial_y = 48.0f;
    static sfClock *clock = NULL;
    const float move_delay = 0.2f;
    if (!clock)
        clock = sfClock_create();
    sfTime time = sfClock_getElapsedTime(clock);
    float elapsed_seconds = sfTime_asSeconds(time);
    static int where = 0;

    pose_curs = sfSprite_getPosition(m->univ.interface.fond_interf);
    pose_curs.x += 18;
    pose_curs.y += initial_y + (cursor_position * y_increment);
    if (elapsed_seconds > move_delay) {
        if (sfKeyboard_isKeyPressed(sfKeyDown)) {
            cursor_position++;
            where++;
            if (cursor_position > max_position) {
                cursor_position = 0;
                where = 0;
            }
            sfClock_restart(clock);
        } else if (sfKeyboard_isKeyPressed(sfKeyUp)) {
            cursor_position--;
            where++;
            if (cursor_position < 0) {
                cursor_position = max_position;
            }
            sfClock_restart(clock);
        }
    }
    sfSprite_setPosition(m->univ.interface.cursor, pose_curs);
    sfRenderWindow_drawSprite(m->window, m->univ.interface.cursor, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyEnter) && where == 0) {
        m->univ.interface.select_inteface = false;
        m->perso->case_visble = false;
    }
}

void draw_player_interface(Global_t *m)
{
    if (m->univ.interface.select_inteface) {
        place_interface(m);
        moove_cursor(m);
    }
}
