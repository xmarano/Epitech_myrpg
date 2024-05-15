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

void displayDialogue(Global_t *m, Dialogue_t *dialogue) {
    sfVector2f position = {50, 50};
    sfText_setPosition(m->hub.dia_pouill, position);

    sfText_setString(m->hub.dia_pouill, dialogue->lines[dialogue->currentLine]);

    if (dialogue->displayFull) {
        // Afficher la phrase entière si displayFull est vrai
        // sfSleep(sfMilliseconds(1000)); // Temps d'attente pour chaque phrase
    } else {
        // Attente d'appui sur 'enter' avant d'afficher la prochaine ligne
        sfEvent event;
        while (sfRenderWindow_pollEvent(m->window, &event)) {
            if (event.type == sfEvtKeyPressed && event.key.code == sfKeyReturn) {
                dialogue->currentLine++;
                if (dialogue->currentLine >= dialogue->lineCount) {
                    // Fin du dialogue
                    dialogue->currentLine = 0; // Réinitialiser pour la prochaine fois
                    return;
                }
                sfText_setString(m->hub.dia_pouill, dialogue->lines[dialogue->currentLine]);
                sfRenderWindow_drawText(m->window, m->hub.dia_pouill, NULL);
                sfRenderWindow_display(m->window);
                return;
            }
        }
    }
}

void what_dialogue(Global_t *m, int word)
{
    if (word == 1)
        displayDialogue(m, &m->dialogue);
}
