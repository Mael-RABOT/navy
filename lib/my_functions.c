/*
** EPITECH PROJECT, 2022
** Cpool
** File description:
** my_functions.c
*/

#include "../include/my_printf.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int my_putstr(char const *str, int prc)
{
    int i;

    i = 0;
    do {
        my_putchar(str[i]);
        i += 1;
    } while (str[i] != '\0' && (i < prc || prc < 0));
    return (i);
}

int my_putchar_c(char c, int sum)
{
    if (c < 0 || c > 127)
        return (crash(sum));
    return (my_putchar(c));
}

int my_put_nbr(unsigned int nombre, int prc)
{
    int sum = 0;
    if (nombre == 2147483648) {
        sum += my_putchar('-');
        return sum + my_put_nbr_u(2147483648, prc);
    }
    int nb = nombre;
    if (nb < 0) {
        sum += my_putchar('-');
        nb = -nb;
        }
    for (int i = 0; i < prc - my_nbrlen(nb); i++)
        sum += my_putchar('0');
    if (nb >= 10) {
        sum += my_put_nbr(nb / 10, 0);
        sum += my_putchar(nb % 10 + '0');
        }
    if (nb < 10)
        sum += my_putchar(nb % 10 + '0');
    return (sum);
}
