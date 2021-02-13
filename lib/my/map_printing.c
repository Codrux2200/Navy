/*
** EPITECH PROJECT, 2021
** navy2
** File description:
** map_printing
*/

#include "my.h"

char **init_map()
{
    char *line = "........";
    char **map = malloc(8 * sizeof(char **));
    
    for (int i = 0; i != 8; i++)
        map[i] = line;
    free(line);
    return map;
}

void print_map(char **coord, navy *game)
{
    coord = convert_coord(coord);
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 0; i != 8; i++){
        my_put_nbr(i + 1);
        my_putstr("|");
        for (int r = 0; r != 8; r++){
            if (compare(coord, r, i)[0] == 1){
                if (coule(game->dead_boat, r, i) == 1)
                    my_putstr("x ");
                else {
                    my_put_nbr(compare(coord, r, i)[1]);
                    my_putstr(" ");
                }
            } else if (no_coule(game->nop, r, i) == 1)
                    my_putstr("o ");
            else 
                my_putstr(". ");
        }
        my_putstr("\n");
    }
}

void print_map2(char **coord, navy2 *game)
{
    coord = convert_coord(coord);
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (int i = 0; i != 8; i++){
        my_put_nbr(i + 1);
        my_putstr("|");
        for (int r = 0; r != 8; r++){
            if (coule(game->dead_boat2, r, i) == 1)
                my_putstr("x ");
            else if (no_coule(game->nop2, r, i) == 1)
                my_putstr("o ");
            else
                my_putstr(". ");
        }
        my_putstr("\n");
    }
}

char *lecture(char *file, navy *game)
{
    int fd = open(file, O_RDONLY);
    char *buffer;
    struct stat sb;

    if (fd == -1){
        my_putstr_err("ERROR READ MAP\n");
        buffer = " ";
    } else {
        stat(file, &sb);
        buffer = malloc((sb.st_size + 1) * sizeof(char *));
        read(fd, buffer, sb.st_size);
    }
    return buffer;
}

void add_no(navy *game, int x, int y)
{
    int i;
    char *test = malloc(2 * sizeof(char *));

    for (i = 0; game->nop[i] != NULL; i++);
    test[0] = x + '0';
    test[1] = y + '0';
    game->nop[i] = test;
    game->nop[i + 1] = NULL; 
}

