NAME = push_swap

SRCS = lib/ft_atoi.c \
		lib/ft_long_atoi.c \
		lib/ft_putchar_fd.c \
		lib/ft_putendl_fd.c \
		lib/ft_split.c \
		lib/ft_putnbr_fd.c \
		utils/check_error.c \
		utils/index.c \
		utils/t_list.c \
		utils/utils.c \
		src/instructions.c \
		src/main.c \
		src/radix.c \
		src/simple.c \

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -Iincludes

RM = rm -rf


all: $(NAME)

$(NAME): $(OBJS)
		@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
