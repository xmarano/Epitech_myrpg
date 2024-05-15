/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** npc.h
*/

#ifndef NPC_H
    #define NPC_H
    #include "../rpg.h"
    #define MAX_LINES 100
    #define MAX_CHARS_PER_LINE 256

typedef struct dial {
    char lines[MAX_LINES][MAX_CHARS_PER_LINE];
    int lineCount;
}Dialogue_t;

typedef struct npc {
    char name[10];
    char link_texture[20];
    //Npc_srpite_t set;
} Npc_t;

#endif
