##
## EPITECH PROJECT, 2024
## B-MUL-200-MAR-2-1-myrpg-yanis.prevost
## File description:
## Makefile
##

SRCLIB	=	lib/my_atoi.c 		\
			lib/my_inttostr.c	\
			lib/my_strlen.c 	\
			lib/my_strcmp.c 	\
			lib/my_strcat.c 	\
			lib/my_printf.c 	\
			lib/my_put_nbr.c 	\
			lib/my_put_nbr_recursive.c 	\
			lib/my_putstr.c 	\
			lib/my_putchar.c 	\

SRCNAME	=	src/*.c	\
			src/setup/*.c	\
			src/menu/*.c	\

LIB 	= 	libmy.a

OBJLIB	=	$(SRCLIB:.c=.o)

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

NAME	=	my_rpg

UNAME	:=	$(shell uname -s)

1	= 	-I/opt/homebrew/Cellar/csfml/2.5.2_1/include/

2 	= 	-L/opt/homebrew/Cellar/csfml/2.5.2_1/lib

$(NAME)	:	$(LIB) $(OBJNAME)

ifeq ($(UNAME),Linux)
	gcc -o $(NAME) $(SRCNAME) -lmy -L./ $(CSFML) $(CFLAGS)
else ifeq ($(UNAME),Darwin)
	gcc -o $(NAME) $(SRCNAME) -lmy -L./ $(CSFML) $(1) $(2) -g3
endif

$(LIB)	:	$(OBJLIB)
	ar rc libmy.a lib/*.o
	rm lib/*.o

all	:	$(LIB) $(NAME)

clean	:
	rm -f $(OBJLIB) $(OBJNAME) libmy.a

fclean	: clean
	rm -f $(NAME)
	rm -rf my_rpg.dSYM

re	: 	fclean all
