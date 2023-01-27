/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-myprintf-mael.rabot
** File description:
** my_put_exponant.c
*/

#include <math.h>
#include "../include/my_printf.h"

int my_put_exponant(double nbr, int prc, int offset, char flag)
{
    int sum = 0;
    double nombre;
    char exponant[] = "\0\0\0\0";
    exponant[0] = 'e' + offset;
    if (my_nbrlen(nbr) > 309 || isnan(nbr) == 1)
        return my_put_inf_or_nan(nbr, offset);
    if (nbr < 1 && nbr > 0) {
        nombre = nbr * my_power_rec(10, my_nbrlen(nbr) - 1);
        exponant[1] = '-';
    } else {
        nombre = nbr / my_power_rec(10, my_nbrlen(nbr) - 1);
        exponant[1] = '+';
    }
    if (prc == 0)
        sum += double_prc_null(nombre, offset);
    else
        sum += my_put_double(nombre, prc, offset, flag);
    if (my_nbrlen(nbr) < 11)
        exponant[2] = '0';
    return (sum + my_putstr(exponant, 4) + my_put_nbr(my_nbrlen(nbr) - 1, 0));
}

int my_is_expo_neg(double nbr, int prc, int offset, char flag)
{
    if (nbr >= 0)
        return (my_put_exponant(nbr, prc, offset, flag));
    my_putchar('-');
    return (my_put_exponant(-nbr, prc, offset, flag) + 1);
}
