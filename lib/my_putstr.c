/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday04-mael.rabot
** File description:
** my_putstr.c
*/

void my_putchar(char c);

int my_putstr_normal(char const *str)
{
    int i;

    i = 0;
    do {
        my_putchar(str[i]);
        i += 1;
    } while (str[i] != '\0');
    return (0);
}
