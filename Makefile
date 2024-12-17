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
	@echo "\nCompilation \033[32msuccessful!\033[0m Input arguments and run:"
	@echo "eg: ./$(NAME) --n1 n2 n3 n4 ... "
	@echo "eg: ./$(NAME) --n1 n2 n3 n4 ... | wc -l"
	@echo "eg: make run -- n1 n2 n3 n4 ... "
	@echo "eg: make run -- n1 n2 n3 n4 ... | wc -l\n"

$(NAME): $(OBJDIR) $(OBJS) $(LIBFT)
	@echo "\033[33mCompilating...\033[0m\n"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

run: $(NAME)
	@ARGS="$(filter-out $@,$(MAKECMDGOALS))";\
	./$(NAME) $$ARGS

clean:
	@echo "\033[33mCleaning up build and library files...\033[0m\n"
	rm -f $(OBJDIR)/*.o
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean
	@echo "\nAll build files cleaned up \033[32msuccessfully!\033[0m"

fclean: clean
	@echo "\033[33mCleaning up executables and static libraries...\033[0m\n"
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	@echo "\nExecutables and static libraries cleaned up \033[32msuccessfully!\033[0m"
	
re: fclean all

%:
	@:

.PHONY: all clean fclean re
