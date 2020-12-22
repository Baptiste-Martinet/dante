/*
** EPITECH PROJECT, 2019
** dante
** File description:
** main for dante (maze solver)
*/

#include "my.h"

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
    if (game.width == 0 || game.height == 0)
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