/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:02:08 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/18 01:48:18 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	apply_rotations(t_frame *frame)
{
	while (frame->a_rotations && frame->b_rotations)
	{
		rr(frame);
		frame->a_rotations--;
		frame->b_rotations--;
	}
	while (frame->a_r_rotations && frame->b_r_rotations)
	{
		rrr(frame);
		frame->a_r_rotations--;
		frame->b_r_rotations--;
	}
	while (frame->a_rotations-- > 0)
		ra(frame);
	while (frame->b_rotations-- > 0)
		rb(frame);
	while (frame->a_r_rotations-- > 0)
		rra(frame);
	while (frame->b_r_rotations-- > 0)
		rrb(frame);
	reset_rotations(frame);
}

/**
- get information about the best element to push to B
- rotate the stacks based on the information set in the frame
- now it's time to push after we did the necessery rotations
- reset the information for the next element
*/
static void	move_to_b(t_frame *frame)
{
	find_cheapest_move(frame);
	apply_rotations(frame);
	pb(frame);
	set_new_highest_lowest(frame, frame->cheapest_value);
	frame->cheapest_moves = 0;
}

/**
- push the first two elements of A to B,
- then set the highest and lowest values of B in order to establish a baseline.
- start pushing each element to it's correct position in B
- until we reach the end of A
*/
static void	start_sorting(t_frame *frame)
{
	int	size;

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
	size = get_stack_size(frame->a);
	while (size > 3)
	{
		move_to_b(frame);
		size--;
	}
}

/**
- push every node from stack B to stack A to it's correct position
- if stack b node is the biggest, push it to the top of stack A then rotate
- if stack b node is the smallest, push it to the top of stack A
- if stack b node is neither,
	find the value bigger than it in stack A and push it to the top
*/
static void	re_populate_a(t_frame *frame)
{
	long int	a_highest;
	long int	a_lowest;

	a_highest = frame->a->prev->data;
	a_lowest = frame->a->data;
	while (frame->b)
	{
		find_correct_position_in_a(frame, &a_highest, &a_lowest);
		apply_rotations(frame);
		pa(frame);
		if (frame->a->data > frame->a->next->data)
			sa(frame);
		if (!frame->b)
			break ;
	}
	if (frame->a->prev->data < frame->a->data)
		rra(frame);
}

/**
- We're moving every element from stack A to stack B
- After we finished sorting, we make sure that the highest value in B is
  at the top of the stack
*/
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
	if (!is_stack_sorted(frame->a))
		sort_three(frame, 'a');
	re_populate_a(frame);
}
