/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "../rpg.h"
#include <ctype.h>

const char *ennemi_wall(int current_ennemi)
{
    switch (current_ennemi) {
        case 5:
            return "assets/perso/dialogue/boss/Boss1_dialogue.png";
        case 6:
            return "assets/perso/dialogue/boss/Boss2_dialogue.png";
        case 7:
            return "assets/perso/dialogue/boss/Boss3_dialogue.png";
        case 8:
            return "assets/perso/dialogue/boss/Boss4_dialogue.png";
        case 9:
            return "assets/perso/dialogue/boss/Boss5_dialogue.png";
        case 10:
            return "assets/perso/dialogue/boss/Boss6_dialogue.png";
        case 11:
            return "assets/perso/dialogue/boss/Boss7_dialogue.png";
        case 12:
            return "assets/perso/dialogue/boss/Boss8_dialogue.png";
        default:
            return NULL;
    }
}

const char *hero_wall(int current_perso)
{
    switch (current_perso) {
        case 0:
            return "assets/perso/dialogue/hero/Roy_dialogue.png";
        case 1:
            return "assets/perso/dialogue/hero/Infenium_dialogue.png";
        case 2:
            return " assets/perso/dialogue/hero/Patecarbo_dialogue.png";
        case 3:
            return "assets/perso/dialogue/hero/Xmarano_dialogue.png";
        case 4:
            return "assets/perso/dialogue/hero/Racaillou_dialogue.png";
        default:
            return NULL;
    }
}

void affichage_mechant(RenderContext_t *context)
{
    const char *filename3 = ennemi_wall(context->current_boss);
    sfTexture *texture3 = sfTexture_createFromFile(filename3, NULL);
    sfSprite *sprite3 = sfSprite_create();
    sfVector2f position_sprite3 = {1200, 667};
    sfIntRect base = {0, 0, 91, 80};
    sfVector2f scale = {3, 3};

    if (filename3) {
        sfSprite_setTexture(sprite3, texture3, sfTrue);
        sfSprite_setPosition(sprite3, position_sprite3);
        sfSprite_setTextureRect(sprite3, base);
        sfSprite_setScale(sprite3, scale);
        sfRenderWindow_drawSprite(context->window, sprite3, NULL);
        sfSprite_destroy(sprite3);
        sfTexture_destroy(texture3);
    }
}

void affichage_hero(RenderContext_t *context)
{
    const char *filename2 = hero_wall(context->current_hero);
    sfTexture *texture2 = sfTexture_createFromFile(filename2, NULL);
    sfSprite *sprite2 = sfSprite_create();
    sfVector2f position_sprite2 = {400, 667};
    sfIntRect base = {0, 0, 91, 80};
    sfVector2f scale = {3, 3};

    if (filename2) {
        sfSprite_setTexture(sprite2, texture2, sfTrue);
        sfSprite_setPosition(sprite2, position_sprite2);
        sfSprite_setTextureRect(sprite2, base);
        sfSprite_setScale(sprite2, scale);
        sfRenderWindow_drawSprite(context->window, sprite2, NULL);
        sfSprite_destroy(sprite2);
        sfTexture_destroy(texture2);
    }
}

void draw_dialogue2(const char *str, int x, int y, RenderContext_t *context)
{
    sfText *text = sfText_create();
    sfVector2f position = {x, y};

    sfText_setString(text, str);
    sfText_setFont(text, context->font);
    sfText_setCharacterSize(text, 30);
    sfText_setColor(text, sfWhite);
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(context->window, text, NULL);
    sfText_destroy(text);
}

void draw_dialogue(const char *str, int x, int y, RenderContext_t *context)
{
    sfText *text = sfText_create();
    sfVector2f position = {x, y};

    sfText_setString(text, str);
    sfText_setFont(text, context->font);
    sfText_setCharacterSize(text, 30);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, position);
    sfRenderWindow_drawText(context->window, text, NULL);
    sfText_destroy(text);
}

void sentencept(char *phrase, RenderContext_t *context, int x, int y)
{
    sfTexture* texture = sfTexture_createFromFile("src/dialogue_code/wall.png", NULL);
    sfSprite* sprite = sfSprite_create();
    sfVector2f position = {x, y};

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_clear(context->window, sfWhite);
    sfRenderWindow_drawSprite(context->window, sprite, NULL);
    affichage_hero(context);
    affichage_mechant(context);
    draw_dialogue(phrase, x, y, context);
    draw_dialogue2(context->name_ennemy, 1625, 882, context);
    draw_dialogue2(context->name_hero, 170, 882, context);
    sfRenderWindow_display(context->window);
    sfSleep(sfSeconds(0.01));
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
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

void parse_file(char *filename, RenderContext_t *context, Global_t *m)
{
    FILE *file = fopen(filename, "r");
    char line[256];
    char last_speaker[256] = "";

    if (file == NULL)
        return;
    context->current_boss = m->current_boss;
    context->current_hero = m->perso->current_perso;
    context->name_ennemy = m->perso[m->current_boss].name_perso;
    context->name_hero = m->perso[m->perso->current_perso].name_perso;
    while (fgets(line, sizeof(line), file)) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            break;
        if (verif_parse(line, context, m->perso->current_perso, last_speaker)
        == 1)
            break;
    }
    m->dialogue.start_dialogue = 0;
    m->current = 1;
    fclose(file);
}
