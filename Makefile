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
		$(SRCDIR)/functions.c\
		$(SRCDIR)/node_attributes.c\
		$(SRCDIR)/node_attributes2.c\
		$(SRCDIR)/errors.c\
		$(SRCDIR)/push_cond.c

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
LIBFT = $(LIBFTDIR)/libft.a
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS) $(LIBFT)
	@echo "\033[33mCompilating...\033[0m\n"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft
	@echo "\nCompilation \033[32msuccessful\033[0m!\n"
	@echo "eg: ./$(NAME) --n1 n2 n3 n4 ... "
	@echo "eg: ./$(NAME) --n1 n2 n3 n4 ... | wc -l\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	@echo "\033[33mCleaning up build and library files...\033[0m\n"
	rm -f $(OBJDIR)/*.o
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean
	@echo "\nAll build files cleaned up \033[32msuccessfully\033[0m!"

fclean: clean
	@echo "\033[33mCleaning up executables and static libraries...\033[0m\n"
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	@echo "\nExecutables and static libraries cleaned up \033[32msuccessfully\033[0m!"
	
re: fclean all

.PHONY: all clean fclean re
