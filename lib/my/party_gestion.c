/*
** EPITECH PROJECT, 2021
** navy2
** File description:
** party_gestion
*/

#include "my.h"
pid_t pid_first;

int player1(char *map, navy *game, navy2 *game2, int pass)
{
    char *buffer = lecture(map, game);

    game->nbr_final = 0;
    if (buffer[0] == ' ' || my_tablen(str_to_world_array(buffer)) < 12 ||
    my_tablen(str_to_world_array(buffer)) > 13)
        return 84;
    count(game, str_to_world_array(buffer));
    my_putstr("my_pid: ");
    my_put_nbr(getpid());
    my_putstr("\n");
    my_putstr("waiting for enemy connection...\n");
    recive(1, game, 1, 0);
    usleep(100);
    send(pid_first, 1, 0, 1);
    my_putstr("\nenemy connected");
    usleep(100);
    send(pid_first, game->nbr_final, 0, 1);
    recive(1, game, 0, 0);
    game2->nbr_final2 = game->nbr_signal[0];
    my_putstr("\n");
    party(buffer, game, game2, pass);
}

void get_pid(int sig, siginfo_t *info, void *context)
{
    pid_first = (long)info->si_pid;
}

void party(char *map, navy *game, navy2 *game2, int pass)
{
    char *buff = malloc(2 * sizeof(char *));
    size_t len = 2;

    my_putstr("\nmy positions:\n");
    print_map(str_to_world_array(map), game);
    my_putstr("\nenemy's positions:\n");
    print_map2(str_to_world_array("second\0"), game2);
    my_putstr("\n");
    while (game->end == 0) {
        pass = 0;
        if (the_end(game, game2) == 1) break;
        cheak_errors(pass, buff, len);
        for (int i = 0; i <= 1; write(1, &buff[i], 1), i++);
        usleep(300);
        my_putstr(": ");
        send(pid_first, (buff[0] - 'A'), (buff[1] - '0'), 2);
        recive(1, game, 0, 0);
        reciv_signal(game, game2, buff);
        party_suite(map, game, game2, buff);
    }
}

void party_suite(char *map, navy *game, navy2 *game2, char *buff)
{
    char x = ' ';
    char y = ' ';
    int nbr = 0;

    my_putstr("\nwaiting for enemy's attack...\n");
    recive(2, game, 0, 0);
    x = (game->nbr_signal[0] + 'A') - 1;
    y = (game->nbr_signal[1] + 1) + '0';
    write(1, &x, 1);
    my_put_nbr(game->nbr_signal[1] + 1);
    my_putstr(": ");
    nbr = verif((game->nbr_signal[0] - 1),
    (game->nbr_signal[1]), game, str_to_world_array(map));
    send(pid_first, nbr, 0, 1);
    my_putstr("\nmy positions:\n");
    print_map(str_to_world_array(map), game);
    my_putstr("\n");
    my_putstr("enemy's positions:\n");
    print_map2(str_to_world_array("second\0"), game2);
    my_putstr("\n");
}
