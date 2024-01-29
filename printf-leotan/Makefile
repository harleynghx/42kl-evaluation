COMPILER	= cc

FLAGS		= -Wall -Wextra -Werror

NAME		= libftprintf.a

SRC			= ft_printf.c \
				ft_printf_util.c

OBJ			= $(SRC:.c=.o)

$(NAME):
		$(COMPILER) $(FLAGS) -I./ -c $(SRC)
		ar -rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
