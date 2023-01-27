/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-myprintf-mael.rabot
** File description:
** bonus_functions.c
*/

#include "../include/my_printf.h"

int my_non_printable(char *str)
{
    int sum = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 127) {
            sum += my_putchar('\\');
            sum += my_put_nbr(str[i], 0);
            i++;
        }
        my_putchar(str[i]);
        i++;
    }
    return (sum);
}

int my_print_bin(unsigned int nb)
{
    int res[32];
    int sum = 0;
    while (nb > 0) {
        res[sum] = nb % 2;
        nb = nb / 2;
        sum++;
    }
    for (int j = sum - 1; j >= 0; j--)
        my_put_nbr(res[j], 0);
    return (sum);
}
