/*
** EPITECH PROJECT, 2021
** navy2
** File description:
** signal_gestion
*/

#include "my.h"

void send(pid_t pid, int to_send, int to_send2, int nbr)
{
    usleep(100);
    int *sendo = malloc(2 * sizeof(int *));
    sendo[0] = to_send;
    sendo[1] = to_send2;
    for (int r = 0; r < nbr; r++){
        for (int i = 0; i != sendo[r]; i++){
            kill(pid, SIGUSR1);
            usleep(30);
        }
        sleep(1);
        kill(pid, SIGUSR2);
    }
}

void get_pid(int sig, siginfo_t *info, void *context)
{
    pid = (long)info->si_pid;
}

void recive(int nbrseg2, navy *game, int first)
{
    game->nbr_signal = malloc(2 * sizeof(int *));
    struct sigaction s, sa;
    int sig2, sig = 0;

    sigemptyset(&s.sa_mask);
    s.sa_flags = SA_SIGINFO;
    sa.sa_flags = SA_SIGINFO;
    s.sa_handler = term;
    sa.sa_sigaction = &get_pid;
    sigaction (SIGUSR1, &s, NULL);
    if (first == 1) sigaction (SIGUSR1, &sa, NULL);
    sigaction (SIGUSR2, &s, NULL);
    while (sig2 != nbrseg2) {
        sig = term(0, NULL, NULL);
        if (sig != 50) {
            game->nbr_signal[sig2] = sig;
            sig2++;
            term(50, NULL, NULL);
        }
    }
}

int term(int sig, siginfo_t *info,  void *context)
{
    static number = 0;
    static sig_old = 0;
    if (sig == SIGUSR1)
        number++;
    if (sig == SIGUSR2){
        sig_old = sig;
    }
    if (sig == 0){
        if (sig_old == SIGUSR2){
            sig_old = 0;
            return number;
        } else
            return 50;
    }
    if (sig == 50){
        number = 0;
        sig_old = 0;
    }
}

void reciv_signal(navy *game, navy2 *game2, char *buff)
{
    if (game->nbr_signal[0] == 1){
        my_putstr("hit\n");
        second_add_str(game2 , (buff[0] - 'A'),  (buff[1] - '0') - 1);
    } else if (game->nbr_signal[0] == 2){
        my_putstr("missed\n");
        second_no_str(game2, (buff[0] - 'A'),  (buff[1] - '0') - 1);
    }
}

