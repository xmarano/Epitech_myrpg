/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "../rpg.h"

void sentencept(char *phrase, sfRenderWindow *window, sfFont *font)
{
    sfText *text = sfText_create();
    sfText_setString(text, phrase);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 20);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_display(window);
    sfSleep(sfSeconds(0.1));
    sfText_destroy(text);
}

void wordpt(char *str, sfRenderWindow *window, sfFont *font)
{
    char *phrase = malloc(strlen(str) + 1);
    strcpy(phrase, "");

    for (int i = 0; i < strlen(str); i++) {
        strncat(phrase, &str[i], 1);
        sentencept(phrase, window, font);
        if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
            sentencept(str, window, font);
            sfSleep(sfSeconds(2.0));
            free(phrase);
            return;
        }
    }
    sentencept(str, window, font);
    sfSleep(sfSeconds(2.0));
    free(phrase);
}

//sfFont* font = sfFont_createFromFile("assets/text.ttf");
//char str[] = "bonjour voici un test un peu long j'avoue, j'ai pas trop d'idee apres";
//wordpt(str, m.window, font);