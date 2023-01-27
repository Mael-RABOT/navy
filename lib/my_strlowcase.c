/*
** EPITECH PROJECT, 2022
** Cpool
** File description:
** my_strlowcase.c
*/

#include <stddef.h>

char upper_to_lower_case(char c)
{
    char lower_cases[26] = "abcdefghijklmnopqrstuvwxyz";
    char upper_cases[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 26; i++) {
        if (upper_cases[i] == c) {
            return (lower_cases[i]);
        }
    }
    return (c);
}

int my_strlen7(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}

char *my_strlowcase(char *str)
{
    if (str == NULL) {
        return (NULL);
    }
    int len = my_strlen7(str);
    for (int i = 0; i < len; i++) {
        str[i] = upper_to_lower_case(str[i]);
    }
    return (str);
}
