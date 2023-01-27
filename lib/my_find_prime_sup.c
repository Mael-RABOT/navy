/*
** EPITECH PROJECT, 2022
** Cpool
** File description:
** my_find_prime_sup.c
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int result = nb + 1;

    if (nb == 0) {
        return (2);
    }
    while (my_is_prime(result) == 0) {
        result++;
    }
    return (result);
}
