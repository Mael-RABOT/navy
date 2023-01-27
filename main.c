/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-nelly.pereira-alves
** File description:
** main
*/

#include "include/my.h"

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        return (print_help());
    if (error_dump(ac, av) == EXIT_FAILURE)
        return (84);
    navy_t *navy = connection(ac, av[1], False);
    char **map = init_map(av[ac - 1]);
    if (map == NULL)
        return (84);
    navy->map = map;
    return (game_loop(navy));
}
