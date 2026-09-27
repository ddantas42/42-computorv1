NAME = computor
CC = c++
CFLAGS = -Wall -Wextra -Werror -Iinc/
RM = rm -f

SRCDIR = ./src/

FILES = main.cpp equation.cpp solve.cpp
SOLVE_FILES = calculate_terms.cpp reduce.cpp create_reduce_string.cpp
SOLVE_DIR = ./src/pre-solve/

SRC = $(addprefix $(SRCDIR), $(FILES)) $(addprefix $(SOLVE_DIR), $(SOLVE_FILES))
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
