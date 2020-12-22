/*
** EPITECH PROJECT, 2018
** my printf
** File description:
** my printf
*/

#include "printf.h"

void dispchar(va_list arg)
{
    char c = va_arg(arg, int);

    write(1, &c, 1);
}

void dispstr(va_list arg)
{
    char *str = va_arg(arg, char *);

    for (int a = 0; str[a] != 0; a++)
        write(1, &str[a], 1);
}

int my_putnbr(int nb)
{
    char c;

    if (nb < 0) {
        write(1, "-", 1);
        my_putnbr(nb * -1);
    } else if (nb >= 10) {
        my_putnbr((nb - (nb % 10)) / 10);
        c = (nb % 10) + 48;
        write(1, &c, 1);
    } else {
        c = nb + 48;
        write(1, &c, 1);
    }
    return (0);
}

void dispnbr(va_list arg)
{
    my_putnbr(va_arg(arg, int));
}