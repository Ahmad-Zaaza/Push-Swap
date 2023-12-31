/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 00:46:17 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/10/22 13:22:56 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_stack_sorted(t_stack *stack)
{
	t_stack	**top;
	t_stack	*tmp;

	top = &stack;
	tmp = *top;
	while (tmp)
	{
		if (tmp->data > tmp->next->data && tmp->next != *top)
			return (0);
		if (tmp->next == *top)
			break ;
		tmp = tmp->next;
	}
	return (1);
}

static t_stack	*create_stack_node(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	push_stack_node(t_stack **stack, t_stack *new_node)
{
	if (!*stack)
	{
		*stack = new_node;
		(*stack)->next = *stack;
		(*stack)->prev = *stack;
	}
	else
	{
		new_node->next = *stack;
		new_node->prev = (*stack)->prev;
		(*stack)->prev = new_node;
		new_node->prev->next = new_node;
		*stack = (*stack)->prev;
	}
}

void	populate_stack(t_frame *frame)
{
	int			i;
	long int	value;
	t_stack		*new_node;

	i = 0;
	while (i < frame->size)
	{
		value = dequeue(&frame->args_queue);
		new_node = create_stack_node(value);
		if (!new_node)
			return (push_swap_error(frame));
		push_stack_node(&frame->a, new_node);
		i++;
	}
}

void	clean_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*tmp;
	t_stack	*tmp2;

	first = (*stack);
	if (!*stack)
		return ;
	while (*stack)
	{
		tmp = *stack;
		tmp2 = (*stack)->next;
		free(tmp);
		if (tmp2 == first)
			break ;
		*stack = tmp2;
	}
}
