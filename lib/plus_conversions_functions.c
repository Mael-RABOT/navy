/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-myprintf-mael.rabot
** File description:
** plus_conversions_functions.c
*/

#include "../include/my_printf.h"

char *plus_bin_conv(unsigned int nb)
{
    int res[32];
    char *tmp;
    int sum = 0;
    while (nb > 0) {
        res[sum] = nb % 2;
        nb = nb / 2;
        sum++;
    }
    tmp = malloc(sum);
    for (int j = sum - 1; j >= 0; j--) {
        tmp[(sum - 1) - j] = res[j] + 48;
    }
    tmp[sum] = '\0';
    return (tmp);
}

char *plus_octal_conv(unsigned int nb)
{
    int res[32];
    char *tmp;
    int sum = 0;
    while (nb > 0) {
        res[sum] = nb % 8;
        nb = nb / 8;
        sum++;
    }
    tmp = malloc(sum);
    for (int j = sum - 1; j >= 0; j--) {
        tmp[(sum - 1) - j] = res[j] + 48;
    }
    tmp[sum] = '\0';
    return (tmp);
}

char *plus_hexa_conv(unsigned int nb, int offset)
{
    char *res;
    int tmp;
    if (nb == 0)
        return ("0");
    unsigned int div = nb;
    int i = 0;
    res = malloc(32);
    while (div > 0) {
        tmp = div % 16;
        if (tmp < 10)
            tmp += '0';
        else
            tmp += 87 + offset;
        res[i] = tmp;
        div /= 16;
        i++;
    }
    res[i] = '\0';
    my_revstr(res);
    return (res);
}
