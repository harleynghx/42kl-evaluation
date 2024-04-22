SRCS = 	./src/server.c \
		./src/client.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../

all: server client

server: server.o libft
	$(CC) -o $@ $< -Llibft -lft

client: client.o libft
	$(CC) -o $@ $< -Llibft -lft

%.o: src/%.c
	$(CC) -c $(CFLAGS) $< -o $@

libft:
	make -C libft

clean:
	rm -f $(OBJS)
	rm -f server.o 
	rm -f client.o
	make -C libft clean
	
fclean: clean
	rm -f server client libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re