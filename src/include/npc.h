/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** npc.h
*/

#ifndef NPC_H
    #define NPC_H
    #include "../rpg.h"

// typedef struct sprite {
//     sfSprite *sprite;
// }Npc_srpite_t;

typedef struct npc {
    char name[10];
    char link_texture[20];
    //Npc_srpite_t set;
} Npc_t;

#endif
