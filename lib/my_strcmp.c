/*
** EPITECH PROJECT, 2022
** Cpool
** File description:
** my_strcmp.c
*/

int my_strlen4(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}

int my_strcmp(char const *s1, char const *s2)
{
    int len1 = my_strlen4(s1);
    int len2 = my_strlen4(s2);
    for (int i = 0; i < len1; i++) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
    }
    return (0);
}
