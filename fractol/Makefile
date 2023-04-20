NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11
LIBFT = -L ./libft/libft.a

SRCS = fractol.c \
		parameter.c \
		mandelbrot.c \
		hooks.c \

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
		${CC} ${CFLAGS} -lm ${OBJS} $(LIBFT) $(MLXFLAGS) -o ${NAME}

clean :
		$(MAKE) clean -C ./libft
		$(RM) $(OBJS)
		echo "OBJS deleted"

fclean : clean
		$(MAKE) fclean -C ./libft
		$(RM) $(NAME)
		echo "$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re




