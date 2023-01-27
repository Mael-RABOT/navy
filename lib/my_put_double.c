/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-myprintf-mael.rabot
** File description:
** my_put_double.c
*/

#include <math.h>
#include "../include/my_printf.h"

char *my_nbr_to_str(char *str, double nombre, char flag, int *i)
{
    double nbr = nombre;
    int len = my_nbrlen(nbr);
    if ((int)nbr == 0)
        len = 1;
    double mult = my_power_rec(10, len - 1);
    int res;
    int j;
    for (j = 0; j < len; j++) {
        res = nbr / mult;
        str[(*i) + j] = res + '0';
        nbr -= res * mult;
        mult /= 10;
    }
    (*i) += j;
    str[(*i)] = '\0';
    return str;
}

int double_prc_null(double nbr, int offset)
{
    int sum = 0;
    int i = 0;
    char *str = malloc(sizeof(char) * (my_nbrlen(nbr) + 2));
    if (my_nbrlen(nbr) > 309 || isnan(nbr) == 1)
        return my_put_inf_or_nan(nbr, offset);
    if (nbr - (long long)nbr > 0.5)
        nbr++;
    my_strcpy(str, my_nbr_to_str(str, nbr, 0, &i));
    if (str[0] == 'i' && offset == -32)
        my_strcpy(str, "INF");
    sum += my_putstr(str, my_strlen(str));
    free(str);
    if (str[0] == 'i' || str[0] == 'I')
        return (sum);
    return (sum);
}

int my_put_double(double nbr, int prc, int offset, char flag)
{
    int sum = 0;
    int i = 0;
    double round;
    char *str = malloc(sizeof(char) * (my_nbrlen(nbr) + 3) * 2);
    if (my_nbrlen(nbr) > 309 || isnan(nbr) == 1)
        return my_put_inf_or_nan(nbr, offset);
    my_strcpy(str, my_nbr_to_str(str, nbr, 0, &i));
    nbr -= (long long)nbr;
    str[i] = '.';
    round = nbr * my_power_rec(10, prc);
    if (round - (long long)round > 0.5)
        round++;
    if (nbr > 1 && my_nbrlen(nbr) > 20)
        round = 0;
    for (i++, prc--; round < my_power_rec(10, prc) && prc > 0; prc--, i++)
        str[i] = '0';
    my_nbr_to_str(str, round, flag, &i);
    sum += my_putstr(trunct(str, i - 1, flag), -1);
    free(str);
    return (sum);
}

int my_is_double_neg(double nbr, int prc, int offset, char flag)
{
    if (nbr >= 0) {
        if (prc == 0)
            return (double_prc_null(nbr, offset));
        return (my_put_double(nbr, prc, offset, flag));
    }
    my_putchar('-');
    if (prc == 0)
        return (double_prc_null(-nbr, offset));
    return (my_put_double(-nbr, prc, offset, flag) + 1);
}
