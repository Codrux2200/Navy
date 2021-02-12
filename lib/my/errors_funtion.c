/*
** EPITECH PROJECT, 2021
** navy2
** File description:
** errors_funtion
*/

#include "my.h"

void cheak_errors(int pass, char *buff, size_t len)
{
    while (pass == 0){
        my_putstr("\nattack: ");
        getline(&buff, &len, stdin);
        if (buff[0] < 'A' || buff[0] > 'H' || buff[1] < '1' || buff[1] > '8'
        || my_strlen(buff) != 3)
            my_putstr("wrong position");
        else
            pass = 1;
    }
}

void party2(char *map, navy *game, pid_t other_pid, navy2 *game2)
{
    char x;
    char y;
    char *buff = malloc(2 * sizeof(char *));
    game->end = 0;
    my_putstr("\nmy positions:\n");
    print_map(str_to_world_array(map), game);
    my_putstr("\nenemy's positions:\n");
    print_map2(str_to_world_array("second\0"), game2);
    my_putstr("\n");
    while (game->end == 0){
        if (the_end(game, game2) == 1) break;
        usleep(300);
        my_putstr("waiting for enemy's attack...\n");
        recive(2, game, 0);
        x = (game->nbr_signal[0] + 'A') - 1;
        y = (game->nbr_signal[1] + 1) + '0';
        write(1, &x, 1);
        if (party2_suite(map, game, other_pid, game2) == 84)
            break;
    }
}

int party2_suite(char *map, navy *game, pid_t other_pid, navy2 *game2)
{
    int nbr = 0;
    char *buff = malloc(2 * sizeof(char *));
    size_t len = 2;
    int pass = 0;

    my_put_nbr(game->nbr_signal[1] + 1);
    my_putstr(": ");
    nbr = verif((game->nbr_signal[0] - 1),
    (game->nbr_signal[1]), game, str_to_world_array(map));
    send(other_pid, nbr, 0, 1);
    cheak_errors(pass, buff, len);
    for (int i = 0; i <= 1; write(1, &buff[i], 1), i++);
    my_putstr(": ");
    send(other_pid, (buff[0] - 'A'), (buff[1] - '0'), 2);
    recive(1, game, 0);
    reciv_signal(game, game2, buff);
    my_putstr("\nmy positions:\n");
    print_map(str_to_world_array(map), game);
    tree_line(game2);
    return (0);
}
