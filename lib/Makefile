##
## EPITECH PROJECT, 2022
## B-MUL-100-LYN-1-1-myradar-mael.rabot
## File description:
## Makefile
##

SRC	=	$(wildcard ./*.c)

OBJ	=	$(SRC:.c=.o)

LIB	=	libmy.a

all:	$(LIB)

$(LIB):	$(OBJ)
	ar rc $(LIB) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(LIB)
	rm -f *.out

re: fclean all
