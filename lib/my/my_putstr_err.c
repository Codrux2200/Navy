/*
** EPITECH PROJECT, 2021
** MiniShell
** File description:
** my_putstr_err
*/
#include <unistd.h>

int my_putstr_err(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write (2, &str[i], 1);
    return (0);
}
