/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-myprintf-mael.rabot
** File description:
** my_functions_fourth.c
*/

#include <math.h>
#include "../include/my_printf.h"

int my_put_inf_or_nan(double nbr, int offset)
{
    if (isnan(nbr) == 1) {
        if (offset == 0)
            return my_putstr("nan", 4);
        if (offset == -32)
            return my_putstr("NAN", 4);
    }
    if (offset == 0)
        return my_putstr("inf", 4);
    if (offset == -32)
        return my_putstr("INF", 4);
}

int print_erno(void)
{
    return my_putstr("Success", -1);
}

int crash(int len)
{
    return (-(len + 1));
}
