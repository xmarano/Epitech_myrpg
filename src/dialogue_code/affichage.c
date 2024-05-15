/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "../rpg.h"
#include <ctype.h>

void drawText(const char *str, int x, int y, sfRenderWindow *window, sfFont *font)
{
    sfText *text = sfText_create();
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 20);
    sfVector2f position = {x, y};
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
}

void wordpt(char *str, sfRenderWindow *window, sfFont *font, const char *num, int position)
{
    char *phrase = malloc(strlen(str) + 1);
    strcpy(phrase, "");

    for (int i = 0; i < strlen(str); i++) {
        strncat(phrase, &str[i], 1);
        if (position == 0) { // current_perso
            drawText(num, 0, sfRenderWindow_getSize(window).y - 30, window, font);
            sentencept(phrase, window, font, 0, 30);
        } else { // speaker
            drawText(num, sfRenderWindow_getSize(window).x - 30, sfRenderWindow_getSize(window).y - 30, window, font);
            sentencept(phrase, window, font, sfRenderWindow_getSize(window).x - 30, 30);
        }
        if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
            sentencept(str, window, font, position, 30);
            sfSleep(sfSeconds(2.0));
            free(phrase);
            return;
        }
    }
    sentencept(str, window, font, position, 30);
    sfSleep(sfSeconds(2.0));
    free(phrase);
}

void sentencept(char *phrase, sfRenderWindow *window, sfFont *font, int x, int y)
{
    sfRenderWindow_clear(window, sfBlack);
    sfText *text = sfText_create();
    sfText_setString(text, phrase);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 20);
    sfVector2f position = {x, y};
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(window, text, NULL);
    sfRenderWindow_display(window);
    sfSleep(sfSeconds(0.1));
    sfText_destroy(text);
}


void parseFile(const char *filename, sfRenderWindow *window, sfFont *font, int current_perso)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier %s\n", filename);
        return;
    }
    char line[256];
    char last_speaker[256] = "";
    while (fgets(line, sizeof(line), file)) {
        if (strchr(line, '*') != NULL) {
            break;
        }
        char *speaker = strtok(line, ":");
        char *dialogue = strtok(NULL, "\n");
        if (dialogue != NULL && (atoi(speaker) == current_perso || !isdigit(speaker[0]))) {
            strcpy(last_speaker, speaker);
            int position = atoi(speaker) == current_perso ? 0 : 1;
            wordpt(dialogue, window, font, last_speaker, position);
        }
    }
    fclose(file);
}


// m.perso->current_perso = 4;
//sfFont* font = sfFont_createFromFile("assets/text.ttf");