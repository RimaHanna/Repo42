NAME = libftprintf.a

SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c\
		 ft_unsigned_putnbr.c ft_min_hex_putnbr.c\
			ft_max_hex_putnbr.c ft_pointer.c\
		

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

RM = rm -f

POINTH = ft_printf.h 

all: $(NAME)

$(NAME) : $(OBJS) $(POINTH)
			ar rcs $(NAME) $(OBJS)

clean:
		 $(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
