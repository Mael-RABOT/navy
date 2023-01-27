/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-nelly.pereira-alves
** File description:
** connect_to_enemy
*/

#include "include/my.h"

static navy_t *NAVY;

void sig_usr(int signo, siginfo_t *info, void *cx_)
{
    if (NAVY->str_len >= MSG_SIZE)
        NAVY->str_len = 0;
    if (signo == SIGKILL)
        return;
    if (signo == SIGUSR1)
        NAVY->str[NAVY->str_len++] = '1';
    else if (signo == SIGUSR2)
        NAVY->str[NAVY->str_len++] = '0';
    my_wait(0, TIMESPAN);
}

static void enemy_pid_handler(int signo, siginfo_t *info, void *cx_)
{
    NAVY->connection->enemy_pid = info->si_pid;
    return;
}

static void update_sigaction(void (*function)(int,  siginfo_t *, void *))
{
    NAVY->connection->sa->sa_sigaction = function;
    sigaction(SIGUSR1, NAVY->connection->sa, NULL);
    sigaction(SIGUSR2, NAVY->connection->sa, NULL);
}

navy_t *connect_player2(char *enemy_pid)
{
    NAVY->player_id = player_2;
    NAVY->connection->enemy_pid = my_getnbr(enemy_pid);
    update_sigaction(enemy_pid_handler);
    kill(NAVY->connection->enemy_pid, SIGUSR1);
    pause();
    update_sigaction(sig_usr);
    my_printf("successfully connected\n\n");
    return (NAVY);
}

navy_t *connection(int args_number, char *enemy_pid, bool_t blank_connection)
{
    if (blank_connection == True)
        return (init_navy());
    if ((NAVY = init_navy()) == NULL)
        return (NULL);
    if (args_number == 2) {
        NAVY->player_id = player_1;
        update_sigaction(enemy_pid_handler);
        my_printf("waiting for enemy connection...\n\n");
        pause();
        update_sigaction(sig_usr);
        my_printf("enemy connected\n\n");
        kill(NAVY->connection->enemy_pid, SIGUSR1);
        return (NAVY);
    }
    return (connect_player2(enemy_pid));
}
