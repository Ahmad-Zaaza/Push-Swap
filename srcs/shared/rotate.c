/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:45:58 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/15 19:35:31 by ahmadzaaza       ###   ########.fr       */
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
	frame->print_operations = 0;
	ra(frame);
	rb(frame);
	frame->print_operations = 1;
	if (frame->print_operations)
		print_operation("r", 'r', frame);
}