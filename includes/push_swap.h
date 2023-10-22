/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:24:21 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/22 13:34:00 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define CNRM "\x1B[0m"
# define CRED "\x1B[31m"
# define CGRN "\x1B[32m"
# define CBLU "\x1B[34m"

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	long int			data;
	struct s_stack		*prev;
	struct s_stack		*next;
}						t_stack;

typedef struct s_arg_node
{
	long int			value;
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
	int					print_operations;
	int					size;
	long int			b_highest;
	long int			b_lowest;
	int					cheapest_value;
	int					cheapest_moves;
	int					a_rotations;
	int					a_r_rotations;
	int					b_rotations;
	int					b_r_rotations;

}						t_frame;

typedef void			(*t_op_fun_ptr)(t_frame *frame);

/* VALIDATION */
void					validate_args(int argc, char **argv, t_frame *frame);
int						get_num_args(char **str);
int						is_str_digit(char *str);
void					cleanup_splitted(char **str, int size);

/* QUEUE*/
void					init__args_queue(t_args_queue *queue);
void					enqueue(t_frame *frame, long int value);
long int				dequeue(t_args_queue *queue);
void					cleanup_queue(t_args_queue *args_queue);
int						get_queue_size(t_args_queue *queue);
int						is_queue_sorted(t_args_queue *queue);

/* STACK */
void					populate_stack(t_frame *frame);
void					clean_stack(t_stack **stack);
void					push_stack_node(t_stack **stack, t_stack *new_node);
int						get_stack_size(t_stack *stack);

/* OPERATIONS */
void					rotate(t_frame *frame, char name);
void					r_rotate(t_frame *frame, char name);
void					swap(t_frame *frame, char name);
void					sa(t_frame *frame);
void					sb(t_frame *frame);
void					pa(t_frame *frame);
void					pb(t_frame *frame);
void					ra(t_frame *frame);
void					rb(t_frame *frame);
void					rra(t_frame *frame);
void					rrb(t_frame *frame);
void					rr(t_frame *frame);
void					rrr(t_frame *frame);

/* PRINTING */
void					print_operation(char *operation, char stack,
							t_frame *frame);
void					print_error(void);
void					print_stacks(t_frame *frame);

/* SORTING */
void					sort_three(t_frame *frame);
long int				get_max(t_stack *stack);
long int				get_min(t_stack *stack);
int						is_stack_sorted(t_stack *stack);
void					sort(t_frame *frame);
int						is_rotate(t_stack *stack);
void					find_cheapest_move(t_frame *frame);
void					reset_rotations(t_frame *frame);
long int				find_pivot_a_node(t_frame *frame);
void					find_position_in_a(t_frame *frame, long int *a_highest,
							long int *a_lowest);
void					move_min_to_top(t_frame *frame, long int a_lowest);

/* FRAME */
void					create_frame(t_frame *frame);
void					push_swap_error(t_frame *frame);

/* STACK UTILS*/
int						moves_to(char direction, t_stack *stack,
							long int value);
int						should_rotate_to(char direction, t_stack *stack,
							long int value);
void					set_new_highest_lowest(t_frame *frame, long int value);

#endif
