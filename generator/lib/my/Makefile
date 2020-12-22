##
## EPITECH PROJECT, 2018
## task01Day01
## File description:
## compiles lib
##

SRC	=	my_printf.c	\
		my_disp.c

NAME	=	my

OBJ	=	$(SRC:.c=.o)

CFLAGS += -I../../include

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc lib$(NAME).a $(OBJ)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all

.PHONY:	clean fclean re all
