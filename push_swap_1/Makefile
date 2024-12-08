#
#
CC = cc
CFLAGS = -g -Wall -Werror -Wextra

SRCDIR = ./src
INCDIR = ./include
OBJDIR = ./obj

SRCS = $(SRCDIR)/main.c\
		$(SRCDIR)/stack.c\
		$(SRCDIR)/functions.c\
		# $(SRCDIR)/rules.c

OBJS = $(SRCS:$(SRCDIR)\%.c=$(OBJDIR)\%.o)
NAME = push_swap

all: $(NAME)
	clear
	@echo "\nSuccessful compilation. Input arguments and run.\n"
	@echo "eg: ./$(NAME) n1 n2 n3 n4 ... \n"
	@echo "eg: ./$(NAME) n1 n2 n3 n4 ... | wc -l\n"

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%$(OBJDIR)\%.o: $(SRCDIR)\%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(NAME)

clean:
	rm -f $(OBJDIR)/$(OBJS)
	@echo "Cleaned up all build files."

fclean: clean
		rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
