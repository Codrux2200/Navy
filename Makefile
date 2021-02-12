##
## EPITECH PROJECT, 2021
## navy2
## File description:
## Makefile
##

SRC     =      ./lib/my/my_put_nbr.c	\
				./lib/my/my_putstr.c	\
				./lib/my/my_strlen.c 	\
				./lib/my/my_getnbr.c   \
				./lib/my/my_putstr_err.c   \
				./lib/my/signal_gestion.c   \
				./lib/my/party_gestion.c   \
				./lib/my/str_to_world_array.c   \
				./lib/my/map_printing.c   \
				./lib/my/gestion_point.c   \
				./lib/my/the_end.c   \
				./lib/my/errors_funtion.c   \


OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

NAME2	= 	./lib/my/my.h

all:	compil_lib compil_my

compil_lib:	$(OBJ)
		ar rc $(NAME) $(OBJ)

compil_my:
		cp $(NAME2) ./include
		gcc -o navy main.c libmy.a


clean:
		rm -f $(OBJ)

fclean:	clean
		rm libmy.a
		rm include/my.h
		rm navy

re: fclean all

