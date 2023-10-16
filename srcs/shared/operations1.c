/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:20:12 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/17 02:03:21 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_operation(char *operation, char stack, t_frame *frame)
{
	if (frame->print_stacks)
		print_stacks(frame);
	else
	{
		ft_putstr_fd(operation, 1);
		ft_putchar_fd(stack, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	swap(t_frame *frame, char name)
{
	t_stack		**stack;
	long int	tmp;

	if (name == 'b')
		stack = &frame->b;
	else
		stack = &frame->a;
	if (!*stack || *stack == (*stack)->next)
		return ;
	tmp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = tmp;
	if (frame->print_operations)
	{
		print_operation("s", name, frame);
	}
}
