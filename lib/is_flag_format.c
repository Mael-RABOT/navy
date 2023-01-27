/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-myprintf-mael.rabot
** File description:
** is_flag_format.c
*/

#include "../include/my_printf.h"

int get_nbr(const char *format, int *i)
{
    int res = 0;
    for (; '0' <= format[*i] && format[*i] <= '9'; (*i)++) {
        res *= 10;
        res = res + format[*i] - 48;
    }
    return res;
}

int is_flag_format(char c)
{
    if (c == '0' || c == '+' || c == '#' || c == '-' || c == ' ')
        return 1;
    return 0;
}

void check_flag_format(const char *format, int *i, int *flag)
{
    int j;
    for (j = *i; is_flag_format(format[j + 1]) == 1; j++) {
        if (format[j + 1] == '+')
            flag[0] = 1;
        if (format[j + 1] == '-')
            flag[1] = 1;
        if (format[j + 1] == '0')
            flag[2] = 1;
        if (format[j + 1] == '#')
            flag[3] = 1;
        if (format[j + 1] == ' ')
            flag[4] = 1;
    }
    (*i) = j + 1;
    if ('0' <= format[j + 1] && format[j + 1] <= '9') {
        flag[5] = my_nbrlen(get_nbr(format, i));
        (*i) -= flag[5];
    }
    (*i)--;
    return;
}
