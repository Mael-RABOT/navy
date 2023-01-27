/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-nelly.pereira-alves
** File description:
** init_NAVY
*/

#include "../include/my.h"

struct sigaction *init_sigaction(void)
{
    struct sigaction *sa;
    sa = malloc(sizeof(struct sigaction));
    sigemptyset(&sa->sa_mask);
    sa->sa_flags = SA_RESTART | SA_SIGINFO;
    sigaction(SIGUSR1, sa, NULL);
    sigaction(SIGUSR2, sa, NULL);
    return (sa);
}

static connection_t *init_connection(void)
{
    connection_t *connection = malloc(sizeof(connection_t));
    int pid = getpid();
    my_printf("my_pid: %d\n", pid);
    connection->personnal_pid = pid;
    connection->enemy_pid = 0;
    connection->sa = malloc(sizeof(struct sigaction));
    connection->sa = init_sigaction();
    return (connection);
}

static char **init_empty_map(void)
{
    char **map = malloc(sizeof(char) * MAP_HEIGHT * MAP_WIDTH);
    for (int i = 0; i < MAP_WIDTH; i++) {
        map[i] = malloc(sizeof(char) * MAP_WIDTH);
        for (int j = 0; j < MAP_HEIGHT; j++)
            map[i][j] = '.';
    }
    return (map);
}

navy_t *init_navy(void)
{
    navy_t *navy = malloc(sizeof(navy_t));
    navy->str = malloc(sizeof(char) * 8);
    if (!navy->str)
        return (NULL);
    navy->str_len = 0;
    navy->connection = malloc(sizeof(connection_t));
    navy->connection = init_connection();
    navy->game = True;
    navy->score = 0;
    navy->enemy_score = 0;
    navy->enemy_map = init_empty_map();
    return (navy);
}
