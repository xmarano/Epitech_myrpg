/*
** EPITECH PROJECT, 2024
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** select_player.c
*/
#include "../rpg.h"
#include "../include/menu.h"

static sfRectangleShape *init_button_select(Global_t *m, sfVector2f size, sfVector2f pos)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfFloatRect rect_pos;
    float pos_y;
    float pos_x;

    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setFillColor(shape, sfColor_fromRGB(245, 178, 49));
    sfRectangleShape_setOutlineThickness(shape, 6);
    sfRectangleShape_setOutlineColor(shape, sfColor_fromRGB(22, 40, 12));
    rect_pos = sfRectangleShape_getLocalBounds(shape);
    pos_y = (m->menu.wsize.y - rect_pos.height) / 2;
    pos_x = (m->menu.wsize.x - rect_pos.width) / 2;
    pos.y += pos_y;
    pos.x += pos_x;
    sfRectangleShape_setPosition(shape, pos);
    return shape;
}

static sfSprite *init_sprite_select(Global_t *m, char *filename, sfVector2f pos)
{
    sfTexture *texture = sfTexture_createFromFile(filename, NULL);
    sfSprite *sprite = sfSprite_create();
    sfFloatRect sprite_pos;
    float pos_y;
    float pos_x;

    sfSprite_setTexture(sprite, texture, sfTrue);
    sprite_pos = sfSprite_getLocalBounds(sprite);
    pos_y = (m->menu.wsize.y - sprite_pos.height) / 2;
    pos_x = (m->menu.wsize.x - sprite_pos.width) / 2;
    pos.y += pos_y;
    pos.x += pos_x;
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

sfText *init_text_select(Global_t *m, char *str, int size, sfVector2f pos)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    sfFloatRect text_pos;
    float pos_y;
    float pos_x;


    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, sfBlack);
    sfText_setString(text, str);
    text_pos = sfText_getLocalBounds(text);
    pos_x = (m->menu.wsize.x - text_pos.width) / 2;
    pos_y = (m->menu.wsize.y - text_pos.height) / 2;
    pos.y += pos_y;
    pos.x += pos_x;
    sfText_setPosition(text, pos);
    return text;
}

static void check_globalbounds(Global_t *m)
{
    m->select.gb_b1 = sfRectangleShape_getGlobalBounds(m->select.button1);
    m->select.gb_b2 = sfRectangleShape_getGlobalBounds(m->select.button2);
    m->select.gb_b3 = sfRectangleShape_getGlobalBounds(m->select.button3);
    m->select.gb_b4 = sfRectangleShape_getGlobalBounds(m->select.button4);
    m->select.gb_b5 = sfRectangleShape_getGlobalBounds(m->select.button5);
    m->select.gb_play = sfRectangleShape_getGlobalBounds(m->select.play);
    m->select.gb_back = sfRectangleShape_getGlobalBounds(m->select.back);
}

void init_select_perso(Global_t *m)
{
    m->select.fond = init_sprite("assets/menu/menu.jpg", (sfVector2f){0, 0});
    m->select.p1 = init_sprite_select(m, "assets/menu/roy.png", (sfVector2f){-510, -150});
    m->select.p2 = init_sprite_select(m, "assets/menu/xmarano.png", (sfVector2f){-260, -150});
    m->select.p3 = init_sprite_select(m, "assets/menu/patecarbo.png", (sfVector2f){-10, -150});
    m->select.p4 = init_sprite_select(m, "assets/menu/infenium.png", (sfVector2f){240, -150});
    m->select.p5 = init_sprite_select(m, "assets/menu/racaillou.png", (sfVector2f){490, -150});
    m->select.p1_w = init_sprite_select(m, "assets/menu/roy_w.png", (sfVector2f){-510, -150});//
    m->select.p2_w = init_sprite_select(m, "assets/menu/xmarano_w.png", (sfVector2f){-260, -150});
    m->select.p3_w = init_sprite_select(m, "assets/menu/patecarbo_w.png", (sfVector2f){-10, -150});
    m->select.p4_w = init_sprite_select(m, "assets/menu/infenium_w.png", (sfVector2f){240, -150});
    m->select.p5_w = init_sprite_select(m, "assets/menu/racaillou_w.png", (sfVector2f){490, -150});//
    m->select.p1_d = init_sprite_select(m, "assets/menu/roy_d.png", (sfVector2f){0, 225});
    m->select.p2_d = init_sprite_select(m, "assets/menu/xmarano_d.png", (sfVector2f){0, 225});
    m->select.p3_d = init_sprite_select(m, "assets/menu/patecarbo_d.png", (sfVector2f){0, 225});
    m->select.p4_d = init_sprite_select(m, "assets/menu/infenium_d.png", (sfVector2f){0, 225});
    m->select.p5_d = init_sprite_select(m, "assets/menu/racaillou_d.png", (sfVector2f){0, 225});
    m->select.title = init_text(m, "SELECT  A  PLAYER", 100, 0);
    m->select.button1 = init_button_select(m, (sfVector2f){200, 75}, (sfVector2f){-500, 25});
    m->select.button2 = init_button_select(m, (sfVector2f){200, 75}, (sfVector2f){-250, 25});
    m->select.button3 = init_button_select(m, (sfVector2f){200, 75}, (sfVector2f){0, 25});
    m->select.button4 = init_button_select(m, (sfVector2f){200, 75}, (sfVector2f){250, 25});
    m->select.button5 = init_button_select(m, (sfVector2f){200, 75}, (sfVector2f){500, 25});
    m->select.back = init_button_select(m, (sfVector2f){100, 50}, (sfVector2f){-625, -325});
    m->select.play = init_button_select(m, (sfVector2f){125, 75}, (sfVector2f){550, 325});
    m->select.back_txt = init_text_select(m, "back", 50, (sfVector2f){-630, -353});
    m->select.play_txt = init_text_select(m, "play", 70, (sfVector2f){543, 290});
    m->select.select = init_text_select(m, "select", 70, (sfVector2f){-5, -10});
    check_globalbounds(m);
}

static void check_hover(Global_t *m)
{
    /*  ROY  */
    hover(m, m->select.button1, &m->select.gb_b1);
    if (sfFloatRect_contains(&m->select.gb_b1, m->mouse.x, m->mouse.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            m->select.p1_select = 1;
            sfRectangleShape_setFillColor(m->select.button1, sfColor_fromRGB(153, 112, 29));
            m->perso->current_perso = ROY;
        }
    }
    if (m->select.p1_select == 1) {
        sfRenderWindow_drawSprite(m->window, m->select.p1_w, NULL);
        sfRenderWindow_drawSprite(m->window, m->select.p1_d, NULL);
        m->select.p2_select = 0;
        m->select.p3_select = 0;
        m->select.p4_select = 0;
        m->select.p5_select = 0;
    }

    /*  XMARANO  */
    hover(m, m->select.button2, &m->select.gb_b2);
    if (sfFloatRect_contains(&m->select.gb_b2, m->mouse.x, m->mouse.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            m->select.p2_select = 1;
            sfRectangleShape_setFillColor(m->select.button2, sfColor_fromRGB(153, 112, 29));
            m->perso->current_perso = XMARANO;
        }
    }
    if (m->select.p2_select == 1) {
        sfRenderWindow_drawSprite(m->window, m->select.p2_w, NULL);
        sfRenderWindow_drawSprite(m->window, m->select.p2_d, NULL);
        m->select.p1_select = 0;
        m->select.p3_select = 0;
        m->select.p4_select = 0;
        m->select.p5_select = 0;
    }

    /*  PATECARBO  */
    hover(m, m->select.button3, &m->select.gb_b3);
    if (sfFloatRect_contains(&m->select.gb_b3, m->mouse.x, m->mouse.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            m->select.p3_select = 1;
            sfRectangleShape_setFillColor(m->select.button3, sfColor_fromRGB(153, 112, 29));
            m->perso->current_perso = PATECARBO;
        }
    }
    if (m->select.p3_select == 1) {
        sfRenderWindow_drawSprite(m->window, m->select.p3_w, NULL);
        sfRenderWindow_drawSprite(m->window, m->select.p3_d, NULL);
        m->select.p1_select = 0;
        m->select.p2_select = 0;
        m->select.p4_select = 0;
        m->select.p5_select = 0;
    }

    /*  INFENIUM  */
    hover(m, m->select.button4, &m->select.gb_b4);
    if (sfFloatRect_contains(&m->select.gb_b4, m->mouse.x, m->mouse.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            m->select.p4_select = 1;
            sfRectangleShape_setFillColor(m->select.button4, sfColor_fromRGB(153, 112, 29));
            m->perso->current_perso = INFENIUM;
        }
    }
    if (m->select.p4_select == 1) {
        sfRenderWindow_drawSprite(m->window, m->select.p4_w, NULL);
        sfRenderWindow_drawSprite(m->window, m->select.p4_d, NULL);
        m->select.p1_select = 0;
        m->select.p2_select = 0;
        m->select.p3_select = 0;
        m->select.p5_select = 0;
    }

    /*  RACAILLOU  */
    hover(m, m->select.button5, &m->select.gb_b5);
    if (sfFloatRect_contains(&m->select.gb_b5, m->mouse.x, m->mouse.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            m->select.p5_select = 1;
            sfRectangleShape_setFillColor(m->select.button5, sfColor_fromRGB(153, 112, 29));
            m->perso->current_perso = RACAILLOU;
        }
    }
    if (m->select.p5_select == 1) {
        sfRenderWindow_drawSprite(m->window, m->select.p5_w, NULL);
        sfRenderWindow_drawSprite(m->window, m->select.p5_d, NULL);
        m->select.p1_select = 0;
        m->select.p2_select = 0;
        m->select.p3_select = 0;
        m->select.p4_select = 0;
    }

    /*  PLAY  */
    hover(m, m->select.play, &m->select.gb_play);
    if (sfFloatRect_contains(&m->select.gb_play, m->mouse.x, m->mouse.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            //destroy_select_perso(m);
            m->current = 12;
        }
    }

    /*  Back  */
    hover(m, m->select.back, &m->select.gb_back);
    if (sfFloatRect_contains(&m->select.gb_back, m->mouse.x, m->mouse.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            //destroy_select_perso(m);
            m->current = 10;
        }
    }
}

void draw_select_perso(Global_t *m)
{
    if (m->current == 11) {
        sfRenderWindow_drawSprite(m->window, m->select.fond, NULL);
        sfRenderWindow_drawSprite(m->window, m->select.p1, NULL);
        sfRenderWindow_drawSprite(m->window, m->select.p2, NULL);
        sfRenderWindow_drawSprite(m->window, m->select.p3, NULL);
        sfRenderWindow_drawSprite(m->window, m->select.p4, NULL);
        sfRenderWindow_drawSprite(m->window, m->select.p5, NULL);
        check_hover(m);
        sfRenderWindow_drawText(m->window, m->select.title, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->select.button1, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->select.button2, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->select.button3, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->select.button4, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->select.button5, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->select.back, NULL);
        sfRenderWindow_drawRectangleShape(m->window, m->select.play, NULL);
        sfRenderWindow_drawText(m->window, m->select.select, NULL);
        sfRenderWindow_drawText(m->window, m->select.back_txt, NULL);
        sfRenderWindow_drawText(m->window, m->select.play_txt, NULL);
    }
}

void destroy_select_perso(Global_t *m)
{
    sfSprite_destroy(m->select.fond);
    sfText_destroy(m->select.title);
    /* ajouter les sprite et text destroy */
}
