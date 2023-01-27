/*
** EPITECH PROJECT, 2022
** Cpool
** File description:
** my_printf.c
*/

#include "../include/my_printf.h"

int selector_bis(const char *format, va_list *params, int *i, int sum)
{
    switch (format[(*i) + 1]) {
        case 'e': return (my_is_expo_neg(va_arg(*params, double),
            STD_PREC, 0, 0));
        case 'E': return (my_is_expo_neg(va_arg(*params, double),
            STD_PREC, -32, 0));
        case 'f': return (my_is_double_neg(va_arg(*params, double),
            STD_PREC, 0, 0));
        case 'F': return (my_is_double_neg(va_arg(*params, double),
            STD_PREC, -32, 0));
        case 'g': return (flag_g(va_arg(*params, double), STD_PREC, 0));
        case 'G': return (flag_g(va_arg(*params, double), STD_PREC, -32));
        case 'n': return (len_to_ptr(va_arg(*params, int *), sum));
        case 'a': return (flag_a(va_arg(*params, double), 13, 0, 'g'));
        case 'A': return (flag_a(va_arg(*params, double), 13, -32, 'g'));
    }
    my_putchar('%');
    my_putchar(format[(*i) + 1]);
    (*i) + 1;
    return (2);
}

int selector(const char *format, va_list *params, int *i, int sum)
{
    switch (format[(*i) + 1]) {
        case 'd': return (my_put_nbr(va_arg(*params, int), 0));
        case 'i': return (my_put_nbr(va_arg(*params, int), 0));
        case 'c': return (my_putchar(va_arg(*params, int)));
        case 'C': return (my_putchar_c(va_arg(*params, int), sum));
        case 's': return (my_putstr(va_arg(*params, char *), -1));
        case 'b': return (my_print_bin(va_arg(*params, unsigned int)));
        case 'S': return (my_non_printable(va_arg(*params, char *)));
        case 'o': return (my_octal_print(va_arg(*params, unsigned int), 0));
        case 'p':
            my_putstr("0x", 3);
            return (my_hexa_print(va_arg(*params, unsigned int), 0, 0) + 2);
        case 'u': return (my_put_nbr_u(va_arg(*params, unsigned int), 0));
        case 'x': return (my_hexa_print(va_arg(*params, unsigned int), 0, 0));
        case 'X': return (my_hexa_print(va_arg(*params, unsigned int), -32, 0));
        case '%': return (my_putchar('%'));
    }
    return (selector_bis(format, params, i, sum));
}

int length_modifier(const char *format, va_list *params, int *i, int sum)
{
    switch (format[(*i) + 1]) {
        case 'h': return (chose_h_selector(format, params, i, sum));
        case 'l': return (chose_l_selector(format, params, i, sum));
        case 'L': return (my_l_selector(format, params, i, sum));
    }
    return (selector(format, params, i, sum));
}

int intra_selector(const char *format, va_list *params, int *i, int sum)
{
    int flag[6] = {0, 0, 0, 0, 0, 0};
    check_flag_format(format, i, flag);
    if (format[(*i) + flag[5] + 1] == '.') {
        (*i) += flag[5];
        return dot_flag(format, params, i, sum);
    }
    if (flag[1] == 1)
        return (minus_flag(format, params, i, sum));
    if (flag[0] == 1 || flag[5] != 0) {
        (*i)--;
        return (plus_flag(format, params, i, sum));
    }
    if (flag[2] == 1)
        return (zero_flag(format, params, i, sum));
    if (flag[3] == 1)
        return (my_hashtag(format, params, i, sum));
    if (flag[4] == 1)
        return (my_space(format, params, i, sum));
    return (length_modifier(format, params, i, sum));
}

int my_printf(const char *format, ...)
{
    int i = 0;
    int *ptr = &i;
    int sum = 0;
    va_list params;
    va_start(params, format);
    for (; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] == 'm') {
            sum += print_erno();
            i += 2;
        }
        if (format[i] == '%') {
            sum += intra_selector(format, &params, ptr, sum);
            i++;
        } else
            sum += my_putchar(format[i]);
        if (sum == -1)
            return (sum);
    }
    va_end(params);
    return (sum);
}
