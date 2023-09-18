NAME = push_swap

CC = cc

SRCS = main.c

OBJECTS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C libft
	$(CC) $(OBJECTS) -o $(NAME)

clean:
	@make clean -C libft
	rm -f $(OBJECTS)

fclean: clean
	@make fclean -C libft
	rm -f $(NAME)

re: fclean all
.PHONY: all clean re fclean