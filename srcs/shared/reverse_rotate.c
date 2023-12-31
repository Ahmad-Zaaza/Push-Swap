/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:46:39 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/22 13:23:03 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_frame *frame)
{
	r_rotate(frame, 'a');
}

void	rrb(t_frame *frame)
{
	r_rotate(frame, 'b');
}

void	rrr(t_frame *frame)
{
	if (frame->print_operations)
	{
		frame->print_operations = 0;
		rra(frame);
		rrb(frame);
		frame->print_operations = 1;
		print_operation("rr", 'r', frame);
	}
	else
	{
		rra(frame);
		rrb(frame);
	}
}
