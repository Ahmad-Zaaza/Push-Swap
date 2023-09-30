NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -fno-omit-frame-pointer -g3

SRCS = push_swap.c args_validation.c args_validation_utils.c args_queue.c stack.c ./operations/operations1.c ./operations/operations2.c \
		sort_utils.c ./sort/sort_three.c ./sort/sort.c frame.c error.c


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