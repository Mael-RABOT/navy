/*
** EPITECH PROJECT, 2022
** Cpool
** File description:
** my_str_islower.c
*/

int my_str_isalpha(char const *str);
int my_strlen7(char const *str);

int check_for_uppercase(char c)
{
    char letter[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 10; i++) {
        if (letter[i] == c) {
            return (0);
        }
    }
    return (1);
}

int my_str_islower(char const *str)
{
    int len = my_strlen7(str);
    int result = 0;
    if (my_str_isalpha(str) == 0) {
        return (0);
    }
    for (int i = 0; i < len; i++) {
        result += check_for_uppercase(str[i]);
    }
    if (result != len) {
        return (0);
    }
    return (1);
}
