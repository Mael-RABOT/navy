/*
** EPITECH PROJECT, 2022
** Cpool
** File description:
** my_str_isprintable.c
*/

int my_strlen(char const *str);

int check_if_printable(char c)
{
    if (c <= 32 || c >= 127) {
        return (0);
    }
    return (1);
}

int my_str_isprintable(char const *str)
{
    int len = my_strlen(str);
    for (int i = 0; i < len; i++) {
        if (check_if_printable(str[i] == 0)) {
            return (0);
        }
    }
    return (1);
}
