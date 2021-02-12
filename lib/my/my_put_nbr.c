/*
** EPITECH PROJECT, 2020
** my_putnbr
** File description:
** my_putnbr
*/
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int my_putstr(char const *str);

int part(int nbr)
{
    if (nbr > 2147483548 || nbr < -2147483548){
        write (2, "int_max !!", 12);
        return 84;
    }
    if (nbr < 0){
        my_putstr("-");
        my_put_nbr(nbr * -1);
        return (0);
    } else if (nbr == 0){
        my_putstr("0");
        return (0);
    } else
        return (1);
}

unsigned int part2(unsigned int nbr)
{
    if (nbr < 0){
        my_putstr("-");
        my_put_nbr(nbr * -1);
        return (0);
    } else if (nbr == 0){
        my_putstr("0");
        return (0);
    } else
        return (1);
}

int my_put_nbr(int nbr)
{
    int i = 0;
    int result = 1;
    int save = 0;
    int count = 0;

    if (part(nbr) == 1){
        for (int c = nbr; c > 0; c = c/10, i++, save++);
        for (; i != 1; i--)
            result = result * 10;
        for (char a; nbr > 0; a++) {
            int chiffre = nbr / result;
            a = chiffre + 48;
            write (1, &a, 1);
            nbr = nbr % result;
            result = result / 10;
            count++;
        }
        for (; count != save; count++)
            write (1, "0", 1);
    }
}

unsigned int my_put_nbr2(unsigned int nbr)
{
    int i = 0;
    unsigned int result = 1;
    int save = 0;
    int count = 0;

    if (part2(nbr) == 1){
        for (unsigned int c = nbr; c > 0; c = c/10, i++, save++);
        for (; i != 1; i--)
            result = result * 10;
        for (char a; nbr > 0; a++) {
            unsigned int chiffre = nbr / result;
            a = chiffre + 48;
            write (1, &a, 1);
            nbr = nbr % result;
            result = result / 10;
            count++;
        }
        for (; count != save; count++)
            write (1, "0", 1);
    }
}