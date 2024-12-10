#
#
CC = cc
CFLAGS = -g -Wall -Werror -Wextra

SRCDIR = ./src
INCDIR = ./include
OBJDIR = ./obj

SRCS = $(SRCDIR)/main.c\
		$(SRCDIR)/stack.c\
		$(SRCDIR)/rules.c\
		$(SRCDIR)/sort.c\
		$(SRCDIR)/functions.c

OBJS = $(SRCS:$(SRCDIR)\%.c=$(OBJDIR)\%.o)
NAME = push_swap

all: $(NAME)
	clear
	@echo "\nSuccessful compilation. Input arguments and run."
	@echo "eg: ./$(NAME) n1 n2 n3 n4 ... "
	@echo "eg: ./$(NAME) n1 n2 n3 n4 ... | wc -l"

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%$(OBJDIR)\%.o: $(SRCDIR)\%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

run: ./$(NAME) 
	@ARGS="$(filter-out $@,$(MAKECMDGOALS))";\
	./$(NAME) $$ARGS

clean:
	rm -f $(OBJDIR)/*.o
	@echo "Cleaned up all build files."

fclean: clean
		rm -f $(NAME)
	
re: fclean all

%:
	@:

.PHONY: all clean fclean re
