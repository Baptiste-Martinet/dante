/*
** EPITECH PROJECT, 2018
** include Day07
** File description:
** prototype of function
*/

#include "my.h"

typedef struct printf_tab {
    char id;
    void (*func)(va_list);
} printf_tab_t;

void dispchar(va_list arg);
void dispstr(va_list arg);
void dispnbr(va_list arg);

