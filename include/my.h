/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-navy-nelly.pereira-alves
** File description:
** my.h
*/

#ifndef TEK1_MY_H_
    #define TEK1_MY_H_

    #define MIN(x, y)           (((x) < (y)) ? (x) : (y))
    #define MAX(x, y)           (((x) > (y)) ? (x) : (y))
    #define ABS(x)              ((x) > 0) ? (x) : (-x)
    #define RAD_TO_DEGRES(x)    (x) * (180 / PI)
    #define NOT_ZERO(x)         ((x) < 0) ? 0 : (x)

    #define PI                  3.14159

    #define SCORE_TO_WIN        14

    #define MSG_SIZE            8
    #define TIMESPAN            1000000
    #define MAP_HEIGHT          8
    #define MAP_WIDTH           8

    #define SIG0                SIGUSR2
    #define SIG1                SIGUSR1
    #define SHOOT_FAILED        0
    #define SHOOT_SUCCEED       255

    #define MAN                 "README.txt"
    #define MAN_SIZE            1000

    #include "mylib.h"
    #include "my_printf.h"
    #include "my_structs.h"

    #include <signal.h>
    #include <math.h>
    #include <stdarg.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stddef.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <sys/syscall.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <stdint.h>
    #include <time.h>
    #include <sys/sysmacros.h>
    #include <pwd.h>
    #include <grp.h>
    #include <errno.h>
    #include <string.h>

    void update_enemy_map(navy_t *navy, bool_t shoot_successful);
    void print_map(char **map);
    void display_map(navy_t *navy);

    int game_loop(navy_t *navy);
    int bin_to_int(char *bin);
    int my_wait(int seconds, int nanoseconds);
    int receive_shoot(navy_t *navy);
    int send_shoot(navy_t *navy);
    int send_shoot_confirmation(navy_t *navy, bool_t shoot_is_successful);

    bool_t receive_shoot_confirmation(navy_t *navy);
    bool_t check_shoot(navy_t *navy);

    char *int_to_bin(unsigned int nb);

    char **init_map(char *path);

    navy_t *init_navy(void);
    navy_t *connection(int args_number, char *enemy_pid,
        bool_t blank_connection);

    //error_management
    int error_dump(int argc, char **argv);

    //print
    int print_help(void);

    //parsing
    char *get_script(char *file);
    int my_read(int fd, int *buf, int nbytes);

#endif /* !TEK1_MY_H_ */
