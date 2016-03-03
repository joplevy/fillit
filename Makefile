NAME = fillit

SRC = main.c read.c globals.c resolution.c ft_tools.c

OBJ = $(SRC:.c=.o)

CCFLAGS = -Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(SCR)
	gcc $(CCFLAGS) -c $(SRC)
	gcc $(CCFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all