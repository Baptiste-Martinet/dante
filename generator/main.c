/*
** EPITECH PROJECT, 2018
** dante
** File description:
** main
*/

#include "generator.h"

static void build_wall(maze_t *maze)
{
    maze->map = malloc(sizeof(char) * maze->size);
    for (int i = 0; i < maze->size; i++) {
        if (i > 0 && (i + 1) % (maze->x + 1) == 0)
            maze->map[i] = '\n';
        else
            maze->map[i] = maze->wall;
    }
    maze->map[maze->size - 1] = '\0';
    maze->map[0] = maze->back;
}

void init(maze_t *maze, int ac, char **av)
{
    maze->wall = 'X';
    maze->room = '*';
    maze->back = '_';
    maze->x = my_atoi(av[1]);
    maze->y = my_atoi(av[2]);
    if (maze->x < 3 && maze->y < 3)
        exit(84);
    maze->size = (maze->x + 1) * maze->y;
    maze->i = 0;
    if (ac == 4)
        maze->perfect = 1;
    else
        maze->perfect = 0;
    build_wall(maze);
}

static int is_error_in_input(int ac, char **av)
{
    for (int i = 1; i < 3; i++) {
        if (is_str_num(av[i]) == 0)
            return 1;
    }
    if (ac == 4) {
        if (are_str_same(av[3], "perfect") == 0)
            return 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 3 || ac == 4) {
        if (is_error_in_input(ac, av) == 1)
            return 84;
        return (generator(ac, av));
    } else
        return 84;
}
