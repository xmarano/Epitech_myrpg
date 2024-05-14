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

void wordpt(char *str, sfRenderWindow *window, sfFont *font, const char *num)
{
    char *phrase = malloc(strlen(str) + 1);
    strcpy(phrase, "");

    for (int i = 0; i < strlen(str); i++) {
        strncat(phrase, &str[i], 1);
        drawText(num, 0, sfRenderWindow_getSize(window).y - 30, window, font);
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

void parseFile(const char *filename, sfRenderWindow *window, sfFont *font, int current_perso)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier %s\n", filename);
        return;
    }
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        int num = atoi(strtok(line, ":"));
        char *dialogue = strtok(NULL, "\n");
        if (dialogue != NULL && num == current_perso) {
            char str_num[10];
            sprintf(str_num, "%d", num);
            wordpt(dialogue, window, font, str_num);
            drawText(str_num, 0, sfRenderWindow_getSize(window).y - 30, window, font);
            sentencept(str_num, window, font);
        }
    }
    fclose(file);
}

// m.perso->current_perso = 4;
//sfFont* font = sfFont_createFromFile("assets/text.ttf");