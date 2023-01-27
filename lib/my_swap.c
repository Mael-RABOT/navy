/*
** EPITECH PROJECT, 2022
** B-CPE-100-LYN-1-1-cpoolday04-mael.rabot
** File description:
** my_swap.c
*/

void my_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
