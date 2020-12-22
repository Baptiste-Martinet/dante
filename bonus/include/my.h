/*
** EPITECH PROJECT, 2018
** solver
** File description:
** solver
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#define LIM(w, h) (w * h + h - 2)

typedef struct game_s {
    char *map;
    int width;
    int height;
    int speed;
} game_t;

/* utils */
char *get_map(const char *filepath);
int get_map_width(const char *map);
int check_error_map(game_t game);

/* utils bonus */
void print_map(char *map, float speed);

#endif /* MY_H_ */