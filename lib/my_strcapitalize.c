/*
** EPITECH PROJECT, 2022
** Cpool
** File description:
** my_strcapitalize.c
*/

char *my_strlowcase(char *str);
int my_strlen7(char const *str);
char lower_to_upper_case(char c);

int can_be_upped(char c)
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

char *make_letter_capital(char *str, int len, int i)
{
    for (int j = 0; j < len - i; j++) {
        if (can_be_upped(str[j]) == 0 && can_be_upped(str[j + 1]) == 1) {
            str[j + 1] = lower_to_upper_case(str[j + 1]);
            break;
        }
        if (str[j] == '\0' || str[j] == ' ') {
            return (str);
        }
    }
    return (str);
}

char *my_strcapitalize(char *str)
{
    str = my_strlowcase(str);
    int len = my_strlen7(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            make_letter_capital(str, len, i);
        }
    }
    return (str);
}
