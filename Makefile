SRC	=	main.c	\
		display.c	\
		generation.c	\
		movements.c	\
		lib/center_string.c	\
		lib/int_size.c	\
		lib/int_to_str.c	\

NAME	=	2048

all:
	gcc $(SRC) -lncurses -o $(NAME)

fclean:
	rm -f $(NAME)
