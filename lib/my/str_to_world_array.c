/*
** EPITECH PROJECT, 2021
** navy2
** File description:
** str_to_world_array
*/

#include "my.h"

char **str_to_world_array(char *str)
{
    int s = 0;
    int index = 0;
    char **tab = malloc((my_strlen(str) + 1) * sizeof(char **));
    char *str_cat = malloc(my_strlen(str) * sizeof(char *));

    for (int i = 0, n = 0; i <= my_strlen(str); i++){
        if (str[i] == ':' || str[i] == '\n' || str[i] == '\0'){
            str_cat[n] = '\0';
            tab[s] = str_cat;
            str_cat = malloc(my_strlen(str) * sizeof(char *));
            s++;
            n = 0;
        } else {
            str_cat[n] = str[i];
            n++;
        }
    }
    tab[s] = NULL;
    free(str_cat);
    return tab;
}
