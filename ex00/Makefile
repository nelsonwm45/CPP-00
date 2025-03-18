# Program Name
NAME = megaphone

# Compiler
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Source and Object
SRCS = megaphone.cpp
OBJ = $(SRCS:.cpp=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all
