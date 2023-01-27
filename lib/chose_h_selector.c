/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-myprintf-mael.rabot
** File description:
** my_hh_selector.c
*/

#include "../include/my_printf.h"

int my_h_selector(const char *format, va_list *params, int *i, int len)
{
    switch (format[(*i) + 1]) {
        case 'd': return (my_put_nbr((short int)va_arg(*params, int), 0));
        case 'i': return (my_put_nbr((short int)va_arg(*params, int), 0));
        case 'b': return (my_print_bin(
            (unsigned short int)va_arg(*params, unsigned int)));
        case 'o': return (my_octal_print(
            (unsigned short int)va_arg(*params, unsigned int), 0));
        case 'u': return (my_put_nbr_u(
            (unsigned short int)va_arg(*params, unsigned int), 0));
        case 'x': return (my_hexa_print(
            (unsigned short int)va_arg(*params, unsigned int), 0, 0));
        case 'X': return (my_hexa_print(
            (unsigned short int)va_arg(*params, unsigned int), 1, 0));
    }
}

int my_hh_selector(const char *format, va_list *params, int *i, int len)
{
    switch (format[(*i) + 1]) {
        case 'd': return (my_put_nbr((char)va_arg(*params, int), 0));
        case 'i': return (my_put_nbr((char)va_arg(*params, int), 0));
        case 'b': return (my_print_bin(
            (unsigned char)va_arg(*params, unsigned int)));
        case 'o': return (my_octal_print(
            (unsigned char)va_arg(*params, unsigned int), 0));
        case 'u': return (my_put_nbr_u(
            (unsigned char)va_arg(*params, unsigned int), 0));
        case 'x': return (my_hexa_print(
            (unsigned char)va_arg(*params, unsigned int), 0, 0));
        case 'X': return (my_hexa_print(
            (unsigned char)va_arg(*params, unsigned int), 1, 0));
    }
}

int chose_h_selector(const char *format, va_list *params, int *i, int len)
{
    (*i) += 1;
    if (format[(*i) + 1] == 'h') {
        (*i) += 1;
        return (my_hh_selector(format, params, i, len));
    } else {
        return (my_h_selector(format, params, i, len));
    }
}
