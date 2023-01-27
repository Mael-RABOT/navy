/*
** EPITECH PROJECT, 2022
** Cpool
** File description:
** my_strcat.c
*/

int my_strlen_third(char const *str)
{
    int i;

    i = 0;
    while (*(str + i) != '\0') {
        i += 1;
    }
    return (i);
}

char *my_strncat(char *dest, char const *src)
{
    int len = my_strlen_third(dest);
    int len2 = my_strlen_third(src);
    int i = 0;
    char result[len + len2];
    for (int i = 0; i < len; i++) {
        result[i] = dest[i];
    }
    for (int j = 0; j < len2; j++) {
        result[len + j] = src[j];
    }
    return (dest);
}
