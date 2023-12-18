SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
CPPFLAGS = -Wextra -Werror -Wextra -std=c++98 -pedantic
RM = rm -f

NAME = main

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
