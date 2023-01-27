/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-nelly.pereira-alves
** File description:
** game_loop
*/

#include "include/my.h"

bool_t convert_input(navy_t *navy, char *input)
{
    if (my_strlen(input) < 2)
        return (EXIT_FAILURE);
    vector_t position;
    position.x = (int)input[0] - 65;
    position.y = my_getnbr(char_to_str(input[1])) - 1;
    if (position.x > 7 || position.y > 7 ||
        position.x < 0 || position.y < 0)
        return (EXIT_FAILURE);
    navy->shoot_to_send = position;
    return (EXIT_SUCCESS);
}

int choose_attack(navy_t *navy)
{
    char *buff = malloc(sizeof(char) * 3);
    my_printf("attack: ");
    read(0, buff, 3);
    lseek(0, 2, 0);
    if (convert_input(navy, buff) == EXIT_SUCCESS)
        return (EXIT_SUCCESS);
    my_printf("wrong position\n");
    return (choose_attack(navy));
}

int player1(navy_t *navy)
{
    choose_attack(navy);
    send_shoot(navy);
    update_enemy_map(navy, receive_shoot_confirmation(navy));
    my_wait(1, TIMESPAN);
    my_printf("waiting for enemy’s attack...\n");
    my_wait(1, TIMESPAN);
    pause();
    receive_shoot(navy);
    send_shoot_confirmation(navy, check_shoot(navy));
    my_wait(1, TIMESPAN);
    return (EXIT_SUCCESS);
}

int player2(navy_t *navy)
{
    my_wait(1, TIMESPAN);
    my_printf("waiting for enemy’s attack...\n");
    my_wait(1, TIMESPAN);
    pause();
    receive_shoot(navy);
    send_shoot_confirmation(navy, check_shoot(navy));
    my_wait(1, TIMESPAN);
    choose_attack(navy);
    send_shoot(navy);
    update_enemy_map(navy, receive_shoot_confirmation(navy));
    return (EXIT_SUCCESS);
}

int game_loop(navy_t *navy)
{
    my_wait(1, 0);
    while (navy->game) {
        display_map(navy);
        if (navy->player_id == player_1) {
            player1(navy);
        }
        if (navy->player_id == player_2) {
            player2(navy);
        }
        if (navy->score == SCORE_TO_WIN) {
            my_printf("I won\n");
            return (EXIT_SUCCESS);
        }
        if (navy->enemy_score == SCORE_TO_WIN) {
            my_printf("Enemy won\n");
            return (EXIT_FAILURE);
        }
    }
    return (EXIT_SUCCESS);
}
