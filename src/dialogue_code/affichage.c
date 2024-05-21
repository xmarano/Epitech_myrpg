/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "../rpg.h"
#include <ctype.h>

void drawText(const char *str, int x, int y, RenderContext *context)
{
    sfText *text = sfText_create();
    sfText_setString(text, str);
    sfText_setFont(text, context->font);
    sfText_setCharacterSize(text, 20);
    sfVector2f position = {x, y};
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(context->window, text, NULL);
    sfText_destroy(text);
}

void sentencept(char *phrase, RenderContext *context, int x, int y)
{
    sfRenderWindow_clear(context->window, sfBlack);
    sfText *text = sfText_create();
    sfText_setString(text, phrase);
    sfText_setFont(text, context->font);
    sfText_setCharacterSize(text, 20);
    sfVector2f position = {x, y};
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(context->window, text, NULL);
    sfRenderWindow_display(context->window);
    sfSleep(sfSeconds(0.1));
    sfText_destroy(text);
}

void wordpt(char *str, RenderContext *context, const char *num, int position)
{
    char *phrase = malloc(strlen(str) + 1);
    strcpy(phrase, "");
    int window_width = sfRenderWindow_getSize(context->window).x;
    int window_height = sfRenderWindow_getSize(context->window).y;

    for (int i = 0; i < strlen(str); i++) {
        strncat(phrase, &str[i], 1);
        if (position == 0) {
            drawText(num, 0, window_height - 30, context);
            sentencept(phrase, context, 0, 30);
            if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
                sentencept(str, context, position, 30);
                sfSleep(sfSeconds(1.0));
                free(phrase);
                return;
            }
        } else {
            drawText(num, window_width - 600, window_height - 600, context);
            sentencept(phrase, context, window_width - 600, 30);
            if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
                sentencept(str, context, window_width - 600, 30);
                sfSleep(sfSeconds(1.0));
                free(phrase);
                return;
            }
        }
    }
    sfSleep(sfSeconds(2.0));
    free(phrase);
}

int verif_parse(char *line, RenderContext *context, int current_perso, char *last_speaker)
{
    char *speaker = strtok(line, ":");
    char *dialogue = strtok(NULL, "\n");

    if (strchr(line, '*') != NULL) {
        return 1;
    }
    if (dialogue != NULL && (atoi(speaker) == current_perso || !isdigit(speaker[0]))) {
        strcpy(last_speaker, speaker);
        int position = atoi(speaker) == current_perso ? 0 : 1;
        wordpt(dialogue, context, last_speaker, position);
    }
    return 0;
}

void parseFile(const char *filename, RenderContext *context, Global_t *m)
{
    FILE *file = fopen(filename, "r");
    char line[256];
    char last_speaker[256] = "";
    
    if (file == NULL) {
        return;
    }
    while (fgets(line, sizeof(line), file)) {
        verif_parse(line, context,  m->perso->current_perso, last_speaker);
    }
    m->dialogue.start_dialogue = 0;
    m->current = 1;
    fclose(file);
}
