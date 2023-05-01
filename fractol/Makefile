NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11

SRCS = fractol.c \
		parameter.c \
		mandelbrot.c \
		julia.c \
		burningship.c \
		hooks.c \
		ft_strncmp.c \
		ft_strlen.c \

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
		${CC} ${CFLAGS} -lm ${OBJS} $(MLXFLAGS) -o ${NAME}

clean :
		$(RM) $(OBJS)
		echo "OBJS deleted"

fclean : clean
		$(RM) $(NAME)
		echo "$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re