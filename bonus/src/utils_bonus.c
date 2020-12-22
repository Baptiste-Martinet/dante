/*
** EPITECH PROJECT, 2019
** dante
** File description:
** main for dante (maze solver)
*/

#include "my.h"

void print_map(char *map, float speed)
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" \
        "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'P')
            printf("\x1B[31m%c\x1B[0m", map[i]);
        else if (map[i] == 'o')
            printf("\x1B[32m%c\x1B[0m", map[i]);
        else
            printf("%c", map[i]);
    }
    printf("\n");
    usleep(speed);
}