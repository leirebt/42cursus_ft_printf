NAME = libftprintf.a
SRC =
BONUS =
SRC_O	=	$(SRC:.c=.o)
BONUS_O =	$(BONUS:.c=.o)
CC	=	gcc
CFLAGS	=	-Werror -Wextra -Wall                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
LIB	= ar rc

all	:	$(NAME)

$(NAME)	:	$(SRC_O) $(BONUS_O)
	$(LIB) $@ $<

%.o	:	%.c libftprintf.h
	$(CC) $(CFLAGS) -c $<

bonus : $(BONUS_O)
	$(LIB) $(NAME) $^

clean	:
	rm -f $(SRC_O) $(BONUS_O)

fclean	: clean
	rm -f $(NAME)

re	: fclean all