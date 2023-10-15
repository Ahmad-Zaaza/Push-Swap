/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 01:35:58 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/15 19:35:31 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	clean_strings(char *a, char *b)
{
	free(a);
	free(b);
}

static void	print(t_stack *stack_a, t_stack *stack_b, t_frame *frame)
{
	char	*a;
	char	*b;

	while (1)
	{
		a = stack_a ? ft_itoa(stack_a->data) : ft_strdup("");
		b = stack_b ? ft_itoa(stack_b->data) : ft_strdup("");
		if (!stack_a && !stack_b)
		{
			clean_strings(a, b);
			break ;
		}
		if (stack_a && stack_a->data < 10 && stack_a->data > -10)
			ft_putstr_fd(" ", 2);
		if (!stack_a)
			ft_putstr_fd("              ", 2);
		else
			ft_putstr_fd("            ", 2);
		ft_putstr_fd(a, 2);
		ft_putstr_fd("  |  ", 2);
		ft_putstr_fd(b, 2);
		ft_putchar_fd('\n', 2);
		clean_strings(a, b);
		stack_a = (stack_a && stack_a != frame->a->prev) ? stack_a->next : NULL;
		stack_b = (stack_b && stack_b != frame->b->prev) ? stack_b->next : NULL;
	}
}

void	print_stacks(t_frame *frame)
{
	usleep(100000);
	ft_putstr_fd("\033[0;94m", 2);
	ft_putstr_fd("\E[H\E[2J", 2);
	ft_putstr_fd("        Stack A", 2);
	ft_putstr_fd("   ", 2);
	ft_putstr_fd("Stack B\n", 2);
	ft_putstr_fd("\033[1;92m", 2);
	print(frame->a, frame->b, frame);
}