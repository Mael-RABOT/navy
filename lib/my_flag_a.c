/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-myprintf-mael.rabot
** File description:
** my_flag_a.c
*/

#include "../include/my_printf.h"

char *precision_null_a(char *str, double nbr)
{
    str[0] = '1';
    if (nbr - 1 >= 0.5)
        str[0]++;
    return str;
}

char *my_double_to_hex(char *str, double nbr, int prc)
{
    long left_part = (long)nbr;
    double right_part = nbr - left_part;
    double res;
    char *base = "0123456789abcdef";
    if (prc == 0)
        return precision_null_a(str, nbr);
    str[0] += base[left_part];
    str[1] = '.';
    res = right_part * 16;
    for (int i = 0; i < prc - 1; i++) {
        str[i + 2] = base[(int)res];
        right_part = res - (int)res;
        res = right_part * 16;
    }
    right_part = res - (int)res;
    if (right_part * 16 > 8)
        res++;
    str[prc + 1] = base[(int)res];
    str[prc + 2] = '\0';
    return (str);
}

int power_flag_a(double *nbr)
{
    int pow = 0;
    while (*nbr > 2) {
        *nbr /= 2;
        pow++;
    }
    while (*nbr < 1) {
        *nbr *= 2;
        pow--;
    }
    return pow;
}

int flag_a(double nbr, int prc, int offset, char trc)
{
    int sum = 0;
    int first = 1;
    char *str = malloc(sizeof(char) * (prc + 3));
    if (nbr < 0) {
        sum += my_putchar('-');
        nbr = -nbr;
    }
    int pow = power_flag_a(&nbr);
    sum += my_putchar('0') + my_putchar('x' + offset);
    trunct(my_double_to_hex(str, nbr, prc), prc + 1, trc);
    sum += my_putstr(alpha_to_maj(str, offset), prc + 3);
    free(str);
    sum += my_putchar('p' + offset);
    if (pow >= 0)
        sum += my_putchar('+');
    return (sum + my_put_nbr(pow, 0));
}
