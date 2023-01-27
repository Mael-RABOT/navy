/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-myprintf-mael.rabot
** File description:
** zero_flag.c
*/

#include "../include/my_printf.h"

char *zero_parser_follow(const char *format, va_list *params, int *i, int len)
{
    switch (format[(*i)]) {
        case 'a': return ("");
        case 'A': return ("");
        case 'e': return ("");
        case 'E': return ("");
        case 'f': return ("");
        case 'F': return ("");
        case 'g': return ("");
        case 'G': return ("");
    }
    return ("");
}

char *zero_parser(const char *format, va_list *params, int *i, int len)
{
    switch (format[(*i) + 1]) {
        case 'd': return (zero_flag_d(va_arg(*params, int), 0));
        case 'i': return (plus_flag_d(va_arg(*params, int), 0));
        case 'c': return (plus_flag_c(format, params, i, len));
        case 'C': return (plus_flag_c_up(format, params, i, len));
        case 's': return (va_arg(*params, char *));
        case 'S': return (plus_non_printable(va_arg(*params, char *)));
        case 'o': return (plus_octal_conv(va_arg(*params, unsigned int)));
        case 'b': return (plus_bin_conv(va_arg(*params, unsigned int)));
        case 'x': return (plus_hexa_conv(va_arg(*params, unsigned int), 0));
        case 'X': return (plus_hexa_conv(va_arg(*params, unsigned int), -32));
        case 'p': return (my_strcat("0x", plus_hexa_conv(
                    va_arg(*params, unsigned int), 0)));
        case 'u': return (plus_flag_u(va_arg(*params, unsigned int)));
    }
    return (zero_parser_follow(format, params, i, len));
}

int zero_flag(const char *format, va_list *params, int *i, int len)
{
    int spaces = extract_nbr(format, i);
    char *to_print = zero_parser(format, params, i, len);
    int str_len = my_strlen(to_print);
    spaces = spaces - str_len;
    if (spaces <= 0)
        return (my_putstr(to_print, sizeof(to_print)));
    if (to_print[0] == '-') {
        my_putchar('-');
        spaces -= 1;
        to_print[0] = '0';
    }
    for (int i = 0; i < spaces; i++)
        my_putchar('0');
    return (spaces + my_putstr(to_print, sizeof(to_print)));
}
