/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-nelly.pereira-alves
** File description:
** int_to_bin
*/

#include "../include/my.h"

void add_zero(char **src)
{
    char *result = malloc(sizeof(char) * (MSG_SIZE / 2));
    for (int i = 0; i < (MSG_SIZE / 2) - my_strlen(*src); i++)
        my_strcat(result, "0");
    my_strcat(result, *src);
    *src = result;
}

char *int_to_bin(unsigned int nb)
{
    int res[32];
    char *tmp;
    int sum = 0;
    while (nb > 0) {
        res[sum] = nb % 2;
        nb = nb / 2;
        sum++;
    }
    tmp = malloc(sum);
    for (int j = sum - 1; j >= 0; j--) {
        tmp[(sum - 1) - j] = res[j] + 48;
    }
    tmp[sum] = '\0';
    add_zero(&tmp);
    return (tmp);
}
