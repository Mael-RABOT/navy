/*
** EPITECH PROJECT, 2022
** Cpool
** File description:
** my_str_isalpha.c
*/

int my_strlen7(char const *str);

int check_number(char c)
{
    char nb[10] = "0123456789";
    for (int i = 0; i < 10; i++) {
        if (nb[i] == c) {
            return (0);
        }
    }
    if (c == ' ' || c == '+' || c == '-') {
        return (0);
    }
    return (1);
}

int my_str_isalpha(char const *str)
{
    int len = my_strlen7(str);
    int result = 0;
    for (int i = 0; i < len; i++) {
        result = check_number(str[i]);
    }
    return (result);
}
