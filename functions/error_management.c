/*
** EPITECH PROJECT, 2022
** my_navy
** File description:
** error_management.c
*/

#include "../include/my.h"

int is_num(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 48 || str[i] > 57)
            return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int error_management(int argc, char **argv)
{
    if (argc < 2 || argc > 3)
        return (84);
    if (argc == 3)
        if (is_num(argv[argc - 2]) == EXIT_FAILURE)
            return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int error_dump(int argc, char **argv)
{
    if (error_management(argc, argv) == EXIT_FAILURE)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}
