/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "../rpg.h"
#include <SFML/Graphics.h>

char *synop_read(void)
{
    char *buffer = NULL;
    long length;
    FILE *f = fopen("src/setting_folder/synopsis.txt", "rb");

    if (f) {
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);
        buffer = malloc(length + 1);
        if (buffer) {
            fread(buffer, 1, length, f);
            buffer[length] = '\0';
        }
        fclose(f);
    }
    return buffer;
}

char *credit_read(void)
{
    char *buffer = NULL;
    long length;
    FILE *f = fopen("src/setting_folder/credit.txt", "rb");

    if (f) {
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);
        buffer = malloc(length + 1);
        if (buffer) {
            fread(buffer, 1, length, f);
            buffer[length] = '\0';
        }
        fclose(f);
    }
    return buffer;
}

void synopsis_bool(Global_t *m)
{
    char *synopsypara = synop_read();

    if (m->setting.synopbool){
        m->setting.coversynop = init_button2(m,
        (sfVector2f){760, 660}, (sfVector2f){900, 200});
        sfRenderWindow_drawRectangleShape(m->window,
        m->setting.coversynop, NULL);
        m->setting.synopsypara = init_text2(m->setting.font,
        synopsypara, 50, (sfVector2f){910, 210});
        sfRenderWindow_drawText(m->window,
        m->setting.synopsypara, NULL);
    }
}

void verif_other(Global_t *m)
{
    char *creditpara = credit_read();

    if (m->setting.creditbool) {
        m->setting.covercredit = init_button2(m,
        (sfVector2f){600, 240}, (sfVector2f){900, 340});
        sfRenderWindow_drawRectangleShape(m->window,
        m->setting.covercredit, NULL);
        m->setting.creditpara = init_text2(m->setting.font,
        creditpara, 50, (sfVector2f){910, 350});
        sfRenderWindow_drawText(m->window,
        m->setting.creditpara, NULL);
    }
    synopsis_bool(m);
    free(creditpara);
}

void verif_thing(Global_t *m)
{
    if (m->setting.displaySizeOptions) {
        sfRenderWindow_drawText(m->window, m->setting.littlez, NULL);
        sfRenderWindow_drawText(m->window, m->setting.mediumz, NULL);
        sfRenderWindow_drawText(m->window, m->setting.bigz, NULL);
    }
    if (m->setting.volumeclicked) {
        sfRenderWindow_drawText(m->window, m->setting.volumeb, NULL);
        sfRenderWindow_drawText(m->window, m->setting.volumeh, NULL);
        sfRenderWindow_drawText(m->window, m->setting.cvolume, NULL);
    }
    verif_other(m);
}
