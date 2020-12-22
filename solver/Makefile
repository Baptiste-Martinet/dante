##
## EPITECH PROJECT, 2018
## dante
## File description:
## Makefile for dante
##

SRC	=	src/main.c \
		src/utils_solver.c \
		src/check_error_map.c

OBJ	=	$(SRC:.c=.o)

NAME    =    solver

CFLAGS += -O3 -Ofast -Og -Wall -Wextra -Iinclude

LDFLAGS =

all:    $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	clean all

.PHONY: clean fclean re all
