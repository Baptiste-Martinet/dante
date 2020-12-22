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

typedef struct game_s {
    char *map;
    int width;
    int height;
    int indx_end;
    int indx;
    int last_indx;
    int looping;
} game_t;

/* utils */
char *get_map(const char *filepath);
int get_map_width(const char *map);
int get_map_height(char *map);
void display_error(const char *msg);

/*check map error */
int check_error_map(game_t game);

#endif /* MY_H_ */