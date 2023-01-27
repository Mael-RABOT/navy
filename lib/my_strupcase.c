/*
** EPITECH PROJECT, 2022
** Cpool
** File description:
** my_strupcase.c
*/

#include <stddef.h>

char lower_to_upper_case(char c)
{
    char lower_cases[26] = "abcdefghijklmnopqrstuvwxyz";
    char upper_cases[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 26; i++) {
        if (lower_cases[i] == c) {
            return (upper_cases[i]);
        }
    }
    return (c);
}

int my_strlen6(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}

char *my_strupcase(char *str)
{
    if (str == NULL) {
        return (NULL);
    }
    int len = my_strlen6(str);
    for (int i = 0; i < len; i++) {
        str[i] = lower_to_upper_case(str[i]);
    }
    return (str);
}
