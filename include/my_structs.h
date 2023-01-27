/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-nelly.pereira-alves
** File description:
** my_structs
*/

#include "my.h"

#ifndef B_CPE_110_LYN_1_1_NAVY_NELLY_PEREIRA_MY_STRUCTS_H_
    #define B_CPE_110_LYN_1_1_NAVY_NELLY_PEREIRA_MY_STRUCTS_H_

typedef enum {False, True} bool_t;

typedef enum {player_1, player_2} player_id_t;

typedef struct vector {
    int x;
    int y;
} vector_t;

typedef struct connection {
    int personnal_pid;
    int enemy_pid;
    struct sigaction *sa;
} connection_t;

typedef struct navy {
    bool_t game;
    int score;
    int enemy_score;
    connection_t *connection;
    player_id_t player_id;
    char *str;
    int str_len;
    vector_t shoot_received;
    vector_t shoot_to_send;
    char **map;
    char **enemy_map;
} navy_t;

#endif /* !B_CPE_110_LYN_1_1_NAVY_NELLY_PEREIRA_MY_STRUCTS_H_ */
