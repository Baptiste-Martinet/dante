/*
** EPITECH PROJECT, 2018
** dante
** File description:
** direction
*/

#include "generator.h"

void dig(maze_t *maze, int direction, int w)
{
    int step = translate(maze, direction);
    char c;

    if (w == 1)
        c = maze->back;
    else
        c = maze->room;
    maze->map[maze->i + step] = c;
    maze->i = maze->i + (step * 2);
    maze->map[maze->i] = c;
}

int translate(maze_t *maze, int direction)
{
    switch (direction) {
        case (0):
            return (-1 * (maze->x + 1));
        case (1):
            return 1;
        case (2):
            return (maze->x + 1);
        case (3):
            return -1;
    }
    exit(84);
}

int is_direction_ok(maze_t *maze, int direction)
{
    int step = translate(maze, direction);
    int next_i = maze->i + (step * 2);

    if (next_i < 0 || next_i >= ((maze->x + 1) * maze->y))
        return 0;
    if (maze->map[next_i] != maze->wall
    || maze->map[maze->i + step] != maze->wall)
        return 0;
    if (maze->map[next_i] == '\n' || maze->map[maze->i + step] == '\n')
        return 0;
    return 1;
}

int choose_direction(maze_t *maze)
{
    int rand = my_rand(4);

    if (is_direction_ok(maze, rand) == 0)
        return choose_direction(maze);
    return rand;
}
