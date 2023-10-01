/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:20:12 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/01 19:32:48 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	print_operation(char *operation, char stack)
{
	ft_putstr_fd(operation, 1);
	ft_putchar_fd(stack, 1);
	ft_putchar_fd('\n', 1);
}

void	swap(t_frame *frame, char name, int print)
{
	t_stack		*top;
	long int	tmp;

	if (name == 'b')
		top = frame->b;
	else
		top = frame->a;
	if (!top || top == (top)->next)
		return ;
	tmp = (top)->data;
	(top)->data = (top)->next->data;
	(top)->next->data = tmp;
	if (print)
	{
		print_operation("s", name);
	}
}

void	ss(t_frame *frame)
{
	swap(frame, 'a', 0);
	swap(frame, 'b', 0);
	print_operation("s", 's');
}

void	pa(t_frame *frame)
{
	t_stack	*from;
	t_stack	*to_move;

	from = frame->b;
	to_move = from;
	if (!to_move)
		return ;
	if (to_move == to_move->next)
		from = NULL;
	else
	{
		(from)->next->prev = (from)->prev;
		(from)->prev->next = (from)->next;
		(from) = (from)->next;
	}
	push_stack_node(frame->a, to_move);
	print_operation("p", 'a');
}

void	pb(t_frame *frame)
{
	t_stack	*from;
	t_stack	*to_move;

	from = frame->a;
	to_move = from;
	if (!to_move)
		return ;
	if (from == from->next)
		from = NULL;
	else
	{
		(from)->next->prev = (from)->prev;
		(from)->prev->next = (from)->next;
		(from) = (from)->next;
	}
	push_stack_node(frame->b, to_move);
	print_operation("p", 'b');
}
