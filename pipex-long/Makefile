NAME = pipex
CC = gcc
RM = rm -f
SRCS = ft_split.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strcmp.c \
		fork_utils.c free_utils.c init_utils.c pipex.c \
		get_next_line.c get_next_line_utils.c
CFLAGS = -Wall -Wextra -Werror
OPTION = -I ./

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(OPTION) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(OPTION) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

bonus: all

re: fclean all

.PHONY: all clean fclean re bonus
