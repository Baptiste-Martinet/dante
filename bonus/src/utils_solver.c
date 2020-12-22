/*
** EPITECH PROJECT, 2019
** dante
** File description:
** main for dante (maze solver)
*/

#include "my.h"

static int get_map_size(const char *filepath)
{
    struct stat sb;

    if (stat(filepath, &sb) == -1)
        return (0);
    return (sb.st_size);
}

char *get_map(const char *filepath)
{
    int fd;
    char *buff;
    int size = get_map_size(filepath);

    buff = malloc(sizeof(char) * size + 1);
    if (buff == NULL || size <= 0)
        return (NULL);
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (NULL);
    read(fd, buff, size);
    buff[size] = '\0';
    close(fd);
    return (buff);
}

int get_map_width(const char *map)
{
    int size = 0;

    if (!map)
        return (-1);
    for (; map[size] != '\0' && map[size] != '\n'; size++);
    return (size);
}

static int check_chars_map(char *map)
{
    for (int i = 0; map[i] != '\0'; i++)
        if (map[i] != '*' && map[i] != 'X' && map[i] != '\n')
            return (84);
    return (0);
}

int check_error_map(game_t game)
{
    int size = 0;

    if (!game.map)
        return (84);
    if (game.map[0] != '*')
        return (84);
    for (int i = 0; game.map[i] != '\0'; i++, size++) {
        if (game.map[i] == '\n') {
            if (size != game.width)
                return 84;
            size = -1;
        }
    }
    if (size != game.width || check_chars_map(game.map) == 84)
        return (84);
    return (0);
}