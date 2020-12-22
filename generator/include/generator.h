/*
** EPITECH PROJECT, 2018
** include Day07
** File description:
** prototype of function
*/

#include "my.h"

/* PROJECT */

typedef struct maze {
    int x;
    int y;
    int i;
    int perfect;
    int size;
    char wall;
    char back;
    char room;
    char *map;
} maze_t;

void free_exit(maze_t *maze);
int generator(int ac, char **av);
int choose_direction(maze_t *maze);
void knock_some_wall_down(maze_t *maze);
int translate(maze_t *maze, int direction);
void init(maze_t *maze, int ac, char **av);
int is_direction_ok(maze_t *maze, int step);
void dig(maze_t *maze, int direction, int w);

/* TOOLS */

int my_rand(int x);
int my_atoi(char *str);
int are_str_same(char *str1, char *str2);
int is_str_num(char *str);
void my_printf(char *s, ...);