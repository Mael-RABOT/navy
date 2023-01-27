/*
** EPITECH PROJECT, 2022
** Cpool
** File description:
** my_str_isnum.c
*/

#include <stdlib.h>
#include "../include/my_printf.h"

int check_letter(char c)
{
    char lower[26] = "abcdefghijklmnopqrstuvwxyz";
    char upper[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 26; i++) {
        if (lower[i] == c) {
            return (0);
        }
    }
    for (int i = 0; i < 26; i++) {
        if (upper[i] == c) {
            return (0);
        }
    }
    if (c == ' ' || c == '+' || c == '-') {
        return (0);
    }
    return (1);
}

int my_str_isnum(char const c)
{
    return (check_letter(c));
}

int len_to_ptr(int *ptr, int len)
{
    *ptr = len;
    return (0);
}

int my_nbrlen(double nbr)
{
    double mult = 1;
    int taille = 0;
    double res = 10;
    if (nbr < 1 && nbr > 0) {
        res = nbr;
        while ((int)res == 0) {
            res *= 10;
            taille++;
        }
        taille++;
    } else {
        while (res > 9) {
            res = nbr / mult;
            mult *= 10;
            taille++;
        }
    }
    return taille;
}

char *alpha_to_maj(char *str, int offset)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ('a' <= str[i] && str[i] <= 'z')
            str[i] = str[i] + offset;
        else
            str[i] = str[i];
    }
    return str;
}
