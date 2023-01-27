/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-nelly.pereira-alves
** File description:
** map_update
*/

#include "include/my.h"

static char *pos_to_str(vector_t position)
{
    char *str = malloc(sizeof(char) * 3);
    str[0] = (char)(position.x + 65);
    str[1] = int_to_str(position.y + 1)[0];
    str[2] = '\0';
    return (str);
}

static void update_map(char ***map, vector_t position, char value)
{
    (*map)[position.x][position.y] = value;
}

bool_t check_shoot(navy_t *navy)
{
    int x = navy->shoot_received.x;
    int y = navy->shoot_received.y;
    char *str_pos = pos_to_str(navy->shoot_received);
    if (navy->map[x][y] != '.' && navy->map[x][y] != 'o'
        && navy->map[x][y] != 'x') {
        my_printf("%s: hit\n\n", str_pos);
        update_map(&navy->map, navy->shoot_received, 'x');
        return (True);
    }
    update_map(&navy->enemy_map, navy->shoot_received, 'o');
    my_printf("%s: missed\n\n", str_pos);
    return (False);
}

void update_enemy_map(navy_t *navy, bool_t shoot_successful)
{
    char *str_pos = pos_to_str(navy->shoot_to_send);
    if (shoot_successful == True) {
        my_printf("%s: hit\n\n", str_pos);
        update_map(&navy->enemy_map, navy->shoot_to_send, 'x');
        return;
    }
    update_map(&navy->enemy_map, navy->shoot_to_send, 'o');
    my_printf("%s: missed\n\n", str_pos);
    return;
}
