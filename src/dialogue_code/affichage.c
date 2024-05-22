/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "../rpg.h"
#include <ctype.h>

/*const char* ennemi_wall(int current_ennemi) {
    switch (current_perso) {
        case 5: return "assets/perso/dialogue/boss/Infenium_dialogue.png";
        case 6: return "assets/perso/dialogue/boss/Patecarbo_dialogue.png";
        case 7: return "assets/perso/dialogue/boss/Racaillou_dialogue.png";
        case 8: return "assets/perso/dialogue/boss/Roy_dialogue.png";
        case 9: return "assets/perso/dialogue/boss/Xmarano_dialogue.png";
        case 10: return "assets/perso/dialogue/boss/Patecarbo_dialogue.png";
        case 11: return "assets/perso/dialogue/boss/Racaillou_dialogue.png";
        case 12: return "assets/perso/dialogue/boss/Roy_dialogue.png";
    }
}

void affichage_mechant(Global_t *m, RenderContext_t *context)
{
    const char* filename2 = hero_wall(m->perso->current_perso);

    sfTexture* texture2 = sfTexture_createFromFile(filename2, NULL);
    sfSprite* sprite2 = sfSprite_create();
    sfSprite_setTexture(sprite2, texture2, sfTrue);
    sfVector2f position_sprite2 = {400, 667};
    sfSprite_setPosition(sprite2, position_sprite2);
    sfIntRect base = {0, 0, 91, 80};
    sfSprite_setTextureRect(sprite2, base);
    sfVector2f scale = {3, 3};
    sfSprite_setScale(sprite2, scale);
    sfRenderWindow_drawSprite(context->window, sprite2, NULL);

    sfSprite_destroy(sprite2);
    sfTexture_destroy(texture2);
}*/

const char* hero_wall(int current_perso) {
    switch (current_perso) {
        case 0: return "assets/perso/dialogue/hero/Infenium_dialogue.png";
        case 1: return "assets/perso/dialogue/hero/Patecarbo_dialogue.png";
        case 2: return "assets/perso/dialogue/hero/Racaillou_dialogue.png";
        case 3: return "assets/perso/dialogue/hero/Roy_dialogue.png";
        case 4: return "assets/perso/dialogue/hero/Xmarano_dialogue.png";
    }
}

void affichage_hero(Global_t *m, RenderContext_t *context)
{
    const char* filename2 = hero_wall(m->perso->current_perso);

    sfTexture* texture2 = sfTexture_createFromFile(filename2, NULL);
    sfSprite* sprite2 = sfSprite_create();
    sfSprite_setTexture(sprite2, texture2, sfTrue);
    sfVector2f position_sprite2 = {400, 667};
    sfSprite_setPosition(sprite2, position_sprite2);
    sfIntRect base = {0, 0, 91, 80};
    sfSprite_setTextureRect(sprite2, base);
    sfVector2f scale = {3, 3};
    sfSprite_setScale(sprite2, scale);
    sfRenderWindow_drawSprite(context->window, sprite2, NULL);

    sfSprite_destroy(sprite2);
    sfTexture_destroy(texture2);
}

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
    //affichage_hero()
    sfSleep(sfSeconds(0.1));
    sfText_destroy(text);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

int skip_ennemy(const char *phrase, RenderContext_t *context)
{
    int window_width = sfRenderWindow_getSize(context->window).x;
    int window_height = sfRenderWindow_getSize(context->window).y;

    if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
        sentencept(phrase, context, window_width - 520, 950);
        sfSleep(sfSeconds(0.5));
        return 1;
    }
    return 0;
}

void ennemy_speak(const char *phrase, const char *num, RenderContext_t *context)
{
    int window_width = sfRenderWindow_getSize(context->window).x;
    int window_height = sfRenderWindow_getSize(context->window).y;

    draw_dialogue(num, window_width - 520, window_height - 520, context);
    sentencept(phrase, context, window_width - 520, 950);
}

int skip_hero(const char *phrase, RenderContext_t *context)
{
    int window_width = sfRenderWindow_getSize(context->window).x;
    int window_height = sfRenderWindow_getSize(context->window).y;

    if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
        sentencept(phrase, context, 25, 950);
        sfSleep(sfSeconds(0.5));
        return 1;
    }
    return 0;
}

void hero_speak(const char *phrase, const char *num, RenderContext_t *context)
{
    int window_width = sfRenderWindow_getSize(context->window).x;
    int window_height = sfRenderWindow_getSize(context->window).y;

    draw_dialogue(num, 25, window_height - 30, context);
    sentencept(phrase, context, 25, 950);
}

void wordpt(char *str, RenderContext_t *context, const char *num, int position)
{
    char *phrase = malloc(strlen(str) + 1);
    int should_skip = 0;

    strcpy(phrase, "");
    for (int i = 0; i < strlen(str); i++) {
        strncat(phrase, &str[i], 1);
        if (position == 0) {
            hero_speak(phrase, num, context);
            should_skip = skip_hero(str, context);
        }
        if (position != 0){
            ennemy_speak(phrase, num, context);
            should_skip = skip_ennemy(str, context);
        }
        if (should_skip) {
            break;
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
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            break;
        if (verif_parse(line, context, m->perso->current_perso, last_speaker) == 1)
            break;
    }
    m->dialogue.start_dialogue = 0;
    m->current = 2;
    fclose(file);
}
