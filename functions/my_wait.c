/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-nelly.pereira-alves
** File description:
** my_wait
*/

#include "../include/my.h"

int my_wait(int seconds, int nanoseconds)
{
    struct timespec req = (struct timespec){seconds, nanoseconds};
    nanosleep(&req, NULL);
    return (EXIT_SUCCESS);
}
