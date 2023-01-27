/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday03-mael.rabot
** File description:
** my_put_nbr.c
*/

void my_putchar(char c);

int reverse_num(int nb)
{
    int reverse_nb = 0;
    int rest = 0;

    while (nb != 0) {
        rest = nb % 10;
        reverse_nb = reverse_nb * 10 + rest;
        nb /= 10;
    }
    return (reverse_nb);
}

int my_put_nbr_normal(int nb)
{
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    nb = reverse_num(nb);

    for (int i = 0; i < 10; i++) {
        my_putchar(nb % 10 + 48);
        nb = nb / 10;
        if (nb == 0) {
            break;
        }
    }
    my_putchar('\n');
    return (0);
}
