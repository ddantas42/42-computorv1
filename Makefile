NAME = computor
CC = c++
# CFLAGS = -Wall -Wextra -Werror -Iinc/
CFLAGS = -Iinc/
RM = rm -f

SRCDIR = ./src/

FILES = main.cpp equation.cpp calculate_terms.cpp

SRC = $(addprefix $(SRCDIR), $(FILES))
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) -f $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
