/*
** EPITECH PROJECT, 2018
** dante
** File description:
** generator
*/

#include "generator.h"

void free_exit(maze_t *maze)
{
    maze->map[maze->size - 2] = maze->room;
    if (maze->x % 2 == 0 && maze->y % 2 == 0) {
        if (my_rand(2) == 0)
            maze->map[(maze->size - 2) + translate(maze, 0)] = maze->room;
        else
            maze->map[maze->size - 3] = maze->room;
    }
}

void knock_some_wall_down(maze_t *maze)
{
    int rand = my_rand(maze->size - 2);

    while (1) {
        if ((rand % (2 * (maze->y + 1)) - (maze->y + 1)) % 2 != 1
            && maze->map[rand] == maze->wall) {
            maze->map[rand] = maze->room;
            return;
        }
        rand = rand + 1;
        if (rand >= (maze->size - 2)) {
            knock_some_wall_down(maze);
            return;
        }
    }
}