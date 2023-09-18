NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

SRCS = push_swap.c args_validation.c args_queue.c

OBJECTS = $(SRCS:%.c=%.o)

LIBS_FLAGS = -Llibft -lft

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C libft
	$(CC) $(CFLAGS) $^ $(LIBS_FLAGS) -o $@

clean:
	@make clean -C libft
	rm -f $(OBJECTS)

fclean: clean
	@make fclean -C libft
	rm -f $(NAME)

re: fclean all
.PHONY: all clean re fclean