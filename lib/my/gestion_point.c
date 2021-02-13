/*
** EPITECH PROJECT, 2021
** navy2
** File description:
** gestion_point
*/

#include "my.h"

void count(navy *game, char **coord)
{
    for (int i = 0; coord[i] != NULL; i++){
        if (my_strlen(coord[i]) == 1)
            game->nbr_final = game->nbr_final + (coord[i][0] - '0');
    }
}

char *convert(char *buff)
{
    if (buff[0] < 'A' && buff[0] > 'H'
    || buff[1] < '1' && buff[1] > '8' || my_strlen(buff) < 3)
        my_putstr_err("wrong position");
    else{
        buff[0] = buff[0];
        buff[1] = buff[1] - 1;
    }
}

void second_add_str(navy2 *game, int x, int y)
{
    int i;
    char *test = malloc(2 * sizeof(char *));

    for (i = 0; game->dead_boat2[i] != NULL; i++);
    test[0] = x + '0';
    test[1] = y + '0';
    game->dead_boat2[i] = test;
    game->dead_boat2[i + 1] = NULL;
}

void second_no_str(navy2 *game, int x, int y)
{
    int i;
    char *test = malloc(2 * sizeof(char *));

    for (i = 0; game->nop2[i] != NULL; i++);
    test[0] = x + '0';
    test[1] = y + '0';
    game->nop2[i] = test;
    game->nop2[i + 1] = NULL;
}

void add_str(navy *game, int x, int y)
{
    int i;
    char *test = malloc(2 * sizeof(char *));
    
    for (i = 0; game->dead_boat[i] != NULL; i++);
    test[0] = x + '0';
    test[1] = y + '0';
    game->dead_boat[i] = test;
    game->dead_boat[i + 1] = NULL;
}
