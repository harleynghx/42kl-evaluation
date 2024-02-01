SRCS		=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
				ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c ft_atol.c \
				ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c ft_free_array.c free.c\
				ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_contains_char.c \
				ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c ft_free_stack.c \
				ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c ft_ibounds.c ft_is_charset.c\
				ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c ft_instr.c get_next_line.c error.c ft_dup_char_array.c
OBJS		= $(SRCS:.c=.o)
BONUS		=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
				ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
				ft_lstmap.c ft_lstnew.c ft_lstsize.c
BONUS_OBJS	= $(BONUS:.c=.o)
CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I.
NAME		= libft.a
ARFLAGS 	= -rcs

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:		$(NAME)

bonus:		$(OBJS) $(BONUS_OBJS)
			ar $(ARFLAGS) $(NAME) $(OBJS) $(BONUS_OBJS)

clean:		
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re bonus
