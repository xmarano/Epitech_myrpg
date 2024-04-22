/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** main.c
*/
#include "rpg.h"
#include <SFML/Graphics.h>

static void diff_size(sfVector2i mouse, Global_t *m)
{
    sfFloatRect bigzBounds = sfRectangleShape_getGlobalBounds(m->setting.bigz);
    sfFloatRect mediumzBounds = sfRectangleShape_getGlobalBounds(m->setting.mediumz);
    sfFloatRect littlezBounds = sfRectangleShape_getGlobalBounds(m->setting.littlez);

    if (sfFloatRect_contains(&littlezBounds, mouse.x, mouse.y)) {
        sfMouse_setPositionRenderWindow((sfVector2i){mouse.x, mouse.y},
        m->window);
        sfRenderWindow_setSize(m->window, (sfVector2u){800, 600});
    }
    if (sfFloatRect_contains(&mediumzBounds, mouse.x, mouse.y)) {
        sfMouse_setPositionRenderWindow((sfVector2i){mouse.x, mouse.y},
        m->window);
        sfRenderWindow_setSize(m->window, (sfVector2u){1280, 720});
    }
    if (sfFloatRect_contains(&bigzBounds, mouse.x, mouse.y)) {
        sfMouse_setPositionRenderWindow((sfVector2i){mouse.x, mouse.y},
        m->window);
        sfRenderWindow_setSize(m->window, (sfVector2u){1920, 1080});
    }
}

static void modify_size(sfVector2i mouse, Global_t *m)
{
    if (m->setting.displaySizeOptions) {
        diff_size(mouse, m);
    }
}

sfRectangleShape *init_button2(Global_t *m, sfVector2f size, sfVector2f position)
{
    sfRectangleShape *shape = sfRectangleShape_create();

    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setFillColor(shape, sfColor_fromRGB(245, 178, 49));
    sfRectangleShape_setOutlineThickness(shape, 6);
    sfRectangleShape_setOutlineColor(shape, sfColor_fromRGB(22, 40, 12));
    sfRectangleShape_setPosition(shape, position);
    return shape;
}

sfText *init_text2(sfFont *font, const char *str, int size, sfVector2f position)
{
    sfText *text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, sfBlack);
    sfText_setString(text, str);
    sfText_setPosition(text, position);
    return text;
}

void event_setting(sfEvent event, Global_t *m)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(m->window);
    sfFloatRect sizeBounds = sfRectangleShape_getGlobalBounds(m->setting.buttonwindow);
    sfFloatRect volumebounds = sfRectangleShape_getGlobalBounds(m->setting.buttonvolum);
    sfFloatRect creditBounds = sfRectangleShape_getGlobalBounds(m->setting.buttoncred);
    sfFloatRect retour = sfRectangleShape_getGlobalBounds(m->setting.buttonretour);
    sfFloatRect bigsynop = sfRectangleShape_getGlobalBounds(m->setting.buttonsynop);

    if (event.type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(&sizeBounds, mouse.x, mouse.y)) {
            m->setting.displaySizeOptions = !m->setting.displaySizeOptions;
        }
        if (sfFloatRect_contains(&volumebounds, mouse.x, mouse.y)) {
            m->setting.volumeclicked = !m->setting.volumeclicked;
        }
        if (sfFloatRect_contains(&creditBounds, mouse.x, mouse.y)) {
            m->setting.creditbool = !m->setting.creditbool;
        }
        if (sfFloatRect_contains(&bigsynop, mouse.x, mouse.y)) {
            m->setting.synopbool = !m->setting.synopbool;
        }
        if (sfFloatRect_contains(&retour, mouse.x, mouse.y)) {
            m->current = 10;
        }
        modify_size(mouse, m);
    }
}

const char* set_synopara() {
    const char *names = "The story takes place in \nthe kingdom of Elae, where we\nfollow agroup of heroes serving\nKing Edgarwho has been\nwatching over the kingdom\nfor many years.Following a\nsurprise attack from the\nneighboring kingdom of Aixus, \nour heroes set off on an\n adventure seeking vengeance\n against the kingdom\n responsible for this \n massacre.You will\nfollow the adventures of our\ngroup of heroes and the challenges\nthat await them in this\nadventure full of twists\nand turns!";
    return names;
}

const char* set_creditpara() {
    const char *names = "CLERC Tom\nGREGORI Leo\nPrevost Yanis \nColombani-gailleur Anthony";
    return names;
}

void init_setting(Global_t *m)
{
    m->setting.font = sfFont_createFromFile("assets/font.ttf");
    m->setting.window_size = sfRenderWindow_getSize(m->window);
    m->setting.background_s = init_sprite("assets/setting/background.png", (sfVector2f){0, 0});
    m->setting.retour = init_text2(m->setting.font, "retour", 50, (sfVector2f){40, 40});
    m->setting.buttonretour = init_button2(m, (sfVector2f){190, 58}, (sfVector2f){10, 50});
    m->setting.titre = init_text2(m->setting.font, "Settings", 100, (sfVector2f){300, 0});
    m->setting.buttonsett = init_button2(m, (sfVector2f){360, 100}, (sfVector2f){290, 20});
    m->setting.credit = init_text2(m->setting.font, "credit", 50, (sfVector2f){160, 600});
    m->setting.buttoncred = init_button2(m, (sfVector2f){140, 58}, (sfVector2f){150, 610});
    m->setting.synopsis = init_text2(m->setting.font, "synopsis", 50, (sfVector2f){160, 250});
    m->setting.buttonsynop = init_button2(m, (sfVector2f){200, 58}, (sfVector2f){150, 260});
    m->setting.volumetxt = init_text2(m->setting.font, "volume", 50, (sfVector2f){594, 600});
    m->setting.buttonvolum = init_button2(m, (sfVector2f){190, 58}, (sfVector2f){570, 610});
    m->setting.sizewindows = init_text2(m->setting.font, "window size", 50, (sfVector2f){590, 250});
    m->setting.buttonwindow = init_button2(m, (sfVector2f){280, 58}, (sfVector2f){570, 260});
    m->setting.littlez = init_text2(m->setting.font, "800 x 600", 50, (sfVector2f){590, 340});
    m->setting.mediumz = init_text2(m->setting.font, "1280 x 720", 50, (sfVector2f){590, 400});
    m->setting.bigz = init_text2(m->setting.font, "1920 x 1080", 50, (sfVector2f){590, 460});
    m->setting.volumeclicked = false;
    m->setting.volumeb = init_text2(m->setting.font, "dicrease volume", 50, (sfVector2f){590, 690});
    m->setting.volumeh = init_text2(m->setting.font, "increase volume", 50, (sfVector2f){590, 750});
    m->setting.cvolume = init_text2(m->setting.font, "volume cut", 50, (sfVector2f){590, 810});
}

void draw_setting(Global_t *m)
{
    if (m->current == 13) {
        sfRenderWindow_drawSprite(m->window, m->setting.background_s, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->setting.buttonsynop, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->setting.buttoncred, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->setting.buttonvolum, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->setting.buttonretour, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->setting.buttonwindow, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->setting.buttonsett, NULL);
        sfRenderWindow_drawText(m->window, m->setting.titre, NULL);
        sfRenderWindow_drawText(m->window, m->setting.synopsis, NULL);
        sfRenderWindow_drawText(m->window, m->setting.volumetxt, NULL);
        sfRenderWindow_drawText(m->window, m->setting.credit, NULL);
        sfRenderWindow_drawText(m->window, m->setting.volumetxt, NULL);
        sfRenderWindow_drawText(m->window, m->setting.retour, NULL);
        sfRenderWindow_drawText(m->window, m->setting.sizewindows, NULL);
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
        if (m->setting.creditbool) {
            m->setting.covercredit = init_button2(m, (sfVector2f){600, 200}, (sfVector2f){1100, 300});
            sfRenderWindow_drawRectangleShape(m->window, m->setting.covercredit, NULL);
            const char* creditpara = set_creditpara();
            m->setting.creditpara = init_text2(m->setting.font, creditpara, 50, (sfVector2f){1120, 310});
            sfRenderWindow_drawText(m->window, m->setting.creditpara, NULL);
        }
        if (m->setting.synopbool){
            m->setting.coversynop = init_button2(m, (sfVector2f){7600, 720}, (sfVector2f){1000, 200});
            sfRenderWindow_drawRectangleShape(m->window, m->setting.coversynop, NULL);
            const char* synopsypara =  set_synopara();
            m->setting.synopsypara = init_text2(m->setting.font, synopsypara, 50, (sfVector2f){1020, 210});
            sfRenderWindow_drawText(m->window, m->setting.synopsypara, NULL);
        }
    }
}
