/*
** EPITECH PROJECT, 2022
** Cpool
** File description:
** my_hashtag.c
*/

#include "../include/my_printf.h"

int hashtag_o(const char *format, va_list *params, int *i)
{
    int tmp = va_arg(*params, unsigned int);
    if (tmp != 0)
        my_putstr("0", 2);
        (*i)--;
        return (my_octal_print(tmp, 0) + 1);
    (*i)--;
    return (my_octal_print(tmp, 0));
}

int hashtag_x(const char *format, va_list *params, int is_lowercase, int *i)
{
    int tmp = va_arg(*params, unsigned int);
    (*i)--;
    if (tmp == 0)
        return (my_hexa_print(tmp, is_lowercase, 0));
    if (is_lowercase == 0)
        my_putstr("0x", 3);
    else
        my_putstr("0X", 3);
    return (my_hexa_print(tmp, is_lowercase, 0) + 2);
}

int hashtag_h(const char *format, va_list *params, int *i, int len)
{
    int interator = 0;
    while (format[*i] == '#') {
            (*i)++;
        }
    return (intra_selector(format, params, i, len));
}

int my_hashtag(const char *format, va_list *params, int *i, int len)
{
    (*i)++;
    switch (format[*i]) {
        case 'o': return (hashtag_o(format, params, i));
        case 'x': return (hashtag_x(format, params, 0, i));
        case 'X': return (hashtag_x(format, params, 1, i));
    }
    (*i)--;
    return (intra_selector(format, params, i, len) - 1);
}
