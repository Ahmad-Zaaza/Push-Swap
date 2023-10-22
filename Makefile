# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 00:54:55 by azaaza            #+#    #+#              #
#    Updated: 2023/10/22 18:03:08 by ahmadzaaza       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = push_swap
CHECKER_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror


SRCS_DIR = ./srcs/
OBJS_DIR = ./objs/


PUSH_SWAP_SRCS_DIR = $(SRCS_DIR)/push_swap/
SHARED_SRCS_DIR = $(SRCS_DIR)/shared/
CHECKER_SRCS_DIR = $(SRCS_DIR)/checker/


PUSH_SWAP_SRCS = a_calculations.c b_calculations.c push_swap.c sort_three.c sort_utils.c sort.c
SHARED_SRCS =  args_validation.c args_validation_utils.c args_queue.c operations1.c operations2.c frame.c error.c print_stacks.c \
				swap.c push.c rotate.c reverse_rotate.c stack_utils.c stack.c
CHECKER_SRCS = checker.c 

PUSH_SWAP_SRCS_PATH = $(PUSH_SWAP_SRCS:%=$(PUSH_SWAP_SRCS_DIR)%)
SHARED_SRCS_PATH = $(SHARED_SRCS:%=$(SHARED_SRCS_DIR)%)
CHECKER_SRCS_PATH = $(CHECKER_SRCS:%=$(CHECKER_SRCS_DIR)%)

SRCS_PATH = $(PUSH_SWAP_SRCS_PATH) $(SHARED_SRCS_PATH) $(CHECKER_SRCS_PATH)


PUSH_SWAP_OBJ = $(PUSH_SWAP_SRCS:%.c=%.o)
SHARED_OBJ = $(SHARED_SRCS:%.c=%.o)
CHECKER_OBJ = $(CHECKER_SRCS:%.c=%.o)
OBJ = $(PUSH_SWAP_OBJ) $(SHARED_OBJ) $(CHECKER_OBJ)

PUSH_SWAP_OBJ_PATH = $(addprefix $(OBJS_DIR), $(PUSH_SWAP_OBJ))
SHARED_OBJ_PATH = $(addprefix $(OBJS_DIR), $(SHARED_OBJ))
CHECKER_OBJ_PATH = $(addprefix $(OBJS_DIR), $(CHECKER_OBJ))

OBJS_PATH = $(PUSH_SWAP_OBJ_PATH) $(SHARED_OBJ_PATH)
CHECKER_OBJS_PATH = $(CHECKER_OBJ_PATH) $(SHARED_OBJ_PATH)


LIBS_FLAGS = -Llibft -lft

all: $(OBJS_DIR) $(NAME)
	 @echo "push_swap is ready"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS_PATH)
	@make -C libft
	@$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ_PATH) $(SHARED_OBJ_PATH) $(LIBS_FLAGS) -o $@ \
	-I includes -I libft

$(CHECKER_NAME): $(CHECKER_OBJS_PATH)
	@make -C libft
	@$(CC) $(CFLAGS) $(CHECKER_OBJ_PATH) $(SHARED_OBJ_PATH) $(LIBS_FLAGS) -o $@ \
	-I includes -I libft

$(PUSH_SWAP_OBJ_PATH): $(PUSH_SWAP_SRCS_PATH)
	@$(MAKE) $(PUSH_SWAP_OBJ)
$(SHARED_OBJ_PATH): $(SHARED_SRCS_PATH)
	@$(MAKE) $(SHARED_OBJ)
$(CHECKER_OBJ_PATH): $(CHECKER_SRCS_PATH)
	@$(MAKE) $(CHECKER_OBJ)

$(PUSH_SWAP_OBJ):
	@$(CC) $(CFLAGS) -c $(PUSH_SWAP_SRCS_DIR)$(@:%.o=%.c) -o $(OBJS_DIR)$@
	
$(SHARED_OBJ): 
	@$(CC) $(CFLAGS) -c $(SHARED_SRCS_DIR)$(@:%.o=%.c) -o $(OBJS_DIR)$@
$(CHECKER_OBJ): 
	@$(CC) $(CFLAGS) -c $(CHECKER_SRCS_DIR)$(@:%.o=%.c) -o $(OBJS_DIR)$@

clean:
	@make clean -C libft
	rm -f $(OBJS_PATH) $(CHECKER_OBJS_PATH)

fclean: clean
	@make fclean -C libft
	rm -f $(NAME) $(CHECKER_NAME)

re: fclean all
.PHONY: all clean re fclean