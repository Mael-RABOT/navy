/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-nelly.pereira-alves
** File description:
** display
*/

#include "../include/my.h"

int print_help(void)
{
    char *buff = malloc(sizeof(char) * MAN_SIZE + 1);
    int fd;
    if ((fd = open(MAN, O_RDONLY)) == -1)
        return (EXIT_FAILURE);
    read(fd, buff, MAN_SIZE);
    my_printf("%s", buff);
    close(fd);
    return (EXIT_SUCCESS);
}

void print_map(char **map)
{
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; ++j)
            my_printf("%c", map[i][j]);
        my_printf("\n");
    }
    my_printf("\n");
}

void display_map(navy_t *navy)
{
    my_printf("my positions:\n |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i < MAP_HEIGHT; i++) {
        my_printf("%d|", i + 1);
        for (int j = 0; j < MAP_WIDTH - 1; j++)
            my_printf("%c ", navy->map[i][j]);
        my_printf("%c\n", navy->map[i][MAP_WIDTH - 1]);
    }
    my_printf("\n");
    my_printf("enemy’s positions:\n |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i < MAP_HEIGHT; i++) {
        my_printf("%d|", i + 1);
        for (int j = 0; j < MAP_WIDTH - 1; j++)
            my_printf("%c ", navy->enemy_map[i][j]);
        my_printf("%c\n", navy->enemy_map[i][MAP_WIDTH - 1]);
    }
    my_printf("\n");
}
