/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:02:08 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/15 19:35:31 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	apply_rotations(t_frame *frame)
{
	while (frame->a_rotations > 0 && frame->b_rotations > 0)
	{
		rr(frame);
		frame->a_rotations--;
		frame->b_rotations--;
	}
	while (frame->a_r_rotations > 0 && frame->b_r_rotations > 0)
	{
		rrr(frame);
		frame->a_r_rotations--;
		frame->b_r_rotations--;
	}
	while (frame->a_rotations > 0)
	{
		ra(frame);
		frame->a_rotations--;
	}
	while (frame->b_rotations > 0)
	{
		rb(frame);
		frame->b_rotations--;
	}
	while (frame->a_r_rotations > 0)
	{
		rra(frame);
		frame->a_r_rotations--;
	}
	while (frame->b_r_rotations > 0)
	{
		rrb(frame);
		frame->b_r_rotations--;
	}
}

static void	move_to_b(t_frame *frame)
{
	// get information about the best element to push to B
	find_cheapest_move(frame);
	// rotate the stacks based on the information set in the frame
	apply_rotations(frame);
	// now it's time to push after we did the necessery rotations
	pb(frame);
	// update the highest and lowest element of B
	set_new_highest_lowest(frame, frame->cheapest_value);
	// reset the information for the next element
	frame->cheapest_moves = 0;
	reset_rotations(frame);
}

static void	start_sorting(t_frame *frame)
{
	int	size;

	size = get_stack_size(frame->a);
	// push the first two elements of A to B,
	// then set the highest and lowest values of B in order to establish a baseline
	pb(frame);
	pb(frame);
	if (frame->b->data > frame->b->next->data)
	{
		frame->b_highest = frame->b->data;
		frame->b_lowest = frame->b->next->data;
	}
	else
	{
		rb(frame);
		frame->b_highest = frame->b->data;
		frame->b_lowest = frame->b->next->data;
	}
	size -= 2;
	// start pushing each element to it's correct position in B
	// until we reach the end of A
	while (size > 0)
	{
		move_to_b(frame);
		size--;
	}
}

static void	re_populate_a(t_frame *frame)
{
	if (!frame->b)
		return ;
	while (frame->b)
	{
		pa(frame);
		if (!frame->b)
			break ;
	}
}

// We're moving every element from stack A to stack B
void	sort(t_frame *frame)
{
	int	highest_moves_to_top;

	start_sorting(frame);
	highest_moves_to_top = moves_to_top(frame->b, frame->b_highest);
	if (should_rotate_to_top(frame->b, frame->b_highest))
		frame->b_rotations = highest_moves_to_top;
	else
		frame->b_r_rotations = highest_moves_to_top;
	apply_rotations(frame);
	re_populate_a(frame);
}
