/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** print_tools.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"

static sfText *init_stats(Global_t *m, int w)
{
    m->shop.Font = sfFont_createFromFile("assets/font.ttf");
    m->shop.text = sfText_create();
    char str[30];

    sprintf(str, "%d", m->weapons[w].attack);
    sfText_setFont(m->shop.text, m->shop.Font);
    sfText_setString(m->shop.text, str); // Définissez le contenu de votre texte ici
    sfText_setColor(m->shop.text, sfRed);
    sfText_setCharacterSize(m->shop.text, 18); // Définissez la taille des caractères de votre texte
    sfText_setPosition(m->shop.text, (sfVector2f){40, 40}); // Définissez la position de votre texte
    if (m->shop.text != NULL)
        sfRenderWindow_drawText(m->window, m->shop.text, NULL);
    // sfText_destroy(m->shop.text);
    // sfFont_destroy(m->shop.Font);
    return m->shop.text;
}

static void draw_stats_shop(Global_t *m)
{
    init_stats(m, COMMON_SWORD);
    if (m->shop.hovered_index == 0) // COM SOWRD
        init_stats(m, COMMON_SWORD);
    if (m->shop.hovered_index == 1)
        init_stats(m, COMMON_BOW);
    if (m->shop.hovered_index == 2)
        init_stats(m, COMMON_SPEAR);
    if (m->shop.hovered_index == 3)
        init_stats(m, COMMON_AXE);
    if (m->shop.hovered_index == 4)
        init_stats(m, RARE_SWORD);
    if (m->shop.hovered_index == 5)
        init_stats(m, RARE_BOW);
    if (m->shop.hovered_index == 6)
        init_stats(m, RARE_SPEAR);
    if (m->shop.hovered_index == 7)
        init_stats(m, RARE_AXE);
    if (m->shop.hovered_index == 8)
        init_stats(m, LEGENDARY_SWORD);
    if (m->shop.hovered_index == 9)
        init_stats(m, LEGENDARY_BOW);
    if (m->shop.hovered_index == 10)
        init_stats(m, LEGENDARY_SPEAR);
    if (m->shop.hovered_index == 11)
        init_stats(m, LEGENDARY_AXE);
    if (m->shop.hovered_index == 12)
        init_stats(m, THUNDER_BOOK);
    if (m->shop.hovered_index == 13)
        init_stats(m, FIRE_BOOK);
    if (m->shop.hovered_index == 14)
        init_stats(m, FREEZE_BOOK);
    if (m->shop.hovered_index == 15)
        init_stats(m, POTION);
}

void move_coin(Global_t *m)
{
    static sfClock *clock = NULL;
    static sfIntRect rect = {0, 0, 16, 16};
    sfTime time;
    float seconds;

    if (clock == NULL)
        clock = sfClock_create();
    time = sfClock_getElapsedTime(clock);
    seconds = sfTime_asSeconds(time);
    if (seconds > 0.1) {
        rect.left += 16;
        if (rect.left >= 144)
            rect.left = 0;
        sfSprite_setTextureRect(m->shop.coin, rect);
        sfClock_restart(clock);
    }
    sfSprite_setPosition(m->shop.coin, (sfVector2f){627, 195});
    sfSprite_setScale(m->shop.coin, (sfVector2f){1.2, 1.2});
    sfRenderWindow_drawSprite(m->window, m->shop.coin, NULL);
    sfSprite_setPosition(m->shop.coin, (sfVector2f){500, 370});
    sfRenderWindow_drawSprite(m->window, m->shop.coin, NULL);
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) >= 0.1f) {
        sfClock_destroy(clock);
        clock = NULL;
    }
}

void move_hover_rect(Global_t *m, int direction)
{
    const int num_columns = 4;
    const int num_rows = 4;
    const int spacing_x = 30;
    const int spacing_y = 30;
    const float move_speed = 0.15f;
    int current_index = m->shop.hovered_index;
    int new_index = current_index;
    static sfClock *clock = NULL;
    sfTime elapsed;
    float elapsed_seconds;

    if (!clock)
        clock = sfClock_create();
    elapsed = sfClock_getElapsedTime(clock);
    elapsed_seconds = sfTime_asSeconds(elapsed);
    if (elapsed_seconds < move_speed)
        return;
    sfClock_restart(clock);
    switch (direction) {
        case sfKeyLeft:
            new_index--;
            break;
        case sfKeyRight:
            new_index++;
            break;
        case sfKeyUp:
            new_index -= num_columns;
            break;
        case sfKeyDown:
            new_index += num_columns;
            break;
    }
    if (new_index < 0 || new_index >= num_columns * num_rows)
        return;
    if (clock != NULL) {
        sfClock_destroy(clock);
        clock = NULL;
    }
    int row = new_index / num_columns;
    int column = new_index % num_columns;
    sfVector2f current_position = sfSprite_getPosition(m->weapons[8].sprite);
    sfVector2f new_position = {
        420 + column * (current_position.x - 420 + spacing_x),
        245 + row * (current_position.y - 245 + spacing_y)
    };
    sfRectangleShape_setPosition(m->shop.hooved, new_position);
    m->shop.hovered_index = new_index;
    draw_stats_shop(m);
}
