/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday03-mael.rabot
** File description:
** check if a paramet n is either negative or positiv,
** printing N or P as a result
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    my_putchar('\n');
    return (0);
}
