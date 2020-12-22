/*
** EPITECH PROJECT, 2019
** dante
** File description:
** main for dante
*/

#include "my.h"

static int find_path(int indx, game_t *g)
{
    int status = 0;
    int dir[4] = {1, (g->width + 1), -1, (g->width * -1) - 1};

    g->map[indx] = 'P';
    print_map(g->map, g->speed);
    if (indx == LIM(g->width, g->height)) {
        g->map[indx] = 'o';
        return (1);
    }
    for (int i = 0; i < 4; i++) {
        if (0 <= (indx + dir[i]) && (indx + dir[i]) <= LIM(g->width, g->height)
            && g->map[indx + dir[i]] == '*') {
            status = find_path((indx + dir[i]), g);
            if (status)
                break;
        }
    }
    if (status)
        g->map[indx] = 'o';
    print_map(g->map, g->speed * 0.7);
    return (status);
}

static int get_map_height(char *map)
{
    int height = 0;

    if (!map)
        return (-1);
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n')
            height++;
    }
    return (height + 1);
}

static void init(game_t *g, const char *filepath, int speed)
{
    g->map = get_map(filepath);
    g->width = get_map_width(g->map);
    g->height = get_map_height(g->map);
    g->speed = speed;
}

static void display_error(const char *msg)
{
    write(2, msg, strlen(msg));
}

int main(int ac, char const **av)
{
    game_t g;

    if (ac != 3) {
        display_error("3 arguments needed\n\t./solver" \
            " [filepath][speed (in milisec)]\n");
        return (84);
    }
    init(&g, av[1], atoi(av[2]));
    if (check_error_map(g) == 84) {
        display_error("Wrong map file\n");
        return (84);
    }
    if (find_path(0, &g) == -1) {
        display_error("No path founded\n");
        return (84);
    }
    return (0);
}