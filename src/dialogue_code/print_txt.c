/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-yanis.prevost
** File description:
** print_txt.c
*/

#include "../rpg.h"
#include "../include/perso.h"
#include "../include/menu.h"
#include "../include/worlds.h"
#include "../include/npc.h"

Dialogue_t readDialogueFromFile(const char *filename)
{
    Dialogue_t dialogue;
    FILE *file = fopen(filename, "r");
    dialogue.lineCount = 0;
    if (file == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fgets(dialogue.lines[dialogue.lineCount], MAX_CHARS_PER_LINE, file) != NULL) {
        // Supprimer le saut de ligne à la fin de chaque ligne
        dialogue.lines[dialogue.lineCount][strcspn(dialogue.lines[dialogue.lineCount], "\n")] = 0;
        dialogue.lineCount++;
        if (dialogue.lineCount >= MAX_LINES) {
            fprintf(stderr, "Nombre maximal de lignes atteint. Augmentez MAX_LINES si nécessaire.\n");
            break;
        }
    }

    fclose(file);
    return dialogue;
}

static void ptr_dia(Global_t *m, int word)
{

}

void what_dialogue(Global_t *m, int word)
{
    if (word == 1)
        ptr_dia(m, word);
}
