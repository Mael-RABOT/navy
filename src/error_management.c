/*
** EPITECH PROJECT, 2022
** my_navy
** File description:
** error_management.c
*/

#include "../include/my.h"

int my_str_isalphanum(char c)
{
    if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9'))) {
        return 1;
    }
    return 0;
}

int is_valid_file_o(char *pathname)
{
    if (open(pathname, O_RDONLY) == -1)
        return 84;
    fclose(pathname);
}

int check_map(int argc, char *argv)
{
    int count = 0;
    int i = 0;

    for (i; argv[i]; i++) {
        if (argv[i] != 7)
            return 84;
        if (!my_str_isalphanum(argv[i]) || argv[i] != 58)
            return 84;
    }
}
