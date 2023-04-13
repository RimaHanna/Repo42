NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -Iincludes
MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11
LIBFT = -L ./libft/libft.a

SRCS = mandelbrot.c \
		parameter.c \

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
		@${CC} ${CFLAGS} -lm ${OBJS} $(LIBFT) $(MLXFLAGS) -o ${NAME}

clean :
		$(MAKE) clean -C ./libft
		$(RM) $(OBJS)

fclean : clean
		$(MAKE) clean -C ./libft
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re




