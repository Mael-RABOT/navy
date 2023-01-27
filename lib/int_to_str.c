/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** int_to_str
*/

#include "stdlib.h"

char *int_to_str(int nb)
{
    if (nb == 0)
        return ("0");
    int res[32];
    char *tmp;
    int sum = 0;
    while (nb > 0) {
        res[sum] = nb % 10;
        nb = nb / 10;
        sum++;
    }
    tmp = malloc(sum);
    for (int j = sum - 1; j >= 0; j--) {
        tmp[(sum - 1) - j] = res[j] + 48;
    }
    tmp[sum] = '\0';
    return (tmp);
}
