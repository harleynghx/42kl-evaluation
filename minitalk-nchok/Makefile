# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 17:40:11 by nchok             #+#    #+#              #
#    Updated: 2024/04/18 16:56:17 by nchok            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client
NAMESV = server
NAMEBC = bonus_client
NAMEBS = bonus_server
HEADER = -I header
SRC_DIR = src/
OBJ_DIR = obj/

CC = gcc
CFLAGS = -Wall -Wextra -Werror
FSANTIZE = -fsanitize=address -g3
RM = rm -f
AR = ar rcs

SRCCL_FILES = client
SRCSV_FILES = server
SRCHP_FILES = helper
SRCBC_FILES = bonus_client
SRCBS_FILES = bonus_server

# create .o and .c files for client
SRCCL = $(addsuffix .c, $(addprefix $(SRC_DIR), $(SRCCL_FILES)))
OBJCL = $(addsuffix .o, $(addprefix $(OBJ_DIR), $(SRCCL_FILES)))

# create .o and .c files for server
SRCSV = $(addsuffix .c, $(addprefix $(SRC_DIR), $(SRCSV_FILES)))
OBJSV = $(addsuffix .o, $(addprefix $(OBJ_DIR), $(SRCSV_FILES)))

# create .o and .c files for helper_fx
SRCHP = $(addsuffix .c, $(addprefix $(SRC_DIR), $(SRCHP_FILES)))
OBJHP = $(addsuffix .o, $(addprefix $(OBJ_DIR), $(SRCHP_FILES)))

# create .o and .c files for bonus_client
SRCBC = $(addsuffix .c, $(addprefix $(SRC_DIR), $(SRCBC_FILES)))
OBJBC = $(addsuffix .o, $(addprefix $(OBJ_DIR), $(SRCBC_FILES)))

# create .o and .c files for bonus_server
SRCBS = $(addsuffix .c, $(addprefix $(SRC_DIR), $(SRCBS_FILES)))
OBJBS = $(addsuffix .o, $(addprefix $(OBJ_DIR), $(SRCBS_FILES)))

# This rule says to create object file in OBJ_DIR from source files in SRC_DIR
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
			$(CC) $(CFLAGS) $(HEADER) -c $< -o $@
# % : wildcard, matching the string
# -c : to generate object
# $< : representing first prerequisite
# -o $@ : '-o' targets the output file and places them at '$@'. $@ means $(OBJ_DIR)%.o

start : $(OBJ_DIR) $(OBJCL) $(OBJSV) $(OBJHP)
	make all
	make bonus

all : $(NAME) $(NAMESV)

$(NAME) : $(OBJCL)
			$(CC) $(CFLAGS) $(OBJCL) $(HEADER) $(OBJHP) -o $(NAME)

$(NAMESV) : $(OBJSV)
			$(CC) $(CFLAGS) $(OBJSV) $(HEADER) $(OBJHP) -o $(NAMESV)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

bonus : $(NAMEBC) $(NAMEBS)

$(NAMEBC) : $(OBJ_DIR) $(OBJBC) $(OBJHP)
		$(CC) $(CFLAGS) $(OBJBC) $(HEADER) $(OBJHP) -o $(NAMEBC)

$(NAMEBS) : $(OBJ_DIR) $(OBJBS) $(OBJHP)
		$(CC) $(CFLAGS) $(OBJBS) $(HEADER) $(OBJHP) -o $(NAMEBS)

clean :
	$(RM) -r $(OBJCL) $(OBJSV) $(NAME) $(NAMESV)
	$(RM) header/minitalk.h.gch

fclean : clean
	$(RM) -r $(OBJ_DIR)
	$(RM) -r $(NAMEBC) $(NAMEBS)

re : clean start

normr :
	norminette $(SRC_DIR) ./header

.PHONY: start all clean fclean re normr
