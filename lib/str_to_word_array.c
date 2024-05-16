/*
** EPITECH PROJECT, 2023
** str_to_word_array
** File description:
** Infos
*/
#include "../src/my.h"

static int count_lines(char *str, char delimiteur)
{
    int count = 0;

    for (int i = 0; str != NULL && str[i] != '\0'; i++) {
        if (str[i] == delimiteur || str[i] == '\n') {
            count++;
        }
    }
    return count;
}

static int *count_char(char *str, char delimiteur)
{
    int *i = malloc(sizeof(int) * 2);

    if (*str == delimiteur)
        str++;
    for (i[0] = 0; str[i[0]] != '\0' &&
        str[i[0]] != '\n' && str[i[0]] != delimiteur; i[0]++);
    if (str[i[0]] == '\n')
        i[0]++;
    if (str[i[0]] == delimiteur)
        i[1]++;
    return i;
}

char **cancer(char **tab, int i)
{
    tab[i] = NULL;
    return tab;
}

char **str_to_word_array(char *str, char d)
{
    int lines = count_lines(str, d);
    int *strc = malloc(sizeof(int) * 2);
    int j = 0;
    int *save;
    int i = 0;
    char **array = malloc(sizeof(char *) * (lines + 1));

    strc = count_char(str, d);
    for (j = 0; j < lines; j++) {
        array[j] = malloc(sizeof(char) * (strc[0] + 1));
        for (i = 0; i < strc[0] && str[i] != d; i++) {
            array[j][i] = str[i];
        }
        str += strc[0] + strc[1];
        array[j][i] = '\0';
        save = strc;
        strc = count_char(str, d);
        free(save);
    }
    return cancer(array, j);
}