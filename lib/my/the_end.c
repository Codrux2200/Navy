/*
** EPITECH PROJECT, 2021
** navy2
** File description:
** the_end
*/

#include "my.h"

int my_tablen(char **tab)
{
    int i;
    for (i = 0; tab[i] != NULL; i++);
    return i;
}

void tree_line(navy2 *game2)
{
    my_putstr("\n");
    my_putstr("enemy's positions:\n");
    print_map2(str_to_world_array("second\0"), game2);
    my_putstr("\n");
}

int verif(int x, int y, navy *game, char **coord)
{
    coord = convert_coord(coord);
    for (int i = 0; coord[i + 1] != NULL; i++){
        if (my_strlen(coord[i]) == 2 && my_strlen(coord[i + 1]) == 2){
            if (x >= (coord[i][0] - '0') && x <= (coord[i + 1][0] - '0')
            && y >= (coord[i][1] - '0') && y <= (coord[i + 1][1] - '0')){
                add_str(game, x, y);
                my_putstr("hit\n");
                return 1;
            }
        }
    }
    add_no(game, x, y);
    my_putstr("missed\n");
    return 2;
}

int the_end(navy *game, navy2 *game2)
{
    if (game->nbr_final == my_tablen(game->dead_boat)){
            my_putstr("Enemy won\n");
            return 1;
        } else if (game2->nbr_final2 == my_tablen(game2->dead_boat2)){
            my_putstr("I won\n");
            return 1;
        }
    return 0;
}

void init(navy *game, navy2 *game2)
{
    game->dead_boat = malloc(36 * sizeof(char **));
    game->dead_boat[0] = NULL;
    game->nop = malloc(36 * sizeof(char **));
    game->nop[0] = NULL;
    game2->dead_boat2 = malloc(36 * sizeof(char **));
    game2->dead_boat2[0] = NULL;
    game2->nop2 = malloc(36 * sizeof(char **));
    game2->nop2[0] = NULL;
}
