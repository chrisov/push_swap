CC = cc
CFLAGS = -g -Wall -Werror -Wextra

SRCS = main.c stack.c quick_sort.c functions.c ft_itoa.c rules.c

OBJS = $(SRCS:.c=.o)
NAME = push_swap

all: $(NAME)
	clear
	@echo "\nSuccessful compilation. Input arguments and run.\n"
	@echo "eg: ./$(NAME) n1 n2 n3 n4 ...\n"

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAME) $(OBJS)
	@echo "Cleaned up all build files."

fclean: clean
		rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
