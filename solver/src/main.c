/*
** EPITECH PROJECT, 2019
** dante
** File description:
** main for dante
*/

#include "my.h"

static void check_around(game_t *game, int action)
{
    int dir[4] = {1, (game->width + 1), -1, (game->width * -1) - 1};

    for (int i = 0; action == 1 && i < 4; i++) {
        if (0 <= (game->indx + dir[i]) && (game->indx + dir[i])
            <= game->indx_end && game->map[game->indx + dir[i]] == '*') {
            game->last_indx = game->indx;
            game->indx += dir[i];
            game->looping = 0;
            break;
        }
    }
    for (int i = 3; game->looping == 1 && action == 2 && i >= 0; i--) {
        if (0 <= (game->indx + dir[i]) && (game->indx + dir[i])
            <= game->indx_end && game->map[game->indx + dir[i]] == 'o') {
            game->map[game->indx] = 'P';
            game->last_indx = game->indx;
            game->indx += dir[i];
            game->looping = 0;
            break;
        }
    }
}

static int find_path_iter(game_t *game)
{
    int temp;

    while (1) {
        game->looping = 1;
        game->map[game->indx] = 'o';
        if (game->indx == game->indx_end)
            return (1);
        check_around(game, 1);
        if (game->looping == 1 && game->map[game->last_indx] == 'o') {
            game->map[game->indx] = 'P';
            temp = game->last_indx;
            game->last_indx = game->indx;
            game->indx = temp;
            game->looping = 0;
        }
        check_around(game, 2);
        if (game->looping == 1)
            return (0);
    }
}

static void init(game_t *game, const char *filepath)
{
    game->map = get_map(filepath);
    if (!game->map)
        return;
    game->width = get_map_width(game->map);
    game->height = get_map_height(game->map);
    game->indx_end = (strlen(game->map) - 1);
    game->indx = 0;
    game->last_indx = 0;
    game->looping = 1;
}

static void p_deleter(char *map, game_t *game)
{
    int dir[4] = {1, (game->width + 1), -1, (game->width * -1) - 1};
    int count = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'P')
            map[i] = '*';
        count = 0;
        if (i != 0 && i != game->indx_end && map[i] == 'o') {
            for (int j = 0; j < 4; j++)
                if (0 <= (i + dir[j]) && (i + dir[j]) <= game->indx_end
                    && game->map[i + dir[j]] == 'o')
                    count++;
            if (count < 2)
                map[i] = '*';
        }
    }
}

int main(int ac, char const **av)
{
    game_t game;

    if (ac < 2) {
        display_error("2 arguments needed\n");
        return (84);
    }
    init(&game, av[1]);
    if (check_error_map(game) == 84) {
        return (84);
    }
    if (!find_path_iter(&game)) {
        printf("no solution found");
        return (84);
    }
    p_deleter(game.map, &game);
    printf("%s", game.map);
    free(game.map);
    return (0);
}