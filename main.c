/*
** EPITECH PROJECT, 2021
** navy2
** File description:
** main
*/
#include "lib/my/my.h"

int main(int ac, char **av)
{
    navy *game = malloc(sizeof(game));
    navy2 *game2 = malloc(sizeof(game2));

    game->end = 0;
    init(game, game2);
    if (ac == 2){
        if (player1(av[1], game, game2, 0) == 84){
            my_putstr_err("ERROR WITH THE MAP CONTENT\n");
            return 84;
        }
    } else if (ac == 3){
        if (player2(av[2], my_getnbr(av[1]), game, game2) == 84){
            my_putstr_err("ERROR WITH THE MAP CONTENT\n");
            return 84;
        }
    }
    else
        my_putstr_err("arguments errors");
}

int coule(char **coord, int x, int y)
{
    for (int i = 0; coord[i] != NULL; i++){
        if (x == (coord[i][0] - '0') && y == (coord[i][1] - '0')){
            return 1;
        }
    }
    return 0;
}

int no_coule(char **coord, int x, int y)
{
    for (int i = 0; coord[i] != NULL; i++){
        if (x == (coord[i][0] - '0') && y == (coord[i][1] - '0')){
            return 1;
        }
    }
    return 0;
}

char **convert_coord(char **brut_coord)
{
    int i;
    for (i = 0; brut_coord[i] != NULL; i++){
        if (my_strlen(brut_coord[i]) == 2){
            brut_coord[i][0] = (brut_coord[i][0] - 'A' + '0');
            brut_coord[i][1] = ((brut_coord[i][1]) - 1);
        }
    }
    return brut_coord;
}

int *compare(char **coord, int x, int y)
{
    int *ret = malloc(2 * sizeof(int *));

    for (int i = 0; coord[i + 1] != NULL; i++){
            if (my_strlen(coord[i]) == 2 && my_strlen(coord[i + 1]) == 2){
                if (x >= (coord[i][0] - '0') && x <= (coord[i + 1][0] - '0')
                && y >= (coord[i][1] - '0') && y <= (coord[i + 1][1] - '0')){
                    ret[0] = 1;
                    ret[1] = my_getnbr(coord[i - 1]);
                    return ret;
                }
            }
    }
    ret[0] = 0;
    ret[1] = NULL;
    return ret;
}

