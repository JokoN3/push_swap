CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

SRCS = main.c parsing.c operations.c operations_utils.c \
		validation.c bubble_sort.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o push_swap

$(LIBFT):
	@make -sC $(LIBFTDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make -sC $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	@make -sC $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re