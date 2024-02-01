NAME		:= so_long

SRCS_DIR	:= ./src
SRCS		:= $(wildcard $(SRCS_DIR)/*.c)
OBJS_DIR	:= ./obj


OBJS		:= $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra
INCLUDES	:= -I libft -I includes

LIB_FT		:= -L libft -lft
LIB_MLX		:= -lmlx -framework OpenGL -framework AppKit
LIBRARY		:= $(LIB_FT) $(LIB_MLX)
INCLUDES	:= -I mlx -I libft -I includes


all: $(NAME)

bonus: $(OBJS)
	@echo "Compiling Bonus $(NAME)..."
	@make bonus -C ./libft
	$(CC) $(FLAGS) $(OBJS) $(LIBRARY) $(INCLUDES) -o so_long_bonus
	@echo "$(NAME) compiled successfully."

$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	@make -C ./libft
	$(CC) $(FLAGS) $(OBJS) $(LIBRARY) $(INCLUDES) -o $@
	@echo "$(NAME) compiled successfully."

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@make clean -C ./libft
	@echo "Object files have been removed."

fclean: clean
	@rm -rf $(NAME)
	@rm -rf so_long_bonus
	@make fclean -C ./libft
	@echo "Object files and $(NAME) have been removed."

re: fclean all

.PHONY: all clean fclean re