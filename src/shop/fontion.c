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

static int check_buy_delay(Global_t *m)
{
    sfTime elapsed_time;
    float seconds;

    if (!m->shop.buy_clock) {
        m->shop.buy_clock = sfClock_create();
    }
    elapsed_time = sfClock_getElapsedTime(m->shop.buy_clock);
    seconds = sfTime_asSeconds(elapsed_time);
    if (seconds >= 0.5f) {
        sfClock_restart(m->shop.buy_clock);
        return 1;
    } else {
        return 0;
    }
}

sfText *init_stats(Global_t *m, int w)
{
    char str[50];
    int atk = m->weapons[w].attack;
    int rng = m->weapons[w].rng;
    int crit = m->weapons[w].crit;
    int acc = m->weapons[w].accuracy;
    int cost = m->weapons[w].cost;

    if (m->shop.text != NULL) {
        sfText_destroy(m->shop.text);
        m->shop.text = NULL;
    }
    if (m->shop.Font != NULL) {
        sfFont_destroy(m->shop.Font);
        m->shop.Font = NULL;
    }
    m->shop.Font = sfFont_createFromFile("assets/font.ttf");
    m->shop.text = sfText_create();
    sprintf(str, "%d\n\n%d\n\n%d\n\n%d\n\n%s%s%d", atk, rng, crit, acc, TABS_5, TABS_6, cost);
    sfText_setFont(m->shop.text, m->shop.Font);
    sfText_setString(m->shop.text, str);
    sfText_setColor(m->shop.text, sfRed);
    sfText_setCharacterSize(m->shop.text, 18);
    sfText_setPosition(m->shop.text, (sfVector2f){235, 265});
    if (m->weapons[w].cost > m->gold)
        sfRenderWindow_drawSprite(m->window, m->shop.lock, NULL);
    if ((sfKeyboard_isKeyPressed(sfKeyB)) && check_buy_delay(m)) {
        if (m->weapons[w].cost < m->gold && m->perso->num_weapons_in_inv < 5)
            import_weapon_inv(m, w);
    }
    return m->shop.text;
}

void draw_stats_shop(Global_t *m)
{
    if (m->shop.hovered_index == 0)
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
    sfSprite_setPosition(m->shop.coin, (sfVector2f){500, 375});
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
    int current_index = m->shop.hovered_index;
    int new_index = current_index;
    static sfClock *clock = NULL;
    sfTime elapsed;
    float elapsed_seconds;

    if (!clock)
        clock = sfClock_create();
    elapsed = sfClock_getElapsedTime(clock);
    elapsed_seconds = sfTime_asSeconds(elapsed);
    if (elapsed_seconds < 0.15f)
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
    sfSprite_setPosition(m->shop.lock, new_position);
    m->shop.hovered_index = new_index;
}
