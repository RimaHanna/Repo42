NAME = philo

SRCS = src/philo.c \
		src/actions.c \
		src/data_init.c \
		src/eat_records_iter.c \
		src/fork_actions.c \
		src/get_action_time.c \
		src/parse.c \
		src/routine.c \
		src/state.c \
		src/time.c \
		src/utils.c \


OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -pthread -Iincludes

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