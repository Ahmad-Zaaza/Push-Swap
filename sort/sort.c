/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:02:08 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/01 19:23:23 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

static void	sort_until_three_or_sorted(t_frame *frame)
{
	int	min;
	int	size;

	size = get_stack_size(frame->a);
	while (size > 3 && !is_stack_sorted(frame->a))
	{
		min = get_min(frame->a);
		if (is_rotate(frame->a))
		{
			while (frame->a->data != min)
			{
				rotate(&frame->a, 'a', 1);
			}
			if (!is_stack_sorted(frame->a))
				pb(frame);
		}
		else
		{
			while (frame->a->data != min)
				r_rotate(&frame->a, 'a', 1);
			if (!is_stack_sorted(frame->a))
				pb(frame);
		}
		size--;
	}
}

static void	re_populate_a(t_frame *frame)
{
	long int	top;

	if (!frame->b)
		return ;
	top = frame->b->prev->data;
	while (frame->b)
	{
		pa(frame);
		if (frame->b->data == top)
			break ;
	}
}

void	sort(t_frame *frame)
{
	sort_until_three_or_sorted(frame);
	if (is_stack_sorted(frame->a))
		re_populate_a(frame);
	else
		sort_three(&frame->a, 'a');
	re_populate_a(frame);
}
