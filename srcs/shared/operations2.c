/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 00:47:13 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/10/18 00:47:48 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_frame *frame, char name)
{
	t_stack	**stack;

	if (name == 'b')
		stack = &frame->b;
	else
		stack = &frame->a;
	if (*stack)
		*stack = (*stack)->next;
	if (frame->print_operations)
		print_operation("r", name, frame);
}

void	r_rotate(t_frame *frame, char name)
{
	t_stack	**stack;

	if (name == 'b')
		stack = &frame->b;
	else
		stack = &frame->a;
	if (*stack)
		*stack = (*stack)->prev;
	if (frame->print_operations)
		print_operation("rr", name, frame);
}
