/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_calculations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 00:44:51 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/10/18 01:17:43 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

long int	find_pivot_a_node(t_frame *frame)
{
	long int	pivot;
	t_stack		*tmp;
	long int	diff;

	pivot = frame->a->data;
	tmp = frame->a;
	diff = 0;
	while (tmp)
	{
		if (tmp->data > frame->b->data)
		{
			if (diff == 0)
			{
				pivot = tmp->data;
				diff = tmp->data - frame->b->data;
			}
			else if (diff > tmp->data - frame->b->data)
			{
				pivot = tmp->data;
				diff = tmp->data - frame->b->data;
			}
		}
		if (tmp->next == frame->a)
			break ;
		tmp = tmp->next;
	}
	return (pivot);
}

static void	set_rotations(t_frame *frame, int a_moves_to_top, long int pivot)
{
	reset_rotations(frame);
	if (should_rotate_to_top(frame->a, pivot))
		frame->a_rotations = a_moves_to_top;
	else
		frame->a_r_rotations = a_moves_to_top;
}

void	find_correct_position_in_a(t_frame *frame, long int *a_highest,
		long int *a_lowest)
{
	long int pivot;
	int a_moves;
	if (frame->b->data < *a_lowest)
	{
		pivot = *a_lowest;
		*a_lowest = frame->b->data;
	}
	else if (frame->b->data > *a_highest)
	{
		pivot = *a_highest;
		*a_highest = frame->b->data;
	}
	else
		pivot = find_pivot_a_node(frame);
	a_moves = moves_to_top(frame->a, pivot);
	set_rotations(frame, a_moves, pivot);
}