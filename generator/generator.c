/*
** EPITECH PROJECT, 2018
** dante
** File description:
** generator
*/

#include "generator.h"

int is_there_a_way(maze_t *maze)
{
    int ways = 0;

    for (int i = 0; i < 4; i++) {
        if (is_direction_ok(maze, i) == 1)
            ways = ways + 1;
    }
    return ways;
}

int is_there_a_way_back(maze_t *maze)
{
    int way = -1;
    int step;

    for (int i = 0; i < 4; i++) {
        step = translate(maze, i);
        if (maze->i + step < maze->size && maze->i + step >= 0
        && maze->map[maze->i + step] == maze->back)
            way = i;
    }
    return way;
}

void do_that_maze(maze_t *maze)
{
    while (1) {
        if (is_there_a_way(maze) != 0) {
            dig(maze, choose_direction(maze), 1);
        } else if (is_there_a_way_back(maze) != -1) {
            maze->map[maze->i] = maze->room;
            dig(maze, is_there_a_way_back(maze), 2);
        } else
            return;
    }
}

int generator(int ac, char **av)
{
    maze_t maze;
    float tmp;

    srand(time(NULL));
    init(&maze, ac, av);
    do_that_maze(&maze);
    if (maze.x % 2 == 0 || maze.y % 2 == 0)
        free_exit(&maze);
    if (maze.perfect == 0) {
        tmp = (maze.size - 2) / 32;
        if (tmp < 1)
            tmp = 1;
        for (int i = 0; i < tmp; i++)
            knock_some_wall_down(&maze);
    }
    write(1, maze.map, maze.size - 1);
    free(maze.map);
    return 0;
}