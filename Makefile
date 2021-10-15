NAME = libftprintf.a
SRC = ft_printf.c\
	  ft_print.c\
	  ft_count_write.c
SRC_O	= $(SRC:.c=.o)
INCLUDES = ft_printf.h
CC	=	gcc
CFLAGS	=	-Werror -Wextra -Wall
LIB	= ar rc

all	:	$(NAME)

$(NAME)	: $(SRC_O)
	$(MAKE) -C libft
	cp libft/libft.a .
	mv libft.a $(NAME)
	$(LIB) $(NAME) $(SRC_O)

%.o	:	%.c ft_printf.h
	$(CC) $(CFLAGS) -c $<


clean	:
	$(MAKE) -C libft/ clean
	rm -f $(SRC_O)

fclean	: clean
	$(MAKE) -C libft/ fclean
	rm -f $(NAME)

re	: fclean all
