/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "rpg.h"
#include "include/perso.h"
#include "include/menu.h"

void moveCharacter(Global_t *m, sfSprite *character, sfIntRect *rect) {
    sfVector2f movement = {0, 0};
    int tic = 0;

    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        movement.y -= SPEED;
        rect->top = 520;
        tic = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        movement.y += SPEED;
        rect->top = 520 + 65 * 2;
        tic = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        movement.x -= SPEED;
        rect->top = 520 + 65;
        tic = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        movement.x += SPEED;
        rect->top = 520 + 65 * 3;
        tic = 1;
    }
    sfTime time = sfClock_getElapsedTime(m->clock);
    float seconds;

    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.09) {
        if (rect->left < (64 * 8) && tic == 1)
            rect->left += 64;
        else
            rect->left = 0;
        sfClock_restart(m->clock);
    }
    sfSprite_move(character, movement);
    sfSprite_setTextureRect(character, *rect);
    sfRenderWindow_drawSprite(m->window, character, NULL);
}

void event_click(sfEvent event, Global_t *m)
{
    if (event.type == sfEvtClosed || m->current == -1)
        sfRenderWindow_close(m->window);
    inventory(m, event);
    if (m->current == 13)
        event_setting(event, m);
}

void clock(Global_t *m)
{
    sfTime time = sfClock_getElapsedTime(m->clock);
    float seconds;

    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        sfClock_restart(m->clock);
    }
}

void rpg(Global_t *m, sfSprite *sprite_perso, sfIntRect *rect)
{
    sfEvent event;

    m->show_mouse = true;
    m->mouse = sfMouse_getPositionRenderWindow(m->window);
    sfRenderWindow_clear(m->window, sfWhite);
    while (sfRenderWindow_pollEvent(m->window, &event))
        event_click(event, m);
    //clock(m);
    draw_menu(m);
    draw_setting(m);
    draw_inventaire(m);
    draw_mouse(m);
    moveCharacter(m, sprite_perso, rect);
    sfRenderWindow_display(m->window);
}

int main(int argc, char **argv)
{
    Global_t m = {0};
    sfVideoMode mode = {1920, 1080, 32};

    if (argc != 1)
        return 84;
    m.window = sfRenderWindow_create(mode, "My Rpg", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(m.window, 60);
    import_weapons_stats(&m);
    setup_stat(&m);
    init_menu(&m);
    init_setting(&m);
    init_inventaire(&m);
    //------------------------------------------------------------------------------------------------
    sfIntRect rect = {0, 520 + 65 * 2, 65, 65};                                                   //  |
    sfSprite *sprite_perso = sfSprite_create();                                                   //  |
    sfTexture *texture_perso = sfTexture_createFromFile(m.perso[XMARANO].texture_battle, NULL);//  |
    sfSprite_setTexture(sprite_perso, texture_perso, sfTrue);                                     //  |
    sfSprite_setTextureRect(sprite_perso, rect);                                                  //  |
    //------------------------------------------------------------------------------------------------
    while (sfRenderWindow_isOpen(m.window))
        rpg(&m, sprite_perso, &rect);
    //-----------------------------------
    sfSprite_destroy(sprite_perso);  //  |
    sfTexture_destroy(texture_perso);//  |
    //-----------------------------------
    destroy_menu(&m);
    sfRenderWindow_destroy(m.window);
    return 0;
}
