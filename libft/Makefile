NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror
GNL_FOLDER = get_next_line

SRCS = ft_atoi.c ft_isdigit.c \
		ft_strlen.c ft_strstr.c \
		ft_strdup.c ft_substr.c ft_split.c ft_itoa.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
		$(GNL_FOLDER)/get_next_line.c $(GNL_FOLDER)/get_next_line_utils.c



OBJECTS = $(SRCS:%.c=%.o) 


all: $(NAME)

.o.c: $(SRCS)
	$(CC) $(CFLAGS) -L . -l ft.h -c $(SRCS)

$(NAME) : $(OBJECTS)
		ar -rcs $@ $?
		
clean: 
	rm -f $(OBJECTS)
	
fclean: clean
	rm -f $(NAME)
		
re: fclean all

.PHONY: all clean re fclean