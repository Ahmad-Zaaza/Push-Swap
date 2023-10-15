/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:55:03 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/15 19:35:31 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_frame *frame)
{
	t_stack	*to_move;

	to_move = frame->b;
	if (!to_move)
		return ;
	if (to_move == to_move->next)
		frame->b = NULL;
	else
	{
		(frame->b)->next->prev = (frame->b)->prev;
		(frame->b)->prev->next = (frame->b)->next;
		(frame->b) = (frame->b)->next;
	}
	push_stack_node(&frame->a, to_move);
	if (frame->print_operations)
		print_operation("p", 'a', frame);
}

void	pb(t_frame *frame)
{
	t_stack	*to_move;

	to_move = frame->a;
	if (!to_move)
		return ;
	if (frame->a == frame->a->next)
		frame->a = NULL;
	else
	{
		(frame->a)->next->prev = (frame->a)->prev;
		(frame->a)->prev->next = (frame->a)->next;
		(frame->a) = (frame->a)->next;
	}
	push_stack_node(&frame->b, to_move);
	if (frame->print_operations)
		print_operation("p", 'b', frame);
}
