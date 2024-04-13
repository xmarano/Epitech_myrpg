/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "rpg.h"

void rpg(sfRenderWindow *window, Sprite_t *s)
{
    sfEvent event;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    s->pos = sfRenderWindow_mapPixelToCoords(window, mouse, NULL);
    my_printf("(x : %d)(y : %d)\n", mouse.x, mouse.y);
    sfRenderWindow_clear(window, sfBlack);
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    sfRenderWindow_drawText(window, s->test, NULL);
    sfRenderWindow_display(window);
}

sfText *init_text(char *str, int size, sfVector2f pos)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/text.ttf");

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, sfWhite);
    sfText_setString(text, str);
    sfText_setPosition(text, pos);
    return text;
}

void text(sfRenderWindow *window, Sprite_t *s)
{
    s->test = init_text("MY RPG", 50, (sfVector2f){30, 12});
}

int main(int argc, char **argv)
{
    Sprite_t s;
    sfVideoMode mode = {1920 / 3, 1080 / 3, 32};
    sfRenderWindow *window;

    if (argc != 1)
        return 84;
    window = sfRenderWindow_create(mode, "My Rpg", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    text(window, &s);
    while (sfRenderWindow_isOpen(window))
        rpg(window, &s);
    sfRenderWindow_destroy(window);
    return 0;
}
