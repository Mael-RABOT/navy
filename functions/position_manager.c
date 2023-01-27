/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-nelly.pereira-alves
** File description:
** position_manager
*/

#include "../include/my.h"

char **cut_binary(char *binary)
{
    char **arr = malloc(sizeof(char) * 8);
    arr[0] = malloc(sizeof(char) * 4);
    arr[1] = malloc(sizeof(char) * 4);
    int i;
    for (i = 0; i < MSG_SIZE / 2; i++)
        arr[0][i] = binary[i];
    for (int j = i; j < MSG_SIZE; j++)
        arr[1][j - i] = binary[j];
    return (arr);
}

int receive_shoot(navy_t *navy)
{
    vector_t new_pos = (vector_t){bin_to_int(cut_binary(navy->str)[0]),
                                bin_to_int(cut_binary(navy->str)[1])};
    if (new_pos.x > 7 || new_pos.y > 7)
        return (EXIT_FAILURE);
    navy->str_len = 0;
    navy->shoot_received = new_pos;
    return (EXIT_SUCCESS);
}

int send_shoot(navy_t *navy)
{
    char *binary = malloc(sizeof(char) * 8);
    my_strcat(binary, int_to_bin(navy->shoot_to_send.x));
    my_strcat(binary, int_to_bin(navy->shoot_to_send.y));
    if (my_strlen(binary) != MSG_SIZE)
        return (EXIT_FAILURE);
    for (int i = 0; i < MSG_SIZE; i++) {
        if (binary[i] == '0') {
            kill(navy->connection->enemy_pid, SIG0);
            my_wait(0, TIMESPAN);
        }
        if (binary[i] == '1') {
            kill(navy->connection->enemy_pid, SIG1);
            my_wait(0, TIMESPAN);
        }
    }
    return (EXIT_SUCCESS);
}
