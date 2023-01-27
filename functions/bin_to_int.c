/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-nelly.pereira-alves
** File description:
** bin_to_int
*/

#include "../include/my.h"

int bin_to_int(char *bin)
{
    int result = 0;
    int size = my_strlen(bin) - 1;
    for (int i = size; i >= 0; i--)
        result += ((int)bin[i] - 48) * my_compute_power_rec(2, size - i);
    return (result);
}
