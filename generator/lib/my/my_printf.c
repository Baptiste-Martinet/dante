/*
** EPITECH PROJECT, 2018
** my printf
** File description:
** my printf
*/

#include "printf.h"

printf_tab_t f_tab[5] = {
        {'c', &dispchar},
        {'s', &dispstr},
        {'i', &dispnbr},
        {'d', &dispnbr},
        {0, 0}
};

void my_printf(char *s, ...)
{
    va_list arg;

    va_start(arg, s);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '%' && s[i + 1] == '%') {
            write(1, "%", 1);
            i = i + 1;
        } else if (s[i] == '%' && s[i + 1] != '%') {
            i = i + 1;
            for (int a = 0; f_tab[a].id != '\0'; a++) {
                if (f_tab[a].id == s[i])
                    f_tab[a].func(arg);
            }
        } else
            write(1, &s[i], 1);
    }
    va_end(arg);
}