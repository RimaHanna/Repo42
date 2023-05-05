NAME = fractol

SRCS = fractol.c \
		parameter.c \
		mandelbrot.c \
		julia.c \
		burningship.c \
		keyhooks.c \
		mousehooks.c \
		utils.c \

OBJS = ${SRCS:.c=.o}

MINI = ./minilibx-linux

CFLAGS = -Wall -Wextra -Werror

CC = gcc

MINI_LINKS = -ldl -lmlx -Lmlx -lXext -lX11 -lz

RM = rm -rf
CRC = make -s -C
DSC = make clean -s -C 

.SILENT : lib ${NAME}

all : ${NAME}

.c.o:
	@${CC} ${CFLAGS} -Imlx -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
	@${CRC} ${MINI}
	@printf "${C_PURPLE}"
	@${CC} ${CFLAGS} -O0 -g ${OBJS} ${INCLUDES} -o ${NAME} $(MINI_LINKS)

clean :
	@printf "${C_BLUE}"
	@${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re

##################COLORS###########################
C_FLASH = \033[5;31m
C_RED = \033[0;31m
C_BLUE = \033[0;34m
C_OCHRA = \033[0;33m
C_TUR = \033[1;36m
C_PURPLE =\033[7;35m
C_CHARCOAL = \033[9;30m
C_RANDOM = \033[1;30m
C_YUHU = \033[1;37m
C_END = \033[0m
##################################################
