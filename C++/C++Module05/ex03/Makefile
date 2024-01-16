NAME		=	a.out_ex03

CPP			=	c++

CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98

SHRUBBERY	=	$(shell find . -name '*_shrubbery')

#directories
SRC_DIR		=	srcs/
OBJ_DIR		=	obj/
INC_DIR		=	includes/

#source files
SRC_FILES	=	Bureaucrat.cpp main.cpp AForm.cpp \
				PresidentialPardonForm.cpp RobotomyRequestForm.cpp \
				ShrubberyCreationForm.cpp Intern.cpp

OBJ_FILES	=	$(SRC_FILES:.cpp=.o)

#paths
SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

#all rule
all: $(NAME)

#compile the executable
$(NAME): $(OBJ)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

#compile objects
$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CPP) $(CPPFLAGS) -I $(INC_DIR) -o $@ -c $<

#clean rule
clean:
	rm -rf $(OBJ_DIR)

#fclean rule
fclean: clean
	rm -f $(NAME)
	rm -f $(SHRUBBERY)

#re rule
re: fclean all

#phony
.PHONY: all clean fclean re