/*
** EPITECH PROJECT, 2022
** Cpool
** File description:
** my_strstr.c
*/

#include <stddef.h>
#include <stdio.h>

int my_strlen3(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}

int check(char *str, char const *to_find, int i, int len)
{
    if (i + len > my_strlen3(str)) {
        return (-1);
    }
    for (int j = 0; j < len; j++) {
        if (str[i + j] != to_find[j]) {
            return (-1);
        }
    }
    return (i);
}

char *my_strstr(char *str, char const *to_find)
{
    int i;

    int result = -1;
    int len1 = my_strlen3(str);
    int len2 = my_strlen3(to_find);
    if (len2 == 0) {
        return (str);
    }
    for (int i = 0; i < len1; i++) {
        if (str[i] == to_find[0]) {
            result = check(str, to_find, i, len2);
        }
    }
    if (result != -1) {
        return (str + result);
    }
    return (NULL);
}
