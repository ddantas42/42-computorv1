NAME = computor
CC = c++
CFLAGS = -Wall -Wextra -Werror -Iinc/
RM = rm -f

SRCDIR = ./src/

MAIN_FILES = main.cpp equation.cpp

PRE_SOLVE_FILES = calculate_terms.cpp reduce.cpp create_reduce_string.cpp
PRE_SOLVE_DIR = ./src/pre-solve/

SOLVER_FILES = solve.cpp solve_degree_2.cpp solve_degree_1.cpp solve_degree_0.cpp
SOLVER_DIR = ./src/solver/

SRC =   $(addprefix $(SRCDIR), $(MAIN_FILES)) \
		$(addprefix $(SOLVER_DIR), $(SOLVER_FILES)) \
		$(addprefix $(PRE_SOLVE_DIR), $(PRE_SOLVE_FILES))
		
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
