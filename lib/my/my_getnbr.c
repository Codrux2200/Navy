/*
** EPITECH PROJECT, 2020
** my getnbr
** File description:
** noidea
*/

#include <stdlib.h>

int my_strlen(char const *str);

int my_getnbr(char *str)
{
    int coeff = 1;
    char *nbr = malloc(my_strlen(str) * sizeof(char));
    int a = 0;
    int multi = 1;

    for (int i = 0, r = 0; str[i] != '\0'; i++){
        if (str[i] >= 48 && str[i] <= 57 ){
            nbr[r] = str[i];
            r++;
        } else if (str[i] == 45 && (str[i + 1] >= 48 && str[i + 1] <= 57 ))
            multi = -1;
        else
            break;
    }
    for (int v = 0; v != my_strlen(nbr); v++)
        coeff = coeff * 10;
    for (int i = 0; nbr[i] != '\0'; i++){
        coeff = coeff / 10;
        a = a + ((nbr[i] - 48) * coeff);
    }
    return (a * multi);
}