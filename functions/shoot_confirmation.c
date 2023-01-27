/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-nelly.pereira-alves
** File description:
** shoot_confirmation
*/

#include "../include/my.h"

int send_shoot_confirmation(navy_t *navy, bool_t shoot_is_successful)
{
    if (shoot_is_successful)
        for (int i = 0; i < MSG_SIZE; i++) {
            kill(navy->connection->enemy_pid, SIG1);
            my_wait(0, TIMESPAN);
        }
    if (!shoot_is_successful)
        for (int i = 0; i < MSG_SIZE; i++) {
            kill(navy->connection->enemy_pid, SIG0);
            my_wait(0, TIMESPAN);
        }
    return (EXIT_SUCCESS);
}

bool_t receive_shoot_confirmation(navy_t *navy)
{
    int msg_value = bin_to_int(navy->str);
    if (msg_value != SHOOT_FAILED && msg_value != SHOOT_SUCCEED)
        return (EXIT_FAILURE);
    return (msg_value == SHOOT_SUCCEED) ? True : False;
}
