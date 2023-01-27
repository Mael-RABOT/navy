/*
** EPITECH PROJECT, 2022
** Cpool
** File description:
** my_compute_square_root.c
*/

int my_compute_power_it(int nb, int p)
{
    int result = nb;

    if (p == 0) {
        return (1);
    } else if (p < 0) {
        return (0);
    }
    for (int i = 1; i < p; i++) {
        result *= nb;
    }
    return (result);
}

int my_compute_square_root(int nb)
{
    int result = 0;

    while (my_compute_power_it(result, 2) <= nb) {
        if (my_compute_power_it(result, 2) == nb) {
            return (result);
        }
        result++;
    }
    return (0);
}
