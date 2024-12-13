#
#
CC = cc
CFLAGS = -g -Wall -Werror -Wextra -I$(INCDIR) -I$(LIBFTDIR)/include

SRCDIR = ./src
OBJDIR = ./obj
INCDIR = ./include
LIBFTDIR = ./include/libft

SRCS = $(SRCDIR)/main.c\
		$(SRCDIR)/stack.c\
		$(SRCDIR)/rules.c\
		$(SRCDIR)/push_cheapest.c\
		$(SRCDIR)/functions.c\
		$(SRCDIR)/node_attributes.c\
		$(SRCDIR)/errors.c

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
LIBFT = $(LIBFTDIR)/libft.a
NAME = push_swap

all: $(NAME)
	clear
	@echo "\nSuccessful compilation. Input arguments and run."
	@echo "eg: ./$(NAME) n1 n2 n3 n4 ... "
	@echo "eg: ./$(NAME) n1 n2 n3 n4 ... | wc -l\n"

$(NAME): $(OBJDIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

run: $(NAME)
	@ARGS="$(filter-out $@,$(MAKECMDGOALS))";\
	./$(NAME) $$ARGS

clean:
	rm -f $(OBJDIR)/*.o
	@echo "Build files cleaned up.\n"

fclean: clean
		rm -f $(NAME)
		@echo "Executable cleaned up.\n"
	
re: fclean all

%:
	@:

.PHONY: all clean fclean re
