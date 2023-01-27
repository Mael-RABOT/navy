/*
** EPITECH PROJECT, 2022
** undefined
** File description:
** my_strlen.c
*/

#include "../include/my_printf.h"

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i += 1;
    }
    return i;
}
