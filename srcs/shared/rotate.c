/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:45:58 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/17 02:20:47 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_frame *frame)
{
	rotate(frame, 'a');
}
void	rb(t_frame *frame)
{
	rotate(frame, 'b');
}
void	rr(t_frame *frame)
{
	if (frame->print_operations)
	{
		frame->print_operations = 0;
		ra(frame);
		rb(frame);
		frame->print_operations = 1;
		print_operation("r", 'r', frame);
	}
	else
	{
		ra(frame);
		rb(frame);
	}
}