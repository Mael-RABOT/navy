/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-myprintf-mael.rabot
** File description:
** my_flag_g.c
*/

#include "../include/my_printf.h"

int my_nbrlen_flag_g(double nbr)
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

char *trunct(char *str, int i, char flag)
{
    if (flag != 'g')
        return str;
    for (; str[i] == '0' && str[i + 1] == '\0'; i--)
        str[i] = '\0';
    if (str[i] == '.')
        str[i] = '\0';
    return str;
}

int prc_g(double nbr, int prc, int len, char flag)
{
    if (prc == 0)
        prc = 1;
    if (flag == 'f') {
        if (0 < nbr && nbr < 1)
            return len + prc - 1;
        return prc - len - 1;
    }
    if (flag == 'e')
        return prc - 1;
}

int flag_g(double nbr, int prc, int ofst)
{
    int len;
    if (nbr < 0)
        len = my_nbrlen(-nbr) - 1;
    else
        len = my_nbrlen(nbr) - 1;
    if (nbr > -1 && nbr < 1 && nbr != 0) {
        if (-len < -4)
            return (my_is_expo_neg(nbr, prc_g(nbr, prc, len, 'e'), ofst, 'g'));
        return (my_is_double_neg(nbr, prc_g(nbr, prc, len, 'f'), ofst, 'g'));
    }
    if (len >= prc)
        return (my_is_expo_neg(nbr, prc_g(nbr, prc, len, 'e'), ofst, 'g'));
    return (my_is_double_neg(nbr, prc_g(nbr, prc, len, 'f'), ofst, 'g'));
}
