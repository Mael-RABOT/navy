/*
** EPITECH PROJECT, 2022
** Cpool
** File description:
** my_strncpy.c
*/

int my_putstr(char const *str);

int my_strlen2(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}

char *my_strncpy(char *dest, char const *src, int n)
{
    for (int i = 0; i < n; i++) {
        if (src[i] == '\0') {
            dest[i] = '\0';
        } else {
            dest[i] = src[i];
        }
    }
    return (dest);
}
