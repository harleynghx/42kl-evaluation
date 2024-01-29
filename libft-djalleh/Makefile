# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djalleh <djalleh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 18:42:18 by djalleh           #+#    #+#              #
#    Updated: 2024/01/17 02:16:57 by djalleh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES			= ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint\
				 ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy\
				 ft_strlcat ft_toupper ft_tolower ft_strchr ft_strrchr\
				 ft_strncmp ft_memchr ft_memcmp ft_strnstr ft_atoi ft_calloc\
				 ft_strdup ft_substr ft_strjoin ft_strtrim ft_split ft_itoa\
				 ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd\
				 ft_putendl_fd ft_putnbr_fd\

SRCS			=$(FILES:%=%.c)

OBJS			=$(FILES:%=%.o)

CC				=gcc

CFLAGS			= -Wall -Wextra -Werror

RM				= rm -f

NAME			= libft.a

all:			$(NAME)


$(NAME):		
				$(CC) $(CFLAGS) -c  $(SRCS) -I.
				ar rcs $(NAME) $(OBJS)


clean:
				$(RM) $(OBJS) 

fclean:			clean
					$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re