/*
** EPITECH PROJECT, 2019
** dante
** File description:
** tools
*/

#include "my.h"

int my_rand(int x)
{
    return (rand() % x);
}

int my_strlen(char *str)
{
    int len;

    for (len = 0; str[len] != '\0'; len++);
    return len;
}

int is_str_num(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}

int are_str_same(char *str1, char *str2)
{
    if (str1 == NULL || str2 == NULL)
        return 0;
    if (my_strlen(str1) != my_strlen(str2))
        return 0;
    for (int i = 0; str1[i] != '\0'; i++)
        if (str1[i] != str2[i])
            return 0;
    return 1;
}

int my_atoi(char *str)
{
    int nb = 0;
    int neg = 1;
    int i = 0;

    if (str[0] == '-') {
        neg = -1;
        i = 1;
    }
    for (; str[i] != '\0'; i++)
        nb = (nb * 10) + (str[i] - 48);
    return (nb * neg);
}
