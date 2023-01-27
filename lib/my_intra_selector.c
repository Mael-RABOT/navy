/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-myprintf-mael.rabot
** File description:
** my_intra_selector.c
*/

#include "../include/my_printf.h"

int my_space(const char *format, va_list *params, int *i, int sum)
{
    my_putchar(' ');
    return (1 + selector(format, params, i, sum));
}

int extract_nbr(const char *format, int *i)
{
    int res = 0;
    int is_neg = 0;
    (*i) += 2;
    if (format[(*i)] == '-') {
        is_neg = 1;
        (*i) += 1;
    }
    while (my_str_isnum(format[(*i)]) == 1) {
        res = res * 10 + (format[(*i)] - 48);
        (*i) += 1;
    }
    (*i) -= 1;
    if (is_neg == 1)
        return (-res);
    return (res);
}

int minus_flag(const char *format, va_list *params, int *i, int sum)
{
    int to_print;
    int tmp = sum;
    (*i)--;
    int number = extract_nbr(format, i);
    sum += selector(format, params, i, sum);
    to_print = number - (sum - tmp);
    if (MAX(number, to_print) == sum)
        return (sum);
    for (int iterator = 0; iterator < to_print; iterator++)
        my_putchar(' ');
    return (sum + to_print);
}

int dot_flag(const char *format, va_list *params, int *i, int sum)
{
    int j = *i;
    int prc = extract_nbr(format, i);
    if (prc < 0) {
        (*i) -= 1;
        return (sum + my_putstr("%.0", 4) + my_put_nbr(prc, 0));
    }
    switch (format[(*i) + 1]) {
        case 'd': return (my_put_nbr(va_arg(*params, int), prc));
        case 'i': return (my_put_nbr(va_arg(*params, int), prc));
        case 'u': return (my_put_nbr_u(va_arg(*params, unsigned int), prc));
        case 's': return (my_putstr(va_arg(*params, char *), prc));
        case 'o': return (my_octal_print(va_arg(*params, unsigned int), prc));
        case 'x': return (my_hexa_print(va_arg(*params, unsigned int), 0, prc));
        case 'X': return (my_hexa_print(va_arg(*params, unsigned int),
            -32, prc));
    }
    (*i) = j;
    return dot_flag_bis(format, params, i, sum);
}

int dot_flag_bis(const char *format, va_list *params, int *i, int sum)
{
    int prc = extract_nbr(format, i);
    if (prc < 0) {
            (*i) -= 1;
            return (sum + my_putstr("%.0", 4) + my_put_nbr(prc, 0));
    }
    switch (format[(*i) + 1]) {
        case 'f': return (my_is_double_neg(va_arg(*params, double),
            prc, 0, 0));
        case 'F': return (my_is_double_neg(va_arg(*params, double),
            prc, -32, 0));
        case 'a': return (flag_a(va_arg(*params, double), prc, 0, 0));
        case 'A': return (flag_a(va_arg(*params, double), prc, -32, 0));
        case 'e': return (my_is_expo_neg(va_arg(*params, double), prc, 0, 0));
        case 'E': return (my_is_expo_neg(va_arg(*params, double),
            prc, -32, 0));
    }
    return (length_modifier(format, params, i, sum));
}
