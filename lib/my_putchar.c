/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday07-nelly.pereira-alves
** File description:
** my_putchar.c
*/

#include "../include/my.h"

int my_putchar_two(char c)
{
    write(2, &c, 1);
    return (EXIT_SUCCESS);
}

int my_perror(char *str)
{
    for (int i = 0; i < my_strlen(str); i++)
        my_putchar_two(str[i]);
    return (84);
}
