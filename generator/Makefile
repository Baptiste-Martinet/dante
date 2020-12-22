##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	main.c		\
		tools.c		\
		generator.c	\
		direction.c	\
		exit.c


NAME	=	generator

all:	$(NAME)

$(NAME):
	(cd lib/my; make)
	gcc $(SRC) -Iinclude -Llib/my -lmy -o $(NAME) -Ofast -Og -O3

clean:
	rm -f $(NAME)
	(cd lib/my; make fclean)

fclean:	clean

re:	clean all

.PHONY: clean fclean re all
