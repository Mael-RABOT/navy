/*
** EPITECH PROJECT, 2022
** Cpool
** File description:
** my_strncmp.c
*/

int my_strlen5(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int len1 = my_strlen5(s1);
    int len2 = my_strlen5(s2);
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
    }
    return (0);
}
