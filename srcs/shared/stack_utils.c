/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 01:08:38 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/22 13:22:17 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_value_index(t_stack *stack, int value)
{
	int	index;

	index = 0;
	while (stack->data != value)
	{
		stack = stack->next;
		index++;
	}
	return (index);
}

int	should_rotate_to(char direction, t_stack *stack, long int value)
{
	int	stack_size;
	int	index;

	stack_size = get_stack_size(stack);
	index = get_value_index(stack, value);
	if (direction == 't')
		return ((index + 1) <= (stack_size / 2));
	return ((index + 1) >= (stack_size / 2));
}

int	moves_to(char direction, t_stack *stack, long int value)
{
	int	moves;
	int	stack_size;
	int	index;

	moves = 0;
	stack_size = get_stack_size(stack);
	index = get_value_index(stack, value);
	if (direction == 't')
		if (index == 0)
			return (0);
	if (direction == 'b')
		if (index == stack_size - 1)
			return (0);
	if ((index + 1) <= (stack_size / 2))
		moves = index;
	else
		moves = stack_size - index;
	return (moves);
}

int	get_stack_size(t_stack *stack)
{
	int		size;
	t_stack	**top;
	t_stack	*tmp;

	top = &stack;
	tmp = *top;
	size = 0;
	while (tmp)
	{
		size++;
		if (tmp->next == *top)
			break ;
		tmp = tmp->next;
	}
	return (size);
}

void	set_new_highest_lowest(t_frame *frame, long int value)
{
	if (value > frame->b_highest)
		frame->b_highest = value;
	if (value < frame->b_lowest)
		frame->b_lowest = value;
}
