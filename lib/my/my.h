/*
** EPITECH PROJECT, 2021
** navy2
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_
#include <signal.h>
#include <stddef.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int *compare(char **coord, int x, int y);
char *convert(char *buff);
char **convert_coord(char **brut_coord);
int my_putstr_err(char const *str);
int my_strlen(char *str);
int my_putstr(char const *str);
int my_put_nbr(int nbr);
int my_getnbr(char *str);
char **str_to_world_array(char *str);
void send(pid_t pid, int to_send, int to_send2, int nbr);
int coule(char **coord, int x, int y);
char **init_map();
int my_tablen(char **tab);
void cheak_errors(int pass, char *buff, size_t len);
typedef struct navy navy;
struct navy{
    char **dead_boat;
    char **nop;
    int* nbr_signal;
    int end;
    int nbr_final;
};
typedef struct navy2 navy2;
struct navy2{
    char **dead_boat2;
    char **nop2;
    int nbr_final2;
};
void second_add_str(navy2 *game, int x, int y);
void second_no_str(navy2 *game, int x, int y);
void add_no(navy *game, int x, int y);
int no_coule(char **coord, int x, int y);
void add_str(navy *game, int x, int y);
int verif(int x, int y, navy *game, char **coord);
void party2(char *map, navy *game, pid_t pid_other, navy2 *game2);
void recive(int nbrseg2, navy *game, int first);
void party(char *map, navy *game, navy2 *game2, int pass);
void print_map(char **coord, navy *game);
void print_map2(char **coord, navy2 *game);
void party_suite(char *map, navy *game, navy2 *game2, char *buff);
int player1(char *map, navy *game, navy2 *game2, int pass);
int player2(char *map, pid_t pid_other, navy *game, navy2 *game2);
char *lecture(char *file, navy *game);
int party2_suite(char *map, navy *game, pid_t other_pid, navy2 *game2);
void reciv_signal(navy *game, navy2 *game2, char *buff);
void tree_line(navy2 *game2);
void count(navy *game, char **coord);
int term(int sig, siginfo_t *info, void *context);
int the_end(navy *game, navy2 *game2);
void init(navy *game, navy2 *game2);
pid_t pid;
#endif /* !MY_H_ */
