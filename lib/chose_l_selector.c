/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-myprintf-mael.rabot
** File description:
** my_hh_selector.c
*/

#include "../include/my_printf.h"

int my_l_selector_double(const char *format, va_list *params, int *i, int sum)
{
    switch (format[(*i) + 1]) {
        case 'a': return (flag_a(
                (long double)va_arg(*params, double), 13, 0, 'g'));
        case 'A': return (flag_a(
                (long double)va_arg(*params, double), 13, -32, 'g'));
        case 'e': return (my_is_expo_neg(
            (long double)va_arg(*params, double), STD_PREC, 0, 0));
        case 'E': return (my_is_expo_neg(
            (long double)va_arg(*params, double), STD_PREC, -32, 0));
        case 'f': return (my_is_double_neg(
            (long double)va_arg(*params, double), STD_PREC, 0, 0));
        case 'F': return (my_is_double_neg(
            (long double)va_arg(*params, double), STD_PREC, -32, 0));
        case 'g': return (flag_g(
            (long double)va_arg(*params, double), STD_PREC, 0));
        case 'G': return (flag_g(
            (long double)va_arg(*params, double), STD_PREC, -32));
    }
    return (0);
}

int my_l_selector(const char *format, va_list *params, int *i, int sum)
{
    switch (format[(*i) + 1]) {
        case 'd': return (my_put_nbr((long int)va_arg(*params, int), 0));
        case 'i': return (my_put_nbr((long int)va_arg(*params, int), 0));
        case 'b': return (my_print_bin(
            (unsigned long int)va_arg(*params, unsigned int)));
        case 'o': return (my_octal_print(
            (unsigned long int)va_arg(*params, unsigned int), 0));
        case 'u': return (my_put_nbr_u(
            (unsigned long int)va_arg(*params, unsigned int), 0));
        case 'x': return (my_hexa_print(
            (unsigned long int)va_arg(*params, unsigned int), 0, 0));
        case 'X': return (my_hexa_print(
            (unsigned long int)va_arg(*params, unsigned int), 1, 0));
    }
    return (my_l_selector_double(format, params, i, sum));
}

int my_ll_selector(const char *format, va_list *params, int *i, int sum)
{
    switch (format[(*i) + 1]) {
        case 'd': return (my_put_nbr((long long int)va_arg(*params, int), 0));
        case 'i': return (my_put_nbr((long long int)va_arg(*params, int), 0));
        case 'b': return (my_print_bin(
            (unsigned long long int)va_arg(*params, unsigned int)));
        case 'o': return (my_octal_print(
            (unsigned long long int)va_arg(*params, unsigned int), 0));
        case 'u': return (my_put_nbr_u(
            (unsigned long long int)va_arg(*params, unsigned int), 0));
        case 'x': return (my_hexa_print(
            (unsigned long long int)va_arg(*params, unsigned int), 0, 0));
        case 'X': return (my_hexa_print(
            (unsigned long long int)va_arg(*params, unsigned int), 1, 0));
    }
}

int chose_l_selector(const char *format, va_list *params, int *i, int sum)
{
    (*i) += 1;
    if (format[(*i) + 1] == 'l') {
        (*i) += 1;
        return (my_ll_selector(format, params, i, sum));
    } else {
        return (my_l_selector(format, params, i, sum));
    }
}
