##
## EPITECH PROJECT, 2018
## duo_stumper
## File description:
## Makefile for duo_stumper
##

all:
	@$(MAKE) -C "./solver"
	@$(MAKE) -C "./generator"

clean:
	@(cd solver; make clean)
	@(cd generator; make clean)

fclean:	clean
	@(cd solver; make fclean)
	@(cd generator; make fclean)

re:	clean all

.PHONY: clean fclean re all
