/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-navy-nelly.pereira-alves
** File description:
** init_map
*/

#include "../include/my.h"

void add_ship(char **map, vector_t start, vector_t end, int size)
{
    for (int i = start.x; i <= end.x; i++)
        for (int j = start.y; j <= end.y; j++)
            map[i][j] = int_to_str(size)[0];

}

int letter_to_int(char c)
{
    int value = (int)c - 'A';
    return (value);
}

char **transform_lines(char **lines)
{
    vector_t start;
    vector_t end;
    char **map = malloc(sizeof(char) * MAP_HEIGHT * MAP_WIDTH);
    for (int i = 0; i < MAP_WIDTH; i++) {
        map[i] = malloc(sizeof(char) * MAP_WIDTH);
        for (int j = 0; j < MAP_HEIGHT; j++)
            map[i][j] = '.';
    }
    for (int i = 0; lines[i] != NULL; i++) {
        start = (vector_t){letter_to_int(lines[i][2]),
                        my_getnbr(char_to_str(lines[i][3]))};
        end = (vector_t){letter_to_int(lines[i][5]),
                        my_getnbr(char_to_str(lines[i][6]))};
        add_ship(map, start, end, my_getnbr(char_to_str(lines[i][0])));
    }
    return (map);
}

char **init_map(char *path)
{
    char **map = malloc(sizeof(char) * MAP_WIDTH * MAP_HEIGHT);
    FILE *stream = fopen(path, "r");
    if (!stream)
        return (NULL);
    size_t len = 0;
    char *line = NULL;
    int i = 0;
    while (getline(&line, &len, stream) != -1) {
        map[i] = malloc(sizeof(char) * MAP_WIDTH);
        my_strcpy(map[i++], line);
    }
    map[i] = NULL;
    fclose(stream);
    return (transform_lines(map));
}
