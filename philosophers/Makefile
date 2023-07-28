# COLORS

DEF_color	=	\033[0;39m
ORANGE		=	\033[0;33m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

# NAMES
NAME = philo

# SRCS
SRCS =	philo.c \
		actions.c \
		data_init.c \
		eat_records_iter.c \
		fork_actions.c \
		get_action_time.c \
		parse.c \
		routine.c \
		state.c \
		time.c \
		utils.c \

# COMMANDS AND FLAGS

CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread -g3
RM = rm -rf
POINTH = philo.h
 
# OBJS
OBJS = $(SRCS:.c=.o)

# RULES

all : ${NAME}

$(NAME) : $(OBJS) $(POINTH)
			ar rcs $(NAME) $(OBJS)

clean :
			${RM} ${OBJS}

fclean : clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
		