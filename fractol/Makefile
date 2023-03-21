NAME = fractol

SRCS = $(wildcard src/*.c)

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -Iincludes

RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
		@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re




