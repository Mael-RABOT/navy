/*
** EPITECH PROJECT, 2022
** Cpool
** File description:
** my_functions_bis.c
*/

#include "../include/my_printf.h"

int my_octal_print(unsigned int nb, int prc)
{
    char res[32];
    int sum = 0;
    int i = 0;
    while (nb > 0) {
        res[i] = (nb % 8) + 48;
        nb = nb / 8;
        i++;
    }
    res[i] = '\0';
    for (int i = 0; i < prc - my_strlen(res); i++) {
        sum += my_putchar('0');
        if (nb == 0 && prc - i == 0)
            return (sum + my_putchar('0'));
    }
    return sum + my_putstr(my_revstr(res), my_strlen(res));

}

int micro_printer(char *res, int i)
{
    for (int j = i - 1; j >= 0; j--)
        my_putchar(res[j]);
    return (i);
}

int my_hexa_print(unsigned int nb, int offset, int prc)
{
    int tmp, sum = 0;
    char res[32];
    unsigned int div = nb;
    int i = 0;
    for (; div > 0; i++, div /= 16) {
        tmp = div % 16;
        if (tmp < 10)
            tmp += '0';
        else
            tmp += 87 + offset;
        res[i] = tmp;
    }
    res[i] = '\0';
    for (int i = 0; i < prc - my_strlen(res); i++) {
        sum += my_putchar('0');
        if (nb == 0 && prc - i == 0)
            return (sum + my_putchar('0'));
    }
    return (sum + micro_printer(res, i));
}

int my_put_nbr_u(unsigned int nb, int prc)
{
    int sum = 0;
    if (nb >= 10) {
        sum += my_put_nbr_u(nb / 10, 0);
        sum += my_putchar(nb % 10 + '0');
    }
    if (nb < 10)
        sum += my_putchar(nb % 10 + '0');
    return (sum);
}
