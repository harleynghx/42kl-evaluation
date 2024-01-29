CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = PmergeMe

all: $(NAME)
re: fclean all

$(NAME): main.o PmergeMe.o
	$(CXX) $(CXXFLAGS) -o $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

.PHONY: all re clean fclean