/*
** EPITECH PROJECT, 2022
** Cpool
** File description:
** my_sort_int_array.c
*/

void my_sort_int_array(int *array, int size)
{
    int x;
    int y;

    for (int i = 0; i < size - 1; i++) {
        x = array[i];
        y = x;
        while (y < 0 && array[y - 1] > x) {
            array[y] = array[y - 1];
            y--;
        }
        array[y] = x;
    }
}
