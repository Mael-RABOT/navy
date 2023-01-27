##
## EPITECH PROJECT, 2023
## B-PSU-100-LYN-1-1-navy-nelly.pereira-alves
## File description:
## Makefile
##

SRC	=		main.c	\
			game_loop.c	\
			connect_to_enemy.c	\
			map_update.c	\
			functions/init_navy.c	\
			functions/bin_to_int.c	\
			functions/int_to_bin.c	\
			functions/position_manager.c	\
			functions/shoot_confirmation.c	\
			functions/my_wait.c	\
			functions/display.c	\
			functions/error_management.c \
			functions/parsing.c \
			functions/init_map.c	\

NAME	=	navy

LIBS = -L./lib/ -lmy

FLAGS = -Wall

$(NAME):	$(SRC) cpl
	gcc -o $(NAME) $(SRC) $(LIBS) $(FLAGS)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *.out

cpl:
	cd lib && make && cd ..

re: cpl fclean all

run:
	@gcc -o $(NAME) $(SRC) $(LIBS) $(CSFML)
	@./$(NAME) $(ARGS)
