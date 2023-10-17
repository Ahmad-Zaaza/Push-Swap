/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 00:47:28 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/10/18 00:47:48 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_frame *frame, char stack_name)
{
	t_stack **stack;

	if (stack_name == 'a')
		stack = &frame->a;
	else
		stack = &frame->b;

	if (get_min(*stack) == (*stack)->data)
	{
		r_rotate(frame, stack_name);
		swap(frame, stack_name);
	}
	else if (get_max(*stack) == (*stack)->prev->data)
	{
		swap(frame, stack_name);
	}
	else if (get_max(*stack) == (*stack)->data)
	{
		rotate(frame, stack_name);
		if (!is_stack_sorted(*stack))
		{
			swap(frame, stack_name);
		}
	}
	else
	{
		r_rotate(frame, stack_name);
	}
}