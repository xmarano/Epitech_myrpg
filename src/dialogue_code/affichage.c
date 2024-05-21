/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "../rpg.h"
#include <ctype.h>

void draw_dialogue(const char *str, int x, int y, RenderContext_t *context)
{
    sfText *text = sfText_create();
    sfText_setString(text, str);
    sfText_setFont(text, context->font);
    sfText_setCharacterSize(text, 30);
    sfText_setColor(text, sfBlack);
    sfVector2f position = {x, y};
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(context->window, text, NULL);
    sfText_destroy(text);
}

void sentencept(char *phrase, RenderContext_t *context, int x, int y)
{
    sfTexture* texture = sfTexture_createFromFile("src/dialogue_code/walltom.png", NULL);
    sfSprite* sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(context->window, sprite, NULL);
    sfText *text = sfText_create();
    sfText_setString(text, phrase);
    sfText_setFont(text, context->font);
    sfText_setCharacterSize(text, 30);
     sfText_setColor(text, sfBlack);
    sfVector2f position = {x, y};
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(context->window, text, NULL);
    sfRenderWindow_display(context->window);
    sfSleep(sfSeconds(0.1));
    sfText_destroy(text);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}


void wordpt(char *str, RenderContext_t *context, const char *num, int position)
{
    char *phrase = malloc(strlen(str) + 1);
    int window_width = sfRenderWindow_getSize(context->window).x;
    int window_height = sfRenderWindow_getSize(context->window).y;

    strcpy(phrase, "");
    for (int i = 0; i < strlen(str); i++) {
        strncat(phrase, &str[i], 1);
        if (position == 0) {
            draw_dialogue(num, 25, window_height - 30, context);
            sentencept(phrase, context, 25, 950);
            if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
                sentencept(str, context, 25, 950);
                sfSleep(sfSeconds(1.0));
                free(phrase);
                return;
            }
        } else {
            draw_dialogue(num, window_width - 520, window_height - 520, context);
            sentencept(phrase, context, window_width - 520, 950);
            if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
                sentencept(str, context, window_width - 520, 950);
                sfSleep(sfSeconds(1.0));
                free(phrase);
                return;
            }
        }
    }
    sfSleep(sfSeconds(2.0));
    free(phrase);
}

int verif_parse(char *line, RenderContext_t *context, int current_perso, char *last_speaker)
{
    char *speaker = strtok(line, ":");
    char *dialogue = strtok(NULL, "\n");
    int position;

    if (strchr(line, '*') != NULL) {
        return 1;
    }
    if (dialogue != NULL && (atoi(speaker) == current_perso ||
    !isdigit(speaker[0]))) {
        strcpy(last_speaker, speaker);
        position = atoi(speaker) == current_perso ? 0 : 1;
        wordpt(dialogue, context, last_speaker, position);
    }
    return 0;
}

void parse_file(const char *filename, RenderContext_t *context, Global_t *m)
{
    FILE *file = fopen(filename, "r");
    char line[256];
    char last_speaker[256] = "";

    if (file == NULL) {
        return;
    }
    while (fgets(line, sizeof(line), file)) {
        if (verif_parse(line, context, m->perso->current_perso, last_speaker) == 1) {
            break;
        }
    }
    m->dialogue.start_dialogue = 0;
    m->current = 1;
    fclose(file);
}
