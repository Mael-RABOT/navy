/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-myprintf-mael.rabot
** File description:
** plus_str_functions.c
*/

#include "../include/my_printf.h"

char *plus_flag_c(const char *format, va_list *params, int *i, int len)
{
    char *res;
    res = malloc(2);
    res[0] = va_arg(*params, int);
    res[1] = '\0';
    return (res);
}

char *plus_flag_c_up(const char *format, va_list *params, int *i, int len)
{
    char *res;
    res = malloc(2);
    res[0] = va_arg(*params, int);
    res[1] = '\0';
    if (res[0] < 0 || res[0] > 127)
        return ("");
    return (res);
}

char *plus_non_printable(char *str)
{
    int sum = 0;
    char *res;
    res = malloc(sizeof(str));
    int i = 0;
    char *tmp;
    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 127) {
            res = malloc(sizeof(res) + 1);
            res[i] = ('\\');
            tmp = plus_flag_d(str[i], 0);
            res = malloc(sizeof(res) + sizeof(tmp));
            res = my_strcat(res, tmp);
            i += 1 + sizeof(tmp);
        }
        res[i] = (str[i]);
        i++;
    }
    res = malloc(sizeof(res) + 1);
    res[i + 1] = '\0';
    return (res);
}
