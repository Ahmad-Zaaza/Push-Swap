#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int					data;
	struct s_stack		*prev;
	struct s_stack		*next;
}						t_stack;

typedef struct s_arg_node
{
	int					value;
	struct s_arg_node	*next;
}						t_arg_node;

typedef struct s_args_queue
{
	t_arg_node			*head;
	t_arg_node			*tail;
}						t_args_queue;

typedef struct s_frame
{
	t_stack				*a;
	t_stack				*b;
	t_args_queue		args_queue;
	int					print_stacks;
	int					size;
}						t_frame;

// validation
void					validate_args(int argc, char **argv, t_frame *frame);
int						get_num_args(char **str);
int						is_str_digit(char *str);
void					cleanup_splitted(char **str, int size);

// queue
void					init_queue(t_args_queue *queue);
void					enqueue(t_args_queue *queue, int value);
int						dequeue(t_args_queue *queue);
void					cleanup_queue(t_args_queue *args_queue);
int						get_queue_size(t_args_queue *queue);
int						is_queue_sorted(t_args_queue *queue);

// stack
void					populate_stack(t_frame *frame);
void					print_stack(t_stack *stack);
void					clean_stack(t_stack **stack);
void					push_stack_node(t_stack **stack, t_stack *new_node);
int						get_stack_size(t_stack *stack);
void					print_stacks(t_stack *stack);

// operations
void					print_operation(char *operation, char stack);
void					swap(t_frame *frame, char name, int print);
void					push(t_stack **from, t_stack **to, char name);
void					ss(t_frame *frame);
void					rotate(t_stack **stack, char name, int print);
void					rr(t_frame *frame);
void					r_rotate(t_stack **stack, char name, int print);
void					rrr(t_frame *frame);

// sort
void					sort_three(t_stack **stack, char stack_name);
int						get_max(t_stack *stack);
int						get_min(t_stack *stack);
int						is_stack_sorted(t_stack *stack);
void					sort(t_frame *frame);
int						is_rotate(t_stack *stack);

// Frame

void					create_frame(t_frame *frame);

void					print_error(char *message);

#endif